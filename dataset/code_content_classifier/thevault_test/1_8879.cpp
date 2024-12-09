void RedrawStatus()
{
	int BatteryStatus, BatteryPct = 0, BatteryTemp, BatteryTime;
	pspTime Time;
	
	pspDebugScreenSetXY(0, 33);
		
	//Read and display time
	pspDebugScreenSetTextColor(GREEN);
	sceRtcGetCurrentClockLocalTime(&Time);
	printf("%02d/%d/%04d %02d:%02d:%02d ", Time.day, Time.month,
		Time.year, Time.hour, Time.minutes, Time.seconds);
		
	//Read battery status
	if(scePowerIsBatteryExist())
	{
		BatteryPct = scePowerGetBatteryLifePercent();
		if(scePowerIsLowBattery()) BatteryStatus = BATTERY_LOW;
		else BatteryStatus = BATTERY_OK;
		if(scePowerIsBatteryCharging()) BatteryStatus++;
	}
	else BatteryStatus = BATTERY_NONE;
	
	//Set text colour
	switch(BatteryStatus)
	{
		case BATTERY_LOW: pspDebugScreenSetTextColor(RED); break;
		case BATTERY_LOW_CHARGING: pspDebugScreenSetTextColor(YELLOW); break;
		case BATTERY_OK_CHARGING: pspDebugScreenSetTextColor(AQUA); break;
		default: pspDebugScreenSetTextColor(GREEN);
	}
	
	//Display status and temperature
	if(BatteryStatus == BATTERY_NONE) printf("---%% ---min --C");
	else
	{
		printf("%d%% ", BatteryPct);
		
		BatteryTime = scePowerGetBatteryLifeTime();
		if(BatteryTime > 0) printf("%dmin ", BatteryTime);
		else printf("---min ");
		
		BatteryTemp = scePowerGetBatteryTemp();
		if(BatteryTemp > 50) pspDebugScreenSetTextColor(RED);
		else if(BatteryTemp > 40) pspDebugScreenSetTextColor(YELLOW);
		else if(BatteryTemp < 20) pspDebugScreenSetTextColor(BLUE);
		else pspDebugScreenSetTextColor(GREEN);
		printf("%dC", BatteryTemp);
	}
	
	
	//Adjust CPU speed depending on battery status
	if(AutoCPUSpeed)
	{
		scePowerSetCpuClockFrequency(CPUSpeeds[BatteryStatus]);
		scePowerSetBusClockFrequency(CPUSpeeds[BatteryStatus] / 2);
	}
	
	//Display CPU speed
	pspDebugScreenSetTextColor(GREEN);
	printf(" %dmhz     ", scePowerGetCpuClockFrequency());
	//a few spaces at the end of this string will wipe out any leftover characters
	//when the string gets shorter, e.g. the battery percentage dropping from 2 to
	//1 digit
}