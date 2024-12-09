void MeshLink::SetDest ( MeshLink *link )
{
	if ( dest != NULL )
	{
		//	Remove current destination
		if ( dest->asDestRoot == this )	dest->asDestRoot = destNext;
		if ( destPrev != NULL )			destPrev->destNext = destNext;
		if ( destNext != NULL )			destNext->destPrev = destPrev;
		destPrev = destNext = NULL;
		dest = NULL;
	}
	if ( link != NULL )
	{
		//	Connect new destination
		dest = link;
		destPrev = NULL;
		destNext = link->asDestRoot;
		if ( destNext != NULL )	destNext->destPrev = this;
		link->asDestRoot = this;
	}
}