
use celestial;

pub struct World {

  // Time, in seconds, since the arbitrary epoch used for this
  // world. Will be used for planetary movement in the future. The
  // simulation time is automatically added to this every tick.
  
  pub time: f64,

  // The system's human-readable name. Earth's system is named "Sol".
  
  pub name: String,

  // The root star of the star system.
  
  root_body: celestial::Body
}

impl World {

  pub fn new() -> World {
    
    World {
      time: 0.0,
      name: String::from("Unnamed World"),
      root_body: celestial::Body::new()
    }
    
  }

}
