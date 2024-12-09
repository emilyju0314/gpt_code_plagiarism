void Matrix3::print(ostream &out) const {
  out << "[";
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      if ((i!=0)&&!(j>0)) out << " ";
      out << (_v[j][i]);
      if (j!=2) out << " ";
    }
    if (i!=2) out << endl;
  }
  out << "]";
}