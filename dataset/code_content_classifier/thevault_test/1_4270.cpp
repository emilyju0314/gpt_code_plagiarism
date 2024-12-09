void HybridCollisionHandler::applyGeometricCollisionHandling(const TwoDScene &scene, const VectorXs &qs, const VectorXs &qe, const VectorXs &qdote, double dt, VectorXs &qm, VectorXs &qdotm)
{
    ImpactZones Z;
    ImpactZones Zprime;
    
    //
    // What you need to implement here: (same as writeup section 4.6)
    //
    // 1. Perform continuous-time collision detection using positions qs and qe.
    // 2. Initialize qm = qe and qdotm = qdote.
    // 3. Construct a list of disjoint impact zones Z from the detected collisions.
    // 4. For each impact zone in Z, apply geometric collision response (by calling 
    //      HybrdiCollisionHandler::performFailsafe, using positions qs and qm, and
    //      modifying qm and qdotm for the vertices in those zones.
    // 5. Perform continuous-time collision detection using positions qs and qm. 
    // 6. Construct a new list of impact zones Z′ consisting of all impact zones in Z, 
    //      plus one zone for each detected collision.
    // 7. Merge the zones in Z' to get disjoint impact zones.
    // 8. If Z and Z' are equal, the algorithm is done, and qm and qdotm are the new, 
    //      collision-free end-of-time-step positions. Z and Z' are equal if they 
    //      contain exactly the same impact zones; impact zones are the same if they 
    //      contain the same particles and they both involve, or both don’t involve, 
    //      a half-plane. If Z != Z', go to step 9.
    // 9. Set Z=Z' and goto step4.
    //
    
    // Your implementation here
    auto collisions = detectCollisions(scene, qs, qe);
    qm = qe;
    qdotm = qdote;
    
    growImpactZones(scene, Z, collisions);
        
    while(true)
    {        
        for(int i=0; i<(int)Z.size(); i++)
            performFailsafe(scene, qs, Z[i], dt, qm, qdotm);
        collisions = detectCollisions(scene, qs, qm);
        auto oldzones = Z;
        growImpactZones(scene, Z, collisions);
        if(zonesEqual(oldzones, Z)) break;
    }    
}