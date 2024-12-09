void ATowerDefensePlayerController::BeginPlay()
{
	Super::BeginPlay();

	GameMode = (ATowerDefenseGameMode*)GetWorld()->GetAuthGameMode();

	ControlledPawn = (ATowerDefensePlayerPawn*)AController::GetPawn();
}