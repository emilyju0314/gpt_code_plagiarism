bool ts::StreamEventDescriptor::asciiPrivate() const
{
    bool ascii = !private_data.empty();
    for (size_t i = 0; ascii && i < private_data.size(); ++i) {
        ascii = private_data[i] >= 0x20 && private_data[i] < 0x80;
    }
    return ascii;
}