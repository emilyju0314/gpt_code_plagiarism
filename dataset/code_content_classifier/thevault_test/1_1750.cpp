CWeaponBinoculars::~CWeaponBinoculars( void )
{
	CSoundEnvelopeController &controller = CSoundEnvelopeController::GetController();
	controller.SoundDestroy( m_pSoundStatic );
	controller.SoundDestroy( m_pSoundSignal );
}