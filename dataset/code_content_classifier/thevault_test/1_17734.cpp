UTVRHoverInputVolume::UTVRHoverInputVolume(): Super()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	SetGenerateOverlapEvents(true);
	SetCollisionProfileName(COLLISION_INTERACT_VOLUME);
	SetAutoActivate(true);
	InputBreakOffDistance = 10.f;
}