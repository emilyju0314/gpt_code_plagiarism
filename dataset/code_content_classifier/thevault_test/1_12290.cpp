AZStd::string GetNeighborhoodName()
        {
            AZStd::string neighborhoodName;

            wchar_t localhost[MAX_COMPUTERNAME_LENGTH + 1];
            DWORD len = AZ_ARRAY_SIZE(localhost);
            if (GetComputerNameW(localhost, &len))
            {
                AZStd::to_string(neighborhoodName, localhost);
            }

            return neighborhoodName;
        }