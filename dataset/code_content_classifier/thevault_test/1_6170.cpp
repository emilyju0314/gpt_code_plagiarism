char *read_text_from_widget(PtWidget_t *widget)
{
      PtArg_t args[1];
      char *str;
  
      PtSetArg(&args[0], Pt_ARG_TEXT_STRING, &str, 0);
      PtGetResources(widget, 1, args);
      return(str);
}