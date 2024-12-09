void fiber_control::trampoline(intptr_t _args) {
  // we may have launched to here by switching in from another fiber.
  // we will need to clean up the previous fiber
  tls* t = get_tls_ptr();
  if (t->prev_fiber) t->parent->reschedule_fiber(t->workerid, t->prev_fiber);
  t->prev_fiber = NULL;
  //printf("%ld: Running fiber: %ld\n", t->workerid, t->cur_fiber->id);

  trampoline_args* args = reinterpret_cast<trampoline_args*>(_args);
  try {
    args->fn();
  } catch (...) {
  }
  delete args;
  fiber_control::exit();
}