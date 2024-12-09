Master(mpi::communicator    comm,          //!< communicator
                           int                  threads__ = 1,  //!< number of threads DIY can use
                           int                  limit__   = -1, //!< number of blocks to store in memory
                           CreateBlock          create_   = 0,  //!< block create function; master manages creation if create != 0
                           DestroyBlock         destroy_  = 0,  //!< block destroy function; master manages destruction if destroy != 0
                           ExternalStorage*     storage   = 0,  //!< storage object (path, method, etc.) for storing temporary blocks being shuffled in/out of core
                           SaveBlock            save      = 0,  //!< block save function; master manages saving if save != 0
                           LoadBlock            load_     = 0,  //!< block load function; master manages loading if load != 0
                           QueuePolicy*         q_policy  = new QueueSizePolicy(4096)): //!< policy for managing message queues specifies maximum size of message queues to keep in memory
                      blocks_(create_, destroy_, storage, save, load_),
                      queue_policy_(q_policy),
                      limit_(limit__),
                      threads_(threads__ == -1 ? static_cast<int>(thread::hardware_concurrency()) : threads__),
                      storage_(storage),
                      // Communicator functionality
                      comm_(comm),
                      expected_(0),
                      exchange_round_(-1),
                      immediate_(true)
                                                        {}