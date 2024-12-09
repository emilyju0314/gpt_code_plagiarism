ParticleSystem::ParticleSystem(uint numParticles, bool bUseVBO, bool bUseGL) :
    m_bInitialized(false),
    m_bUseVBO(bUseVBO),
    m_numParticles(numParticles),
    m_particleRadius(0.1),
    m_doDepthSort(false),
    m_timer(0),
    m_time(0.0f)
{
    m_params.gravity = make_float3(0.0f, 0.0f, 0.0f);
    m_params.globalDamping = 1.0f;
	m_params.noiseSpeed = make_float3(0.0f, 0.0f, 0.0f);

    _initialize(numParticles, bUseGL);

}