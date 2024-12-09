void PenaltyForce::addParticleEdgeGradEToTotal(const VectorXs &x, int vidx, int eidx, VectorXs &gradE)
{
    std::pair<int,int> edge = m_scene.getEdge(eidx);
    
    int index1 = 2*vidx;
    int index2 = 2*edge.first;
    int index3 = 2*edge.second;
    
    VectorXs x1 = x.segment<2>(index1);
    VectorXs x2 = x.segment<2>(index2);
    VectorXs x3 = x.segment<2>(index3);
    
    double r1 = m_scene.getRadius(vidx);
    double r2 = m_scene.getEdgeRadii()[eidx];
    
    VectorXs x3x2 = x3-x2;
    
    double alpha = (x1-x2).dot(x3x2)/(x3x2).dot(x3x2);
    alpha = clamp(alpha, 0.0, 1.0);
    scalar MAlpha = 1.0 - alpha;
    
    VectorXs n = x2 + alpha*(x3x2) - x1;
    scalar nnorm = n.norm();
    
    VectorXs nhat = n;
    nhat.normalize();
    
    scalar size = (r1+r2 + m_thickness);
    if(nnorm < size)
    {
        scalar nnormsize = nnorm - size;
        gradE.segment<2>(index1) -= m_k*nnormsize*nhat;        
        gradE.segment<2>(index2) += m_k*MAlpha*nnormsize*nhat;
        gradE.segment<2>(index3) += m_k*alpha*nnormsize*nhat;
    }    
}