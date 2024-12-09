void CIMAPBodyStruct::walkBodyStructTree(std::unique_ptr<BodyNode> &bodyNode, BodyPartFn walkFn, std::shared_ptr<void> &walkData)
    {
        for (auto &bodyPart : bodyNode->bodyParts)
        {
            if (bodyPart.child)
            {
                walkBodyStructTree(bodyPart.child, walkFn, walkData);
            }
            else
            {
                walkFn(bodyNode, bodyPart, walkData);
            }
        }
    }