std::string
InterfaceSubContextDelegateImpl::getCacheHash(StringRef useInterfacePath) {
  auto normalizedTargetTriple =
      getTargetSpecificModuleTriple(genericSubInvocation.getLangOptions().Target);

  llvm::hash_code H = hash_combine(
      // Start with the compiler version (which will be either tag names or
      // revs). Explicitly don't pass in the "effective" language version --
      // this would mean modules built in different -swift-version modes would
      // rebuild their dependencies.
      swift::version::getSwiftFullVersion(),

      // Simplest representation of input "identity" (not content) is just a
      // pathname, and probably all we can get from the VFS in this regard
      // anyways.
      useInterfacePath,

      // Include the normalized target triple. In practice, .swiftinterface
      // files will be in target-specific subdirectories and would have
      // target-specific pieces #if'd out. However, it doesn't hurt to include
      // it, and it guards against mistakenly reusing cached modules across
      // targets. Note that this normalization explicitly doesn't include the
      // minimum deployment target (e.g. the '12.0' in 'ios12.0').
      normalizedTargetTriple.str(),

      // The SDK path is going to affect how this module is imported, so
      // include it.
      genericSubInvocation.getSDKPath(),

      // Whether or not we're tracking system dependencies affects the
      // invalidation behavior of this cache item.
      genericSubInvocation.getFrontendOptions().shouldTrackSystemDependencies(),

      // Whether or not OSSA modules are enabled.
      //
      // If OSSA modules are enabled, we use a separate namespace of modules to
      // ensure that we compile all swift interface files with the option set.
      unsigned(genericSubInvocation.getSILOptions().EnableOSSAModules));

  return llvm::toString(llvm::APInt(64, H), 36, /*Signed=*/false);
}