
pub struct Vehicle {

  // Time, in seconds, since this vehicle was created. Note that this
  // is not necessarily the same as Simulation::time.
  
  time: f64
}

impl Vehicle {
  
  pub fn new() -> Vehicle {
    Vehicle {
      time: 0.0
    }
  }

  pub fn tick(&mut self, step: f64) -> () {
    self.time += step;
  }
  
}
