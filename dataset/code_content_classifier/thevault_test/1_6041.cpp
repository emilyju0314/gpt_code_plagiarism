void MeshLink::RemoveAsSource()
{
	MeshLink
		*cursor = asSrcRoot;

	while ( cursor != NULL )
	{
		asSrcRoot = cursor->srcNext;
		cursor->srcPrev = NULL;
		cursor->srcNext = NULL;
		cursor->src = NULL;
		cursor = asSrcRoot;
	}
}