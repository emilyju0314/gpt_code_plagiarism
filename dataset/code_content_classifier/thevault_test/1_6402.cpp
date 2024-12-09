void ReportNixStats()
{
	printf("Total NV %d Min %ld Max %ld Avg %f\n", 
				 NVCount, NVMin, NVMax, (double)NVTot/(double)NVCount);
}