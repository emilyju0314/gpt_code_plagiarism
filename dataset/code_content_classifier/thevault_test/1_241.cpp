ghmm(std::istream & in) {
        if (!this->deserialise(in))
            throw std::runtime_error(
                "math::ghmm: deserialisation failed");
    }