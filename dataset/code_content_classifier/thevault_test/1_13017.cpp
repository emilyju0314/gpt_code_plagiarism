void printChunk(FILE * target, AssemblyChunk * aChunk)
{
    /* ensure we have a chunk and stream */
    if(aChunk && target)
    {
        /* print the preamble, if any */
        if (aChunk->preamble && aChunk->preamble->size())
            fprintf(target, "%s\n", aChunk->preamble->data());
        
        /* print the instructions, if any */
        if (aChunk->iList) printInstructionList(target, aChunk->iList);
        
        /* print the postamble, if any */
        if (aChunk->postamble && aChunk->postamble->size())
            fprintf(target, "%s\n", aChunk->postamble->data());
    }
    
    /* complain if a null chunk was passed */
    else if (target)
        fprintf(error, "Cannot print null chunk\n");
    
    /* complain if a null stram was passed */
    
    else if (aChunk)
        fprintf(error, "Cannot print to null stream.\n");
}