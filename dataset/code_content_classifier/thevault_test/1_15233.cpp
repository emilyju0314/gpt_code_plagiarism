canonical_ast::Graph *canonical_ast::generateGraph(Network *network)
{
    vector<canonical_ast::Edge *> input_edges;
    vector<canonical_ast::Edge *> output_edges;

    map<canonical_ast::Node *, Layer *, Graph::nodeCompareFn>  node_layer;
    map<canonical_ast::Node *, Layer *, Graph::nodeCompareFn>::iterator lni;

    map<Tensor *, canonical_ast::Edge *>  tensor_edge;
    map<Tensor *, Tensor *>  nw_tensor_to_can_tensor;
    map<Tensor *, canonical_ast::Edge *>::iterator tei;

    Graph *graph = new Graph();

    vector<Tensor *> network_inputs;
    for (int ni = 0; ni < network->getNumInputs(); ++ni)
    {
        network_inputs.push_back(TensorFactory::priv(network->getInput(ni)));
    }
    input_edges.resize(network_inputs.size());


    vector<Tensor *> network_outputs;
    for (int ni = 0; ni < network->getNumOutputs(); ++ni)
    {
        network_outputs.push_back(TensorFactory::priv(network->getOutput(ni)));
    }
    output_edges.resize(network_outputs.size());

    //    gLogInfo << "canonical_ast::" << __func__ << " network shows " << network_inputs.size() << " inputs and " <<
    //        network_outputs.size() << " outputs" << endl;

    for (int li = 0; li < network->getNumLayers(); li++)
    {
        ILayer *ilayer = network->getLayer(li);
        Layer *layer = LayerFactory::priv(ilayer);
        if ( !(ilayer && layer) )
        {
            gLogError << __func__ << " encountered null layer at network layer index=" << li << endl;
            continue;
        }

        canonical_ast::Node *can_node = newCanonicalNode(layer);
        if ( !can_node )
        {
            delete graph; // blow up
            graph = 0;
            goto done;
        }
        can_node->setGraph(graph);
        graph->insertNode(can_node);

        can_node->setId(graph->nextNodeId());
        can_node->setName(layer->getName());

        node_layer[can_node] = layer;
    }

    //
    // Now all the layer nodes are in the graph.
    // For each layer assemble the edges.
    //

    for (lni = node_layer.begin(); lni != node_layer.end(); ++lni)
    {
        canonical_ast::Node *node = lni->first;
        Layer *l = lni->second;

        size_t input_tensors = 0, output_tensors = 0, aux_input_tensors = 0;
        vector<Tensor *> io_tensors, aux_tensors;
        NVDLA_UNUSED(aux_input_tensors);

        for(int ii = 0, II = l->getNumInputs(); ii < II; ++ii)
        {
            Tensor *tensor = TensorFactory::priv(l->getInput(ii));
            if ( !tensor )
            {
                gLogError << __func__ << " 3.<null>.i." << ii << endl;
                continue;
            }
            io_tensors.push_back(tensor);
            input_tensors++;
        }
        for(int oo = 0, OO = l->getNumOutputs(); oo < OO; ++oo)
        {
            Tensor *tensor = TensorFactory::priv(l->getOutput(oo));
            if ( ! tensor )
            {
                gLogError << __func__ << " 3.<null>.o." << oo << endl;
                continue;
            }
            io_tensors.push_back(tensor);
            output_tensors++;
        }

        for(size_t io = 0, IO = io_tensors.size(); io < IO; ++io)
        {
            Tensor *nw_tensor = io_tensors[io];
            bool is_input = io < input_tensors;
            ast::EdgeSide edge_side( is_input ? ast::EdgeSideEnum::SECOND : ast::EdgeSideEnum::FIRST);
            ast::EdgeDirection edge_dir(ast::EdgeDirectionEnum::DIRECTED);

            map<Tensor *, canonical_ast::Edge *>::iterator f = tensor_edge.find(nw_tensor);
            canonical_ast::Edge *can_edge = 0;
            Tensor* can_tensor = 0;
            if ( f == tensor_edge.end() )
            {
                can_edge = new canonical_ast::Edge();
                can_edge->setGraph(graph);

                can_tensor = nw_tensor->clone();
                can_tensor->setNetwork(NULL);   // get rid of any connections back to the network builder
                can_tensor->setTensorType(TensorType::kIO);
                can_edge->setId(graph->nextEdgeId());
                can_edge->setOriginalTensor(can_tensor);
                graph->insertEdge(can_edge);

                tensor_edge[nw_tensor] = can_edge;
                nw_tensor_to_can_tensor[nw_tensor] = can_tensor;
            } else {
                can_edge = f->second;
            }
            graph->appendNodeToEdge(can_edge, edge_side, node);

            // if this is an input node it could be one of the network inputs.
            // if so keep track of it.
            if ( is_input )
            {
                for ( size_t iti = 0; iti < network_inputs.size(); iti++)
                {
                    if ( nw_tensor == network_inputs[iti] )
                    {
                        // gLogInfo << " identified input edge: " << (int)iti << " tensor id " << tensor->getName() << endl;
                        input_edges[iti] = can_edge;
                        can_tensor = nw_tensor_to_can_tensor[nw_tensor];
                        can_tensor->setTensorType(TensorType::kNW_INPUT);
                        break;
                    }
                }
                node->markInputEdge(can_edge);
            }
            else
            {
                for ( size_t oti = 0; oti < network_outputs.size(); oti++)
                {
                    if ( nw_tensor == network_outputs[oti] )
                    {
                        // gLogInfo << " identified output edge: " << (int)oti << " tensor id " << tensor->getName() << endl;
                        output_edges[oti] = can_edge;
                        can_tensor = nw_tensor_to_can_tensor[nw_tensor];
                        can_tensor->setTensorType(TensorType::kNW_OUTPUT);
                        break;
                    }
                }
                node->markOutputEdge(can_edge);
            }
        }
    }

    if ( input_edges.size() )
    {
        graph->setInputEdges(input_edges);
    }
    if ( output_edges.size() )
    {
        graph->setOutputEdges(output_edges);
    }

    graph->scoredOrdering()->generate();
    graph->markClean();

done:
    return graph;
}