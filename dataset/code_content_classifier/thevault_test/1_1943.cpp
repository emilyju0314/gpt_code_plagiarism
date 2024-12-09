std::string BasicBlock::DotFormatter::exitLabel(
	const BasicBlock *block) {
	std::stringstream out;
	out << "[shape=Msquare,label=\"" << block->label() << "\"]";	
	return out.str();
}