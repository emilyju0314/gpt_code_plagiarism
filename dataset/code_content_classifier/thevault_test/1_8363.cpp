GenericMsg(const unsigned int length, const uint8_t* data):
        length_(length),
        data_(new uint8_t[length_])
    {
        std::copy(&data[0], &data[length_], data_);
    }