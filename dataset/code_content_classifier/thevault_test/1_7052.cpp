v8::Handle<v8::Value> ReadFile(const char* name) {
  int fd = open(name, O_RDONLY);
  if (fd < 0) return ErrnoException(name, errno);

  struct stat st;
  if (fstat(fd, &st) < 0) return ErrnoException("fstat", errno);
  if (!S_ISREG(st.st_mode)) {
    return ErrnoException("not a regular file", EINVAL);
  }

  errno = 0;
  off_t size = lseek(fd, 0, SEEK_END);
  if (errno) return ErrnoException("lseek(end)", errno);
  lseek(fd, 0, SEEK_SET);
  if (errno) return ErrnoException("lseek(0)", errno);

  char* chars = new char[size + 1];
  int nread = 0;
  while (nread < size) {
    int got = read(fd, &chars[nread], size - nread);
    if (got < 0) {
      int errnum = errno;
      delete[] chars;
      return ErrnoException("read", errnum);
    } else if (!got) {
      break;
    }
    nread += got;
  }
  chars[nread] = 0;
  close(fd);
  v8::Handle<v8::String> result = v8::String::New(chars, size);
  delete[] chars;
  return result;
}