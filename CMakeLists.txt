
cmake_minimum_required(VERSION 3.16)
project(L2PipelineProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include external dependencies
include_directories(${CMAKE_SOURCE_DIR}/external)

# Add the source files
add_executable(l2_pipeline src/main.cpp src/parser.cpp src/utils.cpp)

# Ensure nlohmann_json header-only library is included
target_include_directories(l2_pipeline PRIVATE ${CMAKE_SOURCE_DIR}/external/nlohmann)
