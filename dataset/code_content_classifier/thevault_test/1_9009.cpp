void Sema::ProcessDeclAttributeList(Scope *S, Decl *D,
                                    const ParsedAttributesView &AttrList,
                                    bool IncludeCXX11Attributes) {
  if (AttrList.empty())
    return;

  for (const ParsedAttr &AL : AttrList)
    ProcessDeclAttribute(*this, S, D, AL, IncludeCXX11Attributes);

  // FIXME: We should be able to handle these cases in TableGen.
  // GCC accepts
  // static int a9 __attribute__((weakref));
  // but that looks really pointless. We reject it.
  if (D->hasAttr<WeakRefAttr>() && !D->hasAttr<AliasAttr>()) {
    Diag(AttrList.begin()->getLoc(), diag::err_attribute_weakref_without_alias)
        << cast<NamedDecl>(D);
    D->dropAttr<WeakRefAttr>();
    return;
  }

  // FIXME: We should be able to handle this in TableGen as well. It would be
  // good to have a way to specify "these attributes must appear as a group",
  // for these. Additionally, it would be good to have a way to specify "these
  // attribute must never appear as a group" for attributes like cold and hot.
  if (!D->hasAttr<OpenCLKernelAttr>()) {
    // These attributes cannot be applied to a non-kernel function.
    if (const auto *A = D->getAttr<ReqdWorkGroupSizeAttr>()) {
      // FIXME: This emits a different error message than
      // diag::err_attribute_wrong_decl_type + ExpectedKernelFunction.
      Diag(D->getLocation(), diag::err_opencl_kernel_attr) << A;
      D->setInvalidDecl();
    } else if (const auto *A = D->getAttr<WorkGroupSizeHintAttr>()) {
      Diag(D->getLocation(), diag::err_opencl_kernel_attr) << A;
      D->setInvalidDecl();
    } else if (const auto *A = D->getAttr<VecTypeHintAttr>()) {
      Diag(D->getLocation(), diag::err_opencl_kernel_attr) << A;
      D->setInvalidDecl();
    } else if (const auto *A = D->getAttr<OpenCLIntelReqdSubGroupSizeAttr>()) {
      Diag(D->getLocation(), diag::err_opencl_kernel_attr) << A;
      D->setInvalidDecl();
    } else if (!D->hasAttr<CUDAGlobalAttr>()) {
      if (const auto *A = D->getAttr<AMDGPUFlatWorkGroupSizeAttr>()) {
        Diag(D->getLocation(), diag::err_attribute_wrong_decl_type)
            << A << ExpectedKernelFunction;
        D->setInvalidDecl();
      } else if (const auto *A = D->getAttr<AMDGPUWavesPerEUAttr>()) {
        Diag(D->getLocation(), diag::err_attribute_wrong_decl_type)
            << A << ExpectedKernelFunction;
        D->setInvalidDecl();
      } else if (const auto *A = D->getAttr<AMDGPUNumSGPRAttr>()) {
        Diag(D->getLocation(), diag::err_attribute_wrong_decl_type)
            << A << ExpectedKernelFunction;
        D->setInvalidDecl();
      } else if (const auto *A = D->getAttr<AMDGPUNumVGPRAttr>()) {
        Diag(D->getLocation(), diag::err_attribute_wrong_decl_type)
            << A << ExpectedKernelFunction;
        D->setInvalidDecl();
      }
    }
  }

  // Do this check after processing D's attributes because the attribute
  // objc_method_family can change whether the given method is in the init
  // family, and it can be applied after objc_designated_initializer. This is a
  // bit of a hack, but we need it to be compatible with versions of clang that
  // processed the attribute list in the wrong order.
  if (D->hasAttr<ObjCDesignatedInitializerAttr>() &&
      cast<ObjCMethodDecl>(D)->getMethodFamily() != OMF_init) {
    Diag(D->getLocation(), diag::err_designated_init_attr_non_init);
    D->dropAttr<ObjCDesignatedInitializerAttr>();
  }
}