TEST_F(OpenDirectoryTest, OpenFile) {
  auto file_path = temp_dir.GetPath().AppendASCII("test_file");
  ASSERT_TRUE(WriteFile(file_path, "foo"));
  auto dir = OpenDirectoryHandle(file_path);
  ASSERT_FALSE(dir);
}