bool GetIpByHostName(int familyType, const char* hostName, AZStd::string& ip)
        {
            static const size_t kMaxLen = 64; // max length of ipv6 ip is 45 chars, so all ips should be able to fit in this buf
            char ipBuf[kMaxLen];

            addrinfo hints;
            memset(&hints, 0, sizeof(struct addrinfo));
            addrinfo* addrInfo;
            hints.ai_family = (familyType == Driver::BSD_AF_INET6) ? AF_INET6 : AF_INET;
            hints.ai_flags = AI_CANONNAME;

            int result = Platform::GetAddressInfo(hostName, nullptr, &hints, &addrInfo);
            if (result)
            {
                return false;
            }

            if (addrInfo->ai_family == AF_INET6)
            {
                ip = inet_ntop(hints.ai_family, &reinterpret_cast<sockaddr_in6*>(addrInfo->ai_addr)->sin6_addr, ipBuf, AZ_ARRAY_SIZE(ipBuf));
            }
            else
            {
                ip = inet_ntop(hints.ai_family, &reinterpret_cast<sockaddr_in*>(addrInfo->ai_addr)->sin_addr, ipBuf, AZ_ARRAY_SIZE(ipBuf));
            }

            Platform::FreeAddressInfo(addrInfo);
            return true;
        }