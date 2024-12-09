int minimumAdjacentDifference(int a[], int n, int k)
{

	int diff[n - 1];
	for (int i = 0; i < n - 1; i++) {
		diff[i] = a[i + 1] - a[i];
	}

	int answer = findKMin(diff, n - 1, n - k - 1);
	return answer;
}