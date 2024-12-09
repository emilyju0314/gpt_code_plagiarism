int CSchemeManager::GetProportionalNormalizedValue(int scaledValue)
{
	int wide, tall;
	GetSurface()->GetScreenSize( wide, tall );
	return GetProportionalNormalizedValue_( wide, tall, scaledValue );
}