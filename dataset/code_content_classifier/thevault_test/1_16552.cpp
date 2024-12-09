bool Program::defineUniform(const D3DXHANDLE &constantHandle, const D3DXCONSTANT_DESC &constantDescription, std::string name)
{
    if (constantDescription.RegisterSet == D3DXRS_SAMPLER)
    {
        for (unsigned int samplerIndex = constantDescription.RegisterIndex; samplerIndex < constantDescription.RegisterIndex + constantDescription.RegisterCount; samplerIndex++)
        {
            ASSERT(samplerIndex < sizeof(mSamplers)/sizeof(mSamplers[0]));

            mSamplers[samplerIndex].active = true;
            mSamplers[samplerIndex].type = (constantDescription.Type == D3DXPT_SAMPLERCUBE) ? SAMPLER_CUBE : SAMPLER_2D;
            mSamplers[samplerIndex].logicalTextureUnit = 0;
            mSamplers[samplerIndex].dirty = true;
        }
    }

    switch(constantDescription.Class)
    {
      case D3DXPC_STRUCT:
        {
            for (unsigned int arrayIndex = 0; arrayIndex < constantDescription.Elements; arrayIndex++)
            {
                for (unsigned int field = 0; field < constantDescription.StructMembers; field++)
                {
                    D3DXHANDLE fieldHandle = mConstantTablePS->GetConstant(constantHandle, field);

                    D3DXCONSTANT_DESC fieldDescription;
                    UINT descriptionCount = 1;

                    mConstantTablePS->GetConstantDesc(fieldHandle, &fieldDescription, &descriptionCount);

                    std::string structIndex = (constantDescription.Elements > 1) ? ("[" + str(arrayIndex) + "]") : "";

                    if (!defineUniform(fieldHandle, fieldDescription, name + constantDescription.Name + structIndex + "."))
                    {
                        return false;
                    }
                }
            }

            return true;
        }
      case D3DXPC_SCALAR:
      case D3DXPC_VECTOR:
      case D3DXPC_MATRIX_COLUMNS:
      case D3DXPC_OBJECT:
        return defineUniform(constantDescription, name + constantDescription.Name);
      default:
        UNREACHABLE();
        return false;
    }
}