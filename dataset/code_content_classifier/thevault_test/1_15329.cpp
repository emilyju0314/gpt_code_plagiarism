double NumberWithUnits::unitConvertor(double number /*change value*/, const string &unit1 /*from*/, const string &unit2 /*to*/)
  {
    if (unit1 == unit2)
    {
      return number;
    }
    try
    {
      double coef = _unitConvertor.at(unit1).at(unit2);
      return (number * coef);
    }
    catch (const out_of_range &e)
    {
      throw invalid_argument{"Units do not match - [" + unit1 + "] cannot be converted to [" + unit2 + "]"};
    }
  }