bool Link::detachChild(Link* childToRemove)
{
	bool removed = false;

	Link* link = child;
	Link* prevSibling = 0;
	while(link){
		if(link == childToRemove){
			removed = true;
			if(prevSibling){
				prevSibling->sibling = link->sibling;
			} else {
				child = link->sibling;
			}
			break;
		}
		prevSibling = link;
		link = link->sibling;
	}

	if(removed){
		childToRemove->parent = 0;
		childToRemove->sibling = 0;
		setBodyIter(childToRemove, 0);
	}

	return removed;
}