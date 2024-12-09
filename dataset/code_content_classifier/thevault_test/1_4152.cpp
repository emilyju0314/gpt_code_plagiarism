Fraction Fraction::div(const Fraction& F) const {

	Fraction localFrac;
	Fraction recipFrac;

	recipFrac.setNum(F.getDenom());
	recipFrac.setDenom(F.getNum());

	localFrac = mul(recipFrac);

	return localFrac;

}