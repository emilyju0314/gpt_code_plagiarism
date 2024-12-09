static INT32 GetCurrentAttributeValue(INT32 attribute)
{
	INT32 val = 0;
	switch (attribute)
	{
		case HEALTH_ATTRIBUTE:     val = iCurrentHealth;      break;
		case DEXTERITY_ATTRIBUTE:  val = iCurrentDexterity;   break;
		case AGILITY_ATTRIBUTE:    val = iCurrentAgility;     break;
		case STRENGTH_ATTRIBUTE:   val = iCurrentStrength;    break;
		case WISDOM_ATTRIBUTE:     val = iCurrentWisdom;      break;
		case LEADERSHIP_ATTRIBUTE: val = iCurrentLeaderShip;  break;
		case MARKSMANSHIP_SKILL:   val = iCurrentMarkmanship; break;
		case EXPLOSIVE_SKILL:      val = iCurrentExplosives;  break;
		case MEDICAL_SKILL:        val = iCurrentMedical;     break;
		case MECHANICAL_SKILL:     val = iCurrentMechanical;  break;
	}
	return val;
}