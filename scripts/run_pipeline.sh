#!/bin/bash

if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <output_image_path> <file1> [file2 ...]" >&2
    exit 1
fi

OUTPUT_IMAGE=$1
shift
FILES="$@"

CXX_EXECUTABLE="./build/L2Pipeline"

if [ ! -f "$CXX_EXECUTABLE" ]; then
    echo "Error: Executable $CXX_EXECUTABLE not found. Build the project first." >&2
    exit 1
fi

python3 process_data.py "$OUTPUT_IMAGE" < <("$CXX_EXECUTABLE" $FILES)
if [ $? -ne 0 ]; then
    echo "Error: Pipeline failed." >&2
    exit 1
fi

echo "Pipeline executed successfully. Output saved to $OUTPUT_IMAGE."
