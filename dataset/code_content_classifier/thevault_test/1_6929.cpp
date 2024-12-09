int edgeQueue::command(int argc, const char*const* argv) {
  if (strcmp(argv[1], "addPolicyEntry") == 0) {
    // Note: the definition of policy has changed.
    policy.addPolicyEntry(argc, argv);
    return(TCL_OK);
  };

  if (strcmp(argv[1], "addPolicerEntry") == 0) {
    // Note: the definition of policy has changed.
    policy.addPolicerEntry(argc, argv);
    return(TCL_OK);
  };

  if (strcmp(argv[1], "couple") == 0) {
  /*
    printf("%d ", argc);
    for (int i = 1; i < argc; i++) 
      printf("%d(%s) ", i, argv[i]);
    printf("\n");   
  */

    DEWPPolicy *ewp = (DEWPPolicy *)(policy.policy_pool[DEWP]);

    // Get the pointer to the queue to be coupled (in c++)
    //Tcl& tcl = Tcl::instance();
    edgeQueue *cq = (edgeQueue*) TclObject::lookup(argv[2]);
    DEWPPolicy *ewpc = (DEWPPolicy *)((cq->policy).policy_pool[DEWP]);

    ewp->couple(ewpc); 

    return(TCL_OK);
  };

  // couple the EW on request and response links
  if (strcmp(argv[1], "coupleEW") == 0) {
    //printf("%d ", argc);
    //for (int i = 1; i < argc; i++) 
    //printf("%d(%s) ", i, argv[i]);
    //printf("\n");   

    EWPolicy *ewp = (EWPolicy *)(policy.policy_pool[EW]);

    // Get the pointer to the queue to be coupled (in c++)
    //Tcl& tcl = Tcl::instance();
    edgeQueue *cq = (edgeQueue*) TclObject::lookup(argv[2]);
    EWPolicy *ewpc = (EWPolicy *)((cq->policy).policy_pool[EW]);

    // couple the EW detector 
    if (argc > 3)
      ewp->coupleEW(ewpc, atof(argv[3])); 
    else
      ewp->coupleEW(ewpc); 

    return(TCL_OK);
  };

  // Set a rate limitor
  if (strcmp(argv[1], "limit") == 0) {
    //printf("%d ", argc);
    //for (int i = 1; i < argc; i++) 
    //  printf("%d(%s) ", i, argv[i]);
    //printf("\n");

    EWPolicy *ewp = (EWPolicy *)(policy.policy_pool[EW]);
    
    // Packet rate limitor
    if (strcmp(argv[2], "P") == 0) {
      ewp->limitPr(atoi(argv[3]));
      return(TCL_OK);
    } 

    // bits rate limitor
    if (strcmp(argv[2], "B") == 0) {
      ewp->limitBr(atoi(argv[3]));
      return(TCL_OK);
    }
  };

  // Setup an EW detector on a link
  if (strcmp(argv[1], "detect") == 0) {
    //printf("%d ", argc);
    //for (int i = 1; i < argc; i++) 
    //  printf("%d(%s) ", i, argv[i]);
    //printf("\n");

    EWPolicy *ewp = (EWPolicy *)(policy.policy_pool[EW]);
    
    if (strcmp(argv[2], "P") == 0) {
      if (argc > 4)
	ewp->detectPr(atoi(argv[3]), atoi(argv[4]));
      else if (argc > 3)
	ewp->detectPr(atoi(argv[3]));
      else
	ewp->detectPr();

      return(TCL_OK);
    } 

    if (strcmp(argv[2], "B") == 0) {
      if (argc > 4)
	ewp->detectBr(atoi(argv[3]), atoi(argv[4]));
      else if (argc > 3)
	ewp->detectBr(atoi(argv[3]));
      else
	ewp->detectBr();

      return(TCL_OK);
    }
  };

  if (strcmp(argv[1], "getCBucket") == 0) {
    Tcl& tcl = Tcl::instance();
    tcl.resultf("%f", policy.getCBucket(argv));
    return(TCL_OK);
  }
  if (strcmp(argv[1], "printPolicyTable") == 0) {
    policy.printPolicyTable();
    return(TCL_OK);
  }
  if (strcmp(argv[1], "printPolicerTable") == 0) {
    policy.printPolicerTable();
    return(TCL_OK);
  }
  
  return(dsREDQueue::command(argc, argv));
}