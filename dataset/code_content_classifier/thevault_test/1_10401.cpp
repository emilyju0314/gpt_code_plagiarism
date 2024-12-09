void ICOORD::setup_render(ICOORD *major_step, ICOORD *minor_step, int *major, int *minor) const {
  int abs_x = abs(xcoord);
  int abs_y = abs(ycoord);
  if (abs_x >= abs_y) {
    // X-direction is major.
    major_step->xcoord = sign(xcoord);
    major_step->ycoord = 0;
    minor_step->xcoord = 0;
    minor_step->ycoord = sign(ycoord);
    *major = abs_x;
    *minor = abs_y;
  } else {
    // Y-direction is major.
    major_step->xcoord = 0;
    major_step->ycoord = sign(ycoord);
    minor_step->xcoord = sign(xcoord);
    minor_step->ycoord = 0;
    *major = abs_y;
    *minor = abs_x;
  }
}