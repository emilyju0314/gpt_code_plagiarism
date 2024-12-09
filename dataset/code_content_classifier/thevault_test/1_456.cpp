void DS1337::setTickMode(int tickMode) {
	if (tickMode==DS1337_NO_TICKS) {
		readStatus();
		bitSet(_register[DS1337_CONTROL], DS1337_INTCN);
		bitClear(_register[DS1337_CONTROL], DS1337_A2IE);
		bitClear(_register[DS1337_STATUS], DS1337_A2F);
		writeStatus();
		_tickMode = tickMode;
	}
	else if (tickMode==DS1337_TICK_EVERY_SECOND) {
		readStatus();
		bitClear(_register[DS1337_CONTROL], DS1337_INTCN);
		bitClear(_register[DS1337_CONTROL], DS1337_A2IE);
		bitClear(_register[DS1337_CONTROL], DS1337_RS1);
		bitClear(_register[DS1337_CONTROL], DS1337_RS2);
		bitClear(_register[DS1337_STATUS], DS1337_A2F);
		writeStatus();
		_tickMode = tickMode;
	}
	else if (tickMode==DS1337_TICK_EVERY_MINUTE) {
		readStatus();
		readAlarm2();
		bitSet(_register[DS1337_CONTROL], DS1337_INTCN);
		bitSet(_register[DS1337_CONTROL], DS1337_A2IE);
		bitClear(_register[DS1337_STATUS], DS1337_A2F);
		bitSet(_register[DS1337_A2_MINUTES], DS1337_A2M2);
		bitSet(_register[DS1337_A2_HOUR], DS1337_A2M3);
		bitSet(_register[DS1337_A2_DAY], DS1337_A2M4);
		writeAlarm2();
		writeStatus();
		_tickMode = tickMode;
	}
	else if (tickMode==DS1337_TICK_EVERY_HOUR) {
		readStatus();
		readAlarm2();
		bitSet(_register[DS1337_CONTROL], DS1337_INTCN);
		bitSet(_register[DS1337_CONTROL], DS1337_A2IE);
		bitClear(_register[DS1337_STATUS], DS1337_A2F);
		//bitClear(_register[DS1337_A2_MINUTES], DS1337_A2M2);
		_register[DS1337_A2_MINUTES] = 0;
		bitSet(_register[DS1337_A2_HOUR], DS1337_A2M3);
		bitSet(_register[DS1337_A2_DAY], DS1337_A2M4);
		writeAlarm2();
		writeStatus();
		_tickMode = tickMode;
	}
}