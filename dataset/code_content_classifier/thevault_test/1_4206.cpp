unsigned BufferedPacket
::nextEnclosedFrameSize(unsigned char*& /*framePtr*/, unsigned dataSize) {
    // By default, use the entire buffered data, even though it may consist
    // of more than one frame, on the assumption that the client doesn't
    // care.  (This is more efficient than delivering a frame at a time)
    return dataSize;
}