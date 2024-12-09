void PolicyClassifier::printPolicerTable() {
  bool threeColor;
  
  printf("Policer Table:\n");
  for (int i = 0; i < policerTableSize; i++) {
    threeColor = false;
    switch (policerTable[i].policer) {
    case nullPolicer:
      printf("Null ");
      break;
    case TSW2CMPolicer:
      printf("TSW2CM ");
      break;
    case TSW3CMPolicer:
      printf("TSW3CM ");
      threeColor = true;
      break;
    case tokenBucketPolicer:
      printf("Token Bucket ");
      break;
    case srTCMPolicer:
      printf("srTCM ");
      threeColor = true;
      break;
    case trTCMPolicer:
      printf("trTCM ");
      threeColor = true;
      break;
    case SFDPolicer:
      printf("SFD ");
      //printFlowTable();
      break;
    case EWPolicer:
      printf("EW ");
      break;
    case DEWPPolicer:
      printf("DEWP ");
      break;
    default:
      printf("ERROR: Unknown policer type in Policer Table.");
    }
    
    if (threeColor) {
      printf("policer code point %d is policed to yellow ",
	     policerTable[i].initialCodePt);
      printf("code point %d and red code point %d.\n",
	     policerTable[i].downgrade1,
	     policerTable[i].downgrade2);
    } else
      printf("policer code point %d is policed to code point %d.\n",
	     policerTable[i].initialCodePt,
	     policerTable[i].downgrade1);
  }
  printf("\n");
}