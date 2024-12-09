FunctionPass* CreatePatchPeepholeOpt(
    bool enableDiscardOpt) // Enable the optimization for "kill" intrinsic
{
    return new PatchPeepholeOpt(enableDiscardOpt);
}