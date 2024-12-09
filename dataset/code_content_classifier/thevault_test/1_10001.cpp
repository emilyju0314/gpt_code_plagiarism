bool InputEventHandler::IsKeyDown(EKEY_CODE keyCode)const
{
	bool ret = KeyIsDown[keyCode];

	return ret;
}