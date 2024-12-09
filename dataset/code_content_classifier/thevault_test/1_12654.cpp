void SyncAlg :: updateOutputTick(LpId_t src, LpId_t dst, Ticks_t when, Clock* clk)
{
//cout << "*************** syncAlg, at tick " << clk->NowTicks() << " predict= " << when << " src= " << src << " dst= " << dst << " m_times= " << m_outputTS->m_times[src][dst] << endl;

    if(clk->NowTicks() < m_outputTS->m_prev_ticks[src][dst])
	when = (when < m_outputTS->m_prev_ticks[src][dst]) ? when : m_outputTS->m_prev_ticks[src][dst];

    Time_t t = when / clk->freq;
    if(m_outputTS->m_times[src][dst] == 0 || m_outputTS->m_times[src][dst] < Manifold::NowTicks(*clk) / clk->freq) {
        m_outputTS->m_times[src][dst] = t;
        m_outputTS->m_ticks[src][dst] = when;
    }
    else {
        if(t < m_outputTS->m_times[src][dst]) {
	    m_outputTS->m_times[src][dst] = t;
	    m_outputTS->m_ticks[src][dst] = when;
	}
    }
//cout << "m_outputTS[" << src << ", " << dst << "]= " << m_outputTS->m_ticks[src][dst] << endl;
}