inline zmq_msg_t* insert_front(const void* c, size_t len) {
     zmq_msg_t* msg = insert_front();
     if (len > 0) {
       zmq_msg_init_size(msg, len);
       memcpy(zmq_msg_data(msg), c, len);
     } else {
       zmq_msg_init(msg);
     }
     return msg;
   }