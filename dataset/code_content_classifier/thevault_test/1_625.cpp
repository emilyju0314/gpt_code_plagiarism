field_array_t *
restore_standard_field_array( void ) {
  field_array_t * fa; 
  sfa_params_t * p;
  RESTORE( fa );
  RESTORE_ALIGNED( fa->f );
  RESTORE_PTR( fa->g );
  RESTORE( p );
  RESTORE_ALIGNED( p->mc );
  fa->params = p;
  restore_field_advance_kernels( fa->kernel );
  return fa;
}