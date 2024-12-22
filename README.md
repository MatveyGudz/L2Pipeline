# L2Pipeline Project

## Requirements
- GCC >= 11
- Python >= 3.10
- CMake >= 3.16
- matplotlib (Python library)

## Build Instructions
1. Clone the project and navigate to the root directory.
2. Create a build directory and configure the project:
    ```bash
    mkdir build && cd build
    cmake ..
    make
    ```

## Usage
Run the pipeline with the following command:
```bash
bash scripts/run_pipeline.sh output.png file1.txt file2.bin file3.json
```

## Output
- The output scatter plot will be saved as `output.png`.
