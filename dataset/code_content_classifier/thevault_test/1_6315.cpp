int TurnOnAll( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo ){
  
  /* eliminate 'unreferenced' warnings */
  widget = widget, apinfo = apinfo, cbinfo = cbinfo;
  short one = 1;
  for (int i = 0; i < N_AXIS; i++){
    if (statusbits[i] == OFF){
      statusbits[i] = ON;
      if (i == 0)
	{
	  write_state_to_onoff(ABW_Axis0OnOff, one);
	  write_text_to_widget(ABW_Axis0OnOff, ON_TEXT, Pg_RED);}
      if (i == 1)
	{ 
	  write_state_to_onoff(ABW_Axis1OnOff, one); 
	  write_text_to_widget(ABW_Axis1OnOff, ON_TEXT, Pg_RED); 
	}
      if (i == 2)
	{ 
	  write_state_to_onoff(ABW_Axis2OnOff, one); 
	  write_text_to_widget(ABW_Axis2OnOff, ON_TEXT, Pg_RED); 
	}
      if (i == 3)
	{ write_state_to_onoff(ABW_Axis3OnOff, one); 
	  write_text_to_widget(ABW_Axis3OnOff, ON_TEXT, Pg_RED); }
      if (i == 4)
	{ write_state_to_onoff(ABW_Axis4OnOff, one); 
	  write_text_to_widget(ABW_Axis4OnOff, ON_TEXT, Pg_RED); }
      if (i == 5)
	{ write_state_to_onoff(ABW_Axis5OnOff, one); 
	  write_text_to_widget(ABW_Axis5OnOff, ON_TEXT, Pg_RED); }
      if (i == 6)
	{ write_state_to_onoff(ABW_Axis6OnOff, one); 
	  write_text_to_widget(ABW_Axis6OnOff, ON_TEXT, Pg_RED); }
      if (i == 7)
	{ write_state_to_onoff(ABW_Axis7OnOff, one); 
	  write_text_to_widget(ABW_Axis7OnOff, ON_TEXT, Pg_RED); }
      if (i == 8)
	{ write_state_to_onoff(ABW_Axis8OnOff, one); 
	  write_text_to_widget(ABW_Axis8OnOff, ON_TEXT, Pg_RED); }
      if (i == 9)
	{ write_state_to_onoff(ABW_Axis9OnOff, one); 
	  write_text_to_widget(ABW_Axis9OnOff, ON_TEXT, Pg_RED); }
      if (i == 10)
	{ write_state_to_onoff(ABW_Axis10OnOff, one); 
	  write_text_to_widget(ABW_Axis10OnOff, ON_TEXT, Pg_RED); }
      if (i == 11)
	{ write_state_to_onoff(ABW_Axis11OnOff, one); 
	  write_text_to_widget(ABW_Axis11OnOff, ON_TEXT, Pg_RED); }
      if (i == 12)
	{ write_state_to_onoff(ABW_Axis12OnOff, one); 
	  write_text_to_widget(ABW_Axis12OnOff, ON_TEXT, Pg_RED); }
      if (i == 13)
	{ write_state_to_onoff(ABW_Axis13OnOff, one); 
	  write_text_to_widget(ABW_Axis13OnOff, ON_TEXT, Pg_RED); }
      if (i == 14)
	{ write_state_to_onoff(ABW_Axis14OnOff, one); 
	  write_text_to_widget(ABW_Axis14OnOff, ON_TEXT, Pg_RED); }
      if (i == 15)
	{ write_state_to_onoff(ABW_Axis15OnOff, one); 
	  write_text_to_widget(ABW_Axis15OnOff, ON_TEXT, Pg_RED); }
       if (i == 16)
	{ write_state_to_onoff(ABW_Axis16OnOff, one); 
	  write_text_to_widget(ABW_Axis16OnOff, ON_TEXT, Pg_RED); }
      if (i == 17)
	{ write_state_to_onoff(ABW_Axis17OnOff, one); 
	  write_text_to_widget(ABW_Axis17OnOff, ON_TEXT, Pg_RED); }
      if (i == 18)
	{ write_state_to_onoff(ABW_Axis18OnOff, one); 
	  write_text_to_widget(ABW_Axis18OnOff, ON_TEXT, Pg_RED); }
      if (i == 19)
	{ write_state_to_onoff(ABW_Axis19OnOff, one); 
	  write_text_to_widget(ABW_Axis19OnOff, ON_TEXT, Pg_RED); }
      if (i == 20)
	{ write_state_to_onoff(ABW_Axis20OnOff, one); 
	  write_text_to_widget(ABW_Axis20OnOff, ON_TEXT, Pg_RED); }
      if (i == 21)
	{ write_state_to_onoff(ABW_Axis21OnOff, one); 
	  write_text_to_widget(ABW_Axis21OnOff, ON_TEXT, Pg_RED); }
      if (i == 22)
	{ write_state_to_onoff(ABW_Axis22OnOff, one); 
	  write_text_to_widget(ABW_Axis22OnOff, ON_TEXT, Pg_RED); }
      if (i == 23)
	{ write_state_to_onoff(ABW_Axis23OnOff, one); 
	  write_text_to_widget(ABW_Axis23OnOff, ON_TEXT, Pg_RED); }
      if (i == 24)
	{ write_state_to_onoff(ABW_Axis24OnOff, one); 
	  write_text_to_widget(ABW_Axis24OnOff, ON_TEXT, Pg_RED); }
      if (i == 25)
	{ write_state_to_onoff(ABW_Axis25OnOff, one); 
	  write_text_to_widget(ABW_Axis25OnOff, ON_TEXT, Pg_RED); }
      if (i == 26)
	{ write_state_to_onoff(ABW_Axis26OnOff, one); 
	  write_text_to_widget(ABW_Axis26OnOff, ON_TEXT, Pg_RED); }
      if (i == 27)
	{ write_state_to_onoff(ABW_Axis27OnOff, one); 
	  write_text_to_widget(ABW_Axis27OnOff, ON_TEXT, Pg_RED); }
      if (i == 28)
	{ write_state_to_onoff(ABW_Axis28OnOff, one); 
	  write_text_to_widget(ABW_Axis28OnOff, ON_TEXT, Pg_RED); }
      if (i == 29)
	{ write_state_to_onoff(ABW_Axis29OnOff, one); 
	  write_text_to_widget(ABW_Axis29OnOff, ON_TEXT, Pg_RED); }
    }
  }
   return( Pt_CONTINUE ); 
}