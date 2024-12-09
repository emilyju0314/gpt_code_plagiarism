bool CustomizedUIRecordMgr::CanTheUserStartCloudRecording(unsigned int userid)
{
	GetRecordController();
	if (!m_pRecordController){
		return false;
	}

	ZOOM_SDK_NAMESPACE::SDKError rtn;
	rtn = m_pRecordController->CanStartRecording(true, userid);
	if (rtn == ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS){
		return true;
	}else {
		return false;
	}
}