#include <cstdio>

char P[] = "CODEFESTIVAL2016";

char S[20];

int main()
{
	scanf("%s", S);
	int Ans = 0;
	for (int i = 0; i < 16; i ++)
		if (S[i] != P[i])
			Ans ++;
	printf("%d\n", Ans);
	return 0;
}