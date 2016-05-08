
// Length, stored in meters.

pub struct Length(pub f64);

// Velocity, stored in meters per second.

pub struct Velocity(pub f64);

// Mass, stored in kilograms.

pub struct Mass(pub f64);

// Force, stored in newtons.

pub struct Force(pub f64);

impl Length {
  
  pub fn meters(meters: f64) -> Length {
    Length(meters)
  }
  
  pub fn kilometers(kilometers: f64) -> Length {
    Length(kilometers * 1000.0)
  }
  
}

impl Velocity {
  
  pub fn meters_per_second(meters_per_second: f64) -> Velocity {
    Velocity(meters_per_second)
  }
  
}

impl Mass {
  
  pub fn kilograms(kilograms: f64) -> Mass {
    Mass(kilograms)
  }
  
  pub fn grams(grams: f64) -> Mass {
    Mass(grams / 1000.0)
  }
  
}

impl Force {
  
  pub fn newtons(newtons: f64) -> Force {
    Force(newtons)
  }
  
  pub fn kilonewtons(kilonewtons: f64) -> Force {
    Force(kilonewtons * 1000.0)
  }
  
}
