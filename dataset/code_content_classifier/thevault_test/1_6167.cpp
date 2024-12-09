void write_state_to_onoff(PtWidget_t *widget, short newstate)
{
  PtArg_t args[1];
  PtSetArg(&args[0], Pt_ARG_ONOFF_STATE, newstate,0);
  PtSetResources(widget,1,args);
}