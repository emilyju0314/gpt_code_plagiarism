int read_state_from_onoff(PtWidget_t *widget)
{
  PtArg_t args[1];
  int *intval;
  PtSetArg(&args[0], Pt_ARG_ONOFF_STATE, &intval,0);
  PtGetResources(widget,1,args);
  return(*intval);
  
}