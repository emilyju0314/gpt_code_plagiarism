void SatChannel::add_interface(Phy* phy_)
{
	phy_->setchnl(this); // Attach phy to this channel
	phy_->insertchnl(&ifhead_); // Add phy_ to list of phys on the channel
}