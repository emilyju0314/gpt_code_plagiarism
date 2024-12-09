std::string Edge::to_string(size_t stateLen) const
{
	std::string edgeStr;
	//Build the string
	edgeStr = fromState.to_string().substr(STATES - stateLen)
		    + " -("
		    + std::to_string(latency)
		    + ")-> "
		    + toState.to_string().substr(STATES - stateLen);
	return edgeStr;
	//TODO : Format string
}