void AutoDrive::Execute() {
	if(IsStrafe)
		Robot::driveBase->Drive(this->LSpeed, this->RSpeed, this->SSpeed);
	else
		Robot::driveBase->TDrive(this->LSpeed, this->RSpeed);
}