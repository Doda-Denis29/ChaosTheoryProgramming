cmake_minimum_required(VERSION 3.10)
project(ChaosPIS)

include_directories(Config ExternalLibs Project)
file(GLOB SOURCES "Config/*.c" "ExternalLibs/pbPlots/*.c" "Project/*.c")

add_executable(Chaos ${SOURCES})