std::string BasicBlock::DotFormatter::entryLabel(
	const BasicBlock *block) {
	std::stringstream out;
	out << "[shape=Mdiamond,label=\"" << block->label() << "\"]";	
	return out.str();
}