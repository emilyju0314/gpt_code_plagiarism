void buildHeap( int arr[], int n )
{
	// Index of last non-leaf node
	int startIdx = ( n / 2 ) - 1;

	// Perform reverse level order traversal
	// from last non-leaf node and heapify
	// each node
	for ( int i = startIdx; i >= 0; i-- )
	{
		heapify( arr, n, i );
	}
}