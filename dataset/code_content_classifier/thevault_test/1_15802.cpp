foreach(const QHostAddress& address, QNetworkInterface::allAddresses()) {
		if (address.protocol() == QAbstractSocket::IPv4Protocol &&
				address != QHostAddress(QHostAddress::LocalHost) &&
				address.toString().section(".", -1, -1 ) != "1") {

			m_ipAddress = address.toString();
		}
	}