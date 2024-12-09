void AMagicMissile::BeginPlay()
{
	Super::BeginPlay();
	//SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AMagicMissile::BeginSphereOverlap);
	SphereCollision->OnComponentHit.AddDynamic(this, &AMagicMissile::SphereHit);
}