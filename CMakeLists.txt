cmake_minimum_required(VERSION 3.24)
project(thread_checker)

set(CMAKE_CXX_STANDARD 17)
if(APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xclang -fopenmp")

    include_directories(/usr/local/include)

    find_library(OPENMP_LIB libomp.dylib /usr/local/lib)
else()
    find_package(OpenMP)
endif()

add_executable(thread_checker main.cpp)
if(APPLE)
    target_link_libraries(thread_checker LINK_PRIVATE ${OPENMP_LIB})
else()
    target_link_libraries(thread_checker OpenMP::OpenMP_CXX)
endif()
