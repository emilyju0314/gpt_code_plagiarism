void PenaltyForce::addParticleParticleGradEToTotal(const VectorXs &x, int idx1, int idx2, VectorXs &gradE)
{
    int index1 = 2*idx1;
    int index2 = 2*idx2;
    
    VectorXs x1 = x.segment<2>(index1);
    VectorXs x2 = x.segment<2>(index2);
    
    double r1 = m_scene.getRadius(idx1);
    double r2 = m_scene.getRadius(idx2);
    
    VectorXs n = x2-x1;
    scalar nnorm = n.norm();
    
    VectorXs nhat = n;
    nhat.normalize();
    
    scalar size = r1 + r2 + m_thickness; 
    if(nnorm < size)
    {        
        gradE.segment<2>(index1) -= m_k * (nnorm - size) * nhat;
        gradE.segment<2>(index2) += m_k * (nnorm - size) * nhat;
    }    
}