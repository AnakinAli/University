cmake_minimum_required(VERSION 3.28)
project(Second_TermPaper_2)

set(CMAKE_CXX_STANDARD 26)

add_executable(Second_TermPaper_2 main.cpp
        Classes/Plant.cpp
        Classes/Plant.h
        Classes/inputHandle.h
        Classes/Tree.cpp
        Classes/Tree.h
        Classes/Flower.cpp
        Classes/Flower.h
        Classes/PlantHandler.cpp
        Classes/PlantHandler.h)
