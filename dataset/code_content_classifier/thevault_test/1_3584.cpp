bool CShaderAPIDx8::MatrixIsChanging( TransformType_t type )
{
	if ( IsDeactivated() )	
		return false;

	// early out if the transform is already one of our standard types
	if ((type != TRANSFORM_IS_GENERAL) && (type == m_DynamicState.m_TransformType[m_CurrStack]))
		return false;

	return true;
}