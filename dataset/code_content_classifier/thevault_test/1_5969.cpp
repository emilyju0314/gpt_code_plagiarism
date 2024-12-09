void Lsqr::freeLsqrMem()
{
  free_dvec(input->rhs_vec);
  free_dvec(input->sol_vec);
  free_dvec(output->std_err_vec);
  free_dvec(work->bidiag_wrk_vec);
  free_dvec(work->srch_dir_vec);
  return;
}