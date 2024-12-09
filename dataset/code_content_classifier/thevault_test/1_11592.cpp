void GeometricFactors3d_Ngeo(Mesh *mesh, int Ngeo){

  int Nfaces = mesh->Nfaces;
  int K = mesh->K;

  // degree Ngeo nodal points (GCL and all)
  int Np1 = (Ngeo+1);  
  VectorXd r1D, w1D;
  JacobiGL(Ngeo, 0, 0, r1D, w1D);  
  int Np2 = Np1*Np1;
  int Np3 = Np1*Np2;  
  VectorXd rNg(Np3),sNg(Np3),tNg(Np3);
  int sk = 0;
  for (int k = 0; k < Np1; ++k){
    for (int i = 0; i < Np1; ++i){
      for (int j = 0; j < Np1; ++j){
	rNg(sk) = r1D(i);
	sNg(sk) = r1D(j);
	tNg(sk) = r1D(k);	
	++sk;
      }
    }
  }
  // degree Ngeo operators
  MatrixXd V1D = Vandermonde1D(Ngeo,r1D);
  MatrixXd Vr1D = GradVandermonde1D(Ngeo,r1D);
  MatrixXd D1D = mrdivide(Vr1D,V1D);
  MatrixXd I1D = MatrixXd::Identity(Np1,Np1);
  MatrixXd I2D = MatrixXd::Identity(Np2,Np2);  
  MatrixXd Dr = kron(I1D,kron(D1D,I1D));
  MatrixXd Ds = kron(I2D,D1D);
  MatrixXd Dt = kron(D1D,I2D);

  // interp degree N nodes to Ngeo
  MatrixXd VdmNgeo = Vandermonde3DHex(mesh->N,rNg,sNg,tNg);
  MatrixXd VNNgeo = mrdivide(VdmNgeo,mesh->V); 
  
  // construct degree Ngeo nodes
  MatrixXd x = VNNgeo * mesh->x;
  MatrixXd y = VNNgeo * mesh->y;
  MatrixXd z = VNNgeo * mesh->z;
  
  // compute geofacs
  MatrixXd xr = Dr*x;  MatrixXd xs = Ds*x;  MatrixXd xt = Dt*x;
  MatrixXd yr = Dr*y;  MatrixXd ys = Ds*y;  MatrixXd yt = Dt*y;  
  MatrixXd zr = Dr*z;  MatrixXd zs = Ds*z;  MatrixXd zt = Dt*z;  

  // normal curl method: GCL satisfied if 2*Ngeo - 2 < N, or Ngeo < floor(N/2) + 1
  MatrixXd rxJ = (ys.array()*zt.array() - zs.array()*yt.array());
  MatrixXd ryJ = -(xs.array()*zt.array() - zs.array()*xt.array());
  MatrixXd rzJ = (xs.array()*yt.array() - ys.array()*xt.array());

  MatrixXd sxJ = -(yr.array()*zt.array() - zr.array()*yt.array());
  MatrixXd syJ =  (xr.array()*zt.array() - zr.array()*xt.array());
  MatrixXd szJ = -(xr.array()*yt.array() - yr.array()*xt.array());

  MatrixXd txJ =  (yr.array()*zs.array() - zr.array()*ys.array());
  MatrixXd tyJ = -(xr.array()*zs.array() - zr.array()*xs.array());
  MatrixXd tzJ = (xr.array()*ys.array() - yr.array()*xs.array());

  MatrixXd J =
      xr.array()*(ys.array()*zt.array() - zs.array()*yt.array())
    - yr.array()*(xs.array()*zt.array() - zs.array()*xt.array())
    + zr.array()*(xs.array()*yt.array() - ys.array()*xt.array());
  
  // all quantities stored at GLL points (must interp before using)
  MatrixXd VdmN = Vandermonde3DHex(Ngeo,mesh->r,mesh->s,mesh->t);
  MatrixXd VNgeo = Vandermonde3DHex(Ngeo,rNg,sNg,tNg);
  MatrixXd VNgeoN = mrdivide(VdmN,VNgeo); // interp degree N nodes to Ngeo  
  mesh->rxJ = VNgeoN*rxJ;
  mesh->sxJ = VNgeoN*sxJ;
  mesh->txJ = VNgeoN*txJ;  
  mesh->ryJ = VNgeoN*ryJ;
  mesh->syJ = VNgeoN*syJ;
  mesh->tyJ = VNgeoN*tyJ;  
  mesh->rzJ = VNgeoN*rzJ;
  mesh->szJ = VNgeoN*szJ;
  mesh->tzJ = VNgeoN*tzJ;  
  mesh->J = VNgeoN*J;
 
#if 0
  printf("vgeo = [\n");
  for (int e = 0; e < K; ++e){
    for (int i = 0; i < rxJ.rows(); ++i){
      printf(" %f, %f, %f, %f, %f, %f, %f, %f, %f\n",
	     rxJ(i,e),sxJ(i,e),txJ(i,e),
	     ryJ(i,e),syJ(i,e),tyJ(i,e),
	     rzJ(i,e),szJ(i,e),tzJ(i,e));	     

    }
  }
  printf("];\n");  
#endif
  
}