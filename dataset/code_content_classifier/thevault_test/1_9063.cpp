void overlay_circle(SDoublePlane &input, int x_center, int y_center, int radius, int color)
{
  int r2 = radius * radius;
  for (int x = -radius; x <= radius; x++) {
     double y = (double) (sqrt(r2 - x*x)+0.1);
     if(x_center+x >= 0 && x_center+x < input.cols()) {
       if(y_center+y >=0 && y_center+y < input.rows())
         input[y_center+y][x_center+x] = color;
       if(y_center-y >=0 && y_center-y < input.rows())
         input[y_center-y][x_center+x] = color;
     }
   }
}