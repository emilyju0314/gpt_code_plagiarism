static void CheckBlockDesc(const BlockDesc &d) {
  for (int i = 0; i != d.len; i++) {
    TEST_ASSERT((d.ptr[i] & 0xff) == ((d.fill + i) & 0xff));
  }
}