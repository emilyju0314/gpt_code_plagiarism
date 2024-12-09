bool MainWindow::SampleRoboDkEvent(int evt, Item itm)
{
    qDebug() << "";
    qDebug() << "**** New event ****";

    //If this runs in a seperate thread from the api instance thaw sapwned it you won't be able to do
    //Regular api calls like item.Valid()
    //if (itm.Valid())
    //{
        //qDebug() << "  Item: " + itm.Name() + " -> Type: " + itm.Type();
    //}
    //else
    //{
        //Console.WriteLine("  Item not applicable");
    //}

    switch (evt)
    {
        case RoboDK::EVENT_SELECTION_TREE_CHANGED:
            qDebug() << "Event: Selection changed (the tree was selected)";
            break;
        case RoboDK::EVENT_ITEM_MOVED:
            qDebug() << "Event: Item Moved";
            break;
        case RoboDK::EVENT_REFERENCE_PICKED:
            qDebug() << "Event: Reference Picked";
            break;
        case RoboDK::EVENT_REFERENCE_RELEASED:
            qDebug() << "Event: Reference Released";
            break;
        case RoboDK::EVENT_TOOL_MODIFIED:
            qDebug() << "Event: Tool Modified";
            break;
        case RoboDK::EVENT_3DVIEW_MOVED:
            qDebug() << "Event: 3D view moved"; // use ViewPose to retrieve the pose of the camera
            break;
        case RoboDK::EVENT_ROBOT_MOVED:
            qDebug() << "Event: Robot moved";
            break;

        // Important: The following events require consuming additional data from the _COM_EVT buffer
        case RoboDK::EVENT_SELECTION_3D_CHANGED:
        {
            qDebug() << "Event: Selection changed";
            // data contains the following information (24 values):
            // pose (16), xyz selection (3), ijk normal (3), picked feature id (1), picked id (1)
            //double[] data = RDK._recv_Array(RDK->_COM_EVT);
            double data[24];
            int valueCount;
            RDK->Event_Receive_3D_POS(data,&valueCount);
            //
            Mat pose_abs = Mat(data);
            double xyz[3] = { data[16], data[17], data[18] };
            double ijk[3] = { data[19], data[20], data[21] };
            int feature_type = data[22];
            int feature_id = data[23];
            qDebug() << "Additional event data - Absolute position (PoseAbs):";
            qDebug() << pose_abs.ToString();
            qDebug() << "Additional event data - Point and Normal (point selected in relative coordinates)";
            qDebug() << QString::number(xyz[0]) + "," + QString::number(xyz[1]) + "," + QString::number(xyz[2]);
            qDebug() << QString::number(ijk[0]) + "," + QString::number(ijk[1]) + "," + QString::number(ijk[2]);
            qDebug() << "Feature Type and ID";
            qDebug() << QString::number(feature_type) + "-" + QString::number(feature_id);
            break;
        }
        case RoboDK::EVENT_KEY:
        {
            int mouseData[3];
            RDK->Event_Receive_Mouse_data(mouseData);
            int key_press = mouseData[0]; // 1 = key pressed, 0 = key released
            int key_id = mouseData[1]; // Key id as per Qt mappings: https://doc.qt.io/qt-5/qt.html#Key-enum
            int modifiers = mouseData[2]; // Modifier bits as per Qt mappings: https://doc.qt.io/qt-5/qt.html#KeyboardModifier-enum
            qDebug() << "Event: Key pressed: " + QString::number(key_id) + " " + ((key_press > 0) ? "Pressed" : "Released") + ". Modifiers: " + QString::number(modifiers);
            break;
        }
        case RoboDK::EVENT_ITEM_MOVED_POSE:
        {
            Mat pose_rel;
            bool flag = RDK->Event_Receive_Event_Moved(&pose_rel);
            //int nvalues = _recv_Int(_COM_EVT);
            //Mat pose_rel = _recv_Pose(_COM_EVT);
            if (flag == false)
            {
                // future compatibility
            }
            qDebug() << "Event: item moved. Relative pose: " + pose_rel.ToString();
            break;
        }
        default:
            qDebug() << "Unknown event " + QString::number(evt);
            break;
    }
    return true;
}