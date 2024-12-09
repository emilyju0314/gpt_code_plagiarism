void AddXCTestFilesToTestModuleTarget(const SourceFileSet& xctest_file_list,
                                      PBXNativeTarget* native_target,
                                      PBXProject* project,
                                      SourceDir source_dir,
                                      const BuildSettings* build_settings) {
  for (const SourceFile& source : xctest_file_list) {
    std::string source_path = RebasePath(source.value(), source_dir,
                                         build_settings->root_path_utf8());

    // Test files need to be known to Xcode for proper indexing and for
    // discovery of tests function for XCTest and XCUITest, but the compilation
    // is done via ninja and thus must prevent Xcode from compiling the files by
    // adding '-help' as per file compiler flag.
    project->AddSourceFile(source_path, source_path, CompilerFlags::HELP,
                           native_target);
  }
}