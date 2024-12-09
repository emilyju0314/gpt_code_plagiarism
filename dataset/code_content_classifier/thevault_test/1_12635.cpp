seq_t core_exec_atom_t::get_uop_action_id(void * const op)
{
  struct uop_t const * uop = (struct uop_t*) op;
  return uop->exec.action_id;
}