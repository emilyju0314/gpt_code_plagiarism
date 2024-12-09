void RemoteAC::Update (const XPMP2::RemoteAcAnimTy& _acAnim)
{
    // Loop over all includes values and update the respective dataRef values
    for (std::uint8_t idx = 0; idx < _acAnim.numVals; ++idx) {
        const XPMP2::RemoteAcAnimTy::DataRefValTy& dr = _acAnim.v[idx];
        v[dr.idx] = XPMP2::REMOTE_DR_DEF[dr.idx].unpack(dr.v);
    }
}