QColor BlendTreeVisualNode::GetPortColor(const EMotionFX::AnimGraphNode::Port& port) const
    {
        switch (port.m_compatibleTypes[0])
        {
        case EMotionFX::AttributePose::TYPE_ID:
            return QColor(150, 150, 255);
        case MCore::AttributeFloat::TYPE_ID:
            return QColor(0, 200, 0);
        case MCore::AttributeInt32::TYPE_ID:
            return QColor(0, 200, 100);
        case MCore::AttributeBool::TYPE_ID:
            return QColor(0, 200, 200);
        case MCore::AttributeVector2::TYPE_ID:
            return QColor(100, 0, 100);
        case MCore::AttributeVector3::TYPE_ID:
            return QColor(175, 0, 175);
        case MCore::AttributeVector4::TYPE_ID:
            return QColor(255, 0, 255);
        case MCore::AttributeString::TYPE_ID:
            return QColor(50, 75, 255);

        default:
            return QColor(50, 250, 250);
        }
    }