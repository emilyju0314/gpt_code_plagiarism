TEST(ContentUriUtilsTest, DISABLED_ContentUriMimeTest) {
  // Get the test image path.
  FilePath data_dir;
  ASSERT_TRUE(PathService::Get(DIR_TEST_DATA, &data_dir));
  data_dir = data_dir.AppendASCII("file_util");
  ASSERT_TRUE(PathExists(data_dir));
  FilePath image_file = data_dir.Append(FILE_PATH_LITERAL("red.png"));

  // Insert the image into MediaStore. MediaStore will do some conversions, and
  // return the content URI.
  FilePath path = base::InsertImageIntoMediaStore(image_file);
  EXPECT_TRUE(path.IsContentUri());
  EXPECT_TRUE(PathExists(path));

  std::string mime = GetContentUriMimeType(path);
  EXPECT_EQ(mime, std::string("image/png"));

  FilePath invalid_path("content://foo.bar");
  mime = GetContentUriMimeType(invalid_path);
  EXPECT_TRUE(mime.empty());
}