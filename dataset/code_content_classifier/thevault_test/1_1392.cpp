void TiltToAngle::End() {
	turhop->AltitudeControl(0.0);
	SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
	SmartDashboard::PutNumber("Potentiometer", turhop->GetPotAngle());
}