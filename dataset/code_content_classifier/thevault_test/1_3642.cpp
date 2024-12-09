static bool Helper_ExtractIntegerFromValueStringEntry( const char *szValue, int *pnValue )
{
	if ( V_isdigit( *szValue ) )
	{
		*pnValue = V_atoi( szValue );
		return true;
	}
	else if ( char const *szTint = StringAfterPrefix( szValue, "tint_") )
	{
		if ( !V_stricmp( szTint, "min" ) )
		{
			*pnValue = 1;
			return true;
		}
		if ( !V_stricmp( szTint, "max" ) )
		{
			*pnValue = GEconItemSchema().GetGraffitiTintMaxValidDefID();
			return true;
		}
		if ( const CEconGraffitiTintDefinition *pDef = GEconItemSchema().GetGraffitiTintDefinitionByName( szTint ) )
		{
			*pnValue = pDef->GetID();
			return true;
		}
		return false;
	}
	return false;
}