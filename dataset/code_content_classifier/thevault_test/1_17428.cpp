explicit plaintext_input_iterator(std::basic_streambuf<char> & ibuf, bool const read_first_record = true) :
      stream_buf{reinterpret_cast<bio::detail::stream_buffer_exposer<char> *>(&ibuf)}
    {
        init(read_first_record);
    }