FOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		if (ControllingRobot(s))
		{
			pRobot->robot_remote_holder = s;
			return;
		}
	}