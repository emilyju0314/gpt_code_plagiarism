bool
ColorTableAttributes::CreateNode(DataNode *parentNode, bool, bool)
{
    if(parentNode == 0)
        return true;

    // Create a node for ColorTableAttributes.
    DataNode *node = new DataNode("ColorTableAttributes");
    node->AddNode(new DataNode("activeContinuous", activeContinuous));
    node->AddNode(new DataNode("activeDiscrete", activeDiscrete));

    // Add each color table specially.
    char tmp[100];
    ColorControlPointList defaultObject;
    int index = 0;
    for(unsigned int i = 0; i < colorTables.size(); ++i)    
    {
        const ColorControlPointList &ccpl = GetColorTables(i);
        if(!ccpl.GetExternalFlag())
        {
            SNPRINTF(tmp, 100, "table%02d", index++);
            DataNode *ctNode = new DataNode(tmp);
            // Add the color table attributes to the ctNode.
            ctNode->AddNode(new DataNode("ctName", names[i]));
            if(!ccpl.FieldsEqual(1, &defaultObject))
                ctNode->AddNode(new DataNode("equal", ccpl.GetEqualSpacingFlag()));
            if(!ccpl.FieldsEqual(2, &defaultObject))
                ctNode->AddNode(new DataNode("smooth", ccpl.GetSmoothingFlag()));
            if(!ccpl.FieldsEqual(3, &defaultObject))
                ctNode->AddNode(new DataNode("discrete", ccpl.GetDiscreteFlag()));

            // Add the control points to the vector that we'll save out.
            floatVector fvec;
            for(int j = 0; j < ccpl.GetNumControlPoints(); ++j)
            {
                const ColorControlPoint &cp = ccpl.operator[](j);
                fvec.push_back(cp.GetPosition());
                fvec.push_back(float(cp.GetColors()[0]));
                fvec.push_back(float(cp.GetColors()[1]));
                fvec.push_back(float(cp.GetColors()[2]));
            }
            ctNode->AddNode(new DataNode("controlPts", fvec));
            node->AddNode(ctNode);
        }
    }

    node->AddNode(new DataNode("Ntables", index));

    // Add the node to the parent node.
    parentNode->AddNode(node);

    return true;
}