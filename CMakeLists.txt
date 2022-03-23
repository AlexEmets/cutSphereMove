cmake_minimum_required(VERSION 3.21)
project(testTaskSphere)

set(CMAKE_CXX_STANDARD 14)

add_executable(testTaskSphere
        cutSphereMove.cpp
        CreateSkin.cpp
        mwArcFunction.cpp
        mwException.cpp
        mwIdxRangeException.cpp)
