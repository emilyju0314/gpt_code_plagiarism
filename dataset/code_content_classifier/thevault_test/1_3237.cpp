bool UncompressAndWriteFile(const char *filename, const unsigned char *data, size_t len)
{
	z_stream zs = {0};
	if (inflateInit(&zs) != Z_OK)
		return false;

	zs.next_in = (unsigned char *)data;   // input buffer is the whole thing
	zs.avail_in = len;
	try
	{
		unsigned char out_data[1024];  // where uncompressed data is buffered before writing

		CFile64 ff(filename, CFile::modeCreate|CFile::modeWrite|CFile::shareExclusive|CFile::typeBinary);
		do
		{
			// Prepare output buffer
			zs.next_out = out_data;
			zs.avail_out = sizeof(out_data);

			if (inflate(&zs, Z_NO_FLUSH) > Z_STREAM_END)
			{
				// Some sort of zlib decompression error
				ff.Close();
				::remove(filename);  // no point in leaving a partial/empty file around
				return false;
			}

			ff.Write(out_data, sizeof(out_data) - zs.avail_out);  // write all that we got
		} while (zs.avail_in != 0);  // if output buffer is full there may be more

		ff.Close();
	}
	catch (CFileException *pfe)
	{
		// Some sort of error opening or writing to the file
		pfe->Delete();
		return false;
	}
	return true;
}