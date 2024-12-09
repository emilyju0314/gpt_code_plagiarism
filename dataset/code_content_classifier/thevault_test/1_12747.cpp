void tpros::sample( void )
{
	int    i,j,k;
	double *EIG,*e;
	FILE   *fp1;
	mac_inter_C( );

	LU_invert(C,C_inv,mNumTrainingData);

	for(i=1; i <= mNumTrainingData; ++i){
		for(j=1; j <= mNumTrainingData; ++j){
			C_temp[i][j] = C_inv[i][j];
		}
	}

	e = dvector(1,mNumTrainingData);
	EIG = dvector(1,mNumTrainingData);

	tred2(C_temp,mNumTrainingData,EIG,e);
	tqli(EIG,e,mNumTrainingData,C_temp);

	fp1 = fopen( outfile, "w" );
	for(k=1; k <= 2; ++k) {

		for(i=1; i <= mNumTrainingData; ++i){
			e[i] = rand_gaussian( ) * pow( EIG[i], -0.5 );
		}

		for(i=1; i <= mNumTrainingData; ++i){
			t[i] = 0.0;
			for(j=1; j <= mNumTrainingData; ++j){
				t[i] += C_temp[i][j]*e[j];
			}
			fprintf(fp1,"%f %f\n",k_x[i][1],t[i]);
		}
		fprintf(fp1,"\n");

	}
	fclose( fp1 );

	Msg::error("tpros error");
}