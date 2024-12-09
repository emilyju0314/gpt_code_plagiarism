void anglesToCoords(float hip, float knee, float ankle)     // values are in degrees
// converted coordinates are returned in global variables f_cx, f_cy and f_cz
{
   f_cx = (2.5 + 7.5*cos(knee/180*PI)+11*sin((ankle-knee+17)/180*PI))*cos(hip/180*PI);
   f_cy = -7.5*sin(knee/180*PI)-11*cos((ankle-knee+17)/180*PI );
   f_cz = sin(hip/180*PI)*(2.5+7.5*cos(knee/180*PI)+11*sin((ankle-knee+17)/180*PI));
}