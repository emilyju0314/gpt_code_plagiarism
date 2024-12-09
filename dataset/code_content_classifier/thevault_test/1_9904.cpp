bool
VolumeAttributes::CreateNode(DataNode *parentNode, bool completeSave, bool forceAdd)
{
    if(parentNode == 0)
        return false;

    VolumeAttributes defaultObject;
    bool addToParent = false;
    // Create a node for VolumeAttributes.
    DataNode *node = new DataNode("VolumeAttributes");

    if(completeSave || !FieldsEqual(0, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("legendFlag", legendFlag));
    }

    if(completeSave || !FieldsEqual(1, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("lightingFlag", lightingFlag));
    }

    if(completeSave || !FieldsEqual(2, &defaultObject))
    {
        DataNode *colorControlPointsNode = new DataNode("colorControlPoints");
        if(colorControlPoints.CreateNode(colorControlPointsNode, completeSave, false))
        {
            addToParent = true;
            node->AddNode(colorControlPointsNode);
        }
        else
            delete colorControlPointsNode;
    }

    if(completeSave || !FieldsEqual(3, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("opacityAttenuation", opacityAttenuation));
    }

    if(completeSave || !FieldsEqual(4, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("freeformFlag", freeformFlag));
    }

    if(completeSave || !FieldsEqual(5, &defaultObject))
    {
        DataNode *opacityControlPointsNode = new DataNode("opacityControlPoints");
        if(opacityControlPoints.CreateNode(opacityControlPointsNode, completeSave, false))
        {
            addToParent = true;
            node->AddNode(opacityControlPointsNode);
        }
        else
            delete opacityControlPointsNode;
    }

    if(completeSave || !FieldsEqual(6, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("resampleTarget", resampleTarget));
    }

    if(completeSave || !FieldsEqual(7, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("opacityVariable", opacityVariable));
    }

    if(completeSave || !FieldsEqual(8, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("freeformOpacity", freeformOpacity, 256));
    }

    if(completeSave || !FieldsEqual(9, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("useColorVarMin", useColorVarMin));
    }

    if(completeSave || !FieldsEqual(10, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("colorVarMin", colorVarMin));
    }

    if(completeSave || !FieldsEqual(11, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("useColorVarMax", useColorVarMax));
    }

    if(completeSave || !FieldsEqual(12, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("colorVarMax", colorVarMax));
    }

    if(completeSave || !FieldsEqual(13, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("useOpacityVarMin", useOpacityVarMin));
    }

    if(completeSave || !FieldsEqual(14, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("opacityVarMin", opacityVarMin));
    }

    if(completeSave || !FieldsEqual(15, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("useOpacityVarMax", useOpacityVarMax));
    }

    if(completeSave || !FieldsEqual(16, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("opacityVarMax", opacityVarMax));
    }

    if(completeSave || !FieldsEqual(17, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("smoothData", smoothData));
    }

    if(completeSave || !FieldsEqual(18, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("samplesPerRay", samplesPerRay));
    }

    if(completeSave || !FieldsEqual(19, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("rendererType", Renderer_ToString(rendererType)));
    }

    if(completeSave || !FieldsEqual(20, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("gradientType", GradientType_ToString(gradientType)));
    }

    if(completeSave || !FieldsEqual(21, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("num3DSlices", num3DSlices));
    }

    if(completeSave || !FieldsEqual(22, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("scaling", Scaling_ToString(scaling)));
    }

    if(completeSave || !FieldsEqual(23, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("skewFactor", skewFactor));
    }

    if(completeSave || !FieldsEqual(24, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("sampling", SamplingType_ToString(sampling)));
    }


    // Add the node to the parent node.
    if(addToParent || forceAdd)
        parentNode->AddNode(node);
    else
        delete node;

    return (addToParent || forceAdd);
}