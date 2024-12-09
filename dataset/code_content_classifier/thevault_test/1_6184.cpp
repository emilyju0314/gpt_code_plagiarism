void SoundIdentificationProcessing::ComputeIDCMatrix (
	const int rows,
	const int columns,
	YMatrix &idctMatrix,
	int writeToFile
	) {
	
	int i = 0;
	int k = 0;

	idctMatrix.Resize ( 
		rows,
		columns
		);

	
	for ( i = 0; i < rows; i++ ) {
		for ( k = 0; k < columns; k++) {
			idctMatrix( i+1, k+1 ) =  cos ( k * (2 * i +1) * (PI / 2.0f) / (double) rows);
			idctMatrix( i+1, k+1 ) *= ( 1.0f / (double) sqrtf( rows / 2.0f ));
		}
	}

	for ( k = 1; k <= rows; k++)
		idctMatrix ( k, 1 ) = idctMatrix ( k, 1 ) * (sqrtf(2.0f) / 2.0f);

	if ( writeToFile ) {
		FILE *f = fopen ("./output/idctmatrix.txt", "a");

		for ( i = 0; i < rows; i++ ) {
			for ( k = 0; k < columns; k++) {
				fprintf(f,"%f ", idctMatrix( i+1, k+1));
			}
			fprintf( f, "\n");
		}
		fclose( f );
	}

}