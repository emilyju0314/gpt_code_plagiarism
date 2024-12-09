std::pair<std::uint32_t, std::uint64_t> CZIP::deflateFile(const std::string &fileName, std::uint64_t fileSize)
    {
        int deflateResult = 0, flushRemainder = 0;
        std::uint64_t bytesDeflated = 0;
        z_stream deflateZIPStream{};
        std::ifstream fileStream(fileName, std::ios::binary);
        std::uint32_t crc;
        std::uint64_t compressedSize = 0;
        if (fileStream.fail())
        {
            throw Exception("Could not open source file for deflate.");
        }
        crc = crc32(0L, Z_NULL, 0);
        deflateResult = deflateInit2(&deflateZIPStream, Z_DEFAULT_COMPRESSION, Z_DEFLATED, -MAX_WBITS, 8, Z_DEFAULT_STRATEGY);
        if (deflateResult != Z_OK)
        {
            throw Exception("deflateInit2() Error = " + std::to_string(deflateResult));
        }
        do
        {
            fileStream.read((char *)&m_zipInBuffer[0], std::min(fileSize, m_zipIOBufferSize));
            if (fileStream.fail() && !fileStream.eof())
            {
                deflateEnd(&deflateZIPStream);
                throw Exception("Error reading source file to deflate.");
            }
            deflateZIPStream.avail_in = fileStream.gcount();
            fileSize -= deflateZIPStream.avail_in;
            crc = crc32(crc, &m_zipInBuffer[0], deflateZIPStream.avail_in);
            flushRemainder = ((fileStream.eof() || fileSize == 0)) ? Z_FINISH : Z_NO_FLUSH;
            deflateZIPStream.next_in = &m_zipInBuffer[0];
            do
            {
                deflateZIPStream.avail_out = m_zipIOBufferSize;
                deflateZIPStream.next_out = &m_zipOutBuffer[0];
                deflateResult = deflate(&deflateZIPStream, flushRemainder); /* no bad return value */
                bytesDeflated = m_zipIOBufferSize - deflateZIPStream.avail_out;
                writeZIPFile(m_zipOutBuffer, bytesDeflated);
                if (errorInZIPFile())
                {
                    deflateEnd(&deflateZIPStream);
                    throw Exception("Error writing deflated data to ZIP archive.");
                }
                compressedSize += bytesDeflated;
            } while (deflateZIPStream.avail_out == 0);
        } while (flushRemainder != Z_FINISH);
        deflateEnd(&deflateZIPStream);
        fileStream.close();
        return (std::make_pair(crc, compressedSize));
    }