bool SkBitmapProcState::chooseProcs() {
    SkASSERT(!fInvMatrix.hasPerspective());
    SkASSERT(SkOpts::S32_alpha_D32_filter_DXDY || fInvMatrix.isScaleTranslate());
    SkASSERT(fPixmap.colorType() == kN32_SkColorType);
    SkASSERT(fPixmap.alphaType() == kPremul_SkAlphaType ||
             fPixmap.alphaType() == kOpaque_SkAlphaType);

    SkASSERT(fTileModeX != SkTileMode::kDecal);

    fInvProc            = SkMatrixPriv::GetMapXYProc(fInvMatrix);
    fInvSxFractionalInt = SkScalarToFractionalInt(fInvMatrix.getScaleX());
    fInvKyFractionalInt = SkScalarToFractionalInt(fInvMatrix.getSkewY ());

    fAlphaScale = SkAlpha255To256(fPaintAlpha);

    bool translate_only = (fInvMatrix.getType() & ~SkMatrix::kTranslate_Mask) == 0;
    fMatrixProc = this->chooseMatrixProc(translate_only);
    SkASSERT(fMatrixProc);

    if (fInvMatrix.isScaleTranslate()) {
        fSampleProc32 = fBilerp ? SkOpts::S32_alpha_D32_filter_DX   : S32_alpha_D32_nofilter_DX  ;
    } else {
        fSampleProc32 = fBilerp ? SkOpts::S32_alpha_D32_filter_DXDY : S32_alpha_D32_nofilter_DXDY;
    }
    SkASSERT(fSampleProc32);

    // our special-case shaderprocs
    // TODO: move this one into chooseShaderProc32() or pull all that in here.
    if (fAlphaScale == 256
            && !fBilerp
            && SkTileMode::kClamp == fTileModeX
            && SkTileMode::kClamp == fTileModeY
            && fInvMatrix.isScaleTranslate()) {
        fShaderProc32 = Clamp_S32_opaque_D32_nofilter_DX_shaderproc;
    } else {
        fShaderProc32 = this->chooseShaderProc32();
    }

    return true;
}