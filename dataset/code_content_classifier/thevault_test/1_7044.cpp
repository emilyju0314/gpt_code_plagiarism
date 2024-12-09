TEST(Utils, read_write_file_success) {
  char buf[256];
  char tdir[32] = "utiltestXXXXXX";
  EXPECT_TRUE(mkdtemp(tdir) != NULL);
  char tfile[64];
  snprintf(tfile, sizeof(tfile), "%s/%s", tdir, "readfiletest");
  EXPECT_GT(write_to_file(tfile, "foobar\nmagic"), 0);
  EXPECT_NE(-1, read_file_as_string(tfile, buf, sizeof(buf)));
  remove(tfile);
  rmdir(tdir);
  EXPECT_STREQ("foobar\nmagic", buf);
}