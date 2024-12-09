void CClientPIC::ReadConfig (char *filename)
{
    int Kp, Kd, Ki, IL; 
    FILE *fp = fopen (filename, "r");
  assert (fp != NULL);
  
  //ignore comments
    EatLine (fp);
    
  //read gains
  for (int i = 1; i <= nmotors; i++){
    fscanf (fp, "%d %d %d %d\n",
	    &Kp, &Kd, &Ki, &IL);
    
    D_ServoSetGain(i, Kp, Kd, Ki, IL, 255,0,400,1,0);
    if (DEBUG) printf("Read gains: %d %d %d %d\n",Kp,Kd,Ki,IL);
    EatLine (fp);  
  }
  //now read limits_max
  //reading backward b/c daemon number is opposite of virtual number
  if (DEBUG) printf("limits max: ");
  for ( i = 0; i < nmotors; i++){
    fscanf (fp, "%d ", &limits_max[i]);
    if (DEBUG) printf(" %d ",limits_max[i]);
  }
  if (DEBUG) printf(" min: ");
  EatLine(fp);
  //now read limits_min
  for ( i = 0; i < nmotors; i++){
      fscanf (fp, "%d ", &limits_min[i]);
    if (DEBUG) printf(" %d ",limits_min[i]);
  }
  if (DEBUG) printf("\n");
  
  //now read velocity
  //acceleration is velocity * 20
  EatLine(fp);
  for (i = 0; i < nmotors; i++){
    fscanf(fp,"%d ", &PICdefaultvel[i]);
    PICdefaultacc[i] = PICdefaultvel[i]*20;
     if (DEBUG) printf(" vel %d acc %d ;",PICdefaultvel[i],PICdefaultacc[i]);
  }
  if (DEBUG) printf("\n");
}