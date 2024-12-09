std::string PTXKernel::Prototype::getMangledName() const {
	std::stringstream ss;

	ss << identifier << "(";
	if (arguments.size()) {
		int n = 0;
		for (ParameterVector::const_iterator op_it = arguments.begin();
			op_it != arguments.end(); ++op_it) {
		
			ss << (n++ ? "," : "") << op_it->toString();	
		}
	}
	ss << ")";

	return ss.str();
}