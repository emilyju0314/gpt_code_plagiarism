double
sample_risk(const snp_row &snp1, const snp_row &snp2, const arma::vec &phenotype, arma::vec &weight)
{
    int cell = random( ) % 9;
    arma::vec permuted_phenotype = permute_phenotype( phenotype, weight );
    arma::mat counts = joint_count( snp1, snp2, permuted_phenotype, weight );

    return ( counts( cell, 1 ) + 1 ) / ( counts( cell, 0 ) + counts( cell, 1 ) + 2 );
}