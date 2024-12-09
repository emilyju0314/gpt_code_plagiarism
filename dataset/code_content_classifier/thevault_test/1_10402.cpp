void FCOORD::from_direction(uint8_t direction) {
  double radians = angle_from_direction(direction);
  xcoord = cos(radians);
  ycoord = sin(radians);
}