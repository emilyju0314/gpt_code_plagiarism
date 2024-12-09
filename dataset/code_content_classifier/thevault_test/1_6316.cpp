int
TurnOffAll( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo ){
  
    /* eliminate 'unreferenced' warnings */
    widget = widget, apinfo = apinfo, cbinfo = cbinfo;
    short zero = 0;
    for (int i = 0; i < N_AXIS; i++){
          if (statusbits[i] == ON){
	    statusbits[i] = OFF;
	    if (i == 0)
	      {
		write_state_to_onoff(ABW_Axis0OnOff, zero);
		write_text_to_widget(ABW_Axis0OnOff, OFF_TEXT, Pg_BLUE);
	      }
	    if (i == 1)
	      { write_state_to_onoff(ABW_Axis1OnOff, zero);
		write_text_to_widget(ABW_Axis1OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 2)
	      { write_state_to_onoff(ABW_Axis2OnOff, zero);
		write_text_to_widget(ABW_Axis2OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 3)
	      { write_state_to_onoff(ABW_Axis3OnOff, zero);
		write_text_to_widget(ABW_Axis3OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 4)
	      { write_state_to_onoff(ABW_Axis4OnOff, zero);
		write_text_to_widget(ABW_Axis4OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 5)
	      { write_state_to_onoff(ABW_Axis5OnOff, zero);
		write_text_to_widget(ABW_Axis5OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 6)
	      { write_state_to_onoff(ABW_Axis6OnOff, zero);
		write_text_to_widget(ABW_Axis6OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 7)
	      { write_state_to_onoff(ABW_Axis7OnOff, zero);
		write_text_to_widget(ABW_Axis7OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 8)
	      { write_state_to_onoff(ABW_Axis8OnOff, zero);
		write_text_to_widget(ABW_Axis8OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 9)
	      { write_state_to_onoff(ABW_Axis9OnOff, zero);
		write_text_to_widget(ABW_Axis9OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 10)
	      { write_state_to_onoff(ABW_Axis10OnOff, zero);
		write_text_to_widget(ABW_Axis10OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 11)
	      { write_state_to_onoff(ABW_Axis11OnOff, zero);
		write_text_to_widget(ABW_Axis11OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 12)
	      { write_state_to_onoff(ABW_Axis12OnOff, zero);
		write_text_to_widget(ABW_Axis12OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 13)
	      { write_state_to_onoff(ABW_Axis13OnOff, zero);
		write_text_to_widget(ABW_Axis13OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 14)
	      { write_state_to_onoff(ABW_Axis14OnOff, zero);
		write_text_to_widget(ABW_Axis14OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 15)
	      { write_state_to_onoff(ABW_Axis15OnOff, zero);
		write_text_to_widget(ABW_Axis15OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 16)
	      { write_state_to_onoff(ABW_Axis16OnOff, zero);
		write_text_to_widget(ABW_Axis16OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 17)
	      { write_state_to_onoff(ABW_Axis17OnOff, zero);
		write_text_to_widget(ABW_Axis17OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 18)
	      { write_state_to_onoff(ABW_Axis18OnOff, zero);
		write_text_to_widget(ABW_Axis18OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 19)
	      { write_state_to_onoff(ABW_Axis19OnOff, zero);
		write_text_to_widget(ABW_Axis19OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 20)
	      { write_state_to_onoff(ABW_Axis20OnOff, zero);
		write_text_to_widget(ABW_Axis20OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 21)
	      { write_state_to_onoff(ABW_Axis21OnOff, zero);
		write_text_to_widget(ABW_Axis21OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 22)
	      { write_state_to_onoff(ABW_Axis22OnOff, zero);
		         write_text_to_widget(ABW_Axis22OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 23)
	      { write_state_to_onoff(ABW_Axis23OnOff, zero);
		write_text_to_widget(ABW_Axis23OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	         if (i == 24)
	      { write_state_to_onoff(ABW_Axis24OnOff, zero);
		write_text_to_widget(ABW_Axis24OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 25)
	      { write_state_to_onoff(ABW_Axis25OnOff, zero);
		write_text_to_widget(ABW_Axis25OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 26)
	      { write_state_to_onoff(ABW_Axis26OnOff, zero);
		write_text_to_widget(ABW_Axis26OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 27)
	      { write_state_to_onoff(ABW_Axis27OnOff, zero);
		    write_text_to_widget(ABW_Axis27OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 28)
	      { write_state_to_onoff(ABW_Axis28OnOff, zero);
		    write_text_to_widget(ABW_Axis28OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	    if (i == 29)
	      { write_state_to_onoff(ABW_Axis29OnOff, zero);
		    write_text_to_widget(ABW_Axis29OnOff, OFF_TEXT, Pg_BLUE); 
	      }
	  }
    }
     return( Pt_CONTINUE );
}