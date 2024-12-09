void CPhysicsVehicleController::SetWheelForce(int wheelIndex, float force) {
	if (wheelIndex >= m_iWheelCount || wheelIndex < 0) {
		Assert(0);
		return;
	}

	// convert from kg*in/s to kg*m/s
	force *= METERS_PER_INCH;
	//m_pVehicle->applyEngineForce(force, wheelIndex);
}