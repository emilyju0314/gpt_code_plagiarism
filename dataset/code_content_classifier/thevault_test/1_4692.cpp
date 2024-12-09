TEST(PdbFileDiaTest, PdbFileProperlyUninitializesComLibrary) {
  std::filesystem::path file_path_pdb = orbit_test::GetTestdataDir() / "dllmain.pdb";
  {
    ErrorMessageOr<std::unique_ptr<PdbFile>> pdb_file_result =
        PdbFileDia::CreatePdbFile(file_path_pdb, ObjectFileInfo{0x180000000, 0x1000});
    ASSERT_THAT(pdb_file_result, HasNoError());
  }

  HRESULT result = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
  // This would be S_FALSE if the PdbFileDia class didn't properly balance its CoInitialize() call.
  ASSERT_EQ(result, S_OK);
  CoUninitialize();
}