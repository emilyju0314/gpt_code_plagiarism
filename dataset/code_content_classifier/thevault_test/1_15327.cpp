void resize(size_type _size, const value_type& value) { 
        if (_size > size()) {
            insert(end(), _size - size(), value);
        } else {
            erase(begin() + _size, end());
        }
    }