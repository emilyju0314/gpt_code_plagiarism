SizeType GenericStream::WriteFromStream(SizeType bytes, GenericStream* inputStream)
        {
            char tempBuffer[StreamToStreamCopyBufferSize];
            SizeType totalBytesWritten = 0;

            AZ_Assert(inputStream, "Cannot copy from a null input stream.");
            AZ_Assert(inputStream != this, "Can't write and read from the same stream.");

            // Loop through the total number of bytes requested, reading a chunk of it at a time from the inputStream
            // into tempBuffer, then writing it out into this stream.
            for (SizeType windowOffset = 0; windowOffset < bytes; windowOffset += StreamToStreamCopyBufferSize)
            {
                // Read in the appropriate number of bytes on every loop iteration.
                // (ex:  515 bytes requested will read 256 bytes, 256 bytes, and 3 bytes)
                SizeType transferBytes = AZ::GetMin(bytes - windowOffset, aznumeric_cast<SizeType>(StreamToStreamCopyBufferSize));

                SizeType bytesRead = inputStream->Read(transferBytes, tempBuffer);
                if (bytesRead > 0)
                {
                    totalBytesWritten += Write(bytesRead, tempBuffer);
                }
            }

            return totalBytesWritten;
        }