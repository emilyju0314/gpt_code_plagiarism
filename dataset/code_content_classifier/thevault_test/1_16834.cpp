UCSHealthComponent::UCSHealthComponent():
DefaultHealth(100.f),
bIsDead(false),
TeamNumber(255)
{
    SetIsReplicated(true);
}