void FaceExpression(float *face_pos, float *posbuffer){
  short face_axes[21] = {8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,29};
   
   //move upper lids
   float lid_diff = posbuffer[EYE_TILT]/0.28 * 400;

   //Note that position specified for the upper lids are relative to current position
   face_pos[LEFT_UPPER_LID - 8] -= lid_diff;
   face_pos[RIGHT_UPPER_LID - 8] += lid_diff;
      MoveMultipleAxes(21,face_axes,face_pos);
   face_pos[LEFT_UPPER_LID - 8] += lid_diff;
   face_pos[RIGHT_UPPER_LID - 8] -= lid_diff;
}