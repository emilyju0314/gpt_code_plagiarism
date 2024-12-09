FOREACH(PeerPtr& peer, peers)
        {
          if (peer.get() != &receivingPeer && peer->ready)
          {
            sf::Packet notifyPacket;
            notifyPacket << static_cast<sf::Int32>(Server::PlayerConnect);
            notifyPacket << aircraftIdentifierCounter;
            notifyPacket << aircraftInfo[aircraftIdentifierCounter].position.x;
            notifyPacket << aircraftInfo[aircraftIdentifierCounter].position.y;
            peer->socket.send(notifyPacket);
          }
        }