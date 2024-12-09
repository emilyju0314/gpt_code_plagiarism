Fraction Fraction::reduce() {

	Fraction localFrac;

	localFrac.setNum(getNum());
	localFrac.setDenom(getDenom());


	for (int denomC = localFrac.getDenom(); denomC > 1; --denomC) {
		if (localFrac.getNum() % denomC == 0 && localFrac.getDenom() % denomC == 0) {
			localFrac.setNum(localFrac.getNum() / denomC);
			localFrac.setDenom(localFrac.getDenom() / denomC);
		}
	}

	return localFrac;

}