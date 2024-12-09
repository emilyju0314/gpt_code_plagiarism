void PhotonShader::computeFormFactor(int x, int y) {
  const int o_minx = x - maxRadius_;
  const int o_miny = y - maxRadius_;
  const int o_maxx = x + maxRadius_;
  const int o_maxy = y + maxRadius_;
  const int minx = std::max(o_minx, 0);
  const int miny = std::max(o_miny, 0);
  const int maxx = std::min(o_maxx, map_->getWidth() - 1);
  const int maxy = std::min(o_maxy, map_->getHeight() - 1);
  const int maxDiameter = 2 * maxRadius_ + 1;
  float* cellFormFactor = ff_ + (x + y * map_->getWidth()) * maxDiameter * maxDiameter;
  map_->computeFov(x, y, maxRadius_);
  const int squareRad = (maxRadius_ * maxRadius_);
  // float invRad=1.0/squareRad;
  double curFfSum = 0;
  const float offset = 1.0f / (1.0f + (float)(maxRadius_ * maxRadius_) / 20);
  const float factor = 1.0f / (1.0f - offset);
  for (int cx = minx, cdx = minx - o_minx; cx <= maxx; cx++, cdx++) {
    for (int cy = miny, cdy = miny - o_miny; cy <= maxy; cy++, cdy++) {
      if (map_->isInFov(cx, cy)) {
        const int dist = (maxRadius_ - cdx) * (maxRadius_ - cdx) + (maxRadius_ - cdy) * (maxRadius_ - cdy);
        if (dist <= squareRad) {
          // float value = (1.0f-dist*invRad) ;
          // float value =1.0f/(1.0f+(float)(dist)/20);
          float value = (1.0f / (1.0f + (float)(dist) / 20) - offset) * factor;
          curFfSum += value;
          cellFormFactor[cdx + cdy * maxDiameter] = value;
        }
      }
    }
  }
  // scale so that the sum of all form factors for cell x,y is 1.0
  ffSum_[x + y * map_->getWidth()] = (float)curFfSum;
  if (curFfSum > 1E-8) {
    curFfSum = 1.0 / curFfSum;
    for (int cx = minx, cdx = minx - o_minx; cx <= maxx; cx++, cdx++) {
      for (int cy = miny, cdy = miny - o_miny; cy <= maxy; cy++, cdy++) {
        cellFormFactor[cdx + cdy * maxDiameter] *= (float)curFfSum;
      }
    }
  }
}