void macWakeupTimer::start(void)
{
	double BI,bcnRxTime,now,wtime;
	double tmpf;
	BI = (aBaseSuperframeDuration * (1 << mac->macBeaconOrder2)) / mac->phy->getRate('s');
	bcnRxTime = mac->macBcnRxTime / mac->phy->getRate('s');
	now = CURRENT_TIME;
	while (now - bcnRxTime > BI)
	bcnRxTime += BI;
	{
		tmpf = (now - bcnRxTime);;
		wtime = BI - tmpf-aTurnaroundTime/mac->phy->getRate('s');
//		wtime=wtime-3*mac->csmaca->bPeriod;
		if (wtime < 0) {
			printf("WARNING: negative time for wakeup timer");
			abort();
		}
	}
	tmpf = now + wtime;
	lastTime = now + wtime;
	Mac802_15_4Timer::start(wtime);
}