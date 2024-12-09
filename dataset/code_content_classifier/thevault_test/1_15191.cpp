void ATestServerActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (bListenInit)
		RunServer();
}