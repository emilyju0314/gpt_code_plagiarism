int read_selected_item_from_widget(PtWidget_t *widget)
{
      PtArg_t args[1];
      short int *index;
  
      PtSetArg(&args[0], Pt_ARG_CBOX_SEL_ITEM, &index, 0);
      PtGetResources(widget, 1, args);
      return(*index);
}