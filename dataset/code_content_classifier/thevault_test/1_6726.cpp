int CheckSeed (const unsigned long seed[6]) 
	{ 
		int i; 
		for (i = 0; i < 3; ++i) { 
			if (seed[i] >= m1) { 
				fprintf (stderr, "****************************************\n\n");
				fprintf (stderr, "ERROR: Seed[%d] >= 4294967087, Seed is not set.", i);
				fprintf (stderr, "\n\n****************************************\n\n");
				return (-1); 
			} 
		} 
		for (i = 3; i < 6; ++i) { 
			if (seed[i] >= m2) { 
				fprintf (stderr, "****************************************\n\n");
				fprintf (stderr, "ERROR: Seed[%d] >= 429444443, Seed is not set.", i);
				fprintf (stderr, "\n\n****************************************\n\n");
				return (-1); 
			} 
		} 
		if (seed[0] == 0 && seed[1] == 0 && seed[2] == 0) { 
			fprintf (stderr, "****************************************\n\n");
			fprintf (stderr, "ERROR: First 3 seeds = 0.\n\n");
			fprintf (stderr, "****************************************\n\n");
			return (-1); 
		} 
		if (seed[3] == 0 && seed[4] == 0 && seed[5] == 0) { 
			fprintf (stderr, "****************************************\n\n");
			fprintf (stderr, "ERROR: Last 3 seeds = 0.\n\n");
			fprintf (stderr, "****************************************\n\n");
			return (-1); 
		} 
		return 0; 
	}