void RPCWhineAboutNoPay(SOLDIERTYPE& s)
{
	// If the soldier was removed before getting into this function, return
	if (!s.bActive) return;
	if (s.ubWhatKindOfMercAmI != MERC_TYPE__NPC) return;

	TacticalCharacterDialogue(&s, QUOTE_NOT_GETTING_PAID);
}