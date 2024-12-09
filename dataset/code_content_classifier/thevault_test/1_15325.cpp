void pop_back() {
    # ifdef AMI_STL_STRICT_MODE
        if (empty()) __THROW_OUT_OF_BOUNDS;
    # endif
        AMI_std::destroy(__map_end);
        __map_end--;
    # ifdef AMI_STL_MEM_SAVING
        if (capacity() > size() * 4) {
            this->__shrink();
        }
    # endif
    }