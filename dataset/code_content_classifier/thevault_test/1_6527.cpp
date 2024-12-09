void SatChannel::remove_interface(Phy* phy_)
{
	phy_->setchnl(NULL); // Set phy_'s channel pointer to NULL
	phy_->removechnl(); // Remove phy_ to list of phys on the channel
}