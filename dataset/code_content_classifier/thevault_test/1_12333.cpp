static bool convertTransformXMLNodes(XmlNodeRef node)
        {
            bool nodeConverted = false;

            // recurse through children
            for (int i = node->getChildCount(); --i >= 0;)
            {
                if (convertTransformXMLNodes(node->getChild(i)))
                {
                    nodeConverted = true;
                }
            }

            XmlString nodeType;
            if (node->isTag("Node") && node->getAttr("Type", nodeType) && nodeType == "Component")
            {
                XmlString componentTypeId;
                if (node->getAttr("ComponentTypeId", componentTypeId) && componentTypeId == "{27F1E1A1-8D9D-4C3B-BD3A-AFB9762449C0}")   // Type Uuid AZ::EditorTransformComponentTypeId
                {
                    static const char* paramTypeName = "paramType";
                    static const char* paramUserValueName = "paramUserValue";
                    static const char* virtualPropertyName = "virtualPropertyName";

                    // go through child nodes. Convert previous Position, Rotation or Scale tracks ByString to enumerated param types
                    for (const XmlNodeRef& childNode : node)
                    {
                        XmlString paramType;
                        if (childNode->isTag("Track") && childNode->getAttr(paramTypeName, paramType) && paramType == "ByString")
                        {
                            XmlString paramUserValue;
                            if (childNode->getAttr(paramUserValueName, paramUserValue) && paramUserValue == "Position")
                            {
                                childNode->setAttr(paramTypeName, "Position");
                                childNode->setAttr(virtualPropertyName, "Position");
                                childNode->delAttr(paramUserValueName);
                                nodeConverted = true;
                            }
                            else if (childNode->getAttr(paramUserValueName, paramUserValue) && paramUserValue == "Rotation")
                            {
                                childNode->setAttr(paramTypeName, "Rotation");
                                childNode->setAttr(virtualPropertyName, "Rotation");
                                childNode->delAttr(paramUserValueName);
                                nodeConverted = true;
                            }
                            else if (childNode->getAttr(paramUserValueName, paramUserValue) && paramUserValue == "Scale")
                            {
                                childNode->setAttr(paramTypeName, "Scale");
                                childNode->setAttr(virtualPropertyName, "Scale");
                                childNode->delAttr(paramUserValueName);
                                nodeConverted = true;
                            }
                        }
                    }
                }
            }

            return nodeConverted;
        }