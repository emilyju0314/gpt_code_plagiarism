bool CEconQuestDefinition::IsQuestExpressionValid( const char * pszQuestExpr )
{
	if ( !pszQuestExpr || !pszQuestExpr[0] )
		return false;

	CExpressionCalculator expr = CExpressionCalculator( pszQuestExpr ); 

	ZeroOutQuestExpressionVariables( expr );


	// This seemed like a good idea but it doesn't work.
	//
// 	for ( int i = 0; i < expr.VariableCount(); i++ )
// 	{
// 		if ( !StringIsEmpty( expr.GetVariableName( i ) ) && expr.GetVariableValue( i ) != 1.0 )
// 		{
// 			AssertMsg1( 0, "unknown variable %s in quest expression", expr.GetVariableName( i ) );
// 			return false;
// 		}
// 	}

	float flResult;
	bool bSuccess = expr.Evaluate( flResult );

	return ( bSuccess && IsFinite(flResult) );
}