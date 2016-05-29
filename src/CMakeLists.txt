
include_directories(../include/)

add_library(asv
  time.cpp
  
  world.cpp
  
  component.cpp
  vehicle.cpp
  
  simulation.cpp
  )

target_include_directories(asv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
