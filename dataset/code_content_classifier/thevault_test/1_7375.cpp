void ADefaultTower::BeginPlay()
{
	Super::BeginPlay();

	GameMode = (ATowerDefenseGameMode*)GetWorld()->GetAuthGameMode();

	TowerRangeSphere->SetSphereRadius(Range);
	TowerRangeSphere->OnComponentBeginOverlap.AddDynamic(this, &ADefaultTower::OnRangeOverlapBegin);
	TowerRangeSphere->OnComponentEndOverlap.AddDynamic(this, &ADefaultTower::OnRangeOverlapEnd);
	OnClicked.AddDynamic(this, &ADefaultTower::TowerSelected);

	TowerTargeting = ETowerPositionTargeting::TPT_First;
	bMoreThanOneOverlappingEnemy = false;
	bNoOverlappingEnemies = true;
	bReloading = false;
}