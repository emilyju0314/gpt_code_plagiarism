string Parallel_File_Token_Stream::location_() const {
  ostringstream Result;
  if (letter_ != nullptr) {
    Result << letter_->filename_ << ", line " << line();
  } else {
    return "\"\", line 0";
  }
  return Result.str();
}