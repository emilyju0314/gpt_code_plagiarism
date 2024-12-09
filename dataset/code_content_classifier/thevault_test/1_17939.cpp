void mc_pfwl_wait_end(mc_pfwl_state_t *state) {
  if (state->parallel_module_type == MC_PFWL_PARALLELISM_FORM_DOUBLE_FARM) {
    state->pipeline->wait();
  } else {
#ifdef ENABLE_RECONFIGURATION
    state->mf->join();
#else
    state->single_farm->wait();
#endif
  }
#if 0
	while(!state->terminating){
		sleep(1);
	}
#endif
  gettimeofday(&state->stop_time, NULL);
  state->is_running = 0;
}