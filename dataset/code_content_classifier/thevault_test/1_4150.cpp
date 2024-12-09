Fraction Fraction::sub(const Fraction& F) const {

	Fraction negFrac = F;
	negFrac.setNum(negFrac.getNum() * -1);

	Fraction localFrac = add(negFrac);

	return localFrac.reduce();
}