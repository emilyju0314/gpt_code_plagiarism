void ATVRWeaponAttachment::BeginPlay()
{
	Super::BeginPlay();

	TArray<UStaticMeshComponent*> Meshes;
	GetComponents<UStaticMeshComponent>(Meshes);
	for(UStaticMeshComponent* TestMesh: Meshes)
	{
		if(TestMesh->GetCollisionProfileName() == FName("Weapon"))
		{
			AttachmentMeshes.AddUnique(TestMesh);
		}
	}
	
	GetWorldTimerManager().SetTimerForNextTick(this, &ATVRWeaponAttachment::FindAttachPointAndAttach);
}