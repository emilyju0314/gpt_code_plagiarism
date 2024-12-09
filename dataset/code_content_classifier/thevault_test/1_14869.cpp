void HourlyProgressUpdate(void)
{
	UINT8 ubCurrentProgress;

	ubCurrentProgress = CurrentPlayerProgressPercentage();

	// if this is new high, remember it as that
	if (ubCurrentProgress > gStrategicStatus.ubHighestProgress)
	{
		// CJC:  note when progress goes above certain values for the first time
		#define first_event_trigger( progress_threshold ) (ubCurrentProgress >= progress_threshold && gStrategicStatus.ubHighestProgress < progress_threshold)

		// at 35% start the Madlab quest
		if (first_event_trigger(gamepolicy(progress_event_madlab_min)))
		{
			HandleScientistAWOLMeanwhileScene();
		}

		// at 50% make Mike available to the strategic AI
		if (first_event_trigger(gamepolicy(progress_event_mike_min)))
		{
			SetFactTrue( FACT_MIKE_AVAILABLE_TO_ARMY );
		}

		// at 70% add Iggy to the world
		if (first_event_trigger(gamepolicy(progress_event_iggy_min)))
		{
			gMercProfiles[ IGGY ].sSectorX = 5;
			gMercProfiles[ IGGY ].sSectorY = MAP_ROW_C;
		}
		#undef first_event_trigger

		gStrategicStatus.ubHighestProgress = ubCurrentProgress;

		// debug message
		SLOGD("New player progress record: %d%%", gStrategicStatus.ubHighestProgress );
	}
}