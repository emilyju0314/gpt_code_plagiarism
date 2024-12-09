ROW::ROW(           // constructor
    TO_ROW *to_row, // source row
    int16_t kern,   // char gap
    int16_t space   // word gap
    )
    : para_(nullptr) {
  kerning = kern; // just store stuff
  spacing = space;
  xheight = to_row->xheight;
  bodysize = to_row->body_size;
  ascrise = to_row->ascrise;
  descdrop = to_row->descdrop;
  baseline = to_row->baseline;
  has_drop_cap_ = false;
  lmargin_ = 0;
  rmargin_ = 0;
}