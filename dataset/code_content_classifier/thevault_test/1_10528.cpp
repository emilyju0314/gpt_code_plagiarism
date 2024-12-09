ROW::ROW(                // constructor
    int32_t spline_size, // no of segments
    int32_t *xstarts,    // segment boundaries
    double *coeffs,      // coefficients
    float x_height,      // line height
    float ascenders,     // ascender size
    float descenders,    // descender drop
    int16_t kern,        // char gap
    int16_t space        // word gap
    )
    : baseline(spline_size, xstarts, coeffs), para_(nullptr) {
  kerning = kern; // just store stuff
  spacing = space;
  xheight = x_height;
  ascrise = ascenders;
  bodysize = 0.0f;
  descdrop = descenders;
  has_drop_cap_ = false;
  lmargin_ = 0;
  rmargin_ = 0;
}