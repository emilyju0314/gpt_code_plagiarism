static void convert_coeffs(const char* file, K41FourierKnot *fk) {
  FourierKnot tmp(file); Vector3 vcos, vsin;
  fk->clear();
  for (uint i=0;i<tmp.csin.size();i+=4) {
    vcos.setValues(tmp.ccos[i+0][0],tmp.ccos[i+0][2],tmp.ccos[i+1][1]);
    vsin.setValues(tmp.csin[i+1][1],tmp.ccos[i+2][0],tmp.ccos[i+2][2]);
    // cout << v << endl;
    fk->csin.push_back(vsin);
    fk->ccos.push_back(vcos);
  }
}