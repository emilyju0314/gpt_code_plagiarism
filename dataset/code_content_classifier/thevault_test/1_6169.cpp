double read_double_from_widget(PtWidget_t *widget)
{
      PtArg_t args[1];
      double *dval;
  
      PtSetArg(&args[0], Pt_ARG_NUMERIC_VALUE, &dval, 0);
      PtGetResources(widget, 1, args);
      return(*dval);
}