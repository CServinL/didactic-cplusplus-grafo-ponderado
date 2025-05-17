cmake_minimum_required(VERSION 3.10)
project(grafo-ponderado)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable( grafo-ponderado
  src/main.cpp
  src/grafo.cpp
  src/dfs.cpp
  src/mst.cpp
  src/shortest.cpp
)
