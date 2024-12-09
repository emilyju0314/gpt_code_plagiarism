void ADefaultProjectile::BeginPlay()
{
	Super::BeginPlay();

	OverlapSphere->OnComponentBeginOverlap.AddDynamic(this, &ADefaultProjectile::OnProjectileOverlapBegin);
}