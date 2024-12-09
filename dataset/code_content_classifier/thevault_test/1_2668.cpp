gjUser* gjAPI::gjInterUser::GetUser(const int iID)
{
    gjUserPtr pOutput;

    if(this->__CheckCache(iID, &pOutput) == GJ_OK) return pOutput;
    if(this->FetchUserNow(iID, &pOutput) == GJ_OK) return pOutput;

    return m_apUser[0];
}