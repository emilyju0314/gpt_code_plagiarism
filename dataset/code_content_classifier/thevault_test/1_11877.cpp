bool ParseFontFamilyXml(const XmlNodeRef& node, FontFamilyTagXml& xmlData)
    {
        if (!node)
        {
            return false;
        }

        // <fontfamily>
        if (AZStd::string(node->getTag()) == "fontfamily")
        {
            const int numAttributes = node->getNumAttributes();

            if (numAttributes <= 0)
            {
                // Expecting at least one attribute
                return false;
            }

            AZStd::string name;

            for (int i = 0, count = node->getNumAttributes(); i < count; ++i)
            {
                const char* key = "";
                const char* value = "";
                if (node->getAttributeByIndex(i, &key, &value))
                {
                    if (AZStd::string(key) == "name")
                    {
                        name = value;
                    }
                    else
                    {
                        // Unexpected font tag attribute
                        return false;
                    }
                }
            }

            AZ::StringFunc::TrimWhiteSpace(name, true, true);
            if (!name.empty())
            {
                xmlData.m_fontFamilyName = name;
            }
            else
            {
                // Font family must have a name
                return false;
            }
        }

        // <font>
        if (AZStd::string(node->getTag()) == "font")
        {
            xmlData.m_fontTagsXml.push_back(FontTagXml());

            AZStd::string lang;
            for (int i = 0, count = node->getNumAttributes(); i < count; ++i)
            {
                const char* key = "";
                const char* value = "";
                if (node->getAttributeByIndex(i, &key, &value))
                {
                    if (AZStd::string(key) == "lang")
                    {
                        lang = value;
                    }
                    else
                    {
                        // Unexpected font tag attribute
                        return false;
                    }
                }
            }

            AZ::StringFunc::TrimWhiteSpace(lang, true, true);
            if (!lang.empty())
            {
                xmlData.m_fontTagsXml.back().m_lang = lang;
            }
        }

        // <file>
        else if (AZStd::string(node->getTag()) == "file")
        {
            const int numAttributes = node->getNumAttributes();

            if (numAttributes <= 0)
            {
                // Expecting at least one attribute
                return false;
            }

            AZStd::string path;
            AZStd::string tags;

            for (int i = 0, count = node->getNumAttributes(); i < count; ++i)
            {
                const char* key = "";
                const char* value = "";
                if (node->getAttributeByIndex(i, &key, &value))
                {
                    if (AZStd::string(key) == "path")
                    {
                        path = value;
                    }
                    else if (AZStd::string(key) == "tags")
                    {
                        tags = value;
                    }
                    else
                    {
                        // Unexpected font tag attribute
                        return false;
                    }
                }
            }

            AZ::StringFunc::TrimWhiteSpace(tags, true, true);
            if (tags.empty())
            {
                xmlData.m_fontTagsXml.back().m_fontFilename = path;
            }
            else if (tags == "b")
            {
                xmlData.m_fontTagsXml.back().m_boldFontFilename = path;
            }
            else if (tags == "i")
            {
                xmlData.m_fontTagsXml.back().m_italicFontFilename = path;
            }
            else
            {
                // We'll just assume any other tag indicates bold italic
                xmlData.m_fontTagsXml.back().m_boldItalicFontFilename = path;
            }
        }

        for (int i = 0, count = node->getChildCount(); i < count; ++i)
        {
            XmlNodeRef child = node->getChild(i);
            if (!ParseFontFamilyXml(child, xmlData))
            {
                return false;
            }
        }

        return true;
    }