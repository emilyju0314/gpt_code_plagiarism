void
ParticleSystem::dumpBin( float4 **posData,
                         float4 **velData)
{
    m_pos.copy(GpuArray<float4>::DEVICE_TO_HOST);
    *posData = m_pos.getHostPtr();

    m_vel.copy(GpuArray<float4>::DEVICE_TO_HOST);
    *velData = m_vel.getHostPtr();
}