void Fl_Tree_Item::show_self(const char *indent) const {
  if ( label() ) {
    printf("%s-%s (%d children, this=%p, parent=%p depth=%d)\n",
           indent,label(),children(),(void*)this, (void*)_parent, depth());
  }
  if ( children() ) {
    char *i2 = (char*)malloc(strlen(indent) + 2);
    strcpy(i2, indent);
    strcat(i2, " |");
    for ( int t=0; t<children(); t++ ) {
      child(t)->show_self(i2);
    }
  }
  fflush(stdout);
}