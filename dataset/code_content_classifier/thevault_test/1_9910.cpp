bool ACReader::Advance(FMemoryData& EntityWrapper) const
{
	// TODO need to avoid creating a FPlayerEntity all the time, we can just update the internal data pointer
    EntityWrapper.PlayerEntity = FPlayerEntity(m_PlayerEntityAddress);
    return EntityWrapper.PlayerEntity.RefreshData(m_ProcessHandle);
}