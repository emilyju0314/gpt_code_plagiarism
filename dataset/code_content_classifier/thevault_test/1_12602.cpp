Bank :: Bank(const Bank& b)
{
    *this = b;
    this->stats = new Bank_stat_engine();
}