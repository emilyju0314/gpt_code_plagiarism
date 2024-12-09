#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

int t;

string decToBase2(int num) {
	string ret = "";
	if (num == 0) {
		ret = "0";
	}
	while (num > 0) {
		ret += to_string(num % 2);
		num /= 2;
	}
	for (int i = 0; i < ret.length() / 2; i++) {
		swap(ret[i], ret[ret.length() - i - 1]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> x;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			x.pb(num);
		}	
		vector<int> y;
		y.pb(0);
		for (int i = 1; i < n; i++) {
			string xi = decToBase2(x[i]);
			string prev = decToBase2(y[i - 1]^x[i - 1]);
			string curr = "";
			reverse(xi.begin(), xi.end());
			reverse(prev.begin(), prev.end());
			while (xi.length() < prev.length()) {
				xi += "0";
			}
			while (prev.length() < xi.length()) {
				prev += "0";
			}
			reverse(xi.begin(), xi.end());
			reverse(prev.begin(), prev.end());
			for (int i = 0; i < xi.length(); i++) {
				if (prev[i] == '1' && xi[i] == '0') {
					curr += "1";
				} else {
					curr += "0";
				}
			}
			y.pb(stoi(curr, nullptr, 2));
		}
		for (int i : y) {
			cout << i << " ";
		}
		cout << nl;
	}	
}
