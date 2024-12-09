void push_back(const value_type &value) {
        if (capacity() < size() + 1) {
            this->__enlarge();
        }
        AMI_std::construct(__map_end, value);
        __map_end++;
    }