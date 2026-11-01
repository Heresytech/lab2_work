cmake_minimum_required(VERSION 3.23)

project(LAB2)
add_executable(SCVOZNOE)
add_executable(LAB2_PROG)
target_sources(LAB2_PROG PRIVATE ./lab2_src/lab2_src.cpp)
target_sources(SCVOZNOE PRIVATE ./scvoznoe_zad_src/scvoznoe.cpp)