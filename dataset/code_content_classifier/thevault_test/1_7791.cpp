struct Node * RTreeNewIndex()
{
	struct Node *x;
	x = RTreeNewNode();
	x->level = 0; /* leaf */
	return x;
}