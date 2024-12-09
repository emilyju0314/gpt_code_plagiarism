void UnicodeText::Repr::clear() {
  if (ours_)
    delete[] data_;
  data_ = nullptr;
  size_ = capacity_ = 0;
  ours_ = true;
}