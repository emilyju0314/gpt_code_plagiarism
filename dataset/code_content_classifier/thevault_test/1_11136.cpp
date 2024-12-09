int16_t C_OUTLINE::turn_direction() const { // winding number
  DIR128 prevdir;                           // previous direction
  DIR128 dir;                               // current direction
  int16_t stepindex;                        // index to cstep
  int8_t dirdiff;                           // direction difference
  int16_t count;                            // winding count

  if (stepcount == 0) {
    return 128;
  }
  count = 0;
  prevdir = step_dir(stepcount - 1);
  for (stepindex = 0; stepindex < stepcount; stepindex++) {
    dir = step_dir(stepindex);
    dirdiff = dir - prevdir;
    ASSERT_HOST(dirdiff == 0 || dirdiff == 32 || dirdiff == -32);
    count += dirdiff;
    prevdir = dir;
  }
  ASSERT_HOST(count == 128 || count == -128);
  return count; // winding number
}