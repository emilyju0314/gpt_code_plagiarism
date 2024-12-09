void ArmSubsystemC418::Periodic()
{
#ifndef NOHW
    //Log the Halleffects
    Log("Lower HallEffect", m_hallEffectLower.Get());
    Log("Upper HallEffect", m_hallEffectUpper.Get());
#endif
}