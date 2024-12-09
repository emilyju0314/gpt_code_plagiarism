explicit thread_data_reference_counting(
                thread_id_addref addref = thread_id_addref::yes)
              : count_(addref == thread_id_addref::yes)
            {
            }