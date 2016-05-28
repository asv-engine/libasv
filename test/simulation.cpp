
#include "catch.hpp"
#include "asv.h"

SCENARIO("simulations can tick", "[simulation]") {

  GIVEN("A simulation object") {
    ASV::Simulation sim;

    REQUIRE(sim.getTime() == 0.0);
    REQUIRE(sim.getTicks() == 0);

    WHEN("a simulation tick is run") {
      sim.tick();

      THEN("the number of ticks increased by one") {
        REQUIRE(sim.getTicks() == 1);
      }
    }
    
    WHEN("the simulation is stepped through for 10 seconds") {
      sim.tick(10.0);

      THEN("the elapsed time >= 10 seconds") {
        REQUIRE(sim.getTime() >= 10.0);
      }
    }
    
  }
}
