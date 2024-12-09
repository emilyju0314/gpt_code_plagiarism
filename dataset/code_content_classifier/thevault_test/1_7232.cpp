void Fl::watch_widget_pointer(Fl_Widget *&w) 
{
  Fl_Widget **wp = &w;
  int i;
  for (i=0; i<num_widget_watch; ++i) {
    if (widget_watch[i]==wp) return;
  }
  if (num_widget_watch==max_widget_watch) {
    max_widget_watch += 8;
    widget_watch = (Fl_Widget***)realloc(widget_watch, sizeof(Fl_Widget**)*max_widget_watch);
  }
  widget_watch[num_widget_watch++] = wp;
#ifdef DEBUG_WATCH
  printf ("\nwatch_widget_pointer:   (%d/%d) %8p => %8p\n",
    num_widget_watch,num_widget_watch,wp,*wp);
  fflush(stdout);
#endif // DEBUG_WATCH
}