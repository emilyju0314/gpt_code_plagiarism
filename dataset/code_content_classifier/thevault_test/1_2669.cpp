gjUser* gjAPI::gjInterUser::GetMainUser()
{
    if(!m_pAPI->IsUserConnected()) return m_apUser[0];
    return this->GetUser(m_pAPI->GetUserName());
}