void Wart::decode(Digraph & digraph)
{	
	string jumble = store;
	int length = jumble.length();
	double maxScore = 0;
	string decoded = "";
	string jScore;

	for (int i = 1; i <= length; i++)
	{
		if (length % i == 0)
		{
			jScore = unjumble(jumble, i);
			if (digraph.getScore(jScore) > maxScore)
			{
				maxScore = digraph.getScore(jScore);
				decoded = jScore;
			}
		}
	}
	store = decoded;		
}