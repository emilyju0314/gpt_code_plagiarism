int
saveCollEntForChkColl( collEnt_t *collEnt ) {
    if ( collEnt == NULL ) {
        return 0;
    }
    if ( collEnt->collName != NULL ) {
        collEnt->collName = strdup( collEnt->collName );
    }
    if ( collEnt->dataName != NULL ) {
        collEnt->dataName = strdup( collEnt->dataName );
    }
    if ( collEnt->resource != NULL ) {
        collEnt->resource = strdup( collEnt->resource );
    }
    if ( collEnt->resc_hier != NULL ) {
        collEnt->resc_hier = strdup( collEnt->resc_hier );
    }
    return 0;
}