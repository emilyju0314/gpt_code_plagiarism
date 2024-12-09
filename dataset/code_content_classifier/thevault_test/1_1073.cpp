int CAkimboBase::GetWeight() const
{
	SDKWeaponID eSingleID = AliasToWeaponID(GetSDKWpnData().m_szSingle);

	CSDKWeaponInfo* pSingleInfo = CSDKWeaponInfo::GetWeaponInfo(eSingleID);

	Assert(pSingleInfo);
	if (!pSingleInfo)
		return BaseClass::GetWeight();

	return pSingleInfo->iWeight;
}