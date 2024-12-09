void Crossing_Over(vector<pair<int, vector<bool>>> &v)
{
	int pop_count = v.size() / 2;

	for (int i = 0; i < pop_count; ++i)
	{
		// total number of items
		int n = v[i].second.size();

		// choosing a random point
		int point = rand() % n;

		// crossing over at that random point
		for (int pt = 0; pt <= point; ++pt)
		{
			swap(v[2 * i].second[pt], v[2 * i + 1].second[pt]);
		}
	}
}