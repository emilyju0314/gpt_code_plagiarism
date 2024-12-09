int binary_search(vector<int> arr, int key)
{
    int s = 0 , e = arr.size() - 1 ;
    while (s <= e)
    {
        int mid = (s+e)/2 ;
        if (arr[mid] == key) return mid ;

        if (arr[mid] < key) s = mid + 1 ;
        else e = mid - 1 ;
    }
    return -1 ;
}