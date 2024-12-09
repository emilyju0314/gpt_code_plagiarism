int lba::utilizationbased(std::vector<ServiceNode> nodeList, Job job) {
  // NOTE: this should still work for both sqms and mqms
  int least_utilized{0};

  // find the index with the least utilization
  for (size_t ii = 0; ii < nodeList.size(); ii++) {
    // process queue
    nodeList[ii].processQueue(job.getArrival());

    // check if this is less utilized
    // NOTE: using calc util seems to make things better i.e. more balanced
    if (nodeList[least_utilized].calcUtil(job) > nodeList[ii].calcUtil(job)) {
      least_utilized = ii;
    }
  }
  return least_utilized;
}