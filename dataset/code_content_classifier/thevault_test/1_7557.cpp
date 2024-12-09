int BresenhamPlanner(geometry_msgs::Point &a, geometry_msgs::Point &b) {
  int sx, sy, dx, dy, e, e2;
  int x = a.x, y = a.y, i = 0;
  
  if(a.x < b.x) {sx = 1;} else {sx = -1;}
  if(a.y < b.y) {sy = 1;} else {sy = -1;}
  
  dx = ABS(a.x - b.x);
  dy = ABS(a.y - b.y);
  e = dx - dy;
  
  while(x != b.x || y != b.y) {
    e2 = e * 2;
    if(e2 > -dy) {e -= dy; x += sx;}
    if(e2 <  dx) {e += dx; y += sy;}
    
    if(grid_[y][x] == 1) { // occupied (100) or unknown cell (-1)
      return INT_MAX;
    }
    i++;
  }
  
  return i;
}