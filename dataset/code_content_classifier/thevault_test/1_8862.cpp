arma_inline
const Gen<mat, gen_randn>
randn(const uword n_rows, const uword n_cols)
  {
  arma_extra_debug_sigprint();
  
  return Gen<mat, gen_randn>(n_rows, n_cols);
  }