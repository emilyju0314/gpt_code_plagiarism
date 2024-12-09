explicit vector(Allocator const& alloc = Allocator())
          // C++-14, delegating ctor version:
          // vector() : vector(Allocator()) {}
          // explicit vector(Allocator const& alloc)
          : size_(0)
          , capacity_(0)
          , alloc_(alloc)
          , data_()
        {
        }