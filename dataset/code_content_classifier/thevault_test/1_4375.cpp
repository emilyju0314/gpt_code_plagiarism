void CMP_PrepareCMPSourceForIMG_Destination(CMP_Texture* pDstTexture, CMP_FORMAT  SrcFormat)
{

    CMP_DWORD       dwWidth = pDstTexture->dwWidth;
    CMP_DWORD       dwHeight = pDstTexture->dwHeight;
    CMP_FORMAT      newDstFormat = pDstTexture->format;
    CMP_BYTE        *pData;

    pData = pDstTexture->pData;

    switch (SrcFormat)
    {
        // decompressed Data  is in the form BGRA
    case CMP_FORMAT_ATI1N:
    case CMP_FORMAT_ATI2N:
    case CMP_FORMAT_ATI2N_XY:
    case CMP_FORMAT_ATI2N_DXT5:
    case CMP_FORMAT_ATC_RGB:
    case CMP_FORMAT_ATC_RGBA_Explicit:
    case CMP_FORMAT_ATC_RGBA_Interpolated:
    case CMP_FORMAT_BC1:
    case CMP_FORMAT_BC2:
    case CMP_FORMAT_BC3:
    case CMP_FORMAT_BC4:
    case CMP_FORMAT_BC5:
    case CMP_FORMAT_DXT1:
    case CMP_FORMAT_DXT3:
    case CMP_FORMAT_DXT5:
    case CMP_FORMAT_DXT5_xGBR:
    case CMP_FORMAT_DXT5_RxBG:
    case CMP_FORMAT_DXT5_RBxG:
    case CMP_FORMAT_DXT5_xRBG:
    case CMP_FORMAT_DXT5_RGxB:
    case CMP_FORMAT_DXT5_xGxR:
    {
        switch (newDstFormat)
        {
        case CMP_FORMAT_BGRA_8888: break;
        case CMP_FORMAT_RGBA_8888:
        {
            CMP_Map_Bytes(pData, dwWidth, dwHeight, { 2, 1, 0, 3 },4);
            break;
        }
        default: break;
        }
    }
    // decompressed Data  is in the form RGBA_8888
    case CMP_FORMAT_ASTC:
    case CMP_FORMAT_BC6H:
    case CMP_FORMAT_BC7:
    case CMP_FORMAT_GT:
    case CMP_FORMAT_ETC_RGB:
    case CMP_FORMAT_ETC2_RGB:
    case CMP_FORMAT_ETC2_SRGB:
    case CMP_FORMAT_ETC2_RGBA:
    case CMP_FORMAT_ETC2_RGBA1:
    case CMP_FORMAT_ETC2_SRGBA:
    case CMP_FORMAT_ETC2_SRGBA1:
    {
        switch (newDstFormat)
        {
        case CMP_FORMAT_RGBA_8888: break;
        case CMP_FORMAT_BGRA_8888:
        {
            CMP_Map_Bytes(pData, dwWidth, dwHeight, { 2, 1, 0, 3 },4);
            break;
        }
        default: break;
        }
    }
    }
}