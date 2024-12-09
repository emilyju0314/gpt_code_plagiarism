void macWakeupTimer::handle(Event *)
{
	reset();
	EnergyModel *em = mac->netif_->node()->energy_model();
	if (em)
	{
		mac->phy->wakeupNode(0);
	}
}