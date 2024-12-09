size_t DRLBasedDataPlacementOptimizerForLoadJob :: getBestPageSize() {

     if ((numPartitions < 1) || (this->state.numNodes < 1)) {
         return 0;
     }
     if ((bestLambdaIndex >= 0) && (bestLambdaIndex < this->lambdaCandidates.size())) {

         return this->state.inputSize / this->numPartitions;

     } else { 

         return this->state.inputSize / (this->numPartitions/this->state.numNodes);

     }
}