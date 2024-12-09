UTVRGunFireComponent::UTVRGunFireComponent(const FObjectInitializer& OI) : Super(OI)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	MuzzleFlashPSC = nullptr;
	FireAudioComp = nullptr;
	EmptyAudioComp = nullptr;
	FireSoundCue = nullptr;
	EmptySoundCue = nullptr;

	ShotCount = 0;
	bIsFiring = false;
	
	RefireTime = 0.1f;
	RateOfFireRPM = 600;
	
	bHasSingleShot = true;
	bHasBurst = false;
	bHasFullAuto = false;
	
    bHasFireSelector = true;

	LoadedCartridge = nullptr;
	CurrentFireMode = ETVRFireMode::Single;
	bCartridgeIsSpent = false;
	bUseForceTubeKick = false;

	bIsSuppressed = false;
	MuzzleFlashOverride = nullptr;
	
	bDefaultSuppressed = false;
	ImpactSoundComp = nullptr;
}