int read_integer_from_widget(PtWidget_t *widget)
{
      PtArg_t args[1];
      int *intval;
  
      PtSetArg(&args[0], Pt_ARG_NUMERIC_VALUE, &intval, 0);
      PtGetResources(widget, 1, args);
      return(*intval);
}