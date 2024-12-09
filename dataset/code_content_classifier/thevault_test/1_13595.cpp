BLYNK_WRITE(V0)
{
	// Blynk.syncAll() causes an initial write.
	// Ignore it !!!
	static bool first_time = true;
	if (first_time)
	{
		first_time = false;
		return;
	}

	// If switch was "long pressed" for 3 seconds,
	// move the board to OTA mode
	if (!switch_time)
	{
		switch_time = millis();
	}
	else
	{
		uint32_t high_time = millis() - switch_time;

		if (high_time > BLYNK_LONG_PRESS_INTERVAL)
		{
			set_op_mode(MODE_OTA);
			blink_led(5);
		}

		switch_time = 0;
	}
}