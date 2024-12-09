void CShaderAPIDx8::CommitPerPassVertexShaderTransforms()
{
	//GLMPRINTF(( ">-M- CommitPerPassVertexShaderTransforms" ));
	bool projChanged = VertexShaderTransformChanged( MATERIAL_PROJECTION );
	if ( projChanged )
	{
		//GLMPRINTF(( "-M- projChanged=true in CommitPerPassVertexShaderTransforms" ));
		SetVertexShaderViewProj();
		SetVertexShaderModelViewProjAndModelView();

		// Clear change flags
		m_DynamicState.m_TransformChanged[MATERIAL_PROJECTION] &= ~STATE_CHANGED_VERTEX_SHADER;
	}
	else
	{		
		//GLMPRINTF(( "-M- projChanged=false in CommitPerPassVertexShaderTransforms" ));
	}

	//GLMPRINTF(( "<-M- CommitPerPassVertexShaderTransforms" ));
}