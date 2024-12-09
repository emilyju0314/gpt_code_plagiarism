static bool hasLoweredLocalCaptures(AnyFunctionRef AFR,
                                    llvm::DenseSet<AnyFunctionRef> &visited) {
  if (!AFR.getCaptureInfo().hasLocalCaptures())
    return false;
  
  // Scan for local, non-function captures.
  bool functionCapturesToRecursivelyCheck = false;
  auto addFunctionCapture = [&](AnyFunctionRef capture) {
    if (visited.find(capture) == visited.end())
      functionCapturesToRecursivelyCheck = true;
  };
  for (auto &capture : AFR.getCaptureInfo().getCaptures()) {
    if (!capture.getDecl()->getDeclContext()->isLocalContext())
      continue;
    // We transitively capture a local function's captures.
    if (auto func = dyn_cast<AbstractFunctionDecl>(capture.getDecl())) {
      addFunctionCapture(func);
      continue;
    }
    // We may either directly capture properties, or capture through their
    // accessors.
    if (auto var = dyn_cast<VarDecl>(capture.getDecl())) {
      switch (var->getStorageKind()) {
      case VarDecl::StoredWithTrivialAccessors:
        llvm_unreachable("stored local variable with trivial accessors?");

      case VarDecl::InheritedWithObservers:
        llvm_unreachable("inherited local variable?");

      case VarDecl::StoredWithObservers:
      case VarDecl::Addressed:
      case VarDecl::AddressedWithTrivialAccessors:
      case VarDecl::AddressedWithObservers:
      case VarDecl::ComputedWithMutableAddress:
        // Directly capture storage if we're supposed to.
        if (capture.isDirect())
          return true;

        // Otherwise, transitively capture the accessors.
        LLVM_FALLTHROUGH;

      case VarDecl::Computed:
        addFunctionCapture(var->getGetter());
        if (auto setter = var->getSetter())
          addFunctionCapture(setter);
        continue;
      
      case VarDecl::Stored:
        return true;
      }
    }
    // Anything else is directly captured.
    return true;
  }
  
  // Recursively consider function captures, since we didn't have any direct
  // captures.
  auto captureHasLocalCaptures = [&](AnyFunctionRef capture) -> bool {
    if (visited.insert(capture).second)
      return hasLoweredLocalCaptures(capture, visited);
    return false;
  };
  
  if (functionCapturesToRecursivelyCheck) {
    for (auto &capture : AFR.getCaptureInfo().getCaptures()) {
      if (!capture.getDecl()->getDeclContext()->isLocalContext())
        continue;
      if (auto func = dyn_cast<AbstractFunctionDecl>(capture.getDecl())) {
        if (captureHasLocalCaptures(func))
          return true;
        continue;
      }
      if (auto var = dyn_cast<VarDecl>(capture.getDecl())) {
        switch (var->getStorageKind()) {
        case VarDecl::StoredWithTrivialAccessors:
          llvm_unreachable("stored local variable with trivial accessors?");
          
        case VarDecl::InheritedWithObservers:
          llvm_unreachable("inherited local variable?");
          
        case VarDecl::StoredWithObservers:
        case VarDecl::Addressed:
        case VarDecl::AddressedWithTrivialAccessors:
        case VarDecl::AddressedWithObservers:
        case VarDecl::ComputedWithMutableAddress:
          assert(!capture.isDirect() && "should have short circuited out");
          // Otherwise, transitively capture the accessors.
          LLVM_FALLTHROUGH;
          
        case VarDecl::Computed:
          if (captureHasLocalCaptures(var->getGetter()))
            return true;
          if (auto setter = var->getSetter())
            if (captureHasLocalCaptures(setter))
              return true;
          continue;
        
        case VarDecl::Stored:
          llvm_unreachable("should have short circuited out");
        }
      }
      llvm_unreachable("should have short circuited out");
    }
  }
  
  return false;
}