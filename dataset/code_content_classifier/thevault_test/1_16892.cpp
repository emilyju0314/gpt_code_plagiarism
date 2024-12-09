void UpdateScheduler::UpdateCallback(void *pData, int32_t /*result*/)
{
	Fuji* pFuji = (Fuji*)pData;
	pFuji->Update();
}