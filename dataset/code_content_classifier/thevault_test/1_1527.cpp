void RubberBandTool::calcRectCorners(QPoint corner1, QPoint corner2, QPoint &corner3, QPoint &corner4) {
    double slope = ((double)corner2.y() - (double)corner1.y()) / ((double)corner2.x() - (double)corner1.x());

    if((fabs(slope) > DBL_EPSILON) && (slope < DBL_MAX) && (slope > -DBL_MAX)) {
      // corner1,corner2 make up y=m(x-x1)+y1
      // corner3,corner4 must make up || line crossing corner3.
      // b (y-intercept) is what differs from the original line and our parallel line.
      // Go ahead and figure out our new b by using b = -mx1+y1 from the point-slope formula.
      double parallelB = -1 * slope * corner3.x() + corner3.y();

      // Now we have our equation for a parallel line, which our new points lie on. Let's find the perpendicular lines
      // which cross corner1,corner2 in order to figure out where they cross it. Use -1/slope = perpendicular slope and
      // now we have y=m(x-x1)+y1. What we care about is b in y=mx+b, so figure it out using b = m*(-x1)+y1
      double perpSlope = -1.0 / slope;
      double perpLineMode1b = perpSlope * (-1 * corner1.x()) + corner1.y();
      double perpLineMode2b = perpSlope * (-1 * corner2.x()) + corner2.y();

      // Now let's find the perpendicular lines' intercepts on the parallel line.
      // y = mx+b = y = mx+b => mx+b(perpendicular) = mx+b(parallel) for the perp. lines and the parallel line.
      // Combine the b's on the left to make y= m(perp)x+k = m(par)x.
      double perpLineMode1k = perpLineMode1b - parallelB;
      double perpLineMode2k = perpLineMode2b - parallelB;

      // Now we have mx + k = mx (parallel). Divive the parallel slope out to get
      //    (m(perp)x+k)/m(parallel) = x. Move the x over from the left side of the equation by subtracting...
      //    k/m(parallel) = x - m(perp)x/m(parallel). Factor out the x's... k/m(par) = x(1-m(per)/m(par)) and divive
      //    both sides by "(1-m(per)/m(par))". So we end up with: (k/m(par)) / (1 - m(per) / m(par) ) =
      //    k/m(par) / ( (m(par)-m(per)) / m(par) ) = k / m(par) * m(par) / (m(par) - m(per)) = k / (m(par) - m(per))
      double perpLineMode1IntersectX = perpLineMode1k / (slope - perpSlope);
      double perpLineMode2IntersectX = perpLineMode2k / (slope - perpSlope);

      // The intersecting X values are now known, and the equation of the parallel line, so let's roll with it and
      // get our two corners set. perpLineMode1 => corner1 => corner4, perpLineMode2 => corner2 => corner3
      corner3.setX((int)perpLineMode2IntersectX);
      corner3.setY((int)(perpLineMode2IntersectX * slope + parallelB)); //mx+b
      corner4.setX((int)perpLineMode1IntersectX);
      corner4.setY((int)(perpLineMode1IntersectX * slope + parallelB)); //mx+b
    }
    else if(fabs(slope) < DBL_EPSILON) {
      corner3.setX(corner2.x());
      corner3.setY(corner3.y());
      corner4.setX(corner1.x());
      corner4.setY(corner3.y());
    }
    else {
      corner3.setX(corner3.x());
      corner3.setY(corner2.y());
      corner4.setX(corner3.x());
      corner4.setY(corner1.y());
    }
  }