arma::vec
permute_phenotype(const arma::vec &phenotype, arma::vec &weight)
{
    arma::vec permuted_phenotype = phenotype;
    for(int i = phenotype.n_elem - 1; i > 0; --i)
    {
        int j = random( ) % ( i + 1 );

        std::swap( permuted_phenotype[ i ], permuted_phenotype[ j ] );
        std::swap( weight[ i ], weight[ j ] );
    }
    
    return permuted_phenotype;
}