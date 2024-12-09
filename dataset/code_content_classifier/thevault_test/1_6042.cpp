void MeshLink::RemoveAsDest()
{
	MeshLink
		*cursor = asDestRoot;

	while ( cursor != NULL )
	{
		asDestRoot = cursor->destNext;
		cursor->destPrev = NULL;
		cursor->destNext = NULL;
		cursor->dest = NULL;
		cursor = asDestRoot;
	}
}