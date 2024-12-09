inline void pop_front() {
     if (!empty()) {
       msgs.pop_front();
       // shift the read index if it not already at the head
       read_index -= (read_index > 0);
     }
   }