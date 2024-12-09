TEST(PdbFileDiaTest, CreatePdbDoesNotFailOnCoInitializeWhenAlreadyInitialized) {
  std::filesystem::path file_path_pdb = orbit_test::GetTestdataDir() / "dllmain.pdb";
  HRESULT result = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
  ASSERT_TRUE(result == S_OK || result == S_FALSE);
  ErrorMessageOr<std::unique_ptr<PdbFile>> pdb_file_result1 =
      PdbFileDia::CreatePdbFile(file_path_pdb, ObjectFileInfo{0x180000000, 0x1000});
  ASSERT_THAT(pdb_file_result1, HasNoError());
  CoUninitialize();
}