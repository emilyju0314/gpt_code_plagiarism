int 
YARPGalilDeviceDriver::waitForMotionDone(void *cmd)
{
	int rc = 0;
	bool _motion_flag = false;
	int time = *((int *) cmd);

	check_motion_done(&_motion_flag);
	if (time != 0){ 
		while(!_motion_flag){
			ACE_OS::sleep(ACE_Time_Value(0,time));
			check_motion_done(&_motion_flag);
		}
	}
	else {
		while(!_motion_flag)
			check_motion_done(&_motion_flag);
	}

	return rc;
}