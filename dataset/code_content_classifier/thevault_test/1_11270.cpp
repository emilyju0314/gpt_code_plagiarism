inline void pop_front_and_free() {
     if (!empty()) {
       if (front() != NULL) zmq_msg_close(&msgs.front());
       pop_front();
       // shift the read index if it not already at the head
       read_index -= (read_index > 0);
     }
   }