void Initialize(){
  //register ports
  outCommandPort.Register("/YAPOCClient/out/command");
  inPositionPort.Register("/YAPOCClient/in/position");
  in_pos.Register("/YAPOCClient/in/target");
  in_leftboxes.Register("/YAPOCClient/in/leftboxes");
  in_rightboxes.Register("/YAPOCClient/in/rightboxes");
  in_attnboxes.Register("/YAPOCClient/in/attnboxes");

  //initialize newpositions and statusbits
  for (int i = 0; i < N_AXIS; i++){
    newpositions[i] = 0;
    statusbits[i] = OFF;
  }
}