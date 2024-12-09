#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

string ch = "01+-*()";
int ans = -1;

int expression(const string& s, int& k, bool& op);
int factor(const string& s, int& k, bool& op);
int term(const string& s, int& k, bool& op);

// 数字が [0,1023] かチェック
bool valid(const int n){
	return (0 <= n && n < 1024);
}

// <number> ::= <digit> | <number> <digit>
int number(const string& s, int& k){
	int r = 0;
	while( s[k] == '0' || s[k] == '1' ){
		r = r * 2 + (s[k] - '0');
		++k;
	}
	return r;
}

int expression(const string& s, int& k, bool& op){
	int r1 = term(s, k, op);
	if( !valid(r1) ) return -1;
	
	while( k < s.size() ){
		if( s[k] == '+' ){
			++k;
			int r2 = term(s, k, op);
			// 数字が [0,1023] の範囲にないとき
			if( !valid(r2) || !valid(r1+r2) ) return -1;
			
			op = true;
			r1 = r1 + r2;
		}else if( s[k] == '-' ){
			++k;
			int r2 = term(s, k, op);
			
			// 数字が [0,1023] の範囲にないとき
			if( !valid(r2) || !valid(r1-r2) ) return -1;
			
			op = true;
			r1 = r1 - r2;
		}else{
			break;
		}
	}
	return r1;
}

int factor(const string& s, int& k, bool& op){
	if( s[k] == '(' ){ // 括弧のはじまりのとき
		++k; // '(' の 1つ先に進める.
		bool op_ = false;
		int r = expression(s, k, op_);
		// 数字が [0,1023] の範囲にない or ')' がないとき
		if( !valid(r) || s[k] != ')' || !op_ ) return -1;
		
		++k; // ')' の 1つ先に進める.
		return r;
	}else if( s[k] == '0' || s[k] == '1' ){ // 数字のとき
		return number(s, k);
	}else{
		return -1;
	}
}

int term(const string& s, int& k, bool& op){
	int r1 = factor(s, k, op);
	// 数字が [0,1023] の範囲にないとき 
	if( !valid(r1) ) return -1;
	
	while( k < s.size() ){
		if( s[k] == '*' ){
			++k;
			int r2 = factor(s, k, op);
			
			// 数字が [0,1023] の範囲にないとき
			if( !valid(r2) || !valid(r1*r2) ) return -1;
			
			op = true;
			r1 = r1 * r2;
		}else{
			break;
		}
	}
	return r1;
}

// 式が正しいかどうか.
/*bool check(const string& s){
	int par = 0;
	char prev = '\0';
	deque<bool> op(100, false);
	
	for(int i=0 ; i < s.size() ; i++ ){
		if( prev == '\0' ){
			if( s[i] == '(' ){
				++par;
				prev = s[i];
			}else if( s[i] == '0' || s[i] == '1' ){
				prev = s[i];
			}else{
				return false;
			}
		}else if( prev == '(' ){
			if( s[i] == '0' || s[i] == '1' ){
				prev = s[i];
			}else if( s[i] == '(' ){
				++par;
				prev = s[i];
			}else{
				return false;
			}
		}else if( prev == '0' || prev == '1' ){
			if( s[i] == '(' ){
				return false;
			}
			if( s[i] == ')' ){
				if( par < 0 || !op[par] ){
					return false;
				}
				op[par] = false;
				--par;
			}
			prev = s[i];
		}else if( prev == '+' || prev == '-' || prev == '*' ){
			if( par > 0 ){
				op[par] = true;
			}
			if( s[i] == '0' || s[i] == '1' ){
				prev = s[i];
			}else if( s[i] == '(' ){
				++par;
				prev = s[i];
			}else{
				return false;
			}
		}else if( prev == ')' ){
			if( s[i] == '+' || s[i] == '-' || s[i] == '*' ){
				prev = s[i];
			}else if( s[i] == ')' ){
				if( par < 0 || !op[par] ){
					return false;
				}
				op[par] = false;
				--par;
			}else{
				return false;
			}
		}
	}
}*/

bool check(const string& s){
	stack<int> st;
	for(int i=0 ; i < s.size() ; i++ ){
		if( s[i] == '(' ){
			st.push(0);
		}else if( s[i] == ')' ){
			if( st.empty() ){
				return false;
			}else{
				int cnt = st.top();
				if( cnt == 0 ){
					return false;
				}else{
					st.pop();
				}
			}
		}else if( s[i] == '+' || s[i] == '-' || s[i] == '*' ){
			if( !st.empty() ){
				int cnt = st.top();
				st.pop();
				st.push( cnt + 1 );
			}
		}
	}
	return st.empty();
}
int idx2;
/*bool check(const string& s, bool first=true){
  bool flg = false;
 
  while(idx2 < s.size()){
    if(s[idx2] == ')'){
      return flg;
    }
 
    if(s[idx2] == '('){
      idx2++;
      if(!check(s,false)) return false;
    }
 
    if(s[idx2] == '+' || s[idx2] == '-' || s[idx2] == '*'){
      flg = true;
    }
 
    idx2++;
  }
 
  if(first){
    return true;
  }
 
  return flg;
}*/

// '.' の置き換えを全部調べる.
void dfs(string s, const vector<int>& v, int pos){
	if( pos == v.size() ){ // '.' を全部置き換えた後
		int t=0;
		bool op = false;
		// 式が正しいときだけ解を更新.
		//if( check(s) ){
			int res = expression(s, t, op);
			if( t == s.size() )
				ans = max( ans , res );
		//}
		return;
	}
	for(int i=0 ; i < ch.size() ; i++ ){
		char tmp = s[v[pos]];
		s[v[pos]] = ch[i];
		dfs( s , v , pos+1 );
		s[v[pos]] = tmp;
	}
}

int main(){
	// v[i] := 文字列 s について i 番目の'.' の位置 k を返す.(s[v[i]] == '.')
	vector<int> v;
	string s;
	cin >> s;
	
	// '.' のある位置をチェック
	for(int i=0 ; i < s.size() ; i++ ){
		if( s[i] == '.' ) v.push_back(i);
	}
	// DFSで全探索 ('.'が高々5個, 文字が7種類なので7^5通りしかない)
	dfs( s, v, 0 );
	// 解の出力 (解が存在しないときは-1)
	cout << ans << endl;
}