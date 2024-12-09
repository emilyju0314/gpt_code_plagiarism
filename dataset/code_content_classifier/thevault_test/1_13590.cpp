bool isCharPseudoFree(ucs32 inChar)
{
	bool isFree = (inChar == ucBoxSinglHorz) || (inChar == ucBoxDblHorz);
	return isFree;
}