void GeometricFactors3d(Mesh *mesh){

  int Nfaces = mesh->Nfaces;
  int K = mesh->K;

  MatrixXd x = mesh->x;
  MatrixXd y = mesh->y;
  MatrixXd z = mesh->z;  

  // compute geofacs
  MatrixXd Dr = mesh->Dr;
  MatrixXd Ds = mesh->Ds;
  MatrixXd Dt = mesh->Dt;

  MatrixXd xr = Dr*x;  MatrixXd xs = Ds*x;  MatrixXd xt = Dt*x;
  MatrixXd yr = Dr*y;  MatrixXd ys = Ds*y;  MatrixXd yt = Dt*y;  
  MatrixXd zr = Dr*z;  MatrixXd zs = Ds*z;  MatrixXd zt = Dt*z;  

  // use curl-conservative form to compute GCL-satisfying geofacs
  MatrixXd rxJ = Dt * (ys.array()*z.array()).matrix() - Ds * (yt.array()*z.array()).matrix();
  MatrixXd sxJ = Dr * (yt.array()*z.array()).matrix() - Dt * (yr.array()*z.array()).matrix();
  MatrixXd txJ = Ds * (yr.array()*z.array()).matrix() - Dr * (ys.array()*z.array()).matrix();  

  MatrixXd ryJ = -(Dt * (xs.array()*z.array()).matrix() - Ds * (xt.array()*z.array()).matrix());
  MatrixXd syJ = -(Dr * (xt.array()*z.array()).matrix() - Dt * (xr.array()*z.array()).matrix());
  MatrixXd tyJ = -(Ds * (xr.array()*z.array()).matrix() - Dr * (xs.array()*z.array()).matrix());  

  MatrixXd rzJ = -(Dt * (ys.array()*x.array()).matrix() - Ds * (yt.array()*x.array()).matrix());
  MatrixXd szJ = -(Dr * (yt.array()*x.array()).matrix() - Dt * (yr.array()*x.array()).matrix());
  MatrixXd tzJ = -(Ds * (yr.array()*x.array()).matrix() - Dr * (ys.array()*x.array()).matrix());

  MatrixXd J =
      xr.array()*(ys.array()*zt.array() - zs.array()*yt.array())
    - yr.array()*(xs.array()*zt.array() - zs.array()*xt.array())
    + zr.array()*(xs.array()*yt.array() - ys.array()*xt.array());
  
  // all quantities stored at GLL points (must interp before using)
  mesh->rxJ = rxJ;
  mesh->sxJ = sxJ;
  mesh->txJ = txJ;  
  mesh->ryJ = ryJ;
  mesh->syJ = syJ;
  mesh->tyJ = tyJ;  
  mesh->rzJ = rzJ;
  mesh->szJ = szJ;
  mesh->tzJ = tzJ;  
  mesh->J = J;

#if 0
  double err = (Dr*rxJ + Ds*sxJ + Dt*txJ).cwiseAbs().sum() +
    (Dr*ryJ + Ds*syJ + Dt*tyJ).cwiseAbs().sum() +
    (Dr*rzJ + Ds*szJ + Dt*tzJ).cwiseAbs().sum();
  printf("GCL err = %g\n",err);
#endif
  
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