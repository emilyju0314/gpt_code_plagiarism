void DeleteCreatureDirectives()
{
	if( gLair )
		DeleteDirectiveNode( &gLair );
	giLairID = 0;
}