bool PatchSetupTargetFeatures::runOnModule(
    Module& module)  // [in,out] LLVM module to be run on
{
    LLVM_DEBUG(dbgs() << "Run the pass Patch-Setup-Target-Features\n");

    Patch::Init(&module);

    CodeGenManager::SetupTargetFeatures(&module);

    return true; // Modified the module.
}