void PolicyClassifier::printPolicyTable() {
  printf("Policy Table(%d):\n",policyTableSize);
  for (int i = 0; i < policyTableSize; i++)
    {
      switch (policyTable[i].policer) {
      case nullPolicer:
	printf("Flow (%d to %d): Null policer, ",
               policyTable[i].sourceNode,policyTable[i].destNode);
	printf("initial code point %d\n", policyTable[i].codePt);
	break;
      case TSW2CMPolicer:
	printf("Flow (%d to %d): TSW2CM policer, ",
               policyTable[i].sourceNode,policyTable[i].destNode);
	printf("initial code point %d, CIR %.1f bps.\n",
               policyTable[i].codePt, policyTable[i].cir * 8);
	break;
      case TSW3CMPolicer:
	printf("Flow (%d to %d): TSW3CM policer, initial code ",
               policyTable[i].sourceNode, policyTable[i].destNode);
	printf("point %d, CIR %.1f bps, PIR %.1f bytes.\n",
               policyTable[i].codePt, policyTable[i].cir * 8,
               policyTable[i].pir * 8);
	break;
      case tokenBucketPolicer:
	printf("Flow (%d to %d): Token Bucket policer, ",
               policyTable[i].sourceNode,policyTable[i].destNode);
	printf("initial code  point %d, CIR %.1f bps, CBS %.1f bytes.\n",
               policyTable[i].codePt, policyTable[i].cir * 8,
               policyTable[i].cbs);
	break;
      case srTCMPolicer:
	printf("Flow (%d to %d): srTCM policer, initial code ",
               policyTable[i].sourceNode, policyTable[i].destNode);
	printf("point %d, CIR %.1f bps, CBS %.1f bytes, EBS %.1f bytes.\n",
               policyTable[i].codePt, policyTable[i].cir * 8,
               policyTable[i].cbs, policyTable[i].ebs);
	break;
      case trTCMPolicer:
	printf("Flow (%d to %d): trTCM policer, initial code ",
               policyTable[i].destNode, policyTable[i].sourceNode);
	printf("point %d, CIR %.1f bps, CBS %.1f bytes, PIR %.1f bps, ",
	       policyTable[i].codePt, policyTable[i].cir * 8,
               policyTable[i].cbs, policyTable[i].pir * 8);
	printf("PBS %.1f bytes.\n", policyTable[i].pbs);
	break;
      case SFDPolicer:
	printf("Flow (%d to %d): SFD policer, ",
	       policyTable[i].sourceNode,policyTable[i].destNode);
	printf("initial code point %d, TH %d bytes.\n",
	       policyTable[i].codePt, (int)policyTable[i].cir);
	break;
      case EWPolicer:
	printf("Flow (%d to %d): EW policer, ",
	       policyTable[i].sourceNode,policyTable[i].destNode);
	printf("initial code point %d.\n", policyTable[i].codePt);
	break;
      case DEWPPolicer:
	printf("Flow (%d to %d): DEWP policer, ",
	       policyTable[i].sourceNode,policyTable[i].destNode);
	printf("initial code point %d.\n", policyTable[i].codePt);
	break;
      default:
	printf("ERROR: Unknown policer type in Policy Table.\n");
      }
    }
  printf("\n");
}