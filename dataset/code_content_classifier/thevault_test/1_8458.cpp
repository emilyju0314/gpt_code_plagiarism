inline void subPixelRefine(float32* dispImg, uint16* dsiImg, const sint32 width, const sint32 height, const sint32 maxDisp, sint32 method)
{
  const sint32 disp_n = maxDisp+1;

  /* equiangular */
  if (method == 0) {

    for (sint32 y = 0; y < height; y++)
    {
      uint16*  cost = getDispAddr_xyd(dsiImg, width, disp_n, y, 1, 0);
      float* disp = (float*)dispImg+y*width;

      for (sint32 x = 1; x < width-1; x++, cost += disp_n)
      {
        if (disp[x] > 0.0) {

          // Get minimum
          int d_min = (int)disp[x];

          // Compute the equations of the parabolic fit
          uint16* costDmin = cost+d_min;
          sint32 c0 = costDmin[-1], c1 = *costDmin, c2 = costDmin[1];

          __m128 denom = _mm_cvt_si2ss(_mm_setzero_ps(),c2 - c0);
          __m128 left = _mm_cvt_si2ss(_mm_setzero_ps(),c1-c0);
          __m128 right = _mm_cvt_si2ss(_mm_setzero_ps(),c1-c2);
          __m128 lowerMin = _mm_min_ss(left, right);
          __m128 result = _mm_mul_ss(denom, rcp_nz_ss(_mm_mul_ss(_mm_set_ss(2.0f),lowerMin)));

          __m128 baseDisp = _mm_cvt_si2ss(_mm_setzero_ps(),d_min);
          result = _mm_add_ss(baseDisp, result);
          _mm_store_ss(disp+x,result);

        } else {
          disp[x] = -10;
        }
      }
    }
    /* 1: parabolic */
  } else if (method == 1){
    for (sint32 y = 0; y < height; y++)
    {
      uint16*  cost = getDispAddr_xyd(dsiImg, width, disp_n, y, 1, 0);
      float32* disp = dispImg+y*width;

      for (sint32 x = 1; x < width-1; x++, cost += disp_n)
      {
        if (disp[x] > 0.0) {

          // Get minimum, but offset by 1 from ends
          int d_min = (int)disp[x];

          // Compute the equations of the parabolic fit
          sint32 c0 = cost[d_min-1], c1 = cost[d_min], c2 = cost[d_min+1];
          sint32 a = c0+c0 - 4 * c1 + c2+c2;
          sint32 b =  (c0 - c2);

          // Solve for minimum, which is a correction term to d_min
          disp[x] = d_min + b /(float32) a;

        } else {
          disp[x] = -10;
        }
      }
    }
  } else {
    //        assert("subpixel interpolation method nonexisting");
  }
}