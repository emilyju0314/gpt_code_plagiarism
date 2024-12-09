void MapNodes2d(Mesh *mesh){
  int Nfaces = mesh->Nfaces;
  int K = mesh->K;
  int Nv = mesh->Nv;
  MatrixXi EToV = mesh->EToV;

  VectorXd VX = mesh->VX;
  VectorXd VY = mesh->VY;  
 
  MatrixXd x1(EToV.cols(),K);
  MatrixXd y1(EToV.cols(),K);  
  for (int e = 0; e < K; ++e){
    for (int v = 0; v < EToV.cols(); ++v){
      int vid = EToV(e,v);
      x1(v,e) = VX(vid);
      y1(v,e) = VY(vid);      
    }
  }
  // interp to high order GLL nodes (matlab ordering)
  VectorXd r1(4),s1(4);
  r1 << -1.0, 1.0, 1.0, -1.0;
  s1 << -1.0, -1.0, 1.0, 1.0;

  VectorXd r = mesh->r;
  VectorXd s = mesh->s;
  
  MatrixXd Vdm1 = Vandermonde2DQuad(1,r1,s1);
  MatrixXd VdmN = Vandermonde2DQuad(1,r,s);
  //cout << "Vdm1 = " << Vdm1 << endl;
  MatrixXd V1 = mrdivide(VdmN,Vdm1);

  MatrixXd x = V1*x1;
  MatrixXd y = V1*y1;
  mesh->x = x;
  mesh->y = y;

}