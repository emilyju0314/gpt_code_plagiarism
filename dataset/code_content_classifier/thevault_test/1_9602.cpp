std::string MuseRecord::getDirectionTypeString(void) {
	string output = getDirectionTypeField();
	if (output.back() == ' ') {
		output.resize(output.size() - 1);
	}
	if (output.back() == ' ') {
		output.resize(output.size() - 1);
	}
	return output;
}