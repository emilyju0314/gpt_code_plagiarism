Edge::Edge( const std::bitset<STATES> &fromState,
			const size_t              fromID,
			const std::bitset<STATES> &toState,
			const size_t              toID,
			const size_t              latency )
{
	this->toState   = toState;
	this->fromState = fromState;
	this->toID      = toID;
	this->fromID    = fromID;
	this->latency   = latency;
}