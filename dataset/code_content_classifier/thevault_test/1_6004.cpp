void CClientPIC::initialize(char *isd_name, char *ini_filename)
{
  //connect to daemon
  this->pid = qnx_name_locate(0, isd_name, 0, NULL); 
  //ask daemon for the number of motors
  D_GetNumMotors();
  //read configuration file: gains and limits_max/min
  ReadConfig(ini_filename);
  //reset calibrated flags
  ResetCalibrated();
  
}