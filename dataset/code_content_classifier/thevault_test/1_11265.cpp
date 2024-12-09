inline zmq_msg_t* read_next() {
     if (read_index >= size()) return NULL;
     zmq_msg_t* ret = &msgs[read_index];
     ++read_index;
     return ret;
   }