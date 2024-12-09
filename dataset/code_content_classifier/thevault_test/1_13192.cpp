void Shooter::manualControl(double dt) {
  shooterManualSpeed = fabs(_contGroup.Get(ControlMap::shooterManualSpin)) > ControlMap::triggerDeadzone ? _contGroup.Get(ControlMap::shooterManualSpin) : 0;

  _shooterSystem.shooterGearbox.transmission->SetVoltage(shooterManualSpeed);
}