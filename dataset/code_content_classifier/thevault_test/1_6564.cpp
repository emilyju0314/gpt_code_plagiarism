int PolicyClassifier::mark(Packet *pkt) {
  policyTableEntry *policy;
  policerTableEntry *policer;
  int policy_index;
  int codePt;
  hdr_ip* iph;
  
  iph = hdr_ip::access(pkt);
  policy = getPolicyTableEntry(iph->saddr(), iph->daddr());
  if (policy) {
    codePt = policy->codePt;
    policy_index = policy->policy_index;
    policer = getPolicerTableEntry(policy_index, codePt);

    // bug pointed by Jason Kenney <jason@linear.engmath.dal.ca>
    if (policy_pool[policy_index]) {
      policy_pool[policy_index]->applyMeter(policy, pkt);
      codePt = policy_pool[policy_index]->applyPolicer(policy, policer, pkt);
    }
  } else {
    printf("The policy object doesn't exist, ERROR!!!\n");
    exit(-1);    
  }
  
  iph->prio_ = codePt;
  return(codePt);
}