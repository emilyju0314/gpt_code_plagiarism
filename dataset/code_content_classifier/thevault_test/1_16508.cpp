void Surface::releaseRecordedState(IDirect3DDevice9 *device)
{
    if (mFlipState)
    {
        mFlipState->Release();
        mFlipState = NULL;
    }

    if (mPreFlipState)
    {
        mPreFlipState->Release();
        mPreFlipState = NULL;
    }
}