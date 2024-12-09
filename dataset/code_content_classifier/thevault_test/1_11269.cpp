inline void assert_pop_front(const void* c, size_t len) {
     assert(!empty());
     assert(zmq_msg_size(&msgs[0]) == len);
     if (len > 0) {
       assert(memcmp(zmq_msg_data(&msgs[0]), c, len) == 0);
     }
     pop_front_and_free();
   }