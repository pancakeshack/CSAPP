#!/usr/bin/env zsh

# Build and run the main.c file in a lesson directory.
set -euo pipefail

if (( $# != 1 )); then
  print -u2 "Usage: ${0:t} <folder>"
  exit 64
fi

folder=$1
source_file="$folder/main.c"
binary="$folder/main"

if [[ ! -d "$folder" ]]; then
  print -u2 "Error: folder not found: $folder"
  exit 66
fi

if [[ ! -f "$source_file" ]]; then
  print -u2 "Error: main.c not found in: $folder"
  exit 66
fi

gcc -Wall -Wextra -std=c11 "$source_file" -o "$binary"
"$binary"
