ComponentPart(const vectorMat& filtersw, const vectori& filtersi,
			       const vectorf& biasw, const vectori& biasi, const vectorPoint& anchors,
			       const vector2Df& defw, const vectori& defi, const vector2Di& defid,
				   const vector2Di& biasid, const vector2Di& filterid, const vectori& parentid, int self) :
	   filtersw_(&filtersw), filtersi_(&filtersi),
	    biasw_(&biasw), biasi_(&biasi), anchors_(&anchors),
		defw_(&defw), defi_(&defi), defid_(&defid), biasid_(&biasid),
		filterid_(&filterid), parentid_(&parentid), self_(self) {}