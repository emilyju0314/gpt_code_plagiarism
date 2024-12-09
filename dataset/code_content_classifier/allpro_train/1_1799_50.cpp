
#include<iostream>
#include<algorithm>
#include<string>


int main() {
	int st[26]{};
	int tt[26]{};

	std::string s, t;
	std::cin >> s >> t;

	for (unsigned i{}; i < s.size(); i++) {
		st[s[i] - 'a']++;
		tt[t[i] - 'a']++;
	}


	std::sort(st, st + 26);
	std::sort(tt, tt + 26);

	bool match = true;
	for (unsigned i{}; i < 26;i++) {
		match &= st[i] == tt[i];
	}
	std::cout << (match ? "Yes" : "No") << "\n";
	return 0;
}