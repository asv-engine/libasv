
pub mod vehicle;
pub mod world;

pub struct Simulation {
  
  /// Time, in seconds, since simulation start.
  
  pub time: f64,

  /// The main [world](:world.rs).

  pub world: world::World,
  
  /// List of vehicles
  
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
