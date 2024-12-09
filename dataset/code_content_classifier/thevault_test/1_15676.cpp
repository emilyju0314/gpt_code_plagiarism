double InputCapture_TIM::operator[](u8 chNum)
{
	if(chNum==1)
		return _ch1Cnt*_resolution;
	else if(chNum==2)
		return _ch2Cnt*_resolution;
  else if(chNum==3)
		return _ch3Cnt*_resolution;	
	else if(chNum==4)
		return _ch4Cnt*_resolution;
	else
		return 0;
}