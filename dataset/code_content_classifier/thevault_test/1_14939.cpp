bool ValidAmmoType( UINT16 usItem, UINT16 usAmmoType )
{
	if (GCM->getItem(usItem)->getItemClass() == IC_GUN && GCM->getItem(usAmmoType)->getItemClass() == IC_AMMO)
	{
		return GCM->getWeapon(usItem)->matches(GCM->getItem(usAmmoType)->asAmmo()->calibre);
	}
	return false;
}