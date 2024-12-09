bool ts::DVBCharsetUTF8::decode(UString& str, const uint8_t* dvb, size_t dvbSize) const
{
    str = UString::FromUTF8(reinterpret_cast<const char*>(dvb), dvbSize);
    return true;
}