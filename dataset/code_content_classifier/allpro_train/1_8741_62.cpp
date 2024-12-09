#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<set>
#include<stack>
#include<queue>

#define reps(i,j,k) for(int i=(j);i<(k);i++)
#define rep(i,j) reps(i,0,j)
#define fs first
#define sc second
#define pb push_back
#define mk make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class S,class T>
ostream &operator<<(ostream &out, const pair<S,T> p){
	return out << "(" << p.fs << ", " << p.sc << ")";
}

template<class T>
ostream &operator<<(ostream &out, const vector<T> &v){
	out << "{";
	rep(i,v.size()) out << v[i] << ", ";
	return out << "}" << endl;
}

class node{
	public:
		int val;
		vector<node> l, r;
		string to_s(){
			string sl = "", sr = "";
			if(l.size() != 0) sl = l[0].to_s();
			if(r.size() != 0) sr = r[0].to_s();
			return "(" + sl + ")[" + to_string(val) + "](" + sr + ")";
		}
};

int to_i(int &pos, string &s){// str[pos-1] = '['
	int n = 0;
	while(s[pos] != ']'){
		n = n * 10 + s[pos] - '0';
		pos++;
	}
	return n; //str[pos] = ']'
}

node eval(int &pos, string &s){// str[pos] = '('
	pos++;
	node n;
	if(s[pos] != ')'){
		n.l.pb(eval(pos, s));
	}
	pos+=2;
	int v = to_i(pos, s);
	n.val = v;
	pos+=2;
	if(s[pos] != ')'){
		n.r.pb(eval(pos, s));
	}
	pos++;
	return n;
}

node add(node t1, node t2){
	int n = t1.val + t2.val;
	node v;
	v.val = n;
	if(!t1.l.empty() && !t2.l.empty()) v.l.pb(add(t1.l[0], t2.l[0]));
	if(!t1.r.empty() && !t2.r.empty()) v.r.pb(add(t1.r[0], t2.r[0]));
	return v;
}

int main(){
	string s;
	node a[3];
	cin >> s;
	int n=0;
	a[0] = eval(n, s);
	n = 0;
	cin >> s;
	a[1] = eval(n, s);
	n = 0;
	a[2] = add(a[0], a[1]);
	cout << a[2].to_s() << endl;

	return 0;
}