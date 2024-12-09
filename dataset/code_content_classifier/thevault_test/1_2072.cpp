std::string DivergenceGraph::getSpecialName( const ir::PTXOperand* in ) const{
	assert (in->special < ir::PTXOperand::SpecialRegister_invalid);
	return (ir::PTXOperand::toString(in->special).erase(0, 1)
		+ ir::PTXOperand::toString(in->vIndex));
}