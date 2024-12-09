int
TrafficSource::writeNsDefinitionScript(FILE * file) {
  // CBR traffic source has a slightly different syntax
  if (!strcmp(name(), "CBR")) {
    fprintf(file, "set traffic_source(%d) [new Application/Traffic/%s]\n",
                   number_, label_);
    fprintf(file, "$traffic_source(%d) attach-agent $agent(%d)\n", 
                   number_, agent_->number());
//    fprintf(file, "$traffic_source(%d) set packetSize_ %d\n",
//                   number_, packet_size_);
    fprintf(file, "$traffic_source(%d) set interval_ %f\n",
                   number_, interval_);

  } else if (!strcmp(name(), "Exponential")) {
    fprintf(file, "set traffic_source(%d) [new Application/Traffic/%s]\n",
                   number_, label_);
    fprintf(file, "$traffic_source(%d) attach-agent $agent(%d)\n", 
                   number_, agent_->number());
//    fprintf(file, "$traffic_source(%d) set packetSize_ %d\n",
//                   number_, packet_size_);
    fprintf(file, "$traffic_source(%d) set burst_time_ %dms\n",
                   number_, burst_time_);
    fprintf(file, "$traffic_source(%d) set idle_time_ %dms\n",
                   number_, idle_time_);
    fprintf(file, "$traffic_source(%d) set rate_ %dk\n",
                   number_, rate_);

  } else if (!strcmp(name(), "FTP")) {
    fprintf(file, "set traffic_source(%d) [new Application/%s]\n",
                   number_, label_);
    fprintf(file, "$traffic_source(%d) attach-agent $agent(%d)\n", 
                   number_, agent_->number());
    fprintf(file, "$traffic_source(%d) set maxpkts_ %d\n",
                   number_, maxpkts_);

  } else if (!strcmp(name(), "Pareto")) {
    fprintf(file, "set traffic_source(%d) [new Application/Traffic/%s]\n",
                   number_, label_);
    fprintf(file, "$traffic_source(%d) attach-agent $agent(%d)\n", 
                   number_, agent_->number());
//    fprintf(file, "$traffic_source(%d) set packetSize_ %d\n",
//                   number_, packet_size_);
    fprintf(file, "$traffic_source(%d) set burst_time_ %dms\n",
                   number_, burst_time_);
    fprintf(file, "$traffic_source(%d) set idle_time_ %dms\n",
                   number_, idle_time_);
    fprintf(file, "$traffic_source(%d) set rate_ %dk\n",
                   number_, rate_);
    fprintf(file, "$traffic_source(%d) set shape_ %f\n",
                   number_, shape_);

  } else if (!strcmp(name(), "Telnet")) {
    fprintf(file, "set traffic_source(%d) [new Application/%s]\n",
                   number_, label_);
    fprintf(file, "$traffic_source(%d) attach-agent $agent(%d)\n", 
                   number_, agent_->number());
    fprintf(file, "$traffic_source(%d) set interval_ %f\n",
                   number_, interval_);
  }
                          
  return 0;
}