void RubyTest(string proto_file) {
  std::string ruby_tests = FindRubyTestDir();

  google::protobuf::compiler::CommandLineInterface cli;
  cli.SetInputsAreProtoPathRelative(true);

  ruby::Generator ruby_generator;
  cli.RegisterGenerator("--ruby_out", &ruby_generator, "");

  // Copy generated_code.proto to the temporary test directory.
  std::string test_input;
  GOOGLE_CHECK_OK(File::GetContents(
      ruby_tests + proto_file + ".proto",
      &test_input,
      true));
  GOOGLE_CHECK_OK(File::SetContents(
      TestTempDir() + proto_file + ".proto",
      test_input,
      true));

  // Invoke the proto compiler (we will be inside TestTempDir() at this point).
  std::string ruby_out = "--ruby_out=" + TestTempDir();
  std::string proto_path = "--proto_path=" + TestTempDir();
  std::string proto_target = TestTempDir() + proto_file + ".proto";
  const char* argv[] = {
    "protoc",
    ruby_out.c_str(),
    proto_path.c_str(),
    proto_target.c_str(),
  };

  EXPECT_EQ(0, cli.Run(4, argv));

  // Load the generated output and compare to the expected result.
  std::string output;
  GOOGLE_CHECK_OK(File::GetContentsAsText(
      TestTempDir() + proto_file + "_pb.rb",
      &output,
      true));
  std::string expected_output;
  GOOGLE_CHECK_OK(File::GetContentsAsText(
      ruby_tests + proto_file + "_pb.rb",
      &expected_output,
      true));
  EXPECT_EQ(expected_output, output);
}