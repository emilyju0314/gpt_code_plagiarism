inline void insert_back(zmq_msg_t& msg) {
     zmq_msg_t* front = insert_back();
     zmq_msg_init(front);
     zmq_msg_copy(front, &msg);
   }