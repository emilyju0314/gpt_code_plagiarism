void HybridCollisionHandler::performFailsafe(const TwoDScene &scene, const VectorXs &qs, const ImpactZone &zone, double dt, VectorXs &qe, VectorXs &qdote)
{
    //
    // What you need to implement here: (same as writeup section 4.5)
    //
    // 1. Treat the particles as if they were part of a rigid body; that is, treat them as if 
    //      we connected them with rigid beams at the start of the time step.
    // 2. Step the rigid body forward in time to the end of the time step.
    // 3. Set each particle’s modified end-of-time-step position qm to the position dictated 
    //      by the motion of the rigid body.
    // 4. Also set the particle’s modified end-of-time-step velocity to (qm − qs) / h, where 
    //      h is the length of the time step.
    //
    
    // Don't forget to handle fixed objects properly as in writeup section 4.5.1    
    // Your implementation here
    scalar totalmass = 0, angularp = 0, I = 0;
    VectorXs dx = qe - qs;
    VectorXs cm = VectorXs::Zero(2);
    VectorXs p = VectorXs::Zero(2);
    
    const VectorXs& M = scene.getM();
    
    bool hasfixed = false;    
    for(auto i : zone.m_verts)
    {
        auto index = 2*i;
        auto Mindex = M[2*i];
        cm += Mindex * qs.segment<2>(index);
        p += Mindex * dx.segment<2>(index);
        totalmass += Mindex;
        
        if((hasfixed == false)&&(scene.isFixed(i))) hasfixed = true;
    }
    
    cm /= totalmass;
    p /= totalmass;
    
    for(auto i : zone.m_verts)
    {
        int index = 2*i;
        scalar Mindex = M[index];
        VectorXs v = dx.segment<2>(index) - p;
        VectorXs r = qs.segment<2>(index) - cm;        
        angularp += (r[0]*v[1] - r[1]*v[0])*Mindex;        
        I += Mindex * r.dot(r);
    }
    
    if(hasfixed || zone.m_halfplane)
    {
        for(auto i : zone.m_verts)
        {
            int index = 2*i;
            qe.segment<2>(index) = qs.segment<2>(index);
            qdote.segment<2>(index).setZero();
        }
        return;
    }
    
    scalar w = angularp/I;
    
    for(auto i : zone.m_verts)
    {
        int indexi = 2*i;
        const VectorXs& qsi = qs.segment<2>(indexi);
        
        VectorXs r = qsi - cm;        
        VectorXs rperp = r;
        std::swap(rperp[0], rperp[1]);
        rperp[0]*=-1;
        qe.segment<2>(indexi) = cm + p + cos(w)*r + sin(w)*rperp;
        qdote.segment<2>(indexi) = (qe.segment<2>(indexi) - qsi)/dt;
    }
}