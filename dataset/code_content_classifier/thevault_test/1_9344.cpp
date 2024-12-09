void TextureD3D12::createSrvDescriptor() {
  mSrvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
  mSrvDesc.Format = mFormat;
  mSrvDesc.ViewDimension = mTextureViewDimension;
  if (mTextureViewDimension == D3D12_SRV_DIMENSION_TEXTURECUBE) {
    mSrvDesc.Texture2D.MipLevels = 1;
  } else {

    mSrvDesc.Texture2D.MipLevels = static_cast<uint32_t>(std::floor(
                                       std::log2(std::max(mWidth, mHeight)))) +
                                   1;
  }

  mContext->buildSrvDescriptor(mTexture.Get(), mSrvDesc, &mTextureGPUHandle);
}