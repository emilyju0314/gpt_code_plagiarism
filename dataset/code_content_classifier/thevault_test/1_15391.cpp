bool DRLBasedDataPlacementOptimizerForLoadJob :: estimateSizeOfDataToLoad(double & avgSize, double & variance) {
 
     return server.getInfoForLoadJob (this->producerJobName, avgSize, variance);

}