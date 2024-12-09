hmm(std::istream & in) {
        if (!this->deserialise(in))
            throw std::runtime_error(
                "math::hmm: deserialisation failed");
    }