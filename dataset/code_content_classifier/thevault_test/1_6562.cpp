void PolicyClassifier::addPolicerEntry(int argc, const char*const* argv) {
  //int cur_policy;


  if (policerTableSize == MAX_CP)
    printf("ERROR: Policer Table size limit exceeded.\n");
  else {
    if ((strcmp(argv[2], "Dumb") == 0) || (strcmp(argv[2],"Null") == 0)) {
      if(!policy_pool[Null])
	policy_pool[Null] = new NullPolicy;
      policerTable[policerTableSize].policer = nullPolicer;      
      policerTable[policerTableSize].policy_index = Null;      
    } else if (strcmp(argv[2], "TSW2CM") == 0) {
      if(!policy_pool[TSW2CM])
	policy_pool[TSW2CM] = new TSW2CMPolicy;
      policerTable[policerTableSize].policer = TSW2CMPolicer;
      policerTable[policerTableSize].policy_index = TSW2CM;      
    } else if (strcmp(argv[2], "TSW3CM") == 0) {
      if(!policy_pool[TSW3CM])
	policy_pool[TSW3CM] = new TSW3CMPolicy;
      policerTable[policerTableSize].policer = TSW3CMPolicer;
      policerTable[policerTableSize].policy_index = TSW3CM;      
    } else if (strcmp(argv[2], "TokenBucket") == 0) {
      if(!policy_pool[TB])
	policy_pool[TB] = new TBPolicy;
      policerTable[policerTableSize].policer = tokenBucketPolicer;
      policerTable[policerTableSize].policy_index = TB;      
    } else if (strcmp(argv[2], "srTCM") == 0) {
      if(!policy_pool[SRTCM])
	policy_pool[SRTCM] = new SRTCMPolicy;
      policerTable[policerTableSize].policer = srTCMPolicer;
      policerTable[policerTableSize].policy_index = SRTCM;      
    } else if (strcmp(argv[2], "trTCM") == 0){
      if(!policy_pool[TRTCM])
	policy_pool[TRTCM] = new TRTCMPolicy;
      policerTable[policerTableSize].policer = trTCMPolicer;
      policerTable[policerTableSize].policy_index = TRTCM;      
    } else if (strcmp(argv[2], "SFD") == 0) {
      if(!policy_pool[SFD])
	policy_pool[SFD] = new SFDPolicy;
      policerTable[policerTableSize].policer = SFDPolicer;
      policerTable[policerTableSize].policy_index = SFD;      
    } else if (strcmp(argv[2], "EW") == 0) {
      if(!policy_pool[EW])
	policy_pool[EW] = new EWPolicy;
      policerTable[policerTableSize].policer = EWPolicer;
      policerTable[policerTableSize].policy_index = EW;      
    } else if (strcmp(argv[2], "DEWP") == 0) {
      if(!policy_pool[DEWP])
	policy_pool[DEWP] = new DEWPPolicy;
      policerTable[policerTableSize].policer = DEWPPolicer;
      policerTable[policerTableSize].policy_index = DEWP;      
    } else {
      printf("No applicable policer specified, exit!!!\n");
      exit(-1);
    }
  };
  
  policerTable[policerTableSize].initialCodePt = atoi(argv[3]);
  if (policerTable[policerTableSize].policer == nullPolicer)
      policerTable[policerTableSize].downgrade1 = atoi(argv[3]);
    else
      policerTable[policerTableSize].downgrade1 = atoi(argv[4]);
  if (argc == 6)
    policerTable[policerTableSize].downgrade2 = atoi(argv[5]);
  policerTableSize++;
}