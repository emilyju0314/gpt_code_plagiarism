#include <cstdio>
inline void work(int n, int d, int arr[][605])
{
	int blk = 1; 
	while (!(d & 3))
	{
		d >>= 2; 
		blk <<= 1; 
	}
	if (d & 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				arr[i][j] = (i / blk & 1) ^ (j / blk & 1);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				arr[i][j] = i / blk & 1;
		}
	}
}
int arr1[605][605], arr2[605][605], app[5]; 
int main()
{
	// freopen("AGC025-D.in", "r", stdin); 
	int n, d1, d2; 
	scanf("%d%d%d", &n, &d1, &d2);
	work(n << 1, d1, arr1); 
	work(n << 1, d2, arr2); 
	for (int i = 0; i < n << 1; i++)
	{
		for (int j = 0; j < n << 1; j++)
			app[arr1[i][j] << 1 | arr2[i][j]]++; 
	}
	for (int i = 0; i < 4; i++)
	{
		if (app[i] < n * n)
			continue;
		int cnt = n * n; 
		for (int x = 0; x < n << 1; x++)
		{
			for (int y = 0; y < n << 1; y++)
			{
				if ((arr1[x][y] << 1 | arr2[x][y]) == i && cnt)
				{
					printf("%d %d\n", x, y);
					cnt--;
				}
			}
		}
		break; 
	}
	return 0; 
}
