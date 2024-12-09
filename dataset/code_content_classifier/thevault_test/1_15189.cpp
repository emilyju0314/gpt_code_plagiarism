void Node::removeChildren()
{
	for (int i = 0; i < children.size(); ++i)
	{
		children[i]->parent = NULL;
		delete children[i];
	}
	children.clear();
}