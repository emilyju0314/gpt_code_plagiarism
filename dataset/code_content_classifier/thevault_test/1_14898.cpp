static void LoadEnemyGroupStructFromSavedGame(HWFILE const f, GROUP& g)
{
	BYTE data[29];
	f->read(data, sizeof(data));

	ENEMYGROUP* const eg = new ENEMYGROUP{};
	DataReader d{data};
	EXTR_U8(  d, eg->ubNumTroops)
	EXTR_U8(  d, eg->ubNumElites)
	EXTR_U8(  d, eg->ubNumAdmins)
	EXTR_SKIP(d, 1)
	EXTR_U8(  d, eg->ubPendingReinforcements)
	EXTR_U8(  d, eg->ubAdminsInBattle)
	EXTR_U8(  d, eg->ubIntention)
	EXTR_U8(  d, eg->ubTroopsInBattle)
	EXTR_U8(  d, eg->ubElitesInBattle)
	EXTR_SKIP(d, 20)
	Assert(d.getConsumed() == lengthof(data));

	g.pEnemyGroup = eg;
}