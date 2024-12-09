void StatsAlerter::checkAndAlert(const std::vector<float>& n)
{
    for (auto i : n)
    {
        if (i > max)
        { 
            for (int j = 0; j < al.size(); ++j)
            {
                this->al.at(j)->SetAlert();
            }
            break;
        }
    }
}