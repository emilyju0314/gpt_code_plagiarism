void PostRestorePhysicsObject()
{
	for ( int i = g_PostRestoreObjectList.Count()-1; i >= 0; --i )
	{
		if ( g_PostRestoreObjectList[i].pObject )
		{
			if ( g_PostRestoreObjectList[i].growFriction )
			{
				g_PostRestoreObjectList[i].pObject->GetObject()->force_grow_friction_system();
			}
			if ( g_PostRestoreObjectList[i].enableCollisions )
			{
				g_PostRestoreObjectList[i].pObject->EnableCollisions( true );
			}
		}
	}
	g_PostRestoreObjectList.Purge();
}