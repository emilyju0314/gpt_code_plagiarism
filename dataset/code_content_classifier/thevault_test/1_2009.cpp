void
ParticleSystem::initCubeRandom(vec3f origin, vec3f size, vec3f vel, float lifetime)
{
    float4 *posPtr = m_pos.getHostPtr();
    float4 *velPtr = m_vel.getHostPtr();

	for(uint i=0; i < m_numParticles; i++) 
	{
		vec3f pos = origin + svrand()*size;
		posPtr[i] = make_float4(pos.x, pos.y, pos.z, 0.0f);
	    velPtr[i] = make_float4(vel.x, vel.y, vel.z, lifetime);
	}
}