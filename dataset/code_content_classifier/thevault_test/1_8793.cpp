void loop()
{
	while (link_online == 0)
	{
		Serial.println("Link offline. Reset to start over...");
		delay(1000);
	}

	if (Serial.available())
	{
		wifi_link.write(Serial.read());
	}

	if (wifi_link.available())
	{
		/**********************************************
		 * We have some data over the WiFi link. Now,
		 * let us receive the data and try to parse it.
		 * The data contains four bytes. Print each byte
		 * on the serial out for debug.
		 **********************************************/
		getDataFromLink();
		Serial.print((unsigned char) cmd_buf[0], 16);
		Serial.print(' ');
		Serial.print((unsigned char) cmd_buf[1], 16);
		Serial.print(' ');
		Serial.print((unsigned char) cmd_buf[2], 16);
		Serial.print(' ');
		Serial.println((unsigned char) cmd_buf[3], 16);

		if (cmd_buf[0] == 1)
		{
			analogWrite(RED_LED_PIN, cmd_buf[1]);
			analogWrite(GREEN_LED_PIN, cmd_buf[2]);
			analogWrite(BLUE_LED_PIN, cmd_buf[3]);
		}
	}

	if (digitalRead(8) == 0) {
		while (digitalRead(8) == 0);
		Serial.println("Sending command to remote...");
		wifi_link.print("\nAQAA+g==\n");
	}
}