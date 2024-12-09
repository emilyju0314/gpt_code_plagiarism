unsigned char YARPAndroidDeviceDriver::readADC(unsigned char chip, unsigned char board, int channel)
{
	int ch[__AndroidNChannels][__AndroidNChips] =
	{
		{1, 0, 0, 0},
		{1, 1, 0, 0},
		{1, 0, 0, 1},
		{1, 1, 0, 1},
		{1, 0, 1, 0},
		{1, 1, 1, 0},
		{1, 0, 1, 1},
		{1, 1, 1, 1}
	};

	unsigned char result = 0;

	_chipSel = chip;
	_boardSel = board;
	_enable = 0;

	_parOut(0,1);
	_parOut(1,1);
	_parOut(0,1);
	
	_parOut(0,ch[channel][0]);
	_parOut(1,ch[channel][0]);
	_parOut(0,ch[channel][0]);
	
	_parOut(0,ch[channel][1]);
	_parOut(1,ch[channel][1]);
	_parOut(1,ch[channel][1]);
	_parOut(0,ch[channel][1]);

	_parOut(0,ch[channel][2]);
	_parOut(1,ch[channel][2]);
	_parOut(1,ch[channel][2]);
	_parOut(0,ch[channel][2]);

	_parOut(0,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	_parOut(0,ch[channel][3]);

	// receive digital signal from the adc
	_parOut(1,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	
	_parOut(0,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	unsigned char out = _parOut(1,ch[channel][3]);
	result += (out << 7)&128;	// MSB

	_parOut(0,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	out = _parOut(1,ch[channel][3]);
	result += (out << 6)&64;

	_parOut(0,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	out = _parOut(1,ch[channel][3]);
	result += (out << 5)&32;

	_parOut(0,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	out = _parOut(1,ch[channel][3]);
	result += (out << 4)&16;

	_parOut(0,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	out = _parOut(1,ch[channel][3]);
	result += (out << 3)&8;

	_parOut(0,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	out = _parOut(1,ch[channel][3]);
	result += (out << 2)&4;

	_parOut(0,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	out = _parOut(1,ch[channel][3]);
	result += (out << 1)&2;

	_parOut(0,ch[channel][3]);
	_parOut(1,ch[channel][3]);
	out = _parOut(1,ch[channel][3]);
	result += (out)&1;

	_parOut(0,ch[channel][3]);

	return result;
}