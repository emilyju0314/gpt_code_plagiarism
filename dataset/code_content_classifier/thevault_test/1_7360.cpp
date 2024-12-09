void TalonFXDiffSwerveModule::ConfigureNeutralOnLOS(bool enable) {
	double value = enable ? 0 : 1;
	_master.ConfigSetParameter(
		ParamEnum::eRemoteSensorClosedLoopDisableNeutralOnLOS,
		value,
		0x00,
		0x00,
		kTimeoutMs
	);
}