cmake_minimum_required (VERSION 3.20)

project (task01_SQL)

add_subdirectory ("E:\\Netology\\libpqxx-7.9.1" pqxx-build)

add_executable (task01_SQL main.cpp)

target_compile_features (task01_SQL PRIVATE cxx_std_17)

target_link_libraries (task01_SQL pqxx)