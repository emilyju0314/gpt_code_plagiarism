static void ClearWrappedStrings(WRAPPED_STRING* pStringWrapperHead)
{
	WRAPPED_STRING* i = pStringWrapperHead;
	while (i != NULL)
	{
		WRAPPED_STRING* del = i;
		i = i->pNextWrappedString;
		delete del;
	}
}