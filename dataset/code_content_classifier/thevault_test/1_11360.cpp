message_array(size_t num_vertices = 0) :
              message_vector(num_vertices) { 
      for (size_t i = 0; i < 65536; ++i) {
        joincounter[i] = 0; 
        addcounter[i] = 0;
      }
    }