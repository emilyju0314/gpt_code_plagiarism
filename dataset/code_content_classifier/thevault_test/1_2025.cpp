size_t ExecutableKernel::mapArgumentOffsets() {
	unsigned int size = 0;

	for (ParameterVector::iterator it = arguments.begin();
			it != arguments.end(); ++it) {
		unsigned int misAlignment = size % it->getAlignment();
		size += misAlignment == 0 ? 0 : it->getAlignment() - misAlignment;

		it->offset = size;
		size += it->getSize();
	}

	report("ExecutableKernels::mapArgumentOffsets() - '" << name 
		<< "' - size: " << size << " bytes");

	return size;
}