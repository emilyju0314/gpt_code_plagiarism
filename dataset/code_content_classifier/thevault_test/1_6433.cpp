void
OLSR_printer::print_cmn_hdr(FILE* out, struct hdr_cmn* ch) {
	char *error, *direction;
	
	if (ch->error())
		error = "yes";
	else
		error = "no";
		
	if (ch->direction() == hdr_cmn::DOWN)
		direction = "DOWN";
	else if (ch->direction() == hdr_cmn::UP)
		direction = "UP";
	else if (ch->direction() == hdr_cmn::NONE)
		direction = "NONE";
	else
		direction = "UNKNOWN (likely a bug!)";
	
	// We could include this if we were interested in printing address type
	/*if (ch->addr_type() == NS_AF_NONE)
		addr_type = "NS_AF_NONE";
	else if (ch->addr_type() == NS_AF_ILINK)
		addr_type = "NS_AF_ILINK";
	else if (ch->addr_type() == NS_AF_INET)
		addr_type = "NS_AF_INET";
	else
		addr_type = "UNKNOWN (possibly a bug!)";*/
	
	fprintf(out,
		"  COMMON HEADER\n\tptype = %s\n\tuid = %d\n\tsize = %d\n\terror = %s\n\tdirection = %s\n\n",
		packet_info.name(ch->ptype()),
		ch->uid(),
		ch->size(),
		error,
		direction);
}