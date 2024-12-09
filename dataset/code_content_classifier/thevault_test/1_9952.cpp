std_comms(ncclComm_t nccl_comm,
            ucp_worker_h ucp_worker,
            std::shared_ptr<ucp_ep_h*> eps,
            int num_ranks,
            int rank,
            cudaStream_t stream,
            bool subcomms_ucp = true)
    : nccl_comm_(nccl_comm),
      stream_(stream),
      status_(2, stream),
      num_ranks_(num_ranks),
      rank_(rank),
      subcomms_ucp_(subcomms_ucp),
      ucp_worker_(ucp_worker),
      ucp_eps_(eps),
      next_request_id_(0)
  {
    initialize();
  }