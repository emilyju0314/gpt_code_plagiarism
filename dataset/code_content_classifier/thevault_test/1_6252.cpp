int initialize_onoff(){
  //check that all are initially off
  int stat = 0;
  stat += read_state_from_onoff(ABW_Axis0OnOff);
  stat += read_state_from_onoff(ABW_Axis1OnOff);
  stat += read_state_from_onoff(ABW_Axis2OnOff);
  stat += read_state_from_onoff(ABW_Axis3OnOff);
  stat += read_state_from_onoff(ABW_Axis4OnOff);
  stat += read_state_from_onoff(ABW_Axis5OnOff);
  stat += read_state_from_onoff(ABW_Axis6OnOff);
  stat += read_state_from_onoff(ABW_Axis7OnOff); 
  stat += read_state_from_onoff(ABW_Axis8OnOff);
   stat += read_state_from_onoff(ABW_Axis9OnOff);
   stat += read_state_from_onoff(ABW_Axis10OnOff);
   stat += read_state_from_onoff(ABW_Axis11OnOff);
   stat += read_state_from_onoff(ABW_Axis12OnOff);
   stat += read_state_from_onoff(ABW_Axis13OnOff);
   stat += read_state_from_onoff(ABW_Axis14OnOff);
   stat += read_state_from_onoff(ABW_Axis15OnOff);
  stat += read_state_from_onoff(ABW_Axis16OnOff);
  stat += read_state_from_onoff(ABW_Axis17OnOff);
  stat += read_state_from_onoff(ABW_Axis18OnOff);
  stat += read_state_from_onoff(ABW_Axis19OnOff);
  stat += read_state_from_onoff(ABW_Axis20OnOff);
  stat += read_state_from_onoff(ABW_Axis21OnOff);
  stat += read_state_from_onoff(ABW_Axis22OnOff);
  stat += read_state_from_onoff(ABW_Axis23OnOff);
  stat += read_state_from_onoff(ABW_Axis24OnOff);
  stat += read_state_from_onoff(ABW_Axis25OnOff);
  stat += read_state_from_onoff(ABW_Axis26OnOff);
  stat += read_state_from_onoff(ABW_Axis27OnOff);
  stat += read_state_from_onoff(ABW_Axis28OnOff);
   stat += read_state_from_onoff(ABW_Axis29OnOff);
  if (stat > 0){
    printf("At least one axis is not initially off\n"); 
    return -1;
  }
  else {
    printf("All axes are initially zero\n");

  }
  //initialize statusbits
  for (int s = 0; s < N_AXIS; s++)
      statusbits[s] = OFF;
  return 0;
  
}