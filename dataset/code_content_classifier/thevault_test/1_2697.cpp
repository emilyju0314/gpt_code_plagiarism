int gjDataItem::__GetDataBase64Callback(const std::string& sData, void* pAdd, gjVoidPtr* ppOutput)
{
    // parse output and save data
    std::string sReturn;
    const int iError = this->__GetDataCallback(sData, NULL, &sReturn);
    if(iError) return iError;

    // convert Base64 string to binary data
    base64_decode(sReturn.c_str(), (unsigned char*)m_pTarget, P_TO_I(pAdd));

    if(ppOutput) (*ppOutput) = (void*)m_pTarget;
    return GJ_OK;
}