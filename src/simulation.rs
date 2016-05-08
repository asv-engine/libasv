
use world;
use vehicle;

pub struct Simulation {
  
  // Time, in seconds, since simulation start.
  
  pub time: f64,

  // The main [world](:world.rs).

  pub world: world::World,
  
  // List of vehicles that are currently running in the
  // simulation. This only includes vehicles that are currently
  // present in the world. The `Simulation` does not keep track of
  // vehicles that do not exist in the "real (simulated) world".
  
  vehicles: Vec<vehicle::Vehicle>
}

impl Simulation {

  /// Creates a new `Simulation` with default values.
  
  pub fn new() -> Simulation {
    
    Simulation {
      time: 0.0,
      world: world::World::new(),
      vehicles: vec![]
    }
    
  }

  /// # Vehicle management

  pub fn push_vehicle(&mut self, vehicle: vehicle::Vehicle) -> () {
    self.vehicles.push(vehicle);
  }

  /// # Tick
  /// Step through the simulation by one tick.
  /// `self` needs to be mutable because we modify `self.time`.
  
  pub fn tick(&mut self, step: f64) -> () {
    
    // Increments `time` by `step`. Obviously, other stuff will need
    // to happen here, too.
    
    self.time += step;

    for vehicle in self.vehicles.iter_mut() {
      vehicle.tick(step);
    }
    
  }

}
