bool CustomizedUIRecordMgr::CanIChangeOthersRecordingPermission()
{
	GetRecordController();
	if (!m_pRecordController){
		return false;
	}

	ZOOM_SDK_NAMESPACE::SDKError rtn;
	rtn = m_pRecordController->CanAllowDisAllowLocalRecording();
	if (rtn == ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS){
		return true;
	}
	return false;
}