KFORTH_DISASSEMBLY *kforth_disassembly_make(KFORTH_PROGRAM *kfp, int width, int want_cr)
{
	char buf[1000];
	char buf2[1000];
	char *nlstr;
	int cb, pc, opcode;
	int max_opcode;
	int line_length, i, len;
	KFORTH_DISASSEMBLY *result;

	char *program;
	int plen, psize;

	ASSERT( kfp != NULL );
	ASSERT( width >= 20 );

	if( want_cr ) {
		nlstr = "\r\n";
	} else {
		nlstr = "\n";
	}

	result = (KFORTH_DISASSEMBLY*) CALLOC(1, sizeof(KFORTH_DISASSEMBLY));
	ASSERT( result != NULL );

	result->program_text = NULL;

	/*
	 * Compute length of array
	 */
	result->pos_len = kfp->nblocks;
	for(cb=0; cb < kfp->nblocks; cb++) {
		result->pos_len += kfp->block_len[cb] + 1;
	}

	result->pos = (KFORTH_DISASSEMBLY_POS*) CALLOC(result->pos_len, sizeof(KFORTH_DISASSEMBLY_POS));
	ASSERT( result->pos != NULL );

	max_opcode = kforth_ops_max_opcode(kfp->kfops);

	psize = 1000;
	program = (char*) CALLOC(psize, sizeof(char));
	plen = 0;
	program[0] = '\0';
	i = 0;
	for(cb=0; cb < kfp->nblocks; cb++) {
		if( cb == 0 ) {
			sprintf(buf, "main");
		} else {
			sprintf(buf, "row%d", cb);
		}

		len = (int) strlen(buf);

		result->pos[i].cb	= cb;
		result->pos[i].pc	= -1;
		result->pos[i].start_pos= plen;
		result->pos[i].end_pos	= plen + len - 1;
		i++;

		sprintf(buf2, "%s:%s{%s    ", buf, nlstr, nlstr);
		append_to_string(&program, &psize, &plen, buf2);

		line_length = 4;
		for(pc=0; pc < kfp->block_len[cb]; pc++) {

			if( line_length >= width ) {

				sprintf(buf, "%s    ", nlstr);
				line_length = 4;

				append_to_string(&program, &psize, &plen, buf);
			}

			strcpy(buf, "  ");
			line_length += 2;
			append_to_string(&program, &psize, &plen, buf);

			opcode = kfp->opcode[cb][pc];
			if( opcode == 0 ) {
#ifndef __linux__
				sprintf(buf, "%I64d", kfp->operand[cb][pc]);
#else
				sprintf(buf, "%lld", kfp->operand[cb][pc]);
#endif

			} else if( opcode <= max_opcode ) {
				sprintf(buf, "%s", kfp->kfops[opcode].name);

			} else {
				ASSERT(0);
			}

			len = (int) strlen(buf);
			line_length += len;

			result->pos[i].cb	= cb;
			result->pos[i].pc	= pc;
			result->pos[i].start_pos= plen;
			result->pos[i].end_pos	= plen + len - 1;
			i++;

			append_to_string(&program, &psize, &plen, buf);
		}

		/*
		 * We are at the end of a code block, add closing '}' and add entry.
		 */
		sprintf(buf, " %s", nlstr);
		append_to_string(&program, &psize, &plen, buf);

		sprintf(buf, "}");
		len = (int) strlen(buf);

		result->pos[i].cb	= cb;
		result->pos[i].pc	= pc;
		result->pos[i].start_pos= plen;
		result->pos[i].end_pos	= plen + len - 1;
		i++;

		append_to_string(&program, &psize, &plen, buf);

		sprintf(buf, "%s%s", nlstr, nlstr);
		append_to_string(&program, &psize, &plen, buf);
	}

	ASSERT( i == result->pos_len );

	result->program_text = program;

	return result;
}