FOR_EACH(ExplosionQueueElement const, i, gExplosionQueue)
	{
		ExplosionQueueElement const& e = *i;
		BYTE  data[12];
		DataWriter d{data};
		INJ_U32( d, e.uiWorldBombIndex)
		INJ_U32( d, e.uiTimeStamp)
		INJ_U8(  d, e.fExists)
		INJ_SKIP(d, 3)
		Assert(d.getConsumed() == lengthof(data));
		hFile->write(data, sizeof(data));
	}