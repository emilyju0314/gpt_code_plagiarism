void CWretch::BecomeTorso( const Vector &vecTorsoForce, const Vector &vecLegsForce )
{
	CapabilitiesRemove( bits_CAP_MOVE_JUMP );
	CapabilitiesRemove( bits_CAP_MOVE_CLIMB );

	ReleaseHeadcrab( EyePosition(), vecLegsForce * 0.5, true, true, true );

	BaseClass::BecomeTorso( vecTorsoForce, vecLegsForce );
}