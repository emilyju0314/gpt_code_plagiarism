iterator erase(iterator pos) {
    # ifdef AMI_STL_STRICT_MODE
        if (empty()) __THROW_OUT_OF_BOUNDS;
    # endif
        size_type relative = pos - __map_begin;
        if (pos + 1 != end()) {
            AMI_std::copy(pos + 1, end(), pos);
        }
        AMI_std::destroy(__map_end--);
    # ifdef AMI_STL_MEM_SAVING
        if (capacity() > size() * 4) {
            this->__shrink();
        }
    # endif
        return __map_begin + relative;
    }