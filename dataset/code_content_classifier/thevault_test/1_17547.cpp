void ThomasAlgorithm(Eigen::VectorXd& a, Eigen::VectorXd& b, Eigen::VectorXd& c, Eigen::VectorXd& y, Eigen::VectorXd& x){
	int numvals=b.size();
	// forward step
	Eigen::VectorXd c2(numvals-1), y2(numvals);
	c2(0)=c(0)/b(0);
	y2(0)=y(0)/b(0);
	for(int i=1; i<numvals-1; i++){
		c2(i)=c(i)/(b(i)-a(i-1)*c2(i-1));
		y2(i)=(y(i)-a(i-1)*y2(i-1))/(b(i)-a(i-1)*c2(i-1));
	}
	y2(numvals-1)=(y(numvals-1)-a(numvals-2)*y2(numvals-2))/(b(numvals-1)-a(numvals-2)*c2(numvals-2));
	// back substitution
	x(numvals-1)=y2(numvals-1);
	for(int i=numvals-2; i>0; i--){
		x(i)=y2(i)-c2(i)*x(i+1);
	}
}