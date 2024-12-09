FOR_EACH_MAP_FAST( m_mapQuestDefs, i )
	{
		CEconQuestDefinition * pQuestDef = m_mapQuestDefs.Element( i );

		SCHEMA_INIT_CHECK(
			( CEconQuestDefinition::IsQuestExpressionValid( pQuestDef->GetQuestExpression() ) ),
			CFmtStr( "Quest definition %s specifies an expression that does not evaluate.", pQuestDef->GetName() ) );

		if ( pQuestDef->GetQuestBonusExpression() && pQuestDef->GetQuestBonusExpression()[ 0 ] )
		{
			SCHEMA_INIT_CHECK(
				( CEconQuestDefinition::IsQuestExpressionValid( pQuestDef->GetQuestBonusExpression() ) ),
				CFmtStr( "Quest definition %s specifies a bonus expression that does not evaluate.", pQuestDef->GetName() ) );
		}
	}