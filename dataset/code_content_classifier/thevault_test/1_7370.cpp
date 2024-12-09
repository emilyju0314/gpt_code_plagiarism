void ATowerDefensePlayerController::RightMouseDown()
{
	bRightMouseDown = true;
	bShowMouseCursor = false;
	GetMousePosition(MouseX, MouseY);
}