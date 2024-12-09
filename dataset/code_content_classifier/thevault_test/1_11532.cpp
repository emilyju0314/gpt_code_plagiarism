void CIMAPBodyStruct::createBodyStructTree(std::unique_ptr<BodyNode> &bodyNode, const std::string &bodyPart)
    {
        std::uint32_t partNo{1};
        std::string bodyucture(bodyPart.substr(1));
        std::vector<std::string> bodyParts;
        while (bodyucture[0] == '(')
        {
            bodyParts.push_back(CIMAPParse::stringList(bodyucture));
            bodyucture = bodyucture.substr(bodyParts.back().length());
        }
        bodyucture.pop_back();
        bodyucture = bodyucture.substr(1);
        bodyParts.push_back(bodyucture);
        for (auto part : bodyParts)
        {
            if (part[1] == '\"')
            {
                if (!bodyNode->partLevel.empty())
                {
                    bodyNode->bodyParts.push_back({bodyNode->partLevel + "." + std::to_string(partNo), part, nullptr, nullptr});
                }
                else
                {
                    bodyNode->bodyParts.push_back({bodyNode->partLevel + std::to_string(partNo), part, nullptr, nullptr});
                }
            }
            else if (part[1] == '(')
            {
                bodyNode->bodyParts.push_back({"", "", nullptr, nullptr});
                bodyNode->bodyParts.back().child = std::make_unique<BodyNode>();
                bodyNode->bodyParts.back().child->partLevel = bodyNode->partLevel + std::to_string(partNo);
                createBodyStructTree(bodyNode->bodyParts.back().child, part);
            }
            else
            {
                bodyNode->extended = part;
            }
            partNo++;
        }
    }