cmake_minimum_required(VERSION 3.10)
project(ChaosPIS)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(
    Config 
    ExternalLibs/pbPlots 
    Project
)

include_directories(Config ExternalLibs Project)
file(GLOB SOURCES "Config/*.h" "Project/*.h" "ExternalLibs/pbPlots/*.h" "ExternalLibs/pbPlots/*.c" "Config/*.c" "Project/*.c")

add_executable(Chaos ${SOURCES})