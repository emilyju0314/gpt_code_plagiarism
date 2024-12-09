int
RandomnessTests(unsigned (*RandomSource)(), double fTries, char *szName, char *szLabel)
{
	unsigned nR1, nR2, nLastRand, nRand;
	double fc;
	int nFail;

    // TestPerformanceCounter(); return 1;

	printf("%s Report on %u calls to %s\n",szLabel, unsigned(fTries), szName);
	fflush(stdout);
	nR1 = RandomSource();
	nR2 = RandomSource();
	nLastRand = RandomSource();
	for (fc = 0.0; fc < fTries; fc += 1.0) {
		nRand = RandomSource();
		if (nLastRand == nR1 && nRand == nR2) {
			printf("Failed: too short of a period, %d\n", int(fc));
		}
		nLastRand = nRand;
		Frequency(nRand);
		Serial(nRand);
		Gap(nRand);
		Coupon(nRand);
		Permute(nRand);
		Runs(nRand);
		Maximum(nRand);
		MTuple(nRand);
		Frequency360(nRand % 360);
	}
	//
	//  Note, poker report uses serial-test data and then cleans up
	//
	nFail = 0;
	nFail += !FrequencyReport(fc);
	nFail += !SerialReport(fc);
	nFail += !GapReport(fc);
	nFail += !PokerReport(fc);
	nFail += !CouponReport(fc);
	nFail += !PermuteReport(fc);
	nFail += !RunsReport(fc);
	nFail += !MaximumReport(fc);
	nFail += !MTupleReport(fc);
	nFail += !Frequency360Report(fc);
	return nFail;
}