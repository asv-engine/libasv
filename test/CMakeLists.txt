
include_directories(../include/)

add_executable(asv-tests
  value.cpp
  
  simulation.cpp
  
  main.cpp)

target_link_libraries(asv-tests LINK_PUBLIC asv)
