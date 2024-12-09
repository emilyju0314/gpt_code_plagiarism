#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;

#define N 10

class CMap{
public:
	int m[N+2][N+2];
	int ans[N+2][N+2];

	CMap(){ Reset(); ResetAnswer(); }
	
	void Reset(){
		for(int i = 0; i < N+2; ++i){
			for(int j = 0; j < N+2; ++j){
				m[i][j] = 0;
			}
		}
	}
	void ResetAnswer(){
		for(int i = 0; i < N+2; ++i){
			for(int j = 0; j < N+2; ++j){
				ans[i][j] = 0;
			}
		}
	}
	bool inline static inRange(int t){
		return ( 1 <= t && t < N + 1 );
	}

	bool PassParticle(int i, int j, bool bConsiderEfficiency = false)
	{
		int cnt0 = 0;
		int cnt1 = 0;
		const int di[] = {0,-1,0,1,0};
		const int dj[] = {0,0,1,0,-1};

		if( bConsiderEfficiency ){
			for(int k = 0; k < sizeof(di)/sizeof(*di); ++k)
				if( inRange( i+di[k] ) && inRange( j+dj[k] ) )
					if( m[i+di[k]][j+dj[k]] == 1 ) cnt1++; else cnt0++;
		}

		if( cnt1 < cnt0 )
			return false;

		for(int k = 0; k < sizeof(di)/sizeof(*di); ++k)
			if( inRange( i+di[k]) && inRange( j+dj[k]) )
				m[i+di[k]][j+dj[k]] ^= 1;

		ans[ i ][ j ] = 1;
		return true;
	}
	bool NoLight() const
	{
		for(int i = 1; i < N+1; ++i)
			for(int j = 1; j < N+1; ++j)
				if( m[i][j] == 1 ) return false;
		return true;
	}
	void Print()const{
		for(int i = 1; i < N+1; ++i){
			cout << m[i][1];
			for(int j = 2; j < N+1; ++j)
				cout << ' ' << m[i][j];
			cout << '\n';
		}
	}
	void PrintAnswer() const{
		for(int i = 1; i < N+1; ++i){
			cout << ans[i][1];
			for(int j = 2; j < N+1; ++j)
				cout << ' ' << ans[i][j];
			cout << '\n';
		}
	}
};

bool DetermineShootingPoints(CMap &M){
	for(unsigned int i = 2; i < N+1; ++i){
		for(unsigned int j = 1; j < N+1; ++j){
			if( M.m[i-1][j] == 1 ){
				M.PassParticle( i, j );
			}
		}
	}
	if( M.NoLight() )
		return true;
	else
		return false;
}

int main(void){
	int n;

	cin >> n;
	for( int D = 0; D < n; ++D )
	{
		bool bCont = true;
		CMap M;
		bitset<N> B;

		for(int i = 1; i < N+1; ++i)
			for(int j = 1; j < N+1; ++j)
				cin >> M.m[i][j];

		for(unsigned long L = 0; L < (unsigned long)pow(2.0,(double)N) && bCont; ++L){
			B = L;
			//cout << L << ": " << B.to_string() << endl;
			CMap Tmp = M;
			for(unsigned int bits = 0; bits < B.size() && bCont; ++bits){
				if( B[bits] )
					M.PassParticle(1,N-bits);//break;
			}
			if( DetermineShootingPoints( M ) ){
				bCont = false;
				break;
			}
			M = Tmp;
		}
		//cout << "END.\n";
		//cout << "CURRENT MAP:\n";
		//M.Print();
		//cout << "ANSWER:\n";
		M.PrintAnswer();
	}
	return 0;
}