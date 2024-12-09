int CSchemeManager::GetProportionalScaledValue(int normalizedValue)
{
	int wide, tall;
	GetSurface()->GetScreenSize( wide, tall );
	return GetProportionalScaledValue_( wide, tall, normalizedValue );
}