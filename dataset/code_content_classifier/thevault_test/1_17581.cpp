void SickScanCommon::setProtocolType(SopasProtocol cola_dialect_id)
  {
    /* switch(cola_dialect_id)
    {
    case CoLa_A:
      ROS_INFO_STREAM("SickScanCommon::setProtocolType(CoLa_A)");
      break;
    case CoLa_B:
      ROS_INFO_STREAM("SickScanCommon::setProtocolType(CoLa_B)");
      break;
    default:
      ROS_INFO_STREAM("SickScanCommon::setProtocolType(CoLa_Unknown)");
      break;
    } */
    m_protocolId = cola_dialect_id;
  }