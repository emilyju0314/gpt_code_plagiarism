void build_comms_nccl_only(handle_t* handle, ncclComm_t nccl_comm, int num_ranks, int rank)
{
  cudaStream_t stream = handle->get_stream();

  auto communicator = std::make_shared<comms_t>(
    std::unique_ptr<comms_iface>(new raft::comms::std_comms(nccl_comm, num_ranks, rank, stream)));
  handle->set_comms(communicator);
}