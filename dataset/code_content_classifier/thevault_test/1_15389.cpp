Handle<LambdaIdentifier> DRLBasedDataPlacementOptimizerForLoadJob :: getBestLambda() {

     std::string errMsg;
     this->bestLambdaIndex = this->rlClientPtr->getBestLambdaIndex(this->state,
                        this->reward, errMsg);
     std::cout << "bestLambdaIndex = " << bestLambdaIndex << std::endl;
     std::cout << "lambdaCandidates.size() = " << lambdaCandidates.size() << std::endl;
     if (bestLambdaIndex < this->lambdaCandidates.size()) {

          return this->lambdaCandidates[bestLambdaIndex];

      } else {
          std::cout << "we didn't find any lambda probably because it is first time execution" << std::endl;
          return nullptr;
      }

}