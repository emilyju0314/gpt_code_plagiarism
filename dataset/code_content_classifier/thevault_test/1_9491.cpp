static PetscErrorCode EvalHessianDAE_UdotUdot(TS ts, PetscReal time, Vec U, Vec Udot, Vec M, Vec L, Vec X, Vec Y, void *ctx)
{
  const PetscScalar *x,*l,*u,*udot;
  PetscScalar       *y,yd1[2],yd2[2];
  PetscScalar       params[3];
  PetscScalar       v[2][2];
  PetscScalar       *Z[2] = {&v[0][0],&v[1][0]};
  int               m = 2,n = 2,keep = 2,tagifunc_udot = 4;
  PetscErrorCode    ierr;

  PetscFunctionBeginUser;
  ierr = VecGetArray(Y,&y);CHKERRQ(ierr);
  ierr = VecGetArrayRead(X,&x);CHKERRQ(ierr);
  ierr = VecGetArrayRead(L,&l);CHKERRQ(ierr);
  ierr = VecGetArrayRead(U,&u);CHKERRQ(ierr);
  ierr = VecGetArrayRead(Udot,&udot);CHKERRQ(ierr);

  /* we use the split trace on udot only */
  params[0] = u[0];
  params[1] = u[1];
  params[2] = u[0]*u[0] + u[1]*u[1];
  set_param_vec(tagifunc_udot,3,params);
  fos_forward(tagifunc_udot,m,n,keep,u,(PetscScalar*)x,yd1/*dummy*/,yd2/*dummy*/);
  hos_reverse(tagifunc_udot,m,n,1,(PetscScalar*)l,Z);
  y[0] = v[0][1];
  y[1] = v[1][1];

  ierr = VecRestoreArrayRead(Udot,&udot);CHKERRQ(ierr);
  ierr = VecRestoreArrayRead(U,&u);CHKERRQ(ierr);
  ierr = VecRestoreArrayRead(L,&l);CHKERRQ(ierr);
  ierr = VecRestoreArrayRead(X,&x);CHKERRQ(ierr);
  ierr = VecRestoreArray(Y,&y);CHKERRQ(ierr);
  PetscFunctionReturn(0);
}