void writeFlat(ofstream &os, const Statistics *s) {
    os << valueToString(s->Minimum()) << "," <<
       valueToString(s->Maximum()) << "," <<
       valueToString(s->Average()) << "," <<
       valueToString(s->StandardDeviation()) << ",";
  }