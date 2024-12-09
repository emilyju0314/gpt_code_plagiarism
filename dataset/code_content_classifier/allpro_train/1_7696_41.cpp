#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <complex>
#include <fstream>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T> T RoundOff(T a){ return int(a+.5-(a<0)); }
template<class T, class C> void chmax(T& a, C b){ if(a < b) a = b; }
template<class T, class C> void chmin(T& a, C b){ if(b < a) a = b; }
template<class T, class C> pair<T, C> mp(T a, C b){ return make_pair(a, b); }

void convert(string& text, int& cursor, string& buffer, char command);

int main()
{
	string text, buffer;
	int cursor = 0;
	
	for(string line; getline(cin, line) && line != "END_OF_TEXT"; text += line + '\n');
	for(char command; cin >> command && command != '-'; convert(text, cursor, buffer, command));
	
	cout << text;
}

void convert(string& text, int& cursor, string& buffer, char command)
{
	switch(command)
	{
			/*
			 a
			 J[\ð»ÝÌsÌæª¶ÉÚ®·éB
			 */
		case 'a':
		{
			int pos = 0 < cursor ? text.rfind("\n", cursor - 1) : string::npos;
			cursor = (pos == string::npos ? 0 : pos + 1);
						
			break;
		}
			/*
			 e
			 J[\ð»ÝÌsÌsÉÚ®·éB
			 */
		case 'e':
		{
			cursor = text.find("\n", cursor);
			
			break;
		}
			/*
			 p
			 ãÉsª êÎAJ[\ðãÌsÌæª¶ÉÚ®·éB
			 ãÉsªÈ¯êÎAJ[\ðæª¶ÉÚ®·éB
			 */
		case 'p':
		{
			
			if(cursor != 0) while(--cursor) if(text[cursor] == '\n')
			{
				break;
			}

			if(cursor != 0) while(--cursor) if(text[cursor] == '\n')
			{
				cursor++;
				break;
			}
			
			

			break;
		}
			/*
			 n
			 ºÉsª êÎAJ[\ðºÌsÌæª¶ÉÚ®·éB
			 ºÉsªÈ¯êÎAJ[\ðæª¶ÉÚ®·éB
			 */
		case 'n':
		{
			int cur = cursor;
			while(text[cur] != '\n') cur++;
			
			if(cur + 1 == text.size())
			{
				if(cursor != 0) while(--cursor) if(text[cursor] == '\n')
				{
					cursor++;
					break;
				}
			}
			else
			{
				cursor = cur + 1;
			}
			
			break;
		}
			/*
			 f
			 J[\ªsÉÈ¢êAJ[\ðPÂEÉÚ®·éB
			 J[\ªsÉ è©ÂºÉsª éêÍAJ[\ðºÌsÌæª¶ÖÚ®·éB
			 »êÈOÌêÍ½àµÈ¢B
			 */
		case 'f':
		{
			cursor += cursor + 1 != text.size();
			
			break;
		}
			/*
			 b
			 J[\ªæª¶ÅÈ¢ÈçÎAJ[\ðPÂ¶ÉÚ®·éB
			 J[\ªæª¶Å è©ÂãÉsª éêÍAJ[\ðãÌsÌsÖÚ®·éB
			 »êÈOÌêÍ½àµÈ¢
			 */
		case 'b':
		{
			cursor -= 0 < cursor;
			
			break;
		}
			/*
			 d
			 J[\ª¶ðw·êÍ»Ì¶ðí·éBí³ê½¶ÌE¤Ì¶ñÍ¶ÉVtg³êéB
			 J[\ªsðwµºÉsª éêÍAºÌsð»ÌÜÜJ[\ÌÊuÉq°éBÈºÌsÍãÉVtg³êéB
			 »êÈOÌêÍ½àµÈ¢B
			 */
		case 'd':
		{
			if(cursor + 1 != text.size()) text.erase(text.begin() + cursor);
			break;
		}
			/*
			 k
			 J[\ªsÉ éêAºÉsª êÎAd Æ¯¶ìðµobt@ÉPÂÌüsðL^·éB
			 J[\ªsÉÈ¢êAJ[\ªw·¶ðÜß½E¤·×ÄÌ¶ðØèæè»êðobt@ÉL^·éBJ[\Í³ÌsÌsðw·æ¤ÉÈéBSÄÌL^É¨¢Äobt@Íã«³êéB
			 »êÈOÌêÍ½àµÈ¢B
			 */
		case 'k':
		{
			buffer = "";
			if(text[cursor] == '\n')
			{
				if(cursor + 1 == text.size())
					break;
				
				buffer = "\n";
				text.erase(text.begin() + cursor);
			}
			else while(text[cursor] != '\n')
			{
				buffer += text[cursor];
				text.erase(text.begin() + cursor);
			}
			
			break;
		}
			/*
			 y
			 obt@ªóÌêÍÈÉàµÈ¢B
			 obt@ÌàeªüsÌêAJ[\ªw·¶Ì¼OÅüsðs¤BJ[\ÍVµ¢sÌæª¶ÖÚ®·éB
			 obt@Ìàeª¶ñÌêAJ[\ÌÊuÉobt@Ìàeð}ü·éB J[\ÌÊuÍàÆàÆwµÄ¢½¶Ü½ÍsÌêÖÚ®·é
			 */
		case 'y':
		{
			text = text.substr(0, cursor) + buffer + text.substr(cursor);
			cursor += buffer.size();
			
			break;
		}
	}
}