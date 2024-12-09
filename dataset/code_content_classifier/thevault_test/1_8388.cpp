StringRef InterfaceSubContextDelegateImpl::computeCachedOutputPath(
                             StringRef moduleName,
                             StringRef useInterfacePath,
                             llvm::SmallString<256> &OutPath,
                             StringRef &CacheHash) {
  OutPath = genericSubInvocation.getClangModuleCachePath();
  llvm::sys::path::append(OutPath, moduleName);
  OutPath.append("-");
  auto hashStart = OutPath.size();
  OutPath.append(getCacheHash(useInterfacePath));
  CacheHash = OutPath.str().substr(hashStart);
  OutPath.append(".");
  auto OutExt = file_types::getExtension(file_types::TY_SwiftModuleFile);
  OutPath.append(OutExt);
  return OutPath.str();
}