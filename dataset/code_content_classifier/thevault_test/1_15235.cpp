bool Network::deserializeFrom(WisdomContainerEntry *e)
{
    canonical_ast::Graph *graph;
    NVDLA_UNUSED(graph);

    //    gLogError << __func__ << " 1 " << endl;
    Wisdom *wisdom;
    WisdomContainerEntry inputs_entry, outputs_entry, layers_entry;
    NvU32 num_inputs, num_outputs, num_layers;
    map<string, ITensor *> tensor_symbols;
    vector<ILayer *> layers;

    bool ok = true;

    wisdom = e->container_priv()->wisdom_priv();
    ok = NULL != wisdom;
    if ( !ok ) {
        gLogError << __func__ << "missing Wisdom" << endl;
        goto done;
    }

    ok = ok && e->getEntry(string("num_inputs"),  IWisdomContainerEntry::ENTRY_TYPE_UINT32, &inputs_entry);
    ok = ok && e->getEntry(string("num_outputs"), IWisdomContainerEntry::ENTRY_TYPE_UINT32, &outputs_entry);
    ok = ok && e->getEntry(string("num_layers"),  IWisdomContainerEntry::ENTRY_TYPE_UINT32, &layers_entry);

    ok = ok && inputs_entry. readUInt32(num_inputs);
    ok = ok && outputs_entry.readUInt32(num_outputs);
    ok = ok && layers_entry. readUInt32(num_layers);

    if ( !ok ) {
        gLogError << __func__ << " failed to get all num_* entries" << endl;
        goto done;
    }

    //XXX upper bounds check?
    if ( num_inputs == 0 || num_outputs == 0 || num_layers == 0 ) {
        //ok = false;
        gLogError << __func__ << " invalid network deserialization data?" << endl;
        gLogError << __func__ << " inputs=" << num_inputs << " outputs=" << num_outputs << " layers=" <<
            num_layers << endl;
        //	goto done;
    }

    // note re-use of the *_entry locals from above...
    ok = ok && e->getEntry(string("inputs"),  IWisdomContainerEntry::ENTRY_TYPE_OBJECT, &inputs_entry);
    ok = ok && e->getEntry(string("outputs"), IWisdomContainerEntry::ENTRY_TYPE_OBJECT, &outputs_entry);
    ok = ok && e->getEntry(string("layers"),  IWisdomContainerEntry::ENTRY_TYPE_OBJECT, &layers_entry);
    if ( !ok ) {
        gLogError << __func__ << " failed to get inputs, outputs and layers entries" << endl;
        goto done;
    }

    //
    // Gather up the layers referenced by the network.  For each, ascertain
    // whether or not it has been deserialized (check with the Wisdom).
    // If not, do so.
    //
    // The set of layers used by the network is stored as an array of layer symbols.
    //

    layers.clear();

    for ( size_t l = 0; ok && (l < num_layers); l++ ) {
        WisdomContainerEntry layer_index_entry;
        string layer_symbol;
        ILayer *layer;

        ok = ok && layers_entry.getEntry(toString(l),
                                         IWisdomContainerEntry::ENTRY_TYPE_STRING,
                                         &layer_index_entry);
        if ( !ok ) {
            gLogError << "couldn't get layers entry for " << toString(l) << endl;
            goto done;
        }
        ok = ok && layer_index_entry.readString(layer_symbol);
        if ( !ok ) {
            gLogError << "couldn't read layer index symbol string? " << toString(l) << endl;
            goto done;
            break;
        }

        layer = wisdom->getLayerFromSymbol(layer_symbol);

        ok = (NULL != layer);
        if ( ok ) {
            layers.push_back(layer);
        } else {
            gLogError << "couldn't get layer from symbol=[" << layer_symbol << "]" << endl;
            goto done;
        }

        mLayers.push_back(layer);
    }
    if ( !ok ) {
        gLogError << __func__ << " failed to find or instantiate (some) network layers" << endl;
        goto done;
    }


    // go through the input and output tensors and mark them as such.
    // they should have all been deserialized by way of layer references.
    // so if they aren't found something is really wrong.



    for ( size_t i = 0; ok && (i < num_inputs); i++ ) {

        WisdomContainerEntry input_index_entry;
        string input_symbol;
        ITensor *tensor;

        ok = ok && inputs_entry.getEntry(toString(i),
                                         IWisdomContainerEntry::ENTRY_TYPE_STRING,
                                         &input_index_entry);
        if ( !ok ) {
            gLogError << "couldn't get input entry for " << toString(i) << endl;
            goto done;
        }
        ok = ok && input_index_entry.readString(input_symbol);
        if ( !ok ) {
            gLogError << "couldn't read input index symbol string? " << toString(i) << endl;
            goto done;
        }
        tensor = wisdom->findTensorSymbol(input_symbol);
        if ( !tensor ) {
            ok = false;
            gLogError << " couldn't find input tensor sym=[" << input_symbol << "]" << endl;
            goto done;
        }

        ok = markInput(tensor);
        if ( !ok ) {
            gLogError << " problem marking tensor sym=[" << input_symbol << "] as a network input." << endl;
            goto done;
        }
    }

    for ( size_t o = 0; ok && (o < num_outputs); o++ ) {
        WisdomContainerEntry output_index_entry;
        string output_symbol;
        ITensor *tensor;

        ok = ok && outputs_entry.getEntry(toString(o),
                                          IWisdomContainerEntry::ENTRY_TYPE_STRING,
                                          &output_index_entry);
        if ( !ok ) {
            gLogError << "couldn't get output entry for " << toString(o) << endl;
            goto done;
        }
        ok = ok && output_index_entry.readString(output_symbol);
        if ( !ok ) {
            gLogError << "couldn't read output index symbol string? " << toString(o) << endl;
            goto done;
        }
        tensor = wisdom->findTensorSymbol(output_symbol);
        if ( !tensor ) {
            ok = false;
            gLogError << " couldn't find output tensor sym=[" << output_symbol << "]" << endl;
            goto done;
        }
        markOutput(tensor);
    }

 done:
    return ok;

}