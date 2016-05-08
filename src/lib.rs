
pub mod vehicle;
pub mod world;

pub struct Simulation {
  
  // Time, in seconds, since simulation start
  
  pub time: f64,

  pub world: world::World,
  vehicles: Vec<vehicle::Vehicle>
}

impl Simulation {
  
  pub fn new() -> Simulation {
    Simulation {
      time: 0.0,
      world: world::World::new(),
      vehicles: vec![]
    }
  }

  pub fn push_vehicle(&mut self, vehicle: vehicle::Vehicle) -> () {
    self.vehicles.push(vehicle);
  }

}
