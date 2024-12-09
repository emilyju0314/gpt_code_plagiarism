void reverse(int arr[], int l, int h)
{
    while (l < h)
    {
        swap(arr[l++], arr[h--]);
    }
}