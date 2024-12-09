static PetscErrorCode IJacobianDestroy(Mat A)
{
  IJacobianctx   *mctx;
  PetscErrorCode ierr;

  PetscFunctionBeginUser;
  ierr = MatShellGetContext(A,(void**)&mctx);CHKERRQ(ierr);
  ierr = PetscFree(mctx);CHKERRQ(ierr);
  PetscFunctionReturn(0);
}