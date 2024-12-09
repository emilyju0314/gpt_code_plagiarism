bool LocalizationHelpers::IsKeyInList(const AZStd::vector<AZStd::string>& keys, const AZStd::string& target, int& index)
{
    for (index = 0; index < keys.size(); ++index)
    {
        if (keys[index] == target)
        {
            return true;
        }
    }

    index = -1;
    return false;
}