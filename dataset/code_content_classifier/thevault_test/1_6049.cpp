void YAPOCVirtualControl::ReadAxisMap(const char *filename){
      char type;
      FILE *fp = fopen(filename, "r");
      assert (fp != NULL);
      
      //in case of comments
      IgnoreComment(fp);
      //read number of MEI and PIC axes
      fscanf(fp,"%d %d %d\n", &nMEIaxes, &nPICaxes,&numPICdaemons);
      naxes = nMEIaxes + nPICaxes;
      if (DEBUG) printf("Number of MEI axes = %d, Number of PIC axes = %d, Total = %d, Number of PIC daemons = %d\n",
	     nMEIaxes,nPICaxes,naxes,numPICdaemons);
      //in case of comments
      IgnoreComment(fp);
      //for each axis (virtual number 0 - 30), read how it's mapped to actual number
      //and what motor type it is
      for (int i = 0; i < naxes; i++)
	fscanf(fp,"%d %d\n", &axismap[i][AXISTYPE], &axismap[i][AXISNUMBER]);
      fclose(fp);
      
      for (int j = 0; j < naxes; j++)
	if (DEBUG) printf("%d %d\n",axismap[j][AXISTYPE], axismap[j][AXISNUMBER]);
    }