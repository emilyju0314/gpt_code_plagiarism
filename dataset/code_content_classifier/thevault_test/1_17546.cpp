void EamSetflInteractions::Evaluate2ndDerivatives(){
	y2embeddingValues=EvaluateSpline2ndDerivative(embeddingValues, drho);			// 2nd derivative vectors
	y2densityValues=EvaluateSpline2ndDerivative(densityValues, dr);
	y2pairValues=EvaluateSpline2ndDerivative(pairValues, dr);
}