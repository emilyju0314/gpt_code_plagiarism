static void png_read_data(png_structp png_ptr, png_bytep data, png_size_t length)
{
  std::istream* stream = (std::istream*)png_get_io_ptr(png_ptr);
  stream->read((char*)data, length);
  if (stream->fail() || stream->eof()) png_error(png_ptr, "Read Error");
}