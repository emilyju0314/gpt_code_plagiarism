#include <cstdio>
#include <cstring>
using namespace std;

typedef long long STATES;

int main( void )
{
	STATES free_days[31], dp[51], goal_state, next;
	STATES* p;
	int i, j, n, free_day, k;
	short answer;

	while ( scanf( "%d", &n ) == 1 && n )
	{
		memset( free_days, 0, sizeof(free_days) );
		memset( dp, 0, sizeof(dp) );

		goal_state = 0;
		for ( i = 0; i < n; i++ ) goal_state |= 1LL << i;

		for ( i = 0; i < n; i++ )
		{
			scanf( "%d", &k );
			for ( j = 0; j < k; j++ )
			{
				scanf( "%d", &free_day );
				free_days[free_day] |= 1LL << i;
			}
		}

		answer = -1;
		for ( i = 0; i < n; i++ ) dp[i] = 1LL << i;
		p = free_days + 1;
		for ( i = 1; i <= 30; i++, p++ )
		{
			next = 0;
			for ( j = 0; j < n; j++ ) if ( *p & 1LL << j ) next |= dp[j];
			if ( next == goal_state )
			{
				answer = i;
				break;
			}
			for ( j = 0; j < n; j++ ) if ( *p & 1LL << j ) dp[j] |= next;
		}

		printf( "%d\n", answer );
	}

	return 0;
}