int Fitness_Score(vector<bool> &population, vector<int> &value)
{
	int benefit_value = 0;
	for (int i = 0; i < population.size(); ++i)
	{
		if (population[i])
		{
			benefit_value += value[i];
		}
	}

	return benefit_value;
}