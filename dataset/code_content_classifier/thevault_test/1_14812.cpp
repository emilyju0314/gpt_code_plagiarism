void UnLoadCarPortraits(void)
{
	// car protraits loaded?
	if (!giCarPortraits[0]) return;
	for (INT32 i = 0; i != NUMBER_CAR_PORTRAITS; ++i)
	{
		DeleteVideoObject(giCarPortraits[i]);
		giCarPortraits[i] = 0;
	}
}