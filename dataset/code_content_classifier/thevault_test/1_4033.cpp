BytePSCommSocket::BytePSCommSocket(std::shared_ptr<BytePSComm> comm,
                                   const std::string &path_suffix,
                                   const std::vector<int> &members) {
    std::shared_ptr<BytePSCommSocket> sock_comm = std::static_pointer_cast<BytePSCommSocket>(comm);
    // TODO: use private members directly
    _rank = sock_comm->getRank();
    _size = sock_comm->getSize();
    _local_rank = sock_comm->getLocalRank();
    _local_size = sock_comm->getLocalSize();
    _worker_id = sock_comm->getWorkerID();
    _send_path = sock_comm->getSendPath() + path_suffix;
    _recv_path = sock_comm->getRecvPath() + path_suffix;
    _send_fd = initSocket(_local_rank, _send_path);
    _recv_fd = initSocket(_local_rank, _recv_path);

    _members = (members.size() > 0) ? members : sock_comm->getMembers();
    _root = _members.back();

    auto my_role = (_local_rank == _root) ? LOCAL_ROOT : LOCAL_WORKER;
    bool is_root = (my_role == LOCAL_ROOT) ? true : false;
    // init socket comm
    if (is_root) { // root
        _listen_thread = new std::thread(&BytePSCommSocket::startListenThread, this);
    }

    BPS_LOG(DEBUG) << "This is " << path_suffix << (is_root ? " ROOT" : " WORKER")
                   << " device, rank=" << _local_rank
                   << ", all sockets create successfully";
}