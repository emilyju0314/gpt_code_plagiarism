void build_comms_nccl_ucx(
  handle_t* handle, ncclComm_t nccl_comm, void* ucp_worker, void* eps, int num_ranks, int rank)
{
  auto eps_sp = std::make_shared<ucp_ep_h*>(new ucp_ep_h[num_ranks]);

  auto size_t_ep_arr = reinterpret_cast<size_t*>(eps);

  for (int i = 0; i < num_ranks; i++) {
    size_t ptr    = size_t_ep_arr[i];
    auto ucp_ep_v = reinterpret_cast<ucp_ep_h*>(*eps_sp);

    if (ptr != 0) {
      auto eps_ptr = reinterpret_cast<ucp_ep_h>(size_t_ep_arr[i]);
      ucp_ep_v[i]  = eps_ptr;
    } else {
      ucp_ep_v[i] = nullptr;
    }
  }

  cudaStream_t stream = handle->get_stream();

  auto communicator =
    std::make_shared<comms_t>(std::unique_ptr<comms_iface>(new raft::comms::std_comms(
      nccl_comm, (ucp_worker_h)ucp_worker, eps_sp, num_ranks, rank, stream)));
  handle->set_comms(communicator);
}