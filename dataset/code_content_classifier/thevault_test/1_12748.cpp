void tpros::set_up_priors ( void ){
	int i , j , tint ;
	double  temp1 , temp2 ;
	if( lengthprior >= 1 ){
		for(i=1; i <= ngauss; ++i){
			for(j=1; j <= mInputDimension; ++j){
				tint = (i-1)*mInputDimension*npoly + (j-1)*npoly + 1;
				if( npoly > 1 ){	  /* For polynomial case */
					if( gamr_b[i][j] <= 0.0 ){
						printf("\nERROR - default prior not available for polynomial length scales\n");
						Msg::error("tpros error");
					} 
					gamr_a[i][j] = 0.0;

					printf("Length scale prior (%d,%d)(mean,sd) : %-6.2g %-6.2g\n",i,j,gamr_a[i][j],gamr_b[i][j]);
					printf("Length scale offset prior (%d,%d)(mean2,sd2) : %-6.2g %-6.2g\n",i,j,gamr2_a[i][j],gamr2_b[i][j]);

				} else {	  /* For non-polynomial case */
					if( gamr_a[i][j] <= 0.0 ){
						temp1 = prior_length_default  ;            /* mean */
						temp2 = prior_strength_default;            /* d.o.f. */
					} else {
						/* Scaling for Gamma prior */
						if( lengthprior == 1 ){
							printf("Length scale prior (mean,sd) option discontinued\n");
							Msg::error("tpros error");
						}
						else { /* if( lengthprior == 2 ) */
							/* mean and degrees of freedom representation */
							temp1 = gamr_a[i][j]; /* mean   */
							temp2 = gamr_b[i][j]; /* d.o.f. */
						}
					}
					gamr_a[i][j] = temp2;
					gamr_b[i][j] = temp2/temp1;
					if( verbose != 0 ) printf("Length scale prior  (%d,%d)(mean,strength) : %-6.2g %-6.2g a=%-6.2g, b=%-6.2g\n",i,j,temp1,temp2,gamr_a[i][j]  ,gamr_b[i][j] );
				}
			}
		}
	}
	if( noiseprior >= 1 ){
		if( nhidden > 1 ){      /* For polynomial case */
			if( gamn_b <= 0.0 ){
				printf("\nERROR - default prior not available for polynomial noise model\n");
				Msg::error("tpros error");
			} 
			gamn_a = 0.0; /* zero mean Gaussian */
		} else {      /* For non-polynomial case */	/* Inverse Gamma prior */
			if( gamn_a <= 0.0 ){
				temp1 = prior_vertical_default * prior_fractional_noise_default ;
				temp1 = temp1 * temp1 ; 
				temp2 = prior_strength_default;                       /* d.o.f. */
			} else {
				if( noiseprior == 1 ){
					if( 1 ) printf("Noise level prior (mean,sd) option discontinued\n");
					Msg::error("tpros error") ; 
				} else { /* if( noiseprior == 2 ) */
					temp1 = gamn_a; /* centre of noise variance's prior  */
					temp2 = gamn_b; /* d.o.f. */
					if( noiseprior == 3 ){
						printf("Noise level prior (CBJ) option discontinued\n");
					}
				}

			}
			gamn_a = temp2/2.0 ;
			gamn_b = (temp2/2.0) * temp1;
			if( verbose != 0 ) printf("Noise level prior        (mean,strength) : %-6.2g %-6.2g a=%-6.2g, b=%-6.2g\n",temp1,temp2 , gamn_a , gamn_b );
		}
	}
	if( theta1prior >= 1 ){            /*  Inverse Gamma prior */
		if( gamt1_a <= 0.0 ){
			temp1 = prior_vertical_default * prior_vertical_default ;
			temp2 = prior_strength_default;                       /* d.o.f. */
		} else {
			if( theta1prior == 1 ){
				if( 1 ) printf("Theta1 prior (mean,sd) option not available\n");
				Msg::error("tpros error");
			} else { /*      if( theta1prior == 2 ) */
				temp1 = gamt1_a; /* mean vertical variance  */
				temp2 = gamt1_b; /* d.o.f. */
			}
		}
		gamt1_a = temp2/2.0 ;
		gamt1_b = (temp2/2.0 ) * temp1;
		if( verbose != 0 ) printf("Theta1 prior             (mean,strength) : %-6.2g %-6.2g a=%-6.2g, b=%-6.2g\n",temp1,temp2 , gamt1_a , gamt1_b );
	}
	if( theta2prior >= 1 ){
		if( gamt2_a <= 0.0 ){
			temp1 = prior_fractional_theta2_default * prior_vertical_default ;
			/* mean */
			temp2 = prior_strength_default;                       /* d.o.f. */
		} else {
			if( theta2prior == 1 ){
				if( 1 ) printf("Theta2 prior (mean,sd) option not available\n");
				Msg::error("tpros error");
			} else { /*      if( theta2prior == 2 ) */
				temp1 = gamt2_a; /* mean   */
				temp2 = gamt2_b; /* d.o.f. */
			}
		}
		gamt2_a = temp2/2.0 ;
		gamt2_b = (temp2/2.0) * temp1;;
		if( verbose != 0 ) printf("Theta2 prior             (mean,strength) : %-6.2g %-6.2g a=%-6.2g, b=%-6.2g\n",temp1,temp2 , gamt2_a , gamt2_b );
	}
	if( linearprior >= 1 ){
		if( gaussl_m <= 0.0 ){
			/* if priors not set then program does it automatically */
			gaussl_m = prior_linear_default ; 
			temp1 = 0.0;
			for(i=1; i <= mNumTrainingData; ++i){
				temp1 += pow( t[i], 2.0 ); /* was  t[i]-HYP_THETA_0  
										   but I want independence of hyp[] */
			}
			gaussl_sd = pow( temp1 / (double)(mNumTrainingData) , 0.5 );
		}      
		if( verbose != 0 ) printf("Linear term prior        (mean,sd)  : %-6.2g %-6.2g\n",gaussl_m,gaussl_sd);
	}
	if( theta0prior >= 1 ){
		if( gausst0_m <= 0.0 ){
			/* if priors not set then program does it automatically */
			temp1 = 0.0;
			for(i=1; i <= mNumTrainingData; ++i){
				temp1 += t[i];
			}
			gausst0_m  = temp1/(double)(mNumTrainingData); /* data mean */
			temp1 = 0.0;
			for(i=1; i <= mNumTrainingData; ++i){
				temp1 += pow( t[i]-gausst0_m , 2.0 );/* was  t[i]-HYP_THETA_0  */
			}
			gausst0_sd = pow( temp1 / (double)(mNumTrainingData) , 0.5 ); /* vertical s.d. of target */
		} 
		if( verbose != 0 ) printf("Variable Mean prior      (mean,sd)  : %-6.2g %-6.2g\n",gausst0_m,gausst0_sd);
	}

	printf("\n");
}