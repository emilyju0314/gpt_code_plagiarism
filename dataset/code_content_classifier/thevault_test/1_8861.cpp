arma_inline
const Gen<vec, gen_randn>
randn(const uword n_elem)
  {
  arma_extra_debug_sigprint();
  
  return Gen<vec, gen_randn>(n_elem, 1);
  }