vector<vector<bool>> Populate(vector<int> &w, vector<int> &v, int weight)
{
	// vector of vector<bool>
	// this will store set of population
	vector<vector<bool>> population;

	// the number of objects availbale to choose from
	int n = w.size();

	// In an iteration total number of tries to choose a population
	int pop_count = n;

	for (int i = 0; i < pop_count; i++)
	{
		// will store a temporary population
		vector<bool> P(n, 0);

		// this will store the final weight count of the new randomly chosen population
		int wt_count = 0;

		for (int i = 0; i < n; ++i)
		{
			// by default using probabilty 1/2 to choose an object
			// value will always be either 0 or 1
			int value = rand() % 2;

			// we dont want the wt_count to be greater than the knapsack capacity
			if (value == 1)
			{
				// if the wt_count > knapsack capacity then break
				if (wt_count += w[i] > weight)
				{
					break;
				}
			}

			// if p[i] == 0 (the object has not been chosen)
			// if p[i] == 1 (the object has been chosen)
			P[i] = value;
		}

		// pushing that temporary population in the final population vector
		population.push_back(P);
	}

	return population;
}