void NonlinearSolidSolver::quasiStaticSolve()
{
  mfem::Vector zero;
  newton_solver_.Mult(zero, *displacement_->true_vec);
}