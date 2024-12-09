void Fl_Text_Display::highlight_data(Fl_Text_Buffer *styleBuffer,
                                     const Style_Table_Entry *styleTable,
                                     int nStyles, char unfinishedStyle,
                                     Unfinished_Style_Cb unfinishedHighlightCB,
                                     void *cbArg ) {
  mStyleBuffer = styleBuffer;
  mStyleTable = styleTable;
  mNStyles = nStyles;
  mUnfinishedStyle = unfinishedStyle;
  mUnfinishedHighlightCB = unfinishedHighlightCB;
  mHighlightCBArg = cbArg;
  mColumnScale = 0;
  
  mStyleBuffer->canUndo(0);
  damage(FL_DAMAGE_EXPOSE);
}