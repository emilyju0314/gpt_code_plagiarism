#include <cstdio>

#define R register
int main()
{
	R int H, W, h, w; scanf("%d%d%d%d", &H, &W, &h, &w);
	if (H % h == 0 && W % w == 0) puts("No");
	else
	{
		puts("Yes");
		for (R int i = 1; i <= H; ++i, puts(""))
			for (R int j = 1; j <= W; ++j)
				if (i % h == 0 && j % w == 0)
					printf("%d ", -1000 * (h * w - 1) - 1);
				else printf("%d ", 1000);
	}
	return 0;
}