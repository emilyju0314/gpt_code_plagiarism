NvDlaError engine_ast::SDPSuperOpNode::populateEdgePorts()
{
    NvDlaError e = NvDlaSuccess;

    //gLogInfo << name() << " : populateEdgePorts: " << endl;
    //printSdpXEdgeMap();

    EdgeSequence inputEdges = graph()->upstreamDataEdges(this);
    EdgeSequence outputEdges = graph()->downstreamDataEdges(this);

    // upstream Edges are input + aux edges
    size_t upstreamEdgesExpected = 1 + m_sdpXengineToAuxEdgeMap.size();

    /**
     * should be exactly only 1 output edge, it should be the data output,
     * none of the engine nodes is capable of >1 outputs, fail if so since
     * concat and split nodes are handled separately
     */
    if (outputEdges.size() == 0)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s has 0 output edges", name().c_str());
    }
    else if (outputEdges.size() == 1)
    {
        markOutputEdge(outputEdges[0]);
    }
    else
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s has >1 output edges", name().c_str());
    }

    if (inputEdges.size() != upstreamEdgesExpected)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s has (%d) input+aux edges. expected (%d)",
            name().c_str(), inputEdges.size(), upstreamEdgesExpected);
    }

    {
        NvU8 foundEdges = 0;
        NvU8 foundX1Edge = 1 << 0;
        NvU8 foundX2Edge = 1 << 1;
        NvU8 foundInputEdge = 1 << 2;
        NvU8 foundAllEdges = foundX1Edge | foundX2Edge | foundInputEdge;

        EdgeSequence newEdges;
        for (EdgeSequenceIterator iei = inputEdges.begin(); iei != inputEdges.end(); ++iei)
        {
            SdpXengineToEdgeMapIterator xEdge = findSdpAuxEdge(*iei);
            if ( xEdge != m_sdpXengineToAuxEdgeMap.end() )
            {
                if (xEdge->first == SDP_ENGINE_X1)
                    foundEdges |= foundX1Edge;
                else if (xEdge->first == SDP_ENGINE_X2)
                    foundEdges |= foundX2Edge;
                else
                {
                    ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s Aux Edge Y %s not supported. Invalid state",
                        name().c_str(), engine_ast::Edge::prettyId(*iei).c_str());
                }
            }

            if ( (*iei)->isAuxEdge() )
            {
                // just make sure edge is already in the map
                if ( xEdge == m_sdpXengineToAuxEdgeMap.end() )
                {
                    ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s Aux Edge %s not in xEdge map. Invalid state",
                        name().c_str(), engine_ast::Edge::prettyId(*iei).c_str());
                }
                markAuxEdge(*iei);
            }
            else if ( xEdge != m_sdpXengineToAuxEdgeMap.end() )
            {
                // this is a kIO tensor dataedge linked as Aux edge
                markAuxEdge(*iei);
            }
            else if ( (*iei) == m_InputEdge )
            {
                // source input edge
                markInputEdge(*iei);
                foundEdges |= foundInputEdge;
            }
            else
            {
                // Its data edge, but its new one.
                markInputEdge(*iei);
                newEdges.push_back(*iei);
            }
        }

        // Did we find all expected edges? if not, update internal structures.
        if ( foundEdges != foundAllEdges )
        {
            if (newEdges.size() != 1)
            {
                ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s multiple new edges found. Invalid state", name().c_str());
            }

            if (!(foundEdges & foundInputEdge))
            {
                m_InputEdge = newEdges[0];
                foundEdges |= foundInputEdge;
            }
            else if (!(foundEdges & foundX1Edge))
            {
                m_sdpXengineToAuxEdgeMap[SDP_ENGINE_X1] = newEdges[0];
                foundEdges |= foundX1Edge;
            }
            else
            {
                m_sdpXengineToAuxEdgeMap[SDP_ENGINE_X2] = newEdges[0];
                foundEdges |= foundX2Edge;
            }

            if (!(foundEdges & foundAllEdges))
            {
                ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "%s multiple edges missing from the map. Invalid state", name().c_str());
            }
        }

        PROPAGATE_ERROR_FAIL( verifyEdgePorts() );
    }
    fail:
        return e;
}