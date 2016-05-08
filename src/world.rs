
pub struct World {
  pub time: f64,
  pub name: String
}

impl World {
  
  pub fn new() -> World {
    World {
      time: 0.0,
      name: String::from("Sol")
    }
  }

}
