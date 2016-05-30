
#include "catch.hpp"
#include "asv.h"

SCENARIO("values can be created", "[value]") {

  GIVEN("A value") {
    ASV::Value v;

    REQUIRE(v.getName()->compare("") == 0);
    REQUIRE(v.getValueInt() == 0);

    WHEN("the value is set to 42") {
      v.setValue(42);

      THEN("the value is 42") {
        REQUIRE(v.getValueInt() == 42);
      }
      
      THEN("getType() returns INT") {
        REQUIRE(v.getType() == ASV::Value::Type::INT);
      }
      
      THEN("calling getValueDouble(44.9) returns 44.9") {
        REQUIRE(v.getValueDouble(44.9) == 44.9);
      }
      
    }
    
    WHEN("the value is set to 29.92") {
      v.setValue(29.92);

      THEN("the value is 29.92") {
        REQUIRE(v.getValueDouble() == 29.92);
      }
      
      THEN("getType() returns DOUBLE") {
        REQUIRE(v.getType() == ASV::Value::Type::DOUBLE);
      }
      
      THEN("calling getValueInt(90) returns 90") {
        REQUIRE(v.getValueInt(90) == 90);
      }
      
    }
    
    WHEN("the name is set to \"Foobar\"") {
      v.setName("Foobar");

      THEN("the the name is \"Foobar\"") {
        REQUIRE(v.getName()->compare("Foobar") == 0);
      }
    }
    
  }
}
