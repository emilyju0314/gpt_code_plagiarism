static vector<int> find_pattern(const string &pattern, const string &text)
{
	vector<int> result;
	string s = pattern + "$" + text;
	vector<int> pref = compute_prefix_fun(s);

	for (size_t i = pattern.size() + 1; i < s.size(); i++) {
		if (pref[i] == pattern.size()) {
			result.push_back(i - 2*pattern.size());
		}
	}
	cout << endl;

	return result;
}