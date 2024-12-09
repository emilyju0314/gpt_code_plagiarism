void Context::applyShaders()
{
    IDirect3DDevice9 *device = getDevice();
    Program *programObject = getCurrentProgram();
    IDirect3DVertexShader9 *vertexShader = programObject->getVertexShader();
    IDirect3DPixelShader9 *pixelShader = programObject->getPixelShader();

    device->SetVertexShader(vertexShader);
    device->SetPixelShader(pixelShader);

    if (programObject->getSerial() != mAppliedProgram)
    {
        programObject->dirtyAllUniforms();
        programObject->dirtyAllSamplers();
        mAppliedProgram = programObject->getSerial();
    }

    programObject->applyUniforms();
}