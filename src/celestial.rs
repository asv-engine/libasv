
use units;

pub struct Body {

  pub time: f64,

  pub mass: units::Mass

}

impl Body {

  pub fn new() -> Body {

    Body {
      time: 0.0,
      mass: units::Mass(1.0)
    }
    
  }

  pub fn reset(&mut self) -> () {
    
  }

}
