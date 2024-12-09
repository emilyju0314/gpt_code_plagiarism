#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<algorithm>
#include<functional>

#define NIL (-1)
#define MAX 22
#define MAX_PIECES 10
#define BURIED true
#define NONE false
#define PZL true

#define FORUP(var,from,to) for(int var=from;var<=to;++var)
#define FORDOWN(var,from,to) for(int var=from;var>=to;--var)

using namespace std;

class CPiece{
public:
	class piece{
	public:
		int si, sj;
		int H, W;
		bool m[MAX][MAX];
		piece(){ FORUP(i,0,MAX-1)FORUP(j,0,MAX-1)m[i][j]=NONE; }
		void Print() const{
			FORUP(i,1,H){
				FORUP(j,1,W)cout << (m[i][j]==PZL?'#':'.');cout << '\n';
			}
		}
		void DetermineSiSj(){
			FORUP(i,1,H)FORUP(j,1,W)
				if(m[i][j]==PZL){si=i-1;sj=j-1;return ;} 
		}
		bool operator==(const CPiece::piece &t) const {
			if(H==t.H&&W==t.W){
				FORUP(i,1,H)FORUP(j,1,W) if(m[i][j]!=t.m[i][j])
					return false;
				return true;
			}else
				return false;
		}
	};
	vector<piece> rots;
	void CreateRotations(){
		rots[0].DetermineSiSj();
		FORUP(i,1,3){
			bool bExist = false;
			piece next;

			TurnRight90( rots[rots.size()-1], next );
			next.H = rots[rots.size()-1].W;
			next.W = rots[rots.size()-1].H;
			next.DetermineSiSj();

			if( rots.end() == find( rots.begin(), rots.end(), next ) )
				rots.push_back( next );
		}
	}
	int CountPuzzleCells() const {
		int ret = 0;
		FORUP(i,1,rots[0].H)FORUP(j,1,rots[0].W)
			if( rots[0].m[i][j] == PZL )++ret;
		return ret;
	}
	bool operator>(const CPiece &t) const {
		int area=this->rots[0].H * this->rots[0].W;
		int area_t=t.rots[0].H     * t.rots[0].W;
		if(area== area_t)return this->CountPuzzleCells()>t.CountPuzzleCells();
		else return area>area_t;
	}
private:
	void TurnRight90( piece &from, piece &t ){
		FORUP(i,1,from.H)FORUP(j,1,from.W)
			t.m[j][from.H-i+1] = from.m[i][j];
	}
};

class CPieces{
public:
	vector< CPiece > vPieces;
	bitset< MAX_PIECES > bUse;
	bitset< MAX_PIECES > bUsed;
};

class CPuzzle{
public:
	int H, W;
	bool m[MAX][MAX];
	bool chk[MAX][MAX];

	bool inRangeHeight(int i){ return 1 <= i && i <= H; }
	bool inRangeWidth(int j){ return 1 <= j && j <= W; }
	void Initialize()
	{
		FORUP(i,0,MAX-1)FORUP(j,0,MAX-1){
			m[ i ][ j ] = BURIED;
			chk[MAX][MAX] = 0;
		}
	}
	bool CheckAndPutPiece( int i, int j, unsigned int choose, int rot, CPieces &ps )
	{
		bool tmpm[MAX][MAX];
		bool bOk = true;
		CPiece::piece &pce = ps.vPieces[choose].rots[rot];

		FORUP(ci,0,MAX-1)FORUP(cj,0,MAX-1)
			tmpm[ci][cj]=m[ci][cj];

		PutPiece( i, j, pce );

		FORUP(ci,1,H)FORUP(cj,1,W)
			if( m[ci][cj] == NONE )
				for(unsigned int k = 0; k < ps.vPieces.size(); ++k)
					if( k != choose && ps.bUse[k] && !ps.bUsed[k] ){
						vector<CPiece::piece> &vpce = ps.vPieces[k].rots;
						for(unsigned int l = 0; l < vpce.size(); ++l)
							if( TryPutPiece( ci - vpce[l].si, cj - vpce[l].sj, vpce[l] ) )
								CheckPiece( ci - vpce[l].si, cj - vpce[l].sj, vpce[l] );
					}
		
		FORUP(ci,1,H)FORUP(cj,1,W)
			if( m[ci][cj] == NONE && chk[ci][cj] == 0 ){
				ci=H+1;
				cj=W+1;
				bOk=false;
			}

		if( !bOk )
			FORUP(ci,0,MAX-1)FORUP(cj,0,MAX-1)
				m[ci][cj] = tmpm[ci][cj];
		
		return bOk;
	}
	void ResetChk()
	{
		FORUP(i,0,MAX-1)FORUP(j,0,MAX-1)
			chk[i][j] = 0;
	}
	bool TryPutPiece( int i, int j, CPiece::piece &p )
	{
		CPiece::piece &pce = p;

		if( !inRangeHeight(i)||!inRangeWidth(j)||!inRangeHeight(i+pce.H-1)||!inRangeWidth(j+pce.W-1) )
			return false;

		FORUP(ci,i,i+pce.H-1)FORUP(cj,j,j+pce.W-1)
			if( m[ci][cj] == BURIED && pce.m[ci-i+1][cj-j+1] == PZL )
				return false;
		return true;
	}
	bool Complete()
	{
		FORUP(i,1,H)FORUP(j,1,W)
			if( m[i][j] == NONE )
				return false;
		return true;
	}
	int CountEmptyCells()
	{
		int ret = 0;
		FORUP(i,1,H)FORUP(j,1,W)
			if( m[i][j] == NONE )
				++ret;
		return ret;
	}
private:
	void CheckPiece( int i, int j, CPiece::piece &p)
	{
		CPiece::piece &pce = p;

		if(!inRangeHeight(i)||!inRangeWidth(j)||!inRangeHeight(i+pce.H-1)||!inRangeWidth(j+pce.W-1))
			return ;

		FORUP(ci,i,i+pce.H-1)FORUP(cj,j,j+pce.W-1)
			if( m[ci][cj] == NONE && pce.m[ci-i+1][cj-j+1] == PZL )
				chk[ci][cj] = 1;
	}
	void PutPiece( int i, int j, CPiece::piece &p )
	{
		CPiece::piece &pce = p;

		FORUP(ci,i,i+pce.H-1)FORUP(cj,j,j+pce.W-1)
			if( m[ci][cj] == NONE && pce.m[ci-i+1][cj-j+1] == PZL )
				m[ci][cj] = BURIED;
	}
};


bool DFS( CPuzzle &p, CPieces &ps, bool &bAbort ){
	int choose = NIL;

	for(unsigned int i = 0; i < ps.vPieces.size(); ++i)
		if( ps.bUse[i] && !ps.bUsed[i] )
		{
			choose = i;
			break;
		}

	if( choose == NIL )
		if( p.Complete() ) return true;
		else return false;
	else if( p.Complete() )
	{
		bAbort = true;
		return true;
	}

	for(unsigned int k = 0; k < ps.vPieces[choose].rots.size(); ++k)
	{
		CPiece::piece &pce = ps.vPieces[choose].rots[k];
		FORUP(i,1,p.H-pce.H+1)FORUP(j,1,p.W/*-pce.W+1*/)
			if( p.m[i][j] == NONE )
				if( p.TryPutPiece( i - pce.si, j - pce.sj, pce ) )
				{
					CPuzzle pzl_tmp = p;
					bool bResult;

					pzl_tmp.ResetChk();
					if( pzl_tmp.CheckAndPutPiece( i - pce.si, j - pce.sj, choose, k, ps ) )
					{
						ps.bUsed.set( choose );
						bResult = DFS( pzl_tmp, ps, bAbort );
						if( bResult )
							return true;
						ps.bUsed.reset( choose );
					}
				}
	}
	return false;
}
int main()
{
	while( true )
	{
		int n;
		int p;
		CPuzzle pzl;
		CPieces ps;

		pzl.Initialize();

		cin >> pzl.H >> pzl.W;

		if( pzl.H == 0 && pzl.W == 0 )
			break;

		FORUP(i,1,pzl.H)
		{
			string s; cin >> s;
			FORUP(j,1,pzl.W)
				if( s[j - 1] == '#' ) pzl.m[ i ][ j ] = BURIED;
				else pzl.m[ i ][ j ] = NONE;
		}

		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			CPiece tmp;
			CPiece::piece t;
			
			cin >> t.H >> t.W;
			FORUP(j,1,t.H){
				string s; cin >> s;
				FORUP(k,1,t.W)
					if( s[k - 1] == '#' ) t.m[ j ][ k ] = PZL;
					else t.m[ j ][ k ] = NONE;
			}
			tmp.rots.push_back( t );
			tmp.CreateRotations();
			ps.vPieces.push_back( tmp );
		}

		cin >> p;
		for(int i = 0; i < p; ++i)
		{
			int k;
			bool bAbort = false;
			int cntPzl = 0;
			int cntPss = 0;
			CPuzzle pzl_tmp = pzl;
			CPieces ps_tmp;

			ps_tmp.bUse.reset();
			ps_tmp.bUsed.reset();

			cin >> k;
			for( int j = 0; j < k; ++j )
			{
				int t;
				cin >> t;
				ps_tmp.vPieces.push_back( ps.vPieces[t-1] );
				cntPss += ps.vPieces[t-1].CountPuzzleCells();
				ps_tmp.bUse.set( j );
			}
			cntPzl = pzl_tmp.CountEmptyCells();

			if( cntPzl != cntPss )
			{
				cout << "NO\n";
				continue;
			}

			/* ツパツズツδ仰づ個妥・ツつォツつ「ツ渉づ可青ョツ療ア */
			sort( ps_tmp.vPieces.begin(), ps_tmp.vPieces.end(), greater<CPiece>() );

			if( DFS( pzl_tmp, ps_tmp, bAbort ) )
				cout << (bAbort ? "NO\n" : "YES\n");
			else
				cout << "NO\n";
		}
	}
	return 0;
}