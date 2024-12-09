void Lsqr::allocLsqrMem()
{
  long max_num_rows = input->num_rows;
  long max_num_cols = input->num_cols;  

  dvec *temp_vec = (dvec *) alloc_dvec( max_num_rows );
  input->rhs_vec = temp_vec;
  //  input->rhs_vec = (dvec *) alloc_dvec( max_num_rows );
  if (!input->rhs_vec) lsqr_error("lsqr: right hand side vector \'b\' allocation failure in function allocLsqrMem()", -1);

  input->sol_vec = (dvec *) alloc_dvec( max_num_cols );
  if (!input->sol_vec)lsqr_error("lsqr: solution vector \'x\' allocation  failure in function allocLsqrMem()", -1);

  output->std_err_vec = (dvec *) alloc_dvec( max_num_cols );
  if (!output->std_err_vec) lsqr_error("lsqr: standard error vector \'e\' allocation failure in function allocLsqrMem()", -1);

  (output)->sol_vec = (dvec *) (input)->sol_vec;

  work->bidiag_wrk_vec = (dvec *) alloc_dvec( max_num_cols );
  if (!work->bidiag_wrk_vec) lsqr_error("lsqr: bidiagonalization work vector \'v\' allocation failure in function allocLsqrMem()", -1);

  work->srch_dir_vec = (dvec *) alloc_dvec( max_num_cols );
  if (!work->srch_dir_vec)
     lsqr_error("lsqr: search direction vector \'w\' allocation failure in function allocLsqrMem()", -1);

  
  return;
}