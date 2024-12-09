unsigned
FCFSSimpleArbiter::pick_winner ()
{
    unsigned winner = no_channels;
    if(m_requesters.size() > 0) {
        winner = m_requesters.front();
	m_requesters.pop_front();
    }

    return winner;
}