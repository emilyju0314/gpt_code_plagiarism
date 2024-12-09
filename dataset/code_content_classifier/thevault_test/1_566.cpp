op_base(perform_func_type perform_func, complete_func_type complete_func,
        destroy_func_type destroy_func, Descriptor descriptor)
      : perform_func_(perform_func),
        complete_func_(complete_func),
        destroy_func_(destroy_func),
        descriptor_(descriptor),
        result_(),
        bytes_transferred_(0),
        next_(0)
    {
    }