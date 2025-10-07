#!/usr/bin/env python3
"""
Script to extract all unique texture file names from cub3d maps
Scans both invalid and valid map directories and extracts texture paths from:
NO (North), SO (South), WE (West), EA (East) declarations
"""

import os
import re
import sys
from pathlib import Path

def extract_textures_from_file(file_path):
    """
    Extract texture paths from a .cub file
    Returns a set of texture file paths found in the file
    """
    textures = set()
    
    try:
        with open(file_path, 'r') as f:
            content = f.read()
            
        # Regex patterns for texture declarations
        # Matches: NO textures/test/north.xpm, SO assets/brick.png, etc.
        patterns = [
            r'NO\s+(.+\.(?:xpm|png))',  # North texture (xpm or png)
            r'SO\s+(.+\.(?:xpm|png))',  # South texture (xpm or png)
            r'WE\s+(.+\.(?:xpm|png))',  # West texture (xpm or png)
            r'EA\s+(.+\.(?:xpm|png))',  # East texture (xpm or png)
        ]
        
        for pattern in patterns:
            matches = re.findall(pattern, content, re.IGNORECASE)
            for match in matches:
                # Clean up the path (remove extra whitespace)
                texture_path = match.strip()
                if texture_path:
                    textures.add(texture_path)
                    
    except Exception as e:
        print(f"❌ Error reading {file_path}: {e}")
        
    return textures

def scan_directory(directory_path):
    """
    Scan a directory for .cub files and extract all textures
    Returns a set of all unique texture paths found
    """
    all_textures = set()
    files_processed = 0
    
    if not os.path.exists(directory_path):
        print(f"❌ Directory not found: {directory_path}")
        return all_textures
    
    print(f"🔍 Scanning directory: {directory_path}")
    
    for file_path in Path(directory_path).iterdir():
        if file_path.is_file() and (file_path.suffix == '.cub' or file_path.name.endswith('.cub')):
            textures = extract_textures_from_file(file_path)
            if textures:
                print(f"   📄 {file_path.name}: {len(textures)} texture(s)")
                for texture in sorted(textures):
                    print(f"      - {texture}")
            all_textures.update(textures)
            files_processed += 1
    
    print(f"   ✅ Processed {files_processed} .cub files")
    return all_textures

def get_texture_filename(texture_path):
    """
    Extract just the filename from a texture path
    Example: 'textures/test/north.xpm' -> 'north.xpm'
    """
    return os.path.basename(texture_path)

def main():
    """Main function"""
    print("🎨 CUB3D TEXTURE EXTRACTOR")
    print("=" * 50)
    
    # Define directories to scan
    directories = [
        "/home/lhenriqu/GitHub/cub3d/maps/invalid",
        "/home/lhenriqu/GitHub/cub3d/maps/valid"
    ]
    
    all_textures = set()
    
    # Scan both directories
    for directory in directories:
        textures = scan_directory(directory)
        all_textures.update(textures)
        print()
    
    # Display results
    print("=" * 50)
    print("📋 TEXTURE SUMMARY")
    print("=" * 50)
    
    if not all_textures:
        print("❌ No textures found!")
        sys.exit(1)
    
    print(f"🎯 Total unique texture paths found: {len(all_textures)}")
    print("\n📁 Full texture paths:")
    for texture in sorted(all_textures):
        print(f"   - {texture}")
    
    # Extract unique filenames (without paths)
    unique_filenames = set()
    for texture_path in all_textures:
        filename = get_texture_filename(texture_path)
        unique_filenames.add(filename)
    
    print(f"\n🏷️  Unique texture filenames needed ({len(unique_filenames)}):")
    for filename in sorted(unique_filenames):
        print(f"   - {filename}")
    
    # Group by directory structure
    print(f"\n📂 Textures grouped by directory:")
    texture_dirs = {}
    for texture_path in all_textures:
        directory = os.path.dirname(texture_path)
        filename = os.path.basename(texture_path)
        
        if directory not in texture_dirs:
            texture_dirs[directory] = set()
        texture_dirs[directory].add(filename)
    
    for directory in sorted(texture_dirs.keys()):
        print(f"   📁 {directory}:")
        for filename in sorted(texture_dirs[directory]):
            print(f"      - {filename}")
    
    print(f"\n✨ Done! Found {len(unique_filenames)} unique texture files needed.")

if __name__ == "__main__":
    main()
