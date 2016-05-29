
# terms

There are a couple of basic concepts in `libasv`.

Obviously, there's a [`vehicle`](:vehicle.md). A vehicle doesn't have
to be an actual spacecraft; for example, a launchpad would be a vehicle.

A vehicle without any physical components is nothing;
[`components`](:component.md) make up the "logic" of the vehicle,
defining valves, engines, propellant tanks, and more.

The vehicle lives in a [`world`](:world.md).
