void LinearScan::SetContainsAVXFlags(unsigned sizeOfSIMDVector /* = 0*/)
{
    if (compiler->canUseVexEncoding())
    {
        compiler->compExactlyDependsOn(InstructionSet_AVX);
        compiler->GetEmitter()->SetContainsAVX(true);
        if (sizeOfSIMDVector == 32)
        {
            compiler->GetEmitter()->SetContains256bitAVX(true);
        }
    }
}