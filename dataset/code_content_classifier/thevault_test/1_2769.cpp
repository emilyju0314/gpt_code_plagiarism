ComponentPart(const ComponentPart& other, int self) :
		filtersw_(other.filtersw_), filtersi_(other.filtersi_),
		biasw_(other.biasw_), biasi_(other.biasi_), anchors_(other.anchors_),
		defw_(other.defw_), defi_(other.defi_), defid_(other.defid_), biasid_(other.biasid_),
		filterid_(other.filterid_), parentid_(other.parentid_), self_(self) {}