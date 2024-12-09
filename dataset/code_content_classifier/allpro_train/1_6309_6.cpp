#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld=long double;

string st;
int a;

int get_num() {
	int num=0;
	while (a != st.size() && isdigit(st[a])) {
		num*=10;
		num+=st[a]-'0';
		a++;
	}
	return num;
}
vector<int>expr();
vector<int>prim() {
	if (st[a] == '(') {
		a++;
		vector<int>v=expr();
		assert(st[a]==')');
		a++;
		return v;
	}
	else {
		if (st[a] == 'x') {
			a++;
			return vector<int>{1, 0};
		}
		else {
			return vector<int>{get_num()};
		}
	}
}
vector<int> operator+(const vector<int>l, const vector<int>r) {
	vector<int>v(max(l.size(),r.size()));
	int k=max(l.size(),r.size());
	for (int i = 0; i < l.size(); ++i) {
		v[i+k-l.size()]+=l[i];
	}
	for (int j = 0; j < r.size(); ++j) {
		v[j+k-r.size()]+=r[j];
	}
	return v;
}
vector<int> operator*(const vector<int>l, const vector<int>r) {
	vector<int>v(l.size()+r.size()-1);
	for (int i = 0; i < l.size(); ++i) {
		for (int j = 0; j < r.size(); ++j) {
			v[i+j]+=l[i]*r[j];
		}
	}
	return v;
}

vector<int>fact() {
	vector<int>pr(prim());
	if (a != st.size() && st[a] == '^') {
		a++;
		int expo=get_num();

		vector<int>ans{ 1 };
		for (int k = 0; k < expo; ++k) {
			ans=ans*pr;
		}
		return ans;
	}
	else {
		return pr;
	}
}

vector<int>term() {
	vector<int>fa=fact();

	while (a != st.size() && st[a] != '+'&&st[a] != '-'&&st[a] != ')') {
		vector<int>next_fa=fact();
		fa=fa*next_fa;
	}
	return fa;
}
vector<int>expr() {
	vector<int>ter;
	{

		bool minus = false;
		if (st[a] == '-') {
			minus = true;
			a++;
		}
		ter=term();

		if (minus) {
			ter = ter*vector<int>{-1};
		}

	}
	while (a != st.size() &&( st[a] == '+' || st[a] == '-')) {
		bool minus=st[a]=='-';
		a++;
		vector<int>next_ter=term();
		if (minus) {
			next_ter = next_ter*vector<int>{-1};
		}
		ter=ter+next_ter;
	}
	return ter;

}

bool operator<(vector<ld>l, vector<ld>r) {
	if(l.size()!=r.size())return l.size()<r.size();
	for (int i = 0; i < l.size(); ++i) {
		if(abs(l[i])<abs(r[i]))return true;
		else if(abs(l[i])>abs(r[i]))return false;
	}
	return false;
}

int gcd(int a, int b) {
	if(a<0)return gcd(-a,b);
	if(b<0)return gcd(a,-b);
	if(b<a)swap(a,b);
	if(b%a==0)return a;
	else {
		return gcd(b%a,a);
	}
}
int gcd(vector<int>v) {
	int ans=-1;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i]) {
			if(ans==-1)ans=abs(v[i]);
			else ans=gcd(ans,abs(v[i]));
		}
	}
	return ans;
}

vector<ld>solve(vector<ld>l, vector<ld>r) {
	if(r<l)return solve(r,l);
	else {
		vector<ld>ans(r);
		for (int i = 0; i < r.size() - l.size() + 1; ++i) {
			ld num=ans[i]/l[0];

			for (int j = 0; j < l.size(); ++j) {
				ans[i+j]-=num*l[j];
			}
		}
		ans.erase(ans.begin(),find_if_not(ans.begin(), ans.end(), [](const ld a) {return abs(a)<1e-9; }));
		if (ans.empty()) {
			return l;
		}
		else {
			return solve(ans,l);
		}
	}
}

void output(vector<int>v) {
	for (int i = 0; i < v.size(); ++i) {
		int po = v.size() - i - 1;
		if (v[i]) {

			if (i!=0 && v[i] > 0) {
				cout<<"+";
			}

			if (po != 0 && abs(v[i]) == 1) {
				if(v[i]==-1)cout<<"-";
			}
			else {

				cout << v[i];
			}

			if (po >= 2) {
				cout<<"x^"<<po;
			}
			else if (po == 1) {
				cout<<"x";
			}
			else {

			}
		}
		
	}
	cout<<endl;
	return;
}

int main()
{
	while (true) {
		string A,B;cin>>A;
		if(A==".")break;
		cin>>B;

		st=A;
		a=0;
		vector<int>a_expr(expr());

		st=B;
		a=0;
		vector<int>b_expr(expr());

		vector<ld>aa,bb;
		for(int i=0;i<a_expr.size();++i)aa.push_back(a_expr[i]);
		for(int i=0;i<b_expr.size();++i)bb.push_back(b_expr[i]);
		auto ans=solve(aa,bb);
		if (ans[0] < 0) {
			for(auto &an:ans)an=-an;
		}
		int k;
		for ( k = 1; k < 100000; ++k) {
			bool ok=true;
			for (int i = 0; i < ans.size(); ++i) {
				ld n=ans[i]*k;
				if(abs(n-round(n))>1e-5)ok=false;
			}
			if(ok)break;
		}

		vector<int>answer;
		for (int i = 0; i < ans.size(); ++i) {
			answer.push_back(round(ans[i]*k));
		}

		int x=gcd(answer);
		for (int i = 0; i < ans.size(); ++i) {
			answer[i]/=x;
		}

		output(answer);
	}
	
	return 0;
}

