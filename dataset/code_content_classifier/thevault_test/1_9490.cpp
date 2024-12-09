static PetscErrorCode TSComputeSplitJacobians_AD(TS ts,PetscReal time,Vec U,Vec Udot,Mat J_U,Mat pJ_U,Mat J_Udot,Mat pJ_Udot)
{
  PetscErrorCode ierr;

  PetscFunctionBeginUser;
  /* FormIJacobian has special cases for these */
  ierr = FormIJacobian(ts,time,U,Udot,0.0,J_U,pJ_U,NULL);CHKERRQ(ierr);
  ierr = FormIJacobian(ts,time,U,Udot,PETSC_MIN_REAL,J_Udot,pJ_Udot,NULL);CHKERRQ(ierr);
  PetscFunctionReturn(0);
}