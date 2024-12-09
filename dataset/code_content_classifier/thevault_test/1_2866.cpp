void LinearScan::SetContainsAVXFlags(unsigned sizeOfSIMDVector /* = 0*/)
{
    if (compiler->canUseVexEncoding())
    {
        compiler->getEmitter()->SetContainsAVX(true);
        if (sizeOfSIMDVector == 32)
        {
            compiler->getEmitter()->SetContains256bitAVX(true);
        }
    }
}