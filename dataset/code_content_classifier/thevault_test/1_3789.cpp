float CPhysicsObject::GetEnergy() const
{
	IVP_Core *pCore = m_pObject->get_core();
	IVP_FLOAT energy = 0.0f;
	IVP_U_Float_Point tmp;

	energy = 0.5f * pCore->get_mass() * pCore->speed.dot_product(&pCore->speed); // 1/2mvv
	tmp.set_pairwise_mult(&pCore->rot_speed, pCore->get_rot_inertia()); // wI
	energy += 0.5f * tmp.dot_product(&pCore->rot_speed); // 1/2mvv + 1/2wIw

	return ConvertEnergyToHL( energy );
}