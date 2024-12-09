Elf_Ehdr* findElfHeader() {
  int fd = open("/proc/self/exe", O_RDONLY);
  if (fd < 0) return nullptr;
  struct stat fd_stat;
  if (fstat(fd, &fd_stat) < 0) return nullptr;
  void* result = mmap(nullptr, fd_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (result == MAP_FAILED) return nullptr;
  return (Elf_Ehdr*)result;
}