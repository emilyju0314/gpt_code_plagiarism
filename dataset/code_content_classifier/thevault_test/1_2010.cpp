void
ParticleSystem::dumpParticles(uint start, uint count)
{
    m_pos.copy(GpuArray<float4>::DEVICE_TO_HOST);
    float4 *pos = m_pos.getHostPtr();

    m_vel.copy(GpuArray<float4>::DEVICE_TO_HOST);
    float4 *vel = m_vel.getHostPtr();

    for(uint i=start; i<start+count; i++) {
        printf("%d: ", i);
        printf("pos: (%.4f, %.4f, %.4f, %.4f)\n", pos[i].x, pos[i].y, pos[i].z, pos[i].w);
        printf("vel: (%.4f, %.4f, %.4f, %.4f)\n", vel[i].x, vel[i].y, vel[i].z, vel[i].w);
    }
}