float read_value_from_slider(PtWidget_t *widget)
{
    PtArg_t args[1];
    int *intval;
    float dval;
    PtSetArg(&args[0], Pt_ARG_GAUGE_VALUE, &intval, 0);
  
    PtGetResources(widget, 1, args);
  dval = (float)(*intval); 
  
    return(dval);
}