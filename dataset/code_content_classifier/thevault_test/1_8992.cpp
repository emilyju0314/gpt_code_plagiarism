System::System (std::initializer_list<int> dim_list)
    {
        if (std::any_of(std::begin(dim_list), std::end(dim_list), 
            [](int i) { return i <= 0; }))
            throw std::exception();

        dimensions_ = std::vector<int>(dim_list);
        setDefaultParameters();
    }