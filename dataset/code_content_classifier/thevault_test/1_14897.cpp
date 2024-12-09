static void SaveEnemyGroupStruct(HWFILE const f, GROUP const& g)
{
	BYTE              data[29];
	DataWriter d{data};
	ENEMYGROUP const& eg = *g.pEnemyGroup;
	INJ_U8(  d, eg.ubNumTroops)
	INJ_U8(  d, eg.ubNumElites)
	INJ_U8(  d, eg.ubNumAdmins)
	INJ_SKIP(d, 1)
	INJ_U8(  d, eg.ubPendingReinforcements)
	INJ_U8(  d, eg.ubAdminsInBattle)
	INJ_U8(  d, eg.ubIntention)
	INJ_U8(  d, eg.ubTroopsInBattle)
	INJ_U8(  d, eg.ubElitesInBattle)
	INJ_SKIP(d, 20)
	Assert(d.getConsumed() == lengthof(data));

	f->write(data, sizeof(data));
}