void CClientPIC::initialize(char *isd_name)
{
  //connect to daemon
  this->pid = qnx_name_locate(0, isd_name, 0, NULL);
  //ask daemon for the number of motors
  D_GetNumMotors();
  //reset calibrated flags, this shouldn't be necessary but just in case
  ResetCalibrated();
}