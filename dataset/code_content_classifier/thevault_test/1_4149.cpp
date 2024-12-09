Fraction Fraction::add(const Fraction& F) const {

	Fraction localFrac;
	localFrac.setDenom(getDenom() * F.getDenom());
	localFrac.setNum( (getNum() * F.getDenom()) + (F.getNum() * getDenom()) );

	return localFrac.reduce();

}