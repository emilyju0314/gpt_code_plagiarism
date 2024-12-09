bool DivergenceGraph::isDivSource( const ir::PTXOperand* srt ) const{
	return ((srt->addressMode == ir::PTXOperand::Special) &&
		( (srt->special == ir::PTXOperand::laneId) ||
		(srt->special == ir::PTXOperand::tid &&
		(srt->vIndex == ir::PTXOperand::ix))));
}