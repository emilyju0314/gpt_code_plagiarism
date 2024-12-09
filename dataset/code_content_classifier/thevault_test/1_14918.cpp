void EnvironmentController( BOOLEAN fCheckForLights )
{
	UINT32 uiOldWorldHour;
	UINT8  ubLightAdjustFromWeather = 0;


	// do none of this stuff in the basement or caves
	if( gfBasement || gfCaves )
	{
		guiEnvWeather	&= (~WEATHER_FORECAST_THUNDERSHOWERS );
		guiEnvWeather	&= (~WEATHER_FORECAST_SHOWERS );

		if ( guiRainLoop != NO_SAMPLE )
		{
			SoundStop( guiRainLoop );
			guiRainLoop = NO_SAMPLE;
		}
		return;
	}

	if(fTimeOfDayControls )
	{
		uiOldWorldHour = GetWorldHour();

		// If hour is different
		if ( uiOldWorldHour != guiEnvTime )
		{
			// Hour change....

			guiEnvTime=uiOldWorldHour;
		}

		//ExecuteStrategicEventsUntilTimeStamp( (UINT16)GetWorldTotalMin( ) );

		// Polled weather stuff...
		// ONly do indooors
		if( !gfBasement && !gfCaves )
		{
#if 0
			if ( guiEnvWeather & ( WEATHER_FORECAST_THUNDERSHOWERS | WEATHER_FORECAST_SHOWERS ) )
			{
				if ( guiRainLoop == NO_SAMPLE )
				{
					guiRainLoop	= PlayJA2Ambient( RAIN_1, MIDVOLUME, 0 );
				}

				// Do lightning if we want...
				if ( guiEnvWeather & ( WEATHER_FORECAST_THUNDERSHOWERS ) )
				{
					EnvDoLightning( );
				}

			}
			else
			{
				if ( guiRainLoop != NO_SAMPLE )
				{
					SoundStop( guiRainLoop );
					guiRainLoop = NO_SAMPLE;
				}
			}
#endif
		}

		if ( gfDoLighting && fCheckForLights )
		{
			// Adjust light level based on weather...
			ubLightAdjustFromWeather = GetTimeOfDayAmbientLightLevel();

			// ONly do indooors
			if( !gfBasement && !gfCaves )
			{
				// Rain storms....
#if 0
				if ( guiEnvWeather & ( WEATHER_FORECAST_THUNDERSHOWERS | WEATHER_FORECAST_SHOWERS ) )
				{
					// Thunder showers.. make darker
					if ( guiEnvWeather & ( WEATHER_FORECAST_THUNDERSHOWERS ) )
					{
						ubLightAdjustFromWeather = (UINT8)(__min( gubEnvLightValue+2, NORMAL_LIGHTLEVEL_NIGHT ));
					}
					else
					{
						ubLightAdjustFromWeather = (UINT8)(__min( gubEnvLightValue+1, NORMAL_LIGHTLEVEL_NIGHT ));
					}
				}
#endif
			}


			LightSetBaseLevel( ubLightAdjustFromWeather );

			//Update Merc Lights since the above function modifies it.
			HandlePlayerTogglingLightEffects( FALSE );

			// Make teams look for all
			// AllTeamsLookForAll( FALSE );

			// Set global light value
			SetRenderFlags(RENDER_FLAG_FULL);
			gfDoLighting = FALSE;
		}

	}

}