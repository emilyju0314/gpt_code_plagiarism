static vector<int> BuildSuffixArray(const string &text)
{
	vector<int> result;
	int n = (int)text.size();

	for (int i = 0; i < n; i++) {
		result.push_back(i);
	}

	sort(result.begin(), result.end(), SuffixCmp(text));

	return result;
}