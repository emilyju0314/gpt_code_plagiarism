void TiltToAngle::Execute() {

	if(turhop->GetTiltAngle() > desiredAngle)
			{turhop->AltitudeControl(-0.85);}
		else if(turhop->GetTiltAngle() < desiredAngle)
			{turhop->AltitudeControl(0.85);}
	
	SmartDashboard::PutNumber("Tilt Angle", turhop->GetTiltAngle());
	SmartDashboard::PutNumber("Potentiometer", turhop->GetPotAngle());
}