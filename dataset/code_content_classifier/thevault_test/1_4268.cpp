bool HybridCollisionHandler::applyIterativeImpulses(const TwoDScene &scene, const VectorXs &qs, const VectorXs &qe, const VectorXs &qdote, double dt, VectorXs &qefinal, VectorXs &qdotefinal)
{	
    qefinal = qe;
	qdotefinal = qdote;
	for (int i = 0; i < m_maxiters; i++)
	{
		auto collisions = detectCollisions(scene, qs, qefinal);
		if (collisions.size() == 0)
			return true;
		else 
		{
			VectorXs newqe = qefinal;
			VectorXs newqdote = qdotefinal;
			applyImpulses(scene, collisions, qs, newqe, newqdote, dt, qefinal, qdotefinal);
		}
	}
    return false;
}