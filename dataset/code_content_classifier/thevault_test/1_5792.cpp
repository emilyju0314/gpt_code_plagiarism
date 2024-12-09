void PeptideNamespace::Peptide::printFragments(std::ostream& out,
        bool printHeader, bool printFoundIntensity) const
{
	assert(out);

	if(printHeader) {
        out << "index" << OUT_DELIM << "label" << OUT_DELIM << "mz";
        if(printFoundIntensity)
            out << OUT_DELIM << "foundIntensity";
        out << NEW_LINE;
    }
	size_t len = fragments.size();
	for(size_t i = 0; i < len; i++) {
        out << i << OUT_DELIM <<
            fragments[i].getLabel() <<
            OUT_DELIM << fragments[i].getMZ();
            if(printFoundIntensity)
                out << OUT_DELIM << fragments[i].getFoundIntensity();
        out << NEW_LINE;
    }
}