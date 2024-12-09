std::uint32_t CZIP::inflateFile(const std::string &fileName, std::uint64_t fileSize)
    {
        int inflateResult = Z_OK;
        std::uint64_t inflatedBytes = 0;
        z_stream inlateZIPStream{};
        std::ofstream fileStream(fileName, std::ios::binary | std::ios::trunc);
        std::uint32_t crc;
        if (fileStream.fail())
        {
            throw Exception("Could not open destination file for inflate.");
        }
        crc = crc32(0L, Z_NULL, 0);
        if (fileSize == 0)
        {
            return (crc);
        }
        inflateResult = inflateInit2(&inlateZIPStream, -MAX_WBITS);
        if (inflateResult != Z_OK)
        {
            throw Exception("inflateInit2() Error = " + std::to_string(inflateResult));
        }
        do
        {
            readZIPFile(m_zipInBuffer, std::min(fileSize, m_zipIOBufferSize));
            if (errorInZIPFile())
            {
                inflateEnd(&inlateZIPStream);
                throw Exception("Error reading ZIP archive file during inflate.");
            }
            inlateZIPStream.avail_in = readCountZIPFile();
            if (inlateZIPStream.avail_in == 0)
            {
                break;
            }
            inlateZIPStream.next_in = (Bytef *)&m_zipInBuffer[0];
            do
            {
                inlateZIPStream.avail_out = m_zipIOBufferSize;
                inlateZIPStream.next_out = (Bytef *)&m_zipOutBuffer[0];
                inflateResult = inflate(&inlateZIPStream, Z_NO_FLUSH);
                switch (inflateResult)
                {
                case Z_NEED_DICT:
                    inflateResult = Z_DATA_ERROR;
                    inflateEnd(&inlateZIPStream);
                    throw Exception("Error inflating ZIP archive. = " + std::to_string(inflateResult));
                case Z_DATA_ERROR:
                case Z_MEM_ERROR:
                    inflateEnd(&inlateZIPStream);
                    throw Exception("Error inflating ZIP archive. = " + std::to_string(inflateResult));
                }
                inflatedBytes = m_zipIOBufferSize - inlateZIPStream.avail_out;
                fileStream.write((char *)&m_zipOutBuffer[0], inflatedBytes);
                if (fileStream.fail())
                {
                    inflateEnd(&inlateZIPStream);
                    throw Exception("Error writing to file during inflate.");
                }
                crc = crc32(crc, &m_zipOutBuffer[0], inflatedBytes);
            } while (inlateZIPStream.avail_out == 0);
            fileSize -= m_zipIOBufferSize;
        } while (inflateResult != Z_STREAM_END);
        inflateEnd(&inlateZIPStream);
        return (crc);
    }