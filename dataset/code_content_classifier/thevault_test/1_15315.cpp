void tester(int id){

	moodycamel::ConsumerToken ctok(candq); // Consumes from candq
	moodycamel::ProducerToken ptok(countq); // Produces for countq
	int mecount = 0;
	std::tuple<lint, int, lint, int>* retvals;
	bitset<tn> F;
	// Iterate until a kill-sentry is found
	while(true){
		candq.wait_dequeue(ctok, F); // Wait for new guy in queue

		if ((F.test(0) == 1) && (F.test(1) == 0)) { // Not a positive LTF
			std::ostringstream stream;
			stream << "Tester thread " << id << " terminating after testing " << mecount << " functions.\n";
			log(stream.str());
			return;		// Stop looking (termination signal)
		}

		// Holds the number of classes of each of 4 types associated with F
		retvals = new tuple<lint, int, lint, int>(0, 0, 0, 0);
		
		/* If an LTF, generate # of goldilocks functions in its orbit */
		/* Place into retvals */
		if (issep(F)) { 
			// Get the dual
			bitset<tn> Fd;
			dual(F, Fd); 

			// Store self-dualization as double-long array
			int FSD[2 * tn];
			for (int i = 0; i < tn; i++) {
				FSD[i] = F.test(i);
				FSD[i + tn] = Fd.test(i);
			}

			// And chow parameters
			// Since self-dual, the extra zeroth chow parameter is 2^(n+1)/2 = 2^n
			// Each other chow parameter of the self-dualization is double.
			int chow[n + 1];
			chowdualup(F, chow);		// The self-dualization has parameters double these
			
			// For each distinct anti-self-dualization
			bool newantisd = true;	// If this antiselfdual is distinct from those tested
			for (int i = 0; i <= n; i++) {
				if (!newantisd) {
					if (chow[i] != chow[i - 1]) {
						newantisd = true;
					}
				}

				if (newantisd) {
					// If self-dual pair
					if (chow[i] == tn / 2) {
						// Test xi = 0 for smallness
						bool isSmall = true;
						for (int j = 1; j <= n; j++) {	// testing the singleton values
							if ((FSD[two(j)]) && (j != i)) {
								isSmall = false;
								break;
							}
						}
						if (isSmall) {
							// Sn multiplicity computation
							// reps = size of Sn orbit of generator
							static lint max = fact(n);
							lint reps = max;
							int rchow[n];			// Get reduced chow parameters
							int p = 0;
							for (int j = 0; j <= n; j++) {
								if (j != i) {
									rchow[p] = chow[j];
									p++;
								}
							}

							int pcount = 1;
							for (int j = 1; j < n; j++) {
								if (rchow[j] == rchow[j - 1]) {
									pcount++;
								}
								else {
									reps /= fact(pcount);
									pcount = 1;
								}
							}
							reps /= fact(pcount);

							// Record number of classes from this generator
							get<0>(*retvals) += reps;
							get<1>(*retvals) += 1;
							get<2>(*retvals) += reps;
							get<3>(*retvals) += 1;
						}
					}
					else { // Not self dual (distinct)
						int numberPS = 2;			// Innocent until proven guilty

						// Test xi = 0 for smallness
						for (int j = 1; j <= n; j++) {	// testing the singleton values
							if ((FSD[two(j)]) && (j != i)) {
								numberPS--;
								break;
							}
						}

						// Test xi = 1 smallness
						int ti = two(i);
						for (int j = 1; j <= n; j++) {	// testing the singleton values
							if ((FSD[two(j) + ti]) && (j != i)) {
								numberPS--;
								break;
							}
						}

						// Now compute corresponding counts
						if (numberPS > 0) {
							
							// Sn multiplicity computation
							// reps = size of Sn orbit of the generator
							static lint max = fact(n);
							lint reps = max;
							int rchow[n];			// Get reduced chow parameters
							int p = 0;
							for (int j = 0; j <= n; j++) {
								if (j != i) {
									rchow[p] = chow[j];
									p++;
								}
							}

							int pcount = 1;
							for (int j = 1; j < n; j++) {
								if (rchow[j] == rchow[j - 1]) {
									pcount++;
								}
								else {
									reps /= fact(pcount);
									pcount = 1;
								}
							}
							reps /= fact(pcount);

							// Record number of classes from this generator
							if (numberPS == 2) {
								get<0>(*retvals) += reps;
								get<1>(*retvals) += 1;
								get<2>(*retvals) += reps;
								get<2>(*retvals) += reps;
								get<3>(*retvals) += 2;
							}
							else { // = 1
								get<2>(*retvals) += reps;
								get<3>(*retvals) += 1;
							}
						}
					}
					newantisd = false;
				}
			} // End for loop
		} // End F sep/ F testing and enumerating

		// Pass number of 
		countq.enqueue(ptok, *retvals);
		mecount++;

	} // End while loop
}