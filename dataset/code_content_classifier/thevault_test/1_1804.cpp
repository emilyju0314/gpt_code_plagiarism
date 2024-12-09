void Backend::ReHeap(Node* arr[],int i){
  int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < currentSize && arr[l]->value > arr[largest]->value)
        largest = l;

    // If right child is larger than largest so far
    if (r < currentSize && arr[r]->value > arr[largest]->value)
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        ReHeap(arr,largest);
    }
}