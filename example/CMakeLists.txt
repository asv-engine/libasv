
include_directories(../include/)

add_executable(asv-example
  main.cpp)

target_link_libraries(asv-example LINK_PUBLIC asv)
