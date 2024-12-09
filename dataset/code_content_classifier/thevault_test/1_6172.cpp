void  write_integer_to_widget(PtWidget_t *widget, int val){
  PtArg_t args[1];
  PtSetArg(&args[0],Pt_ARG_NUMERIC_VALUE, val, 0);
  PtSetResources(widget,1,args);
}