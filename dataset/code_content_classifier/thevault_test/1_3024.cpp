int Matrix::save(pugi::xml_node root)
{
	if(!root)
		return 1;

	//Add the matrix node
	pugi::xml_node matrix_node = root.append_child("matrix");

	//Determine indent
	char indent[20];
	int depth = matrix_node.depth() - 1;
	int idx;
	for(idx = 0; idx < depth; idx++)
		indent[idx] = '\t';
	indent[idx] = '\0';

	//Build a formated string with the matrix values
	std::ostringstream mat_stream;
	mat_stream << std::setiosflags(std::ios::showpoint) << std::endl << indent;
	mat_stream << DEC_FORMAT << r0[0] << " ";
	mat_stream << DEC_FORMAT << r0[1] << " ";
	mat_stream << DEC_FORMAT << r0[2] << " ";
	mat_stream << DEC_FORMAT << r0[3] << std::endl << indent;

	mat_stream << DEC_FORMAT << r1[0] << " ";
	mat_stream << DEC_FORMAT << r1[1] << " ";
	mat_stream << DEC_FORMAT << r1[2] << " ";
	mat_stream << DEC_FORMAT << r1[3] << std::endl << indent;

	mat_stream << DEC_FORMAT << r2[0] << " ";
	mat_stream << DEC_FORMAT << r2[1] << " ";
	mat_stream << DEC_FORMAT << r2[2] << " ";
	mat_stream << DEC_FORMAT << r2[3] << std::endl << indent;

	mat_stream << DEC_FORMAT << r3[0] << " ";
	mat_stream << DEC_FORMAT << r3[1] << " ";
	mat_stream << DEC_FORMAT << r3[2] << " ";
	mat_stream << DEC_FORMAT << r3[3] << std::endl;

	indent[depth - 1] = '\0';
	mat_stream << indent;

	//Create string and add to node
	std::string matrix = mat_stream.str();
	matrix_node.text() = matrix.c_str();

	return 0;
}