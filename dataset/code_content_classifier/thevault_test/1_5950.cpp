void scaleColorImage(byte* src, int sw, int sh,
                         int scx, int scy, byte* dst,
                         int dw, int dh, ufloat sx, ufloat sy)
    {
      for (int x = 0; x < dw; ++x)
        for (int y = 0; y < dh; ++y)
        {
          //find the corresponding point in source image
          ufloat fsrcx = (ufloat) (x-dw/2) / sx  + (ufloat) scx;
          ufloat fsrcy = (ufloat) (y-dh/2) / sy  + (ufloat) scy;
          int srcx = (int) fsrcx;
          int srcy = (int) fsrcy;
          if (srcx <= 0 || srcx >= sw - 1 || srcy <= 0 || srcy >= sh - 1)
            memset(dst + (x + y * dw) * 3, 0, 3);
          else //do the bilinear interpolation
          {
            ufloat xfactor = fsrcx - (ufloat) srcx;
            ufloat yfactor = fsrcy - (ufloat) srcy;
            for (int color = 0; color < 3; ++color)
            {
              ufloat up = (ufloat) src[(srcx + srcy * sw) * 3 + color]
                * (1.0 - xfactor)
                + (ufloat) src[(srcx + 1 + srcy * sw) * 3 + color] * xfactor;
              ufloat down = (ufloat) src[(srcx + (srcy + 1) * sw) * 3 + color]
                * (1.0 - xfactor)
                + (ufloat) src[(srcx + 1 + (srcy + 1) * sw) * 3 + color]
                * xfactor;
              ufloat result = up * (1.0 - yfactor) + down * yfactor;
              dst[(x + y * dw) * 3 + color] = (byte) result;
            }
          }
        }
    }