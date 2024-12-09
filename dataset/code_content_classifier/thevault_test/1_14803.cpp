static void ClearUndoMapIndexTree(void)
{
	if( top )
		DeleteTreeNode( &top );
}