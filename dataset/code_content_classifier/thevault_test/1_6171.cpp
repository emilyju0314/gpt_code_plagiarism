void write_text_to_widget(PtWidget_t *widget, char* text, PgColor_t textcolor){
 
  PtArg_t args[2];
  PtSetArg(&args[0],Pt_ARG_COLOR, textcolor, 0);
  PtSetArg(&args[1],Pt_ARG_TEXT_STRING,text,1);
  PtSetResources(widget,2,args);
 
}