int CShaderAPIDx8::GetMatrixStack( MaterialMatrixMode_t mode ) const
{
	Assert( mode >= 0 && mode < NUM_MATRIX_MODES );
	return mode;
}