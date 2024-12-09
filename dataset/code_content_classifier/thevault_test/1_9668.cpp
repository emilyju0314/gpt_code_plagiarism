HumNum HumNum::operator+(const HumNum& value) const {
	int a1  = getNumerator();
	int b1  = getDenominator();
	int a2  = value.getNumerator();
	int b2  = value.getDenominator();
	int ao = a1*b2 + a2 * b1;
	int bo = b1*b2;
	HumNum output(ao, bo);
	return output;
}