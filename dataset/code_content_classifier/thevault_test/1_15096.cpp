FOR_EACH(ExplosionQueueElement, i, gExplosionQueue)
	{
		BYTE  data[12];
		hFile->read(data, sizeof(data));
		DataReader d{data};
		ExplosionQueueElement& e = *i;
		EXTR_U32( d, e.uiWorldBombIndex)
		EXTR_U32( d, e.uiTimeStamp)
		EXTR_U8(  d, e.fExists)
		EXTR_SKIP(d, 3)
		Assert(d.getConsumed() == lengthof(data));
	}