void CrossBarSwitch::handle_inf_arrival( int inputid, LinkData* data)
{
    switch ( data->type ) {
        case FLIT:
            {
                if (data->f->type == HEAD)
                {
                    //generate the order record for out queue to guarantee the network follow FIFO principal
                    order_record[static_cast<HeadFlit*>(data->f)->dst_id].push_back(inputid);
                    //generate the record when header flit coming
                    stat_packets_in++;
                }
                
                stat_flits_in++;
                in_buffer[inputid].push_back(data->f);
                break;
            }

        case CREDIT:
            {
                //add credit back when credit coming
                downstream_credits[inputid]++;
                assert(downstream_credits[inputid] <= (uint)credits);
                break;
            }

        default:	
            assert(0);
            break;
    }	
    // delete ld.. if ld contains a flit it is not deleted. see destructor
    delete data;
}