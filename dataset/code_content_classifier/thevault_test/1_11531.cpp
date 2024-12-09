void CIMAPBodyStruct::parseBodyStructTree(std::unique_ptr<BodyNode> &bodyNode)
    {
        for (auto &bodyPart : bodyNode->bodyParts)
        {
            if (bodyPart.child)
            {
                parseBodyStructTree(bodyPart.child);
            }
            else
            {
                parseBodyPart(bodyPart);
            }
        }
    }