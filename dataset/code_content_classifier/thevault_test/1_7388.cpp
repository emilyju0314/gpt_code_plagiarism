BigInt pow(const BigInt& base, BigInt exp) {
    if (exp < 0) {
        if (base == 0)
            throw std::logic_error("Cannot divide by zero");
        return abs(base) == 1 ? base : 0;
    }
    if (exp == 0) {
        if (base == 0)
            throw std::logic_error("Zero cannot be raised to zero");
        return 1;
    }
  
    BigInt result = base, result_odd = 1;
    while (exp > 1){
        if (exp % 2 == 1)
            result_odd *= result;
        result *= result;
        exp /= 2;
    }

    return result * result_odd;
}