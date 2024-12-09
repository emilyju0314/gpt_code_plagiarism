TEST_F(OpenDirectoryTest, OpenNonExistent) {
  auto dir =
      OpenDirectoryHandle(temp_dir.GetPath().AppendASCII("non_existent"));
  ASSERT_FALSE(dir);
}