cmake_minimum_required(VERSION 3.20)
project(M2OEP_Large_idavis1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(M2OEP_Large_idavis1
        Athlete.cpp
        Athlete.h
        Team.cpp
        Team.h
        Soccer.cpp
        Soccer.h
        Sport.cpp
        Sport.h
        main.cpp)

add_executable(M2OEP_Large_idavis1_testing
        Athlete.cpp
        Athlete.h
        Team.cpp
        Team.h
        Soccer.cpp
        Soccer.h
        Sport.cpp
        Sport.h
        testing.cpp)

