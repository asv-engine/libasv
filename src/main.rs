
// I'm not sure whether or not a sort of test wrapper should be
// included with Rust libraries, and if so, whether or not to
// `.gitignore` `Cargo.lock`.

// Include the library.

extern crate libasv;

fn main() {
  let mut sim = libasv::simulation::Simulation::new();

  let vehicle = libasv::vehicle::Vehicle::new();

  sim.push_vehicle(vehicle);

  //println!("world name: {}", sim.world.name);

  // Simple test to make sure `Simulation::tick` works properly.
  
  let ticks_per_second = 100;

  // 1 day of simulation
  let seconds = 60 * 60 * 24;
  
  while (sim.time as i32) < seconds {
    sim.tick(1.0 / ticks_per_second as f64);
  }

  // Print out the number of seconds that have been simulated.
  
  println!("simulation time: {}", sim.time);
}
