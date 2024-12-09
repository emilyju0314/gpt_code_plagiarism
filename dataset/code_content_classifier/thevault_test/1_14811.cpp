BOOLEAN PerformDensityTest()
{
	if( Random(100) < gusSelectionDensity )
		return TRUE;
	return FALSE;
}