UTVRTriggerComponent::UTVRTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	TriggerAxis = 0.f;
	
	TriggerActivate = 0.4f;
	TriggerReset = 0.2f;
	bTriggerNeedsReset = false;

	bDualStageTrigger = false;
	TriggerActivate2 = 0.8f;
	TriggerReset2 = 0.65f;
	bTriggerNeedsReset2 = false;
}