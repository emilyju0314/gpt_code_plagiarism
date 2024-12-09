int specCost( Type* ty ) {
		PassVisitor<CountSpecs> counter;
		maybeAccept( ty, *counter.pass.visitor );
		return counter.pass.get_count();
	}