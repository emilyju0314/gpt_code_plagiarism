bool DRLBasedDataPlacementOptimizerForLoadJob :: computeLastReward(double & reward) {
    std::cout << "to compute last reward for " << this->producerJobName << std::endl;
    return server.getReward(this->producerJobName, reward);

}