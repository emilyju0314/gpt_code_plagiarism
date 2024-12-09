#include <iostream>
#include <string>
#include <deque>
using namespace std;

int g;
int prior[128];
int lft[16];
string s;
int pos;

void expr(int pr, deque<char> &res){
	if( pr == g ){
		if( s[pos] == '(' ){
			++pos;
			expr(0, res);
			++pos;
		}
		else{
			res.push_back( s[pos] );
			++pos;
		}
	}
	else{
		deque<char> dq;

		expr(pr + 1, dq);

		while( prior[s[pos]] == pr ){
			dq.push_front('(');
			dq.push_back( s[pos] );
			++pos;
			expr(pr + lft[pr], dq);
			dq.push_back(')');
		}
		
		res.insert( res.end(), dq.begin(), dq.end() );
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d, m, n;
	char a, p;
	
	prior['('] = prior[')'] = -1;
	
	cin >> d;
	while( d-- ){
		cin >> g;
		for(int i = 0; i < g; ++i){
			cin >> a >> m;
			lft[i] = (a == 'L');
			
			for(int j = 0; j < m; ++j){
				cin >> p;
				prior[p] = i;
			}
		}
		
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> s;
			s = '(' + s + ')';
			pos = 0;
			deque<char> res;
			expr(g, res);
			cout << string(res.begin(), res.end()) << '\n';
		}
		
		if( d ) cout << '\n';
	}
}