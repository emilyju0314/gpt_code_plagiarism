inline void insert_front(zmq_msg_t& msg) {
     zmq_msg_t* front = insert_front();
     zmq_msg_init(front);
     zmq_msg_copy(front, &msg);
   }