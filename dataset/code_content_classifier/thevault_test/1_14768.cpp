static void InitVideoFace(UINT8 ubMercID)
{
	//Create the facial index
	FACETYPE& f = InitFace(ubMercID, 0, 0);
	giMercFaceIndex = &f;

	SetAutoFaceActive(guiVideoFaceBackground, FACE_AUTO_RESTORE_BUFFER, f, 0, 0);

	RenderAutoFace(f);

	gubCurrentStaticMode = VC_NO_STATIC;

	gfVideoFaceActive = TRUE;

	guiMercAttitudeTime = GetJA2Clock();
}