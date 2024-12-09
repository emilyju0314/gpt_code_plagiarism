void UUserWidget_MenuPadPlus::OnJoystickAxisChangedAlternate(
	  TArray<class UMenuPadPlusButton*> ButtonsArray
	, class UObject* NormalTexture
	, class UObject* HoveredTexture
	, class UObject* PressedTexture
	, float ImageSizeX
	, float ImageSizeY
	, class USoundCue* HoveredSound
	, class USoundCue* PressedSound
	, class AMyPlayerController* InPC)
{
	auto const MenuCount = 0;

	if (ButtonsArray.Num() > MenuCount && InPC)
	{
		int32 ArrayLength = ButtonsArray.Num();

		for (int32 i = 0; i < ArrayLength; ++i)
		{
			if (ButtonsArray[i]->HasUserFocus(InPC))
			{
				FButtonStyle ButtonStyle;
				ButtonStyle.Normal.SetResourceObject(HoveredTexture);
				ButtonStyle.Hovered.SetResourceObject(HoveredTexture);
				ButtonStyle.Pressed.SetResourceObject(PressedTexture);

				ButtonStyle.Normal.ImageSize = FVector2D(ImageSizeX, ImageSizeY);
				ButtonStyle.Hovered.ImageSize = FVector2D(ImageSizeX, ImageSizeY);
				ButtonStyle.Pressed.ImageSize = FVector2D(ImageSizeX, ImageSizeY);

				if (PressedSound != NULL) ButtonStyle.PressedSlateSound.SetResourceObject(PressedSound);

				if (HoveredSound != NULL)
				{
					if (!ButtonsArray[i]->bCanPlayHoveredSound)
					{
						auto const WorldPtr = GetWorld();
						if (ensure(WorldPtr)) UGameplayStatics::PlaySound2D(WorldPtr, HoveredSound);
						ButtonsArray[i]->bCanPlayHoveredSound = true;
					}
				}

				ButtonsArray[i]->SetStyle(ButtonStyle);
				if (!ButtonsArray[i]->bHasForcedPressed) ButtonsArray[i]->ForceHoveredText();
			}
			else
			{
				FButtonStyle ButtonStyle;
				ButtonStyle.Normal.SetResourceObject(NormalTexture);
				ButtonStyle.Hovered.SetResourceObject(NormalTexture);

				ButtonStyle.Normal.ImageSize = FVector2D(ImageSizeX, ImageSizeY);
				ButtonStyle.Hovered.ImageSize = FVector2D(ImageSizeX, ImageSizeY);

				if (ButtonsArray[i]->bCanPlayHoveredSound) ButtonsArray[i]->bCanPlayHoveredSound = false;

				ButtonsArray[i]->SetStyle(ButtonStyle);
				ButtonsArray[i]->ForceNormalText();
			}
		}
	}
}