#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);

struct value{
	virtual string get_prop(vs &keys,int pos)=0;
};

struct mapping_item{
	string key;
	value *v;
};

struct text:public value{
	string s;
	virtual string get_prop(vs &keys,int pos){
		if(pos==keys.size()){
			return "string \"" + s + "\"";
		}else{
			return "no such property";
		}
	}
};

struct mapping:public value{
	vector<mapping_item> mapping_items;
	virtual string get_prop(vs &keys,int pos){
		if(pos==keys.size()){
			return "object";
		}
		REP(i,mapping_items.size()){
			if(mapping_items[i].key==keys[pos]){
				return mapping_items[i].v->get_prop(keys,pos+1);
			}
		}
		return "no such property";
	}
};


mapping *read_mapping(string &s,int &pos,int n);

//mapping-item(n): indent(n) key ':' ' ' string '\n'
//                 | indent(n) key ':' '\n' mapping(m) (ただしm>n)
mapping_item read_mapping_item(string &s,int &pos,int n){
	mapping_item m;
	//indent(0): "" (※空文字列)
	//indent(n+1): ' ' indent(n) (※スペースをn+1個並べた文字列)
	REP(i,n){
		assert(s[pos]==' ');
		pos++;
	}
	//key: [a-z0-9]+ (※英字小文字または数字からなる1文字以上の文字列)
	while(s[pos]!=':'){
		m.key+=s[pos];
		pos++;
	}
	assert(s[pos]==':');
	pos++;
	if(s[pos]==' '){
		pos++;
		//string: [a-z0-9 ]+ (※英字小文字または数字またはスペースからなる1文字以上の文字列)
		text *t=new text;
		while(s[pos]!='\n'){
			t->s+=s[pos];
			pos++;
		}
		assert(s[pos]=='\n');
		pos++;
		m.v=t;
	}else{
		assert(s[pos]=='\n');
		pos++;
		int cnt=0;
		while(s[pos+cnt]==' '){
			cnt++;
		}
		m.v=read_mapping(s,pos,cnt);
	}
	return m;
}

//mapping(n): mapping-item(n) | mapping-item(n) mapping(n)
mapping *read_mapping(string &s,int &pos,int n){
	mapping* m=new mapping;
	while(pos<s.size()){
		int cnt=0;
		while(s[pos+cnt]==' '){
			cnt++;
		}
		if(cnt!=n)break;
		m->mapping_items.push_back(read_mapping_item(s,pos,n));
	}
	return m;
}

//yaml: mapping(0)
mapping *read_yaml(string &s){
	int pos=0;
	return read_mapping(s,pos,0);
}

int main(){
	string key_str;
	cin>>key_str;
	string yaml_str;
	string line;
	getline(cin,line);
	while(getline(cin,line)){
		yaml_str+=line+'\n';
	}
	string s;
	vs keys;
	FOR(i,1,key_str.size()){
		if(key_str[i]=='.'){
			keys.push_back(s);
			s="";
		}else{
			s.push_back(key_str[i]);
		}
	}
	if(s.size()){
		keys.push_back(s);
	}
	mapping* yaml=read_yaml(yaml_str);
	cout<<yaml->get_prop(keys,0)<<endl;
}