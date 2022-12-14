cmake_minimum_required(VERSION 3.10)

project(main)

set(CMAKE_C_COMPILER /opt/homebrew/opt/llvm/bin/clang)
set(CMAKE_CXX_COMPILER /opt/homebrew/opt/llvm/bin/clang++)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_OSX_DEPLOYMENT_TARGET 12.5)

#set(CMAKE_CXX_FLAGS "-Wall /opt/homebrew/opt/openblas/lib/libopenblas.a -fopenmp")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#SET(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# check and add third party packages
message("Check third party packages:\n")

message("[Eigen]")
find_package(Eigen3 3.4 REQUIRED NO_MODULE)
#include_directories(${EIGEN3_INCLUDE_DIR})
message(STATUS "Eigen location: ${EIGEN3_INCLUDE_DIR}\n")

message("[Qt]")
find_package(Qt6 6.3 REQUIRED COMPONENTS Core)
message(STATUS "Qt6 version: ${Qt6_VERSION}")
get_target_property(QtCore_location Qt6::Core LOCATION)
message(STATUS "Qt6 Core location: ${QtCore_location}\n")

message("[Python]")

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
#message(STATUS "Python location: ${Python3_EXECUTABLE}")
message(STATUS "Python include path: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python library path: ${Python3_LIBRARIES}\n")
# Configure
message("Start configure & generate:")

message("\nConfigure Library:")
add_subdirectory(src/Mesh)

message("\nConfigure Application:")
include_directories(src/Mesh)
add_executable(main main.cpp)

# target_include_directories(main PUBLIC "${EIGEN3_INCLUDE_DIR}")
target_link_libraries(main Qt6::Core)
target_link_libraries(main Eigen3::Eigen)
target_link_libraries(main "-framework Accelerate")
target_link_libraries(main "-lfmt")

target_link_libraries(main Mesh)
