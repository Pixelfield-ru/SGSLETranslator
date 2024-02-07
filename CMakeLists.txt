cmake_minimum_required(VERSION 3.27)
project(SGSLETranslator)

file(GLOB_RECURSE SGSLE_TRANSLATOR_SOURCES Sources/*.cpp Sources/*.h)

set(CMAKE_CXX_STANDARD 23)

add_executable(SGSLETranslator ${SGSLE_TRANSLATOR_SOURCES}
        Sources/SGSLETranslator.h
        Sources/SGSLETranslator.cpp)
