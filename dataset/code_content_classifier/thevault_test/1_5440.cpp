void function::add_buffer(std::pair < std::string, tiramisu::buffer * > buf)
{
        assert(!buf.first.empty() && ("Empty buffer name."));
        assert((buf.second != NULL) && ("Empty buffer."));

        this->buffers_list.insert(buf);
}