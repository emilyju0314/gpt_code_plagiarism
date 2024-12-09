ABatteryPickup::ABatteryPickup(){

	// When batteries spawn in, have them fall
	GetMesh()->SetSimulatePhysics(true);

	// Base power of the battery
	batteryPower = 150;

}