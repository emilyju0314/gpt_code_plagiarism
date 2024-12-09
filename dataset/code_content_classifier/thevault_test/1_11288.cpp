flexible_type sum(std::shared_ptr<unity_sarray> unity_data){
    log_func_entry();

    if (unity_data->size() > 0){
      bool failure = false;
      size_t reference_size;
      size_t failure_size; 
      auto reductionfn =
        [&failure, &reference_size, &failure_size]
        (const flexible_type& in, std::pair<bool, flexible_type>& sum)->bool {
          if (in.get_type() != flex_type_enum::UNDEFINED) {
            flexible_type tmp_img = in;
            image_util_detail::decode_image_impl(tmp_img.mutable_get<flex_image>());
            flexible_type f(flex_type_enum::VECTOR);
            f.soft_assign(tmp_img);
            if (sum.first == false) {
              // initial val
              sum.first = true;
              sum.second = f;
            } else if (sum.second.size() == f.size()) {
              // accumulation
              sum.second += f;
            } else {
              // length mismatch. fail
              failure = true;
              reference_size = sum.second.size();
              failure_size = f.size();
              return false;
            }
          }
          return true;
        };

      auto combinefn =
        [&failure, &reference_size, &failure_size]
        (const std::pair<bool, flexible_type>& f, 
         std::pair<bool, flexible_type>& sum)->bool {
          if (sum.first == false) {
            // initial state
            sum = f;
          } else if (f.first == false) {
            // there is no f to add.
            return true;
          } else if (sum.second.size() == f.second.size()) {
            // accumulation
            sum.second += f.second;
          } else {
            // length mismatch
            failure = true;
            reference_size = sum.second.size();
            failure_size = f.second.size();
            return false;
          }
          return true;
        };
      std::pair<bool, flexible_type> start_val{false, flex_vec()};
      std::pair<bool, flexible_type> sum_val =
        query_eval::reduce<std::pair<bool, flexible_type>>(unity_data->get_planner_node(), 
                                                           reductionfn, 
                                                           combinefn, 
                                                           start_val);

      if(failure){
        std::string error = 
            std::string("Cannot perform sum or average over images of different sizes. ")
            + std::string("Found images of total size (ie. width * height * channels) ")
            + std::string(" of both ") + std::to_string(reference_size) 
            + std::string( "and ") + std::to_string(failure_size) 
            + std::string(". Please use graplab.image_analysis.resize() to make images a uniform") 
            + std::string(" size.");
        log_and_throw(error);
      }
      return sum_val.second;
    }

    log_and_throw("Input image sarray is empty");
    __builtin_unreachable();
  }