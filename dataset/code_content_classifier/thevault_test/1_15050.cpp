void InitializeRoadMacros()
{
	INT16 i, end;
	INT16 sMacro = 0;
	end = sizeof( gRoadMacros ) / sizeof( MACROSTRUCT );
	for( i = 0; i < end; i++ )
	{
		if( gRoadMacros[ i ].sMacroID == sMacro )
		{
			gsRoadMacroStartIndex[ sMacro ] = i;
			sMacro++;
		}
	}
//	i = ROADPIECES001;
}