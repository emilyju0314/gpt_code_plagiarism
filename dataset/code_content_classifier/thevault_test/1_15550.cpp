void dualPivotQuickSort(int a[], int left, int right, int div)
{
    int len = right - left;

    if (len < LIS_THRESHOLD)
    { // insertion sort for small arrays
        for (int i = left + 1; i <= right; i++)
            for (int j = i; j > left && a[j] < a[j - 1]; j--)
                swap(a, j, j - 1);
        return;
    }
    int third = len / div;

    // "medians"
    int m1 = left + third;
    int m2 = right - third;

    if (m1 <= left)
        m1 = left + 1;
    if (m2 >= right)
        m2 = right - 1;
    if (a[m1] < a[m2])
    {
        swap(a, m1, left);
        swap(a, m2, right);
    }
    else
    {
        swap(a, m1, right);
        swap(a, m2, left);
    }

    // pivots
    int pivot1 = a[left];
    int pivot2 = a[right];

    // pointers
    int less = left + 1;
    int great = right - 1;

    // sorting
    for (int k = less; k <= great; k++)
    {
        if (a[k] < pivot1)
            swap(a, k, less++);
        else if (a[k] > pivot2)
        {
            while (k < great && a[great] > pivot2)
                great--;

            swap(a, k, great--);

            if (a[k] < pivot1)
                swap(a, k, less++);
        }
    }
    // swaps
    int dist = great - less;

    if (dist < 13)
        div++;
    swap(a, less - 1, left);
    swap(a, great + 1, right);

    // subarrays
    dualPivotQuickSort(a, left, less - 2, div);
    dualPivotQuickSort(a, great + 2, right, div);

    // equal elements
    if (dist > len - 13 && pivot1 != pivot2)
    {
        for (int k = less; k <= great; k++)
        {
            if (a[k] == pivot1)
                swap(a, k, less++);
            else if (a[k] == pivot2)
            {
                swap(a, k, great--);

                if (a[k] == pivot1)
                    swap(a, k, less++);
            }
        }
    }
    // subarray
    if (pivot1 < pivot2)
        dualPivotQuickSort(a, less, great, div);
}