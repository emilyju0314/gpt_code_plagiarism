void add_matrix_to_vectors(Matrix &block, std::vector<double> &V,
                           std::vector<int>  &I, std::vector<int> &J,
                           int &vert_offset, int &horiz_offset){
	for ( int k = 0; k < block.outerSize(); ++k ) {
		for ( Matrix::InnerIterator it(block, k); it; ++it ){
			V.push_back(it.value());

			/* Push back current row and column indices */
			I.push_back(it.row() + vert_offset);   	
			J.push_back(it.col() + horiz_offset);
		}
	}
}