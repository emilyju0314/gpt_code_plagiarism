#include <iostream>
#include <cstring>
#include <cctype>	
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

// 0:TOP 1:FRONT 2:RIGHT 3:LEFT 4:BACK 5:BOTTOM
string list[24] = {
	"012345","024135","031425","043215","103254","120534",
	"135024","152304","201453","215043","240513","254103",
	"304152","310542","345012","351402","402351","425031",
	"430521","453201","513240","521430","534120","542310"
};

bool used[8];
string data[8];
char puzzle[6][8];

// eêÉÂ¢ÄobNgbN·éÛÉµª¶¶È¢æ¤mF·é×«Æ±ëB
// ôFnumberAïFface ÉÎµÄ¢éÏÈtH[}bgBIíèÍ -1B
int connect[8][8] = {
	{-1},
	{0,3,-1},		// Êu:0 ÉÊ:3 ªÚ±µÄ¢é
	{1,1,-1},		// Êu:1 ÉÊ:1 ªÚ±µÄ¢é
	{0,1,2,2,-1},	// Êu:0 ÉÊ:1 ªÚ±µAÊu:2 ÉÊ:2 ªÚ±µÄ¢é
	{0,5,-1},		// Êu:0 ÉÊ:5 ªÚ±µÄ¢é
	{1,5,4,3,-1},	// Êu:1 ÉÊ:5 ªÚ±µAÊu:4 ÉÊ:3 ªÚ±µÄ¢é
	{2,5,5,1,-1},	// Êu:2 ÉÊ:5 ªÚ±µAÊu:5 ÉÊ:1 ªÚ±µÄ¢é
	{3,5,4,1,6,2,-1}// Êu:3 ÉÊ:5 ªÚ±µAÊu:4 ÉÊ:1 ªÚ±µAÊu:6 ÉÊ:2 ªÚ±µÄ¢é
};

bool ok (char a, char b )
{
	return (tolower(a ) == tolower(b ) && a != b );
} 

bool backTrack (int cur )
{
	if (cur == 8 )
		return true;

	rep (d, 8 ){
		if (used[d] ) continue;

		used[d] = true;
		rep (i, 24 ){
			rep (j, 6 )
				puzzle[cur][j] = data[d][list[i][j]];

			bool f = true;
			for (int j = 0; connect[cur][j] != -1; j += 2 ){
				int pos = connect[cur][j];
				int face = connect[cur][j+1];
				f &= ok (puzzle[pos][5-face], puzzle[cur][face] );
			} // end for
			if (f )
				if (backTrack(cur + 1 ) )
					return true;
		} // end rep
		used[d] = false;
	} // end rep

	return false;
}
	
int main()
{
	rep (i, 24 )
		rep (j, 6 )
			list[i][j] -= '0';

	while (cin >> data[0] , data[0] != "0" ){
		for (int i = 1; i < 8; i++ )
			cin >> data[i];
		memset (used, false, sizeof (used ) );

		cout << (backTrack (0 ) ? "YES" : "NO" ) << endl;
	} // end while

		
	return 0;
}