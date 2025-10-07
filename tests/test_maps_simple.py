#!/usr/bin/env python3
"""
Simple test script for cub3d invalid maps
Tests if ./cub3d <map> prints error messages and checks for memory leaks
"""

import os
import subprocess
import sys
import glob
from pathlib import Path

def test_map(map_file):
    """Test a single map file"""
    map_name = os.path.basename(map_file)
    print(f"\n🧪 Testing: \033[1;36m{map_name}\033[0m")
    
    # Test basic execution
    try:
        result = subprocess.run(
            ["./cub3d", map_file],
            cwd="/home/lhenriqu/GitHub/cub3d",
            capture_output=True,
            text=True,
            timeout=5
        )
        
        # Check if there's output (error message)
        has_output = bool(result.stdout.strip() or result.stderr.strip())
        
        if has_output:
            print(f"\033[1;32m✅ ERROR HANDLING: Program printed error message\033[0m")
            print(f"   \033[33mExit code:\033[0m {result.returncode}")
            if result.stdout.strip():
                print(f"   \033[36mstdout:\033[0m {result.stdout.strip()}")
            if result.stderr.strip():
                print(f"   \033[35mstderr:\033[0m {result.stderr.strip()}")
        else:
            print(f"\033[1;31m❌ ERROR HANDLING: No output detected (silent failure)\033[0m")
            return False
            
    except subprocess.TimeoutExpired:
        print(f"❌ ERROR HANDLING: Program timed out")
        return False
    except Exception as e:
        print(f"❌ ERROR HANDLING: Execution error: {e}")
        return False
    
    # Test with valgrind for memory leaks
    print(f"🔍 Checking memory leaks with valgrind...")
    try:
        valgrind_result = subprocess.run(
            ["valgrind", "--leak-check=full", "--error-exitcode=42", "./cub3d", map_file],
            cwd="/home/lhenriqu/GitHub/cub3d",
            capture_output=True,
            text=True,
            timeout=10
        )
        
        # Check for actual memory leaks (not just "still reachable")
        valgrind_output = valgrind_result.stderr
        
        definitely_lost = "definitely lost: 0 bytes in 0 blocks" not in valgrind_output and "definitely lost:" in valgrind_output
        possibly_lost = "possibly lost: 0 bytes in 0 blocks" not in valgrind_output and "possibly lost:" in valgrind_output
        
        if definitely_lost or possibly_lost:
            print(f"❌ MEMORY LEAKS: Detected memory leaks")
            # Extract leak info
            lines = valgrind_output.split('\n')
            for line in lines:
                if "definitely lost:" in line or "possibly lost:" in line:
                    if "0 bytes in 0 blocks" not in line:
                        print(f"   {line.strip()}")
            return False
        else:
            print(f"✅ MEMORY LEAKS: No memory leaks detected")
            
    except subprocess.TimeoutExpired:
        print(f"❌ MEMORY LEAKS: Valgrind timed out")
        return False
    except Exception as e:
        print(f"❌ MEMORY LEAKS: Valgrind error: {e}")
        return False
    
    return True

def main():
    print("🎯 CUB3D INVALID MAPS TESTER")
    print("=" * 50)
    
    # Check if executable exists
    if not os.path.exists("/home/lhenriqu/GitHub/cub3d/cub3d"):
        print("❌ cub3d executable not found! Run 'make' first.")
        sys.exit(1)
    
    # Check if valgrind is available
    try:
        subprocess.run(["valgrind", "--version"], capture_output=True, check=True)
        print("✅ valgrind found")
    except:
        print("❌ valgrind not found! Install valgrind for memory leak testing.")
        sys.exit(1)
    
    # Get all invalid map files
    invalid_dir = "/home/lhenriqu/GitHub/cub3d/maps/invalid"
    map_files = []
    
    for file_path in Path(invalid_dir).iterdir():
        if file_path.is_file():
            if file_path.suffix == '.cub' or file_path.name in ['filetype_missing']:
                map_files.append(str(file_path))
    
    map_files.sort()
    print(f"📁 Found {len(map_files)} invalid map files to test\n")
    
    # Test all maps
    passed = 0
    failed = 0
    failed_maps = []
    
    for map_file in map_files:
        if test_map(map_file):
            passed += 1
        else:
            failed += 1
            failed_maps.append(os.path.basename(map_file))
    
    # Summary
    print("\n" + "=" * 50)
    print("📊 TEST SUMMARY")
    print("=" * 50)
    print(f"✅ Passed: {passed}")
    print(f"❌ Failed: {failed}")
    print(f"📈 Total:  {passed + failed}")
    
    if failed_maps:
        print(f"\n❌ Failed maps:")
        for map_name in failed_maps:
            print(f"   - {map_name}")
    
    if failed == 0:
        print(f"\n🎉 All tests passed!")
        sys.exit(0)
    else:
        print(f"\n⚠️  Some tests failed!")
        sys.exit(1)

if __name__ == "__main__":
    main()