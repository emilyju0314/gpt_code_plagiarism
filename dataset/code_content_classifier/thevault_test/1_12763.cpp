HRESULT CDRGTexture::Restore(LPDIRECT3DDEVICE7 pd3dDevice, DWORD dwNewStage )
{
	dwStage = dwNewStage;
	return Restore( pd3dDevice );
}