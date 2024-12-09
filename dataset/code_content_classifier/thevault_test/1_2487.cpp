Analytic_CP_Eloss::Analytic_CP_Eloss(SP_Analytic_Model model_in,
                                     rtt_cdi::CParticle target_in, // NOLINT
                                     rtt_cdi::CParticle projectile_in,
                                     rtt_cdi::CPModelAngleCutoff model_angle_cutoff_in)
    : rtt_cdi::CPEloss(target_in, projectile_in, rtt_cdi::CPModelType::ANALYTIC_ETYPE,
                       model_angle_cutoff_in),
      analytic_model(std::move(model_in)) {
  Ensure(analytic_model);
}