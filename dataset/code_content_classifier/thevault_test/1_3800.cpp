CPhysicsObject *CPhysicsVehicleController::CreateWheel(int wheelIndex, vehicle_axleparams_t &axle) {
	if (wheelIndex >= VEHICLE_MAX_WHEEL_COUNT)
		return NULL;

	Vector position = axle.offset;
	Vector bodyPosition;
	QAngle bodyAngles;
	m_pBody->GetPosition(&bodyPosition, &bodyAngles);
	matrix3x4_t matrix;
	AngleMatrix(bodyAngles, bodyPosition, matrix);

	// HACK: This will only work with vehicles that have 2 wheels per axle
	if (wheelIndex & 1) {
		position += axle.wheelOffset;
	} else {
		position -= axle.wheelOffset;
	}

	QAngle angles = vec3_angle;
	Vector wheelPositionHL;
	VectorTransform(position, matrix, wheelPositionHL);

	objectparams_t params;
	memset(&params, 0, sizeof(params));

	params.damping = axle.wheels.damping;
	params.dragCoefficient = 0;
#ifdef USE_WHEELED_VEHICLE
	params.enableCollisions = true;
#else
	params.enableCollisions = false;
#endif
	params.inertia = axle.wheels.inertia;
	params.mass = axle.wheels.mass;
	params.pGameData = m_pBody->GetGameData();
	params.pName = "VehicleWheel";
	params.rotdamping = axle.wheels.rotdamping;
	params.rotInertiaLimit = 0;

	// needs to be in HL units because we're calling through the "outer" interface to create
	// the wheels
	float radius = axle.wheels.radius;
	float r3 = radius * radius * radius;
	params.volume = (4.0f / 3.0f) * M_PI_F * r3;

	// TODO: Change this to a cylinder!
	CPhysicsObject *pWheel = (CPhysicsObject *)m_pEnv->CreateSphereObject(radius, axle.wheels.materialIndex, wheelPositionHL, angles, &params);
	pWheel->Wake();
	pWheel->AddCallbackFlags(CALLBACK_IS_VEHICLE_WHEEL);

	pWheel->GetObject()->setActivationState(DISABLE_DEACTIVATION);

	// Create it in bullet now
#ifdef USE_WHEELED_VEHICLE
	btVector3 wheelOffset;
	ConvertPosToBull(position, wheelOffset);
	wheelOffset -= ((btMassCenterMotionState *)m_pBody->GetObject()->getMotionState())->m_centerOfMassOffset.getOrigin();

	btVehicleWheel &wheel = m_pVehicle->addWheel(pWheel->GetObject(), wheelOffset, btMatrix3x3::getIdentity(), btVector3(0, -1, 0), btVector3(-1, 0, 0));
	wheel.suspensionRestLength = ConvertDistanceToBull(axle.wheels.springAdditionalLength);
	wheel.suspensionConstant = axle.suspension.springConstant;
	wheel.suspensionDamping = axle.suspension.springDamping;
	wheel.maxSuspensionForce = axle.suspension.maxBodyForce * m_pBody->GetMass();
#else
	// Create the wheel in bullet
	btVector3 bullConnectionPointCS0;
	btScalar bullSuspensionRestLength, bullWheelRadius;

	// This parameter is unused by bullet.
	bool bIsFrontWheel = (wheelIndex < 2);		// HACK: Only works with 2 front wheels

	btVector3 bullWheelDirectionCS0(0, -1, 0);	// Straight down
	btVector3 bullWheelAxleCS(1, 0, 0);			// Left

	ConvertPosToBull(position, bullConnectionPointCS0);
	bullConnectionPointCS0 -= ((btMassCenterMotionState *)m_pBody->GetObject()->getMotionState())->m_centerOfMassOffset.getOrigin();

	bullSuspensionRestLength = ConvertDistanceToBull(axle.wheels.springAdditionalLength);
	bullWheelRadius = ConvertDistanceToBull(axle.wheels.radius);

	btWheelInfo &wheelInfo = m_pVehicle->addWheel(bullConnectionPointCS0, bullWheelDirectionCS0, bullWheelAxleCS, bullSuspensionRestLength, bullWheelRadius, m_tuning, bIsFrontWheel);

	// FIXME: frictionScale is UNUSED (or we're not parsing something correctly)!
	//wheelInfo.m_frictionSlip = axle.wheels.frictionScale;
	wheelInfo.m_frictionSlip = 1.5f; // debug value
	wheelInfo.m_maxSuspensionForce = axle.suspension.maxBodyForce * m_pBody->GetMass();
	wheelInfo.m_suspensionStiffness = axle.suspension.springConstant;
	
	wheelInfo.m_clientInfo = pWheel;
#endif

	return pWheel;
}