StdMpi(MPI::Intracomm& comm, bool b = true) :
        mpiComm(comm),
        commPrepared(true),
        exchangeDataSize(b)
      {}