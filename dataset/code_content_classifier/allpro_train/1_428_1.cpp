#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)
#define mp make_pair
#define P pair<int,int>
#define enld endl

string bigsum(string A, string B) {
	//A+Bを返す
	vector<char>num(10);
	num = { '0','1','2','3','4','5','6','7','8','9' };
	if (A.size() > B.size()) {
		swap(A, B);
	}
	int a = A.size();
	int b = B.size();
	int size = b + 1;
	reverse(A);
	reverse(B);
	vector<int>V(size, 0);
	rep(i, a) {
		V[i] = (A[i] - '0') + (B[i] - '0');
	}
	for (int i = a; i < b; i++) {
		V[i] = (B[i] - '0');
	}
	rep(i, size - 1) {
		V[i + 1] += (V[i] / 10);
		V[i] %= 10;
	}
	reverse(V);
	int flag = false;
	string ret;
	rep(i, size) {
		if (V[i] == 0 && flag == false)continue;
		else {
			ret.push_back(num[V[i]]);
			flag = true;
		}
	}
	if (ret.empty()) {
		ret = "0";
	}
	return ret;
}

string bigmulti(string A, string B) {
	//A*Bを返す
	vector<char>num(10);
	num = { '0','1','2','3','4','5','6','7','8','9' };
	if (A.size() > B.size()) {
		swap(A, B);
	}
	int a = A.size();
	int b = B.size();
	int size = a + b;
	reverse(A);
	reverse(B);
	vector<int>V(size, 0);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			V[i + j] += ((A[i] - '0') * (B[j] - '0'));
		}
	}
	rep(i, size - 1) {
		V[i + 1] += (V[i] / 10);
		V[i] %= 10;
	}
	reverse(V);
	int flag = false;
	string ret;
	for (int i = 0; i < size; i++) {
		if (V[i] == 0 && flag == false)continue;
		else {
			ret.push_back(num[V[i]]);
			flag = true;
		}
	}
	if (ret.empty()) {
		ret = "0";
	}
	return ret;
}

bool bigcomp(string A, string B) {
	//A>=Bならtrue A<Bならfalseを返す
	if (A.size() > B.size())return true;
	else if (A.size() < B.size())return false;
	else {
		if (A >= B)return true;
		else return false;
	}
}

string bigdif(string A, string B) {
	//AとBの差の絶対値を返す
	vector<char>num(10);
	num = { '0','1','2','3','4','5','6','7','8','9' };
	if (A.size() < B.size())swap(A, B);
	else if (A.size() == B.size()) {
		if (A < B)swap(A, B);
	}
	int a = A.size();
	int b = B.size();
	int size = a;
	reverse(A);
	reverse(B);
	vector<int>V(size, 0);
	rep(i, b) {
		V[i] = (A[i] - '0') - (B[i] - '0');
	}
	for (int i = b; i < size; i++) {
		V[i] = (A[i] - '0');
	}
	int flag = false;
	reverse(V);
	rep(i, size - 1) {
		if (V[i] == 0 && flag == false)continue;
		else {
			V[i]--;
			V[i + 1] += 10;
			flag = true;
		}
	}
	reverse(V);
	rep(i, size - 1) {
		V[i + 1] += (V[i] / 10);
		V[i] %= 10;
	}
	reverse(V);
	flag = false;
	string ret;
	rep(i, size) {
		if (V[i] == 0 && flag == false)continue;
		else {
			ret.push_back(num[V[i]]);
			flag = true;
		}
	}
	if (ret.empty()) {
		ret = "0";
	}
	return ret;
}

string bigabs(string S) {
	//abs(S)を返す
	string ans;
	if (S[0] != '-') {
		ans = S;
	}
	else {
		ans = S.substr(1, S.size() - 1);
	}
	return ans;
}

int main() {
	string A, B;
	cin >> A >> B;
	string ans;
	if (A[0]!='-') {
		if (B[0]!='-') {
			ans = bigsum(A, B);
			cout << ans << endl;
		}
		else {
			B = bigabs(B);
			ans = bigdif(A, B);
			if (bigcomp(A, B)) {
				cout << ans << endl;
			}
			else {
				cout << '-' << ans << endl;
			}
		}
	}
	else {
		A = bigabs(A);
		if (B[0]!='-') {
			ans = bigdif(A, B);
			if (bigcomp(B, A)) {
				cout << ans << endl;
			}
			else {
				cout << '-' << ans << endl;
			}
		}
		else {
			B = bigabs(B);
			ans = bigsum(A, B);
			cout << '-' << ans << endl;
		}
	}

}
