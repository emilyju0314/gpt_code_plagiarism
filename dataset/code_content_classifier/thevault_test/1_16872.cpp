void AMyHUD::InitMenuPadPlus()
{
	class UUserWidget_MenuPadPlus* MenuPtr = nullptr;
	auto const WorldPtr = GetWorld();

	if (ensure(WorldPtr))
	{
		auto PC = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(WorldPtr, PLAYER_CONTROLLER_INDEX));

		if (PC != nullptr)
		{
			if (MenuWidgetBlueprint != NULL)
			{
				MenuPtr = CreateWidget<UUserWidget_MenuPadPlus>(WorldPtr, MenuWidgetBlueprint);

				if (MenuPtr != nullptr)
				{
					MenuPtr->AddToViewport();

					// Sets Focus on a Button in Menu, using a Player Controller
					UMenuPadPlusStatics::SetButtonFocus(MenuPtr->GetFirstWidget(), PC);
				}
			}
		}
	}
}