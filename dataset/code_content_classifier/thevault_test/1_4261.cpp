void PenaltyForce::addParticleHalfplaneGradEToTotal(const VectorXs &x, int vidx, int pidx, VectorXs &gradE)
{
    int index1 = 2*vidx;
    
    VectorXs x1 = x.segment<2>(index1);
    std::pair<VectorXs, VectorXs> plane = m_scene.getHalfplane(pidx);
    VectorXs pdir = plane.first;
    VectorXs pn = plane.second;
    
    scalar pndotpn = pn.dot(pn);
    VectorXs n = ((pdir - x1).dot(pn)/pndotpn)*pn;
    scalar nnorm = n.norm();
    
    VectorXs nhat = n;
    nhat.normalize();
    
    double r = m_scene.getRadius(vidx);    
    scalar size = r + m_thickness;
    if(nnorm < size)
    {
        gradE.segment<2>(index1) -= m_k*(nnorm-size)*nhat.dot(pn)/pndotpn*pn;
    }
    
}