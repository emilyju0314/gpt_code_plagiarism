bool Fraction::gt(const Fraction& F) {

	double F1 = getNum() / getDenom();
	double F2 = F.getNum() / F.getDenom();

	if (F1 > F2) return true;
	else return false;

}