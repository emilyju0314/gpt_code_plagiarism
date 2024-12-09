bool CustomizedUIRecordMgr::DoesTheUserSupportLocalRecording(unsigned int userid)
{
	GetRecordController();
	if (!m_pRecordController){
		return false;
	}

	ZOOM_SDK_NAMESPACE::SDKError rtn;
	rtn = m_pRecordController->IsSupportLocalRecording(userid);
	if (rtn == ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS){
		return true;
	}
	return false;
}