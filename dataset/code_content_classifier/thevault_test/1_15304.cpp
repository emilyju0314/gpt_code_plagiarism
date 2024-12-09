static bool readBinaryProto(dc::NetParameter* net, const char* file, size_t bufSize)
{
    CHECK_NULL_RET_VAL(net, false);
    CHECK_NULL_RET_VAL(file, false);
    using namespace google::protobuf::io;

    std::ifstream stream(file, std::ios::in | std::ios::binary);
    if (!stream)
    {
        std::cout << "could not open file " << file << std::endl;
        return false;
    }

    IstreamInputStream rawInput(&stream);
    CodedInputStream codedInput(&rawInput);
    codedInput.SetTotalBytesLimit(int(bufSize), -1);

    bool ok = net->ParseFromCodedStream(&codedInput);
    stream.close();

    if (!ok)
    {
        std::cout << "Caffe Parser: could not parse binary model file" << std::endl;
        return false;
    }

    return ok;
}