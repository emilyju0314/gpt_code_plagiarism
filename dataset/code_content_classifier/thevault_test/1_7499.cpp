void writhe_frame_normals(Tube<Vector3>* t, Vector3* Normals) {

  int Nloc = t->nodes();
  Vector3 e_ij, down_dir, tan;

  for (int i=0;i<Nloc;i++) {

    tan = (*t)[i].getTangent();

    vector<Biarc<Vector3> >::iterator bi_tmp, b_i = t->begin()+i;
    vector<Biarc<Vector3> >::iterator b_j = b_i + 1;
    if (b_j == t->end()) b_j = t->begin();

    down_dir = tan;
    while (b_j!=b_i) {
      e_ij = (b_j->getPoint()-b_i->getPoint());
      e_ij.normalize();
      down_dir += e_ij;
      // tmp.append(e_ij,Vector3(0,0,0));
      b_j = b_j + 1;
      if (b_j == t->end()) b_j = t->begin();
    }
    down_dir += -tan;

    down_dir/= (float)(Nloc+1);
    down_dir = down_dir - down_dir.dot(tan)*tan;
    down_dir.normalize();

    Normals[i] = down_dir;

  }
}