void Generate_Mutation(vector<pair<int, vector<bool>>> &v)
{

	for (int i = 0; i < v.size(); ++i)
	{
		// total number of items
		int n = v[0].second.size();

		// number of mutations generated
		// mutating 10 % of the data
		int num = n / 10;
		while (num--)
		{
			// choosing a random point for mutation
			int index = rand() % n;

			// if 0 then 1 (and vice versa)
			v[i].second[index] = !v[i].second[index];
		}
	}
}