void MapNodes3d(Mesh *mesh){
  int Nfaces = mesh->Nfaces;
  int K = mesh->K;
  int Nv = mesh->Nv;
  MatrixXi EToV = mesh->EToV;

  VectorXd VX = mesh->VX;
  VectorXd VY = mesh->VY;
  VectorXd VZ = mesh->VZ;    
 
  MatrixXd x1(EToV.cols(),K);
  MatrixXd y1(EToV.cols(),K);
  MatrixXd z1(EToV.cols(),K);    
  for (int e = 0; e < K; ++e){
    for (int v = 0; v < EToV.cols(); ++v){
      int vid = EToV(e,v);
      x1(v,e) = VX(vid);
      y1(v,e) = VY(vid);
      z1(v,e) = VZ(vid);            
    }
  }
  // interp to high order GLL nodes (matlab ordering)
  VectorXd r1(8),s1(8),t1(8);
  r1 << -1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0;
  s1 << -1.0, 1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 1.0;  
  t1 << -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0;  

  VectorXd r = mesh->r;
  VectorXd s = mesh->s;
  VectorXd t = mesh->t;  
  
  MatrixXd Vdm1 = Vandermonde3DHex(1,r1,s1,t1);
  MatrixXd VdmN = Vandermonde3DHex(1,r,s,t);
  //cout << "Vdm1 = " << Vdm1 << endl;
  MatrixXd V1 = mrdivide(VdmN,Vdm1);

  MatrixXd x = V1*x1;
  MatrixXd y = V1*y1;
  MatrixXd z = V1*z1;  
  mesh->x = x;
  mesh->y = y;
  mesh->z = z;

  /*cout << "VX = [" << VX << "];" << endl;
  cout << "VY = [" << VY << "];" << endl;
  cout << "VZ = [" << VZ << "];" << endl;
  cout << "x1 = [" << x1 << "];" << endl;
  cout << "y1 = [" << y1 << "];" << endl;
  cout << "z1 = [" << z1 << "];" << endl;  
  cout << "x = [" << x << "];" << endl;
  cout << "y = [" << y << "];" << endl;
  cout << "z = [" << z << "];" << endl;  */

}