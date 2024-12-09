void ReadPosition(float *posbuffer){
  //function for reading position of all 30 dofs 
  //read a K4JointPos object sent by YAPOC into input port (inPositionPort)
  //this K4JointPos object contains an element: positions (float[30]) which 
  //encodes motor position in ticks
  //ConvertToRadians is used to convert each value in positions into radians
  //these radian values are then copied into posbuffer
  inPositionPort.Read(1);
  pos = inPositionPort.Content();
  pos.ConvertToRadians();
  for (int i = 0; i < N_AXIS; i++)
    posbuffer[i] = pos.positions[i];  
}