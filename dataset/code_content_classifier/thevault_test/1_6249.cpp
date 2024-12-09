int
SetVelocity( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	  	    
	if (axis_selected == 1){
	  double newvel = read_double_from_widget(ABW_VelocityValue);
	  
	  for (int i = 0; i < N_AXIS; i++){
	    if (i == current_axis){
	      newvelocity[i] = newvel;
		bits[i] = ON;
	      }
	      else {
		newvelocity[i] = 0;
		bits[i] = OFF;
	      }
	  }
	  newcommand.CreateSetVelocityMsg(newvelocity,bits);
	  SendMessage(newcommand);
	  printf("Sending request to change velocity for axis %d to %f\n",current_axis, newvel);
	} 
	return( Pt_CONTINUE );

	}