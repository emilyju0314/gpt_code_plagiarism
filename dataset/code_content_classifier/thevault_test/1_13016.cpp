AssemblyChunk *newAssemblyChunk()
{
    /* allocate memory variables */
    AssemblyChunk * aChunk = (AssemblyChunk *) malloc(sizeof(AssemblyChunk));
    
    /* initialize fields */
    aChunk->preamble = NULL;
    aChunk->iList = NULL;
    aChunk->postamble = NULL;
    aChunk->next = NULL;
    aChunk->prev = NULL;
}