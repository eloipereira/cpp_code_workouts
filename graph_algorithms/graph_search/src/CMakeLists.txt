cmake_minimum_required(VERSION 3.10)

project(graph_src)



set (PROJECT_SOURCES
  graph.h
  weighted_graph.h
  utils.h
)

add_library(graph_lib STATIC graph.h graph_search.h weighted_graph.h utils.h)
target_include_directories(graph_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(graph_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(graph_src
  main.cpp
  ${PROJECT_SOURCES}
)
