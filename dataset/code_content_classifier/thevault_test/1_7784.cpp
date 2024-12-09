struct Node * RTreeNewNode()
{
	register struct Node *n;

	//n = new Node;
	n = (struct Node*)malloc(sizeof(struct Node));
	assert(n);
	RTreeInitNode(n);
	return n;
}