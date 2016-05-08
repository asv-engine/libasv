
extern crate libasv;

fn main() {
  let mut sim = libasv::Simulation::new();

  let vehicle = libasv::vehicle::Vehicle::new();

  sim.push_vehicle(vehicle);

  println!("world name: {}", sim.world.name);
}
