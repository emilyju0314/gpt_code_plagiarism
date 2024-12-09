static void SkyriderDestroyed(void)
{
	// remove any arrival events for the helicopter's group
	VEHICLETYPE& v = GetHelicopter();
	DeleteStrategicEvent(EVENT_GROUP_ARRIVAL, v.ubMovementGroup);
	KillAllInVehicle(v);

	// kill skyrider
	gMercProfiles[ SKYRIDER ].bLife = 0;

	// destroy helicopter
	fHelicopterDestroyed = TRUE;

	// zero out balance due
	gMercProfiles[ SKYRIDER ].iBalance = 0;
	iTotalAccumulatedCostByPlayer = 0;

	// remove vehicle and reset
	RemoveVehicleFromList(v);
	iHelicopterVehicleId = -1;
}