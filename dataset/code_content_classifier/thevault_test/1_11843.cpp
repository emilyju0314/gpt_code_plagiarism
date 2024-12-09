AZ::Outcome<void, AZStd::string> SubgraphInterface::Parse()
        {
            m_outKeys.clear();

            for (const auto& in : m_ins)
            {
                for (const auto& out : in.outs)
                {
                    if (!AddOutKey(out.displayName))
                    {
                        return AZ::Failure(AZStd::string::format("Out %s was already in the list", out.displayName.c_str()));
                    }
                }
            }

            for (const auto& latent : m_latents)
            {
                if (!AddOutKey(latent.displayName))
                {
                    return AZ::Failure(AZStd::string::format("Out %s was already in the list", latent.displayName.c_str()));
                }
            }

            return AZ::Success();
        }