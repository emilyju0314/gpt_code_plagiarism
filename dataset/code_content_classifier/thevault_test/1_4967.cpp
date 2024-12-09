static int
Report(double x2, double x97, const char *szTest)
{
	if (x2 > x97) {
		printf("       FAIL: %8d.%1d chi-square above 97th percentile in %s\n",
			int(x2), int(10.0*x2)%10, szTest);
		return 0;
	} else {
		printf("       pass: %8d.%1d chi-square in %s\n",
			int(x2), int(10.0*x2)%10, szTest);
		return 1;
	}
}