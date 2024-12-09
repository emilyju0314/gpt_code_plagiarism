bool ConnectionWorker::NegotiateDirect(bool initiate)
{
#if defined(DEBUG_NEGOTIATION)
    AZ_TracePrintf(AssetProcessor::DebugChannel, "ConnectionWorker::NegotiateDirect: %p", this);
#endif
    using Detail::ReadNegotiation;
    using Detail::WriteNegotiation;
    using namespace AzFramework::AssetSystem;

    AZStd::string azBranchToken;
    AzFramework::ApplicationRequests::Bus::Broadcast(&AzFramework::ApplicationRequests::CalculateBranchTokenForEngineRoot, azBranchToken);
    QString branchToken(azBranchToken.c_str());
    QString projectName = AssetUtilities::ComputeProjectName();
    
    NegotiationMessage myInfo;

    char processId[20];
    azsnprintf(processId, 20, "%lld", QCoreApplication::applicationPid());
    myInfo.m_identifier = "ASSETPROCESSOR";
    myInfo.m_negotiationInfoMap.insert(AZStd::make_pair(NegotiationInfo_ProcessId, AZ::OSString(processId)));
    myInfo.m_negotiationInfoMap.insert(AZStd::make_pair(NegotiationInfo_BranchIndentifier, AZ::OSString(azBranchToken.c_str())));
    myInfo.m_negotiationInfoMap.insert(AZStd::make_pair(NegotiationInfo_ProjectName, AZ::OSString(projectName.toUtf8().constData())));
    NegotiationMessage engineInfo;

    if (initiate)
    {
        if (!WriteNegotiation(this, m_engineSocket, myInfo))
        {
            Q_EMIT ErrorMessage("Unable to send negotiation message");
            QTimer::singleShot(0, this, SLOT(DisconnectSockets()));
            return false;
        }

        if (!ReadNegotiation(this, m_waitDelay, m_engineSocket, engineInfo))
        {
            Q_EMIT ErrorMessage("Unable to read negotiation message");
            QTimer::singleShot(0, this, SLOT(DisconnectSockets()));
            return false;
        }
    }
    else
    {
        unsigned int serial = 0;
#if defined(DEBUG_NEGOTIATION)
        AZ_TracePrintf(AssetProcessor::DebugChannel, "ConnectionWorker::NegotiateDirect: Reading negotiation from engine socket %p", this);
#endif
        if (!ReadNegotiation(this, m_waitDelay, m_engineSocket, engineInfo, &serial))
        {
#if defined(DEBUG_NEGOTIATION)
            AZ_TracePrintf(AssetProcessor::DebugChannel, "ConnectionWorker::NegotiateDirect: no negotation arrived %p", this);
#endif
            Q_EMIT ErrorMessage("Unable to read engine negotiation message");
            QTimer::singleShot(0, this, SLOT(DisconnectSockets()));
            return false;
        }

#if defined(DEBUG_NEGOTIATION)
        AZ_TracePrintf(AssetProcessor::DebugChannel, "ConnectionWorker::NegotiateDirect: writing negotiation to engine socket %p", this);
#endif
        if (!WriteNegotiation(this, m_engineSocket, myInfo, serial))
        {
#if defined(DEBUG_NEGOTIATION)
            AZ_TracePrintf(AssetProcessor::DebugChannel, "ConnectionWorker::NegotiateDirect: no negotation sent %p", this);
#endif
            Q_EMIT ErrorMessage("Unable to send negotiation message");
            QTimer::singleShot(0, this, SLOT(DisconnectSockets()));
            return false;
        }
    }

    // Skip the process Id validation during negotiation if the identifier is UNITTEST
    if (engineInfo.m_identifier != "UNITTEST")
    {
        if (strncmp(engineInfo.m_negotiationInfoMap[NegotiationInfo_ProcessId].c_str(), processId, strlen(processId)) == 0)
        {
            Q_EMIT ErrorMessage("Attempted to negotiate with self");
            QTimer::singleShot(0, this, SLOT(DisconnectSockets()));
            return false;
        }
    }

    if (engineInfo.m_apiVersion != myInfo.m_apiVersion)
    {
        Q_EMIT ErrorMessage("Negotiation Failed.Version Mismatch.");
        QTimer::singleShot(0, this, SLOT(DisconnectSockets()));
        return false;
    }

    QString incomingBranchToken(engineInfo.m_negotiationInfoMap[NegotiationInfo_BranchIndentifier].c_str());
    if (QString::compare(incomingBranchToken, branchToken, Qt::CaseInsensitive) != 0)
    {
        // if we are here it means that the editor/game which is negotiating is running on a different branch
        // note that it could have just read nothing from the engine or a repeat packet, in that case, discard it silently and try again.
        AZ_TracePrintf(AssetProcessor::ConsoleChannel, "ConnectionWorker::NegotiateDirect: branch token mismatch from %s - %p - %s vs %s\n", engineInfo.m_identifier.c_str(), this, incomingBranchToken.toUtf8().data(), branchToken.toUtf8().data());
        AssetProcessor::MessageInfoBus::Broadcast(&AssetProcessor::MessageInfoBus::Events::NegotiationFailed);
        QTimer::singleShot(0, this, SLOT(DisconnectSockets()));
        return false;
    }

    QString incomingProjectName(engineInfo.m_negotiationInfoMap[NegotiationInfo_ProjectName].c_str());
    // Do a case-insensitive compare for the project name because some (case-sensitive) platforms will lower-case the incoming project name
    if(QString::compare(incomingProjectName, projectName, Qt::CaseInsensitive) != 0)
    {
        AZ_TracePrintf(AssetProcessor::ConsoleChannel, "ConnectionWorker::NegotiateDirect: project name mismatch from %s - %p - %s vs %s\n", engineInfo.m_identifier.c_str(), this, incomingProjectName.toUtf8().constData(), projectName.toUtf8().constData());
        AssetProcessor::MessageInfoBus::Broadcast(&AssetProcessor::MessageInfoBus::Events::NegotiationFailed);
        QTimer::singleShot(0, this, SLOT(DisconnectSockets()));
        return false;
    }

    Q_EMIT Identifier(engineInfo.m_identifier.c_str());
    Q_EMIT AssetPlatformsString(engineInfo.m_negotiationInfoMap[NegotiationInfo_Platform].c_str());

#if defined(DEBUG_NEGOTIATION)
    AZ_TracePrintf(AssetProcessor::DebugChannel, "ConnectionWorker::NegotiateDirect: negotation complete %p", this);
#endif

    Q_EMIT ConnectionEstablished(m_engineSocket.peerAddress().toString(), m_engineSocket.peerPort());
    connect(&m_engineSocket, &QTcpSocket::readyRead, this, &ConnectionWorker::EngineSocketHasData);
    // force the socket to evaluate any data recv'd between negotiation and now
    QTimer::singleShot(0, this, SLOT(EngineSocketHasData()));

    return true;
}