std::error_code ModuleInterfaceLoader::findModuleFilesInDirectory(
  ImportPath::Element ModuleID,
  const SerializedModuleBaseName &BaseName,
  SmallVectorImpl<char> *ModuleInterfacePath,
  std::unique_ptr<llvm::MemoryBuffer> *ModuleBuffer,
  std::unique_ptr<llvm::MemoryBuffer> *ModuleDocBuffer,
  std::unique_ptr<llvm::MemoryBuffer> *ModuleSourceInfoBuffer,
  bool skipBuildingInterface, bool IsFramework) {

  // If running in OnlySerialized mode, ModuleInterfaceLoader
  // should not have been constructed at all.
  assert(LoadMode != ModuleLoadingMode::OnlySerialized);

  llvm::SmallString<256>
  ModPath{ BaseName.getName(file_types::TY_SwiftModuleFile) },
  InPath{  BaseName.getName(file_types::TY_SwiftModuleInterfaceFile) },
  PrivateInPath{BaseName.getName(file_types::TY_PrivateSwiftModuleInterfaceFile)};

  // First check to see if the .swiftinterface exists at all. Bail if not.
  auto &fs = *Ctx.SourceMgr.getFileSystem();
  if (!fs.exists(InPath)) {
    if (fs.exists(ModPath)) {
      LLVM_DEBUG(llvm::dbgs()
        << "No .swiftinterface file found adjacent to module file "
        << ModPath.str() << "\n");
      return std::make_error_code(std::errc::not_supported);
    }
    return std::make_error_code(std::errc::no_such_file_or_directory);
  }

  // If present, use the private interface instead of the public one.
  if (fs.exists(PrivateInPath)) {
    InPath = PrivateInPath;
  }

  // If we've been told to skip building interfaces, we are done here and do
  // not need to have the module actually built. For example, if we are
  // currently answering a `canImport` query, it is enough to have found
  // the interface.
  if (skipBuildingInterface) {
    if (ModuleInterfacePath)
      *ModuleInterfacePath = InPath;
    return std::error_code();
  }

  // Create an instance of the Impl to do the heavy lifting.
  auto ModuleName = ModuleID.Item.str();
  ModuleInterfaceLoaderImpl Impl(
      Ctx, ModPath, InPath, ModuleName, InterfaceChecker.CacheDir,
      InterfaceChecker.PrebuiltCacheDir, InterfaceChecker.BackupInterfaceDir,
      ModuleID.Loc, InterfaceChecker.Opts,
      InterfaceChecker.RequiresOSSAModules, dependencyTracker,
      llvm::is_contained(PreferInterfaceForModules, ModuleName)
          ? ModuleLoadingMode::PreferInterface
          : LoadMode);

  // Ask the impl to find us a module that we can load or give us an error
  // telling us that we couldn't load it.
  auto ModuleBufferOrErr = Impl.findOrBuildLoadableModule();
  if (!ModuleBufferOrErr)
    return ModuleBufferOrErr.getError();

  if (ModuleBuffer) {
    *ModuleBuffer = std::move(*ModuleBufferOrErr);
    if (ModuleInterfacePath)
      *ModuleInterfacePath = InPath;
  }

  // Open .swiftsourceinfo file if it's present.
  if (auto SourceInfoError = openModuleSourceInfoFileIfPresent(ModuleID,
                                                               BaseName,
                                                       ModuleSourceInfoBuffer))
    return SourceInfoError;

  // Delegate back to the serialized module loader to load the module doc.
  if (auto DocLoadErr = openModuleDocFileIfPresent(ModuleID, BaseName,
                                                   ModuleDocBuffer))
    return DocLoadErr;

  return std::error_code();
}