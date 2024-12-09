bool ts::UString::hexaDecode(ts::ByteBlock& result) const
{
    result.clear();
    return hexaDecodeAppend(result);
}