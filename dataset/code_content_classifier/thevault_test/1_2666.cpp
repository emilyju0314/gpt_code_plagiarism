void gjNetwork::__KillCall(gjCall* pCall)
{
    // search callback object
    FOR_EACH(it, m_apCall)
    {
        gjCall* pCurCall = (*it);

        if(pCurCall == pCall)
        {
            CURL* pSession = pCurCall->GetSession();

            // delete callback object
            pCurCall->Finish(false);
            m_apCall.erase(std::find(m_apCall.begin(), m_apCall.end(), pCall));
            SAFE_DELETE(pCurCall)

            // close cURL session
            curl_multi_remove_handle(m_pMultiHandle, pSession);
            curl_easy_cleanup(pSession);

            return;
        }
    }
}