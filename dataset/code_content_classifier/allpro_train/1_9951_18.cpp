#include <iostream>
using namespace std;

int memo[8193][20];
int rm[20],N;

int solve(int S, int turn)
{
	if(memo[S][turn]!=-1) return memo[S][turn];

	if(turn%2==0) {
		bool ok = false;
		for(int i=1; i<=rm[turn]; i++) {
			int remain = S-i;
			if(remain <= 0) continue;

			if(solve(remain, (turn+1)%N)==1) ok = true;
		}

		if(ok) memo[S][turn] = 1; else memo[S][turn] = 0;
	}
	else {
		bool ok = true;
		for(int i=1; i<=rm[turn]; i++) {
			int remain = S-i;
			if(remain <= 0) continue;

			if(solve(remain, (turn+1)%N)==0) ok = false;
		}

		if(ok) memo[S][turn] = 1; else memo[S][turn] = 0;
	}

	return memo[S][turn];
}

int main()
{
	int S;
	while(cin >> N, N) {
		cin >> S;
		N *= 2;

		for(int i=0; i<=S; i++)
		for(int j=0; j<N; j++)
			memo[i][j] = -1;


		for(int i=0; i<N; i++)
			cin >> rm[i];

		cout << solve(S, 0) << endl;
	}
}