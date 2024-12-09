#include <bits/stdc++.h>
#define Max 300005

using namespace std;

int n, q;
int A[ Max ], Aux;

void Update(int Target)
{

	for(int i = 1; i <= 50; i++)
	{

		if(A[ i ] != - 1 and A[ i ] < A[ Target ] and i != Target)
			A[ i ] ++;

	}

	A[ Target ] = 1;

}

int IndexOf(int Target)
{


	int Ans = A[ Target ];
	
	Update( Target );

	return Ans;

}

int main()
{

	scanf("%d %d", &n, &q);

	memset( A, -1, sizeof A );

	for(int i = 1; i <= n; i++)
	{

		scanf("%d", &Aux);

		if(A[ Aux ] == -1)
			A[ Aux ] = i;
		
	}

	for(int i = 1; i <= q; i++)
	{
	
		scanf("%d", &Aux);

		if( i != q )
			printf("%d ", IndexOf( Aux ) );
		else
			printf("%d\n", IndexOf( Aux ) );

	}

	return 0;

}