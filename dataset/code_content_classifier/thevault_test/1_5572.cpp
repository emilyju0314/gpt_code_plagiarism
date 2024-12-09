int Final_Score(vector<pair<int, vector<bool>>> &v, vector<int> &w, vector<int> &value, int weight)
{
	int out = -1;

	for (auto it : v)
	{
		int benefit_val = 0;
		int wt = 0;
		int n = it.second.size();

		for (int u = 0; u < n; u++)
		{
			if (it.second[u] == 1)
			{
				if (wt + w[u] > weight)
					break;
				wt += w[u];
				benefit_val += value[u];
			}
		}

		out = max(out, benefit_val);
	}
	return out;
}