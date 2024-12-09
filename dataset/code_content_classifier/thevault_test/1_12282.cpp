bool RuleContainer::VectorToRuleContainerConverter(SerializeContext& context, SerializeContext::DataElementNode& classElement)
            {
                int elementIndex = classElement.FindElement(AZ_CRC("rules", 0x899a993c));
                if (elementIndex >= 0)
                {
                    AZ::SerializeContext::DataElementNode& rulesElement = classElement.GetSubElement(elementIndex);

                    // Clone the rule elements.
                    AZStd::vector<AZ::SerializeContext::DataElementNode> rules;
                    const int numSubElements = rulesElement.GetNumSubElements();
                    rules.reserve(numSubElements);

                    for (int i = 0; i < numSubElements; i++)
                    {
                        AZ::SerializeContext::DataElementNode& sharedPtrElement = rulesElement.GetSubElement(i);

                        if (sharedPtrElement.GetNumSubElements() > 0)
                        {
                            AZ::SerializeContext::DataElementNode& ruleElement = sharedPtrElement.GetSubElement(0);
                            rules.push_back(ruleElement);
                        }
                    }

                    // Remove the original rule vector element.
                    classElement.RemoveElement(elementIndex);

                    // Add a new rule container element.
                    const int ruleContainerIndex = classElement.AddElement<RuleContainer>(context, "rules");
                    if (ruleContainerIndex >= 0)
                    {
                        AZ::SerializeContext::DataElementNode& ruleContainerElement = classElement.GetSubElement(ruleContainerIndex);

                        // Create a rule vector element.
                        const int rulesVectorIndex = ruleContainerElement.AddElement<AZStd::vector<AZStd::shared_ptr<DataTypes::IRule>>>(context, "rules");
                        AZ::SerializeContext::DataElementNode& ruleVectorElement = ruleContainerElement.GetSubElement(rulesVectorIndex);
               
                        // Add the copied rules to the rule vector element.
                        for (SerializeContext::DataElementNode& rule : rules)
                        {
                            int valueIndex = ruleVectorElement.AddElement<AZStd::shared_ptr<DataTypes::IRule>>(context, "element");
                            SerializeContext::DataElementNode& pointerNode = ruleVectorElement.GetSubElement(valueIndex);

                            pointerNode.AddElement(rule);
                        }
                    }
                }

                return true;
            }