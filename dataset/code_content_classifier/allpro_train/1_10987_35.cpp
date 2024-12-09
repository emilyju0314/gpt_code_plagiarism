#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;


int main(){
	vector<char> goal(32);
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 7; ++j){
			goal[i * 8 + j] = (i + 1) * 10 + j + 1;
		}
	}

	int n;
	for( scanf("%d", &n); n--; ){
		int x;
		vector<char> v(32);
		v[0] = 11;
		v[8] = 21;
		v[16] = 31;
		v[24] = 41;

		for(int i = 0; i < 4; ++i){
			for(int j = 1; j <= 7; ++j){
				scanf("%d", &x);
				
				if( x % 10 != 1 ){
					v[i * 8 + j] = x;
				}
			}
		}
		
		queue<vector<char> > q;
		q.push(v);
		q.push( vector<char>() );

		set<vector<char> > st;
		st.insert(v);

		int t = 0;
		while(true){
			if( q.size() == 1 ){
				t = -1;
				break;
			}
			
			v = q.front();
			q.pop();
			
			if( v.empty() ){
				++t;
				q.push(v);
				continue;
			}
			
			if( v == goal ){
				break;
			}

			int pos[48] = {};
			for(int i = 0; i < 4; ++i){
				for(int j = 0; j <= 7; ++j){
					int p = i * 8 + j;
					pos[ v[p] ] = p;
				}
			}

			for(int i = 0; i < 4; ++i){
				for(int j = 1; j <= 7; ++j){
					int p = i * 8 + j;
					
					if( v[p] == 0 && v[p - 1] % 10 != 7 ){
						vector<char> v2 = v;
						x = v[p - 1];
						v2[p] = x + 1;
						v2[ pos[x + 1] ] = 0;
						
						if( st.find(v2) == st.end() ){
							st.insert(v2);
							q.push(v2);
						}
					}
				}
			}
		}
		
		printf("%d\n", t);
	}
}