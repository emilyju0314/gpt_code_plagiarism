inline void clear() {
     for (size_t i = 0;i < msgs.size(); ++i) {
       zmq_msg_close(&msgs[i]);
     }
     msgs.clear();
     read_index = 0;
   }