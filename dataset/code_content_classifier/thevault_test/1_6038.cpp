void MeshLink::SetSource ( MeshLink *link )
{
	if ( src != NULL )
	{
		//	Remove current source
		if ( src->asSrcRoot == this )	src->asSrcRoot = srcNext;
		if ( srcPrev != NULL )			srcPrev->srcNext = srcNext;
		if ( srcNext != NULL )			srcNext->srcPrev = srcPrev;
		srcPrev = srcNext = NULL;
		src = NULL;
	}
	if ( link != NULL )
	{
		//	Connect new source
		src = link;
		srcPrev = NULL;
		srcNext = link->asSrcRoot;
		if ( srcNext != NULL )	srcNext->srcPrev = this;
		link->asSrcRoot = this;
	}
}