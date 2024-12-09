arma::mat ProjectHarvest_helperCpp(const arma::mat& data_n,const arma::mat& Surv, const arma::mat& Fec,const double& SRB,const arma::mat& H_n, const arma::mat& H_np1,bool global, const List& aK0,const bool & null){
	arma::mat X_n1 = (1-H_n) % (data_n/H_n);
	arma::mat D_bir = DD(global, X_n1, aK0[0], aK0[2] ,null);
	arma::mat D_dea = DD(global, X_n1, aK0[1], aK0[2] ,null);
	return(H_np1 % (getLeslieCpp(Surv % D_dea, Fec % D_bir, SRB)*X_n1));
	
}