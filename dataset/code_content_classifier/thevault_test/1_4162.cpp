void ElasticitySolver::QuasiStaticSolve()
{
  // Apply the boundary conditions
  *bc_rhs_ = *rhs_;
  for (auto& bc : ess_bdr_) {
    SLIC_ASSERT_MSG(std::holds_alternative<std::shared_ptr<mfem::VectorCoefficient>>(bc.coef),
                    "Displacement boundary condition had a non-vector coefficient.");
    auto vec_coef = std::get<std::shared_ptr<mfem::VectorCoefficient>>(bc.coef);
    vec_coef->SetTime(time_);
    displacement_->gf->ProjectBdrCoefficient(*vec_coef, bc.markers);
    displacement_->gf->GetTrueDofs(*displacement_->true_vec);
    mfem::EliminateBC(*K_mat_, *K_e_mat_, bc.true_dofs, *displacement_->true_vec, *bc_rhs_);
  }

  K_solver_->SetOperator(*K_mat_);

  K_solver_->Mult(*bc_rhs_, *displacement_->true_vec);
}