void
show_diffs()
{
	u_int32_t i, j;

	for(i = 0; i < NODES; i++) {
		for(j = i + 1; j < NODES; j++) {
			if(D1[i*NODES + j] != D2[i*NODES + j]) {

				if(D2[i*NODES + j] == INFINITY)
					DestUnreachableCount++;

                                if(TIME > 0.0) {
                                        RouteChangeCount++;
                                        NodeList[i].route_changes++;
                                        NodeList[j].route_changes++;
                                }

				if(TIME == 0.0) {
					fprintf(stdout, GOD_FORMAT2,
						i, j, D2[i*NODES + j]);
#ifdef SHOW_SYMMETRIC_PAIRS
					fprintf(stdout, GOD_FORMAT2,
						j, i, D2[j*NODES + i]);
#endif
				}
				else {
					fprintf(stdout, GOD_FORMAT, 
						TIME, i, j, D2[i*NODES + j]);
#ifdef SHOW_SYMMETRIC_PAIRS
					fprintf(stdout, GOD_FORMAT, 
						TIME, j, i, D2[j*NODES + i]);
#endif
				}
			}
		}
	}

	memcpy(D1, D2, sizeof(int) * NODES * NODES);
}