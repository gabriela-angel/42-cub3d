#!/usr/bin/env python3
"""
Test script for cub3d invalid maps
This script tests all invalid maps in the maps/invalid/ directory to ensure:
1. The program prints error messages (not silent failure)
2. No memory leaks occur (using valgrind)
3. Program exits with appropriate error codes
"""

import os
import subprocess
import sys
import glob
from pathlib import Path

# Colors for output
class Colors:
    RED = '\033[91m'
    GREEN = '\033[92m'
    YELLOW = '\033[93m'
    BLUE = '\033[94m'
    MAGENTA = '\033[95m'
    CYAN = '\033[96m'
    WHITE = '\033[97m'
    BOLD = '\033[1m'
    END = '\033[0m'

def print_header(text):
    """Print a formatted header"""
    print(f"\n{Colors.BLUE}{Colors.BOLD}{'='*60}{Colors.END}")
    print(f"{Colors.BLUE}{Colors.BOLD}{text.center(60)}{Colors.END}")
    print(f"{Colors.BLUE}{Colors.BOLD}{'='*60}{Colors.END}")

def print_test_result(test_name, passed, message=""):
    """Print test result with colors"""
    status = f"{Colors.GREEN}PASS{Colors.END}" if passed else f"{Colors.RED}FAIL{Colors.END}"
    print(f"[{status}] {test_name}")
    if message:
        print(f"       {message}")

def run_cub3d_test(map_path):
    """
    Run cub3d with a map file and return results
    Returns: (exit_code, stdout, stderr, has_output)
    """
    try:
        result = subprocess.run(
            ["./cub3d", map_path],
            cwd="/home/lhenriqu/GitHub/cub3d",
            capture_output=True,
            text=True,
            timeout=5  # 5 second timeout
        )
        
        # Check if there's any output (stdout or stderr)
        has_output = bool(result.stdout.strip() or result.stderr.strip())
        
        return result.returncode, result.stdout, result.stderr, has_output
    
    except subprocess.TimeoutExpired:
        return -1, "", "TIMEOUT", False
    except Exception as e:
        return -2, "", str(e), False

def run_valgrind_test(map_path):
    """
    Run cub3d with valgrind to check for memory leaks
    Returns: (has_leaks, leak_summary)
    """
    try:
        # Run with valgrind
        cmd = [
            "valgrind",
            "--leak-check=full",
            "--show-leak-kinds=all",
            "--track-origins=yes",
            "--error-exitcode=42",
            "./cub3d",
            map_path
        ]
        
        result = subprocess.run(
            cmd,
            cwd="/home/lhenriqu/GitHub/cub3d",
            capture_output=True,
            text=True,
            timeout=10  # 10 second timeout for valgrind
        )
        
        # Parse valgrind output for leaks
        valgrind_output = result.stderr
        
        # Only consider actual leaks, not "still reachable" memory
        has_leaks = False
        definitely_lost = "definitely lost: 0 bytes in 0 blocks" not in valgrind_output and "definitely lost:" in valgrind_output
        possibly_lost = "possibly lost: 0 bytes in 0 blocks" not in valgrind_output and "possibly lost:" in valgrind_output
        
        has_leaks = definitely_lost or possibly_lost
        
        # Extract leak summary
        leak_summary = ""
        if "LEAK SUMMARY:" in valgrind_output:
            lines = valgrind_output.split('\n')
            summary_start = False
            for line in lines:
                if "LEAK SUMMARY:" in line:
                    summary_start = True
                    continue
                if summary_start and line.strip():
                    if line.startswith("=="):
                        leak_summary += line.split("==")[2].strip() + "\n"
                    else:
                        break
        
        return has_leaks, leak_summary.strip()
    
    except subprocess.TimeoutExpired:
        return True, "TIMEOUT during valgrind test"
    except Exception as e:
        return True, f"Error running valgrind: {str(e)}"

def test_single_map(map_file):
    """
    Test a single map file
    Returns: (passed, details)
    """
    map_name = os.path.basename(map_file)
    results = {}
    
    print(f"\n{Colors.CYAN}Testing: {map_name}{Colors.END}")
    
    # Test 1: Basic execution test
    exit_code, stdout, stderr, has_output = run_cub3d_test(map_file)
    
    # For invalid maps, we expect:
    # 1. Non-zero exit code OR some error output
    # 2. Some output (error message) should be printed
    
    if exit_code == -1:
        results['execution'] = (False, "Program timed out")
    elif exit_code == -2:
        results['execution'] = (False, f"Execution error: {stderr}")
    elif not has_output:
        results['execution'] = (False, "No error message printed (silent failure)")
    elif exit_code == 0 and not (stdout.strip() or stderr.strip()):
        results['execution'] = (False, "Program succeeded but should have failed")
    else:
        results['execution'] = (True, f"Exit code: {exit_code}, Output detected")
    
    # Test 2: Memory leak test with valgrind
    print(f"   Running valgrind check...")
    has_leaks, leak_summary = run_valgrind_test(map_file)
    
    if has_leaks:
        results['memory'] = (False, f"Memory leaks detected:\n{leak_summary}")
    else:
        results['memory'] = (True, "No memory leaks detected")
    
    return results

def main():
    """Main test function"""
    print_header("CUB3D INVALID MAPS TESTING")
    
    # Check if cub3d executable exists
    cub3d_path = "/home/lhenriqu/GitHub/cub3d/cub3d"
    if not os.path.exists(cub3d_path):
        print(f"{Colors.RED}Error: cub3d executable not found at {cub3d_path}{Colors.END}")
        print("Run 'make' to build the project first.")
        sys.exit(1)
    
    # Check if valgrind is available
    try:
        subprocess.run(["valgrind", "--version"], capture_output=True, check=True)
    except (subprocess.CalledProcessError, FileNotFoundError):
        print(f"{Colors.YELLOW}Warning: valgrind not found. Memory leak tests will be skipped.{Colors.END}")
        return
    
    # Get all map files in the invalid directory
    invalid_maps_dir = "/home/lhenriqu/GitHub/cub3d/maps/invalid"
    map_files = []
    
    # Get all .cub files and files without extension that should be maps
    for file_path in Path(invalid_maps_dir).iterdir():
        if file_path.is_file():
            # Include .cub files and files that look like map files
            if file_path.suffix == '.cub' or file_path.name in ['filetype_missing']:
                map_files.append(str(file_path))
    
    map_files.sort()
    
    if not map_files:
        print(f"{Colors.RED}No map files found in {invalid_maps_dir}{Colors.END}")
        sys.exit(1)
    
    print(f"Found {len(map_files)} invalid map files to test")
    
    # Test statistics
    total_tests = 0
    passed_tests = 0
    failed_maps = []
    
    # Test each map
    for map_file in map_files:
        results = test_single_map(map_file)
        map_name = os.path.basename(map_file)
        
        # Check execution test
        exec_passed, exec_msg = results['execution']
        print_test_result(f"{map_name} - Error handling", exec_passed, exec_msg)
        
        # Check memory test
        mem_passed, mem_msg = results['memory']
        print_test_result(f"{map_name} - Memory leaks", mem_passed, mem_msg)
        
        total_tests += 2
        if exec_passed:
            passed_tests += 1
        else:
            failed_maps.append(f"{map_name} (execution)")
            
        if mem_passed:
            passed_tests += 1
        else:
            failed_maps.append(f"{map_name} (memory)")
    
    # Print summary
    print_header("TEST SUMMARY")
    print(f"Total tests: {total_tests}")
    print(f"Passed: {Colors.GREEN}{passed_tests}{Colors.END}")
    print(f"Failed: {Colors.RED}{total_tests - passed_tests}{Colors.END}")
    
    if failed_maps:
        print(f"\n{Colors.RED}Failed tests:{Colors.END}")
        for failed in failed_maps:
            print(f"  - {failed}")
    
    # Exit with appropriate code
    if passed_tests == total_tests:
        print(f"\n{Colors.GREEN}{Colors.BOLD}All tests passed!{Colors.END}")
        sys.exit(0)
    else:
        print(f"\n{Colors.RED}{Colors.BOLD}Some tests failed!{Colors.END}")
        sys.exit(1)

if __name__ == "__main__":
    main()
