Fraction Fraction::mul(const Fraction& F) const {

	Fraction localFrac;

	localFrac.setNum(getNum() * F.getNum());
	localFrac.setDenom(getDenom() * F.getDenom());

	return localFrac.reduce();
}