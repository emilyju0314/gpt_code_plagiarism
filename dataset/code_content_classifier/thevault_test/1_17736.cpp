void ATVRCartridge::BeginPlay()
{
	Super::BeginPlay();

	GetStaticMeshComponent()->OnComponentHit.AddDynamic(this, &ATVRCartridge::OnComponentHit);
}