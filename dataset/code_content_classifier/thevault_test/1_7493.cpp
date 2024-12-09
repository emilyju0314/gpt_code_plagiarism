static void convert_coeffs(const char* file, K51FourierKnot *fk) {
  FourierKnot tmp(file); Vector3 vcos, vsin;
  fk->clear();
  for (uint i=0;i<tmp.csin.size();i+=2) {
    vcos.setValues(tmp.ccos[i+0][1],tmp.csin[i+0][0],tmp.csin[i+0][2]);
    vsin.setValues(tmp.ccos[i+1][1],tmp.csin[i+1][0],tmp.csin[i+1][2]);
    // cout << v << endl;
    fk->csin.push_back(vsin);
    fk->ccos.push_back(vcos);
  }
}