bool CWretch::CanEnterVehicle( CPropJeepEpisodic *pVehicle )
{
	if ( pVehicle == NULL )
		return false;

	return pVehicle->NPC_CanEnterVehicle( this, false );
}