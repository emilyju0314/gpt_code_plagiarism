void CShaderAPIDx8::FlushHiStencil()
{
	LOCK_SHADERAPI();
	Dx9Device()->FlushHiZStencil( D3DFHZS_SYNCHRONOUS );
}