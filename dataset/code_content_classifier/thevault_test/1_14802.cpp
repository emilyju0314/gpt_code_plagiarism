static void DeleteTreeNode(MapIndexBinaryTree** node)
{
	if( (*node)->left )
		DeleteTreeNode( &((*node)->left) );
	if( (*node)->right )
		DeleteTreeNode( &((*node)->right) );
	delete *node;
	*node = NULL;
}