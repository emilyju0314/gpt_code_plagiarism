void ArtifactNLMS3::train(mat X)
{
	// in the below we use (roughly) the notation of Haykin, 4th ed. pg 324

	size_t t = X.n_cols;

	// copy X -> Y
	mat Y(X);

	mat Z(W);	// copy W -> Z

	for (size_t i=0; i<n; i++) {

		X.row(i).zeros();

		for (size_t k=0; k<t; k++) {

			// yhat = w(k) * x(k)
			double yhat = dot(W.col(i), X.col(k));

			// alpha(k) = y(k) - w'(k) * x(k);
			double alpha = Y(i, k) - yhat;

			// temp(k) = (mu * alpha(k) (k)) / ||x(k)||^2
			double xnorm = norm(X.col(k));
			double temp = (mu * alpha) / ((xnorm * xnorm) + FLT_EPSILON);

			// w(k+1) = w(k) + x(k) * temp(k)
			// scalar has to come second because of operator overloading
			Z.col(i) += X.col(k) * temp;
		}

		X.row(i) = Y.row(i);
	}

	{
		lock_guard<mutex> lock(mtx);
		W = Z;
	}

}