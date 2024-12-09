bool traj_run(Trajectory &t, Position pos, float rad) {
  assert(t.ps.size()>0);
  int step = 0;
  float vel = 1;
  float gx, gy, norm;
  int px, py;
  Particle part, part_new;

  while((dist2(t.ps.back(),pos)>rad*rad) && (step++ < MAX_ITER)) {
    part = t.ps.back();
    // compute grad
    px = (int)(part.x); py = (int)(part.y);
    if (px>Res-2) gx = 0;
    else
      gx = pttable[px+1][py]-pttable[px][py];
    if (py>Res-2) gy = 0;
    else
      gy = pttable[px][py+1]-pttable[px][py];

    cout << "px="<<px<<",py="<<py<< ",gx="<<gx << ",gy=" << gy << endl << flush;

    norm = sqrt(gx*gx+gy*gy);
    gx /= norm; gy /= norm;
    // run down the gradient
    part_new.x = part.x - gx*vel;
    part_new.y = part.y - gy*vel;

    if (part_new.x>=Res) part_new.x = Res-1;
    if (part_new.y>=Res) part_new.y = Res-1;

    if (part_new.x<0) part_new.x = 0;
    if (part_new.y<0) part_new.y = 0;

    t.ps.push_back(part_new);
  }
  if (step<MAX_ITER)
    return true;
  return false;
}