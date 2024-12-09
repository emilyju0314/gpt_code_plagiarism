void ACSTrackerBot::BeginPlay()
{
    Super::BeginPlay();

    if (Role == ROLE_Authority)
    {
        NextPathPoint = GetNextPathPoint(); 
        GetWorldTimerManager().SetTimer(TimerHandle_CheckNearbyBots, this, &ACSTrackerBot::CheckNearbyBots, CheckNearbyBotsInterval, true);
    }
}