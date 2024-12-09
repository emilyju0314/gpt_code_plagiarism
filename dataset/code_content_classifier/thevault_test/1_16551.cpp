void Program::link()
{
    unlink();

    if (!mFragmentShader || !mFragmentShader->isCompiled())
    {
        return;
    }

    if (!mVertexShader || !mVertexShader->isCompiled())
    {
        return;
    }

    mPixelHLSL = mFragmentShader->getHLSL();
    mVertexHLSL = mVertexShader->getHLSL();

    if (!linkVaryings())
    {
        return;
    }

    Context *context = getContext();
    const char *vertexProfile = context->supportsShaderModel3() ? "vs_3_0" : "vs_2_0";
    const char *pixelProfile = context->supportsShaderModel3() ? "ps_3_0" : "ps_2_0";

    ID3DXBuffer *vertexBinary = compileToBinary(mVertexHLSL.c_str(), vertexProfile, &mConstantTableVS);
    ID3DXBuffer *pixelBinary = compileToBinary(mPixelHLSL.c_str(), pixelProfile, &mConstantTablePS);

    if (vertexBinary && pixelBinary)
    {
        IDirect3DDevice9 *device = getDevice();
        HRESULT vertexResult = device->CreateVertexShader((DWORD*)vertexBinary->GetBufferPointer(), &mVertexExecutable);
        HRESULT pixelResult = device->CreatePixelShader((DWORD*)pixelBinary->GetBufferPointer(), &mPixelExecutable);

        if (vertexResult == D3DERR_OUTOFVIDEOMEMORY || vertexResult == E_OUTOFMEMORY || pixelResult == D3DERR_OUTOFVIDEOMEMORY || pixelResult == E_OUTOFMEMORY)
        {
            return error(GL_OUT_OF_MEMORY);
        }

        ASSERT(SUCCEEDED(vertexResult) && SUCCEEDED(pixelResult));

        vertexBinary->Release();
        pixelBinary->Release();
        vertexBinary = NULL;
        pixelBinary = NULL;

        if (mVertexExecutable && mPixelExecutable)
        {
            if (!linkAttributes())
            {
                return;
            }

            if (!linkUniforms(mConstantTablePS))
            {
                return;
            }

            if (!linkUniforms(mConstantTableVS))
            {
                return;
            }

            // these uniforms are searched as already-decorated because gl_ and dx_
            // are reserved prefixes, and do not receive additional decoration
            mDxDepthRangeLocation = getUniformLocation("dx_DepthRange", true);
            mDxDepthLocation = getUniformLocation("dx_Depth", true);
            mDxViewportLocation = getUniformLocation("dx_Viewport", true);
            mDxHalfPixelSizeLocation = getUniformLocation("dx_HalfPixelSize", true);
            mDxFrontCCWLocation = getUniformLocation("dx_FrontCCW", true);
            mDxPointsOrLinesLocation = getUniformLocation("dx_PointsOrLines", true);

            mLinked = true;   // Success
        }
    }
}