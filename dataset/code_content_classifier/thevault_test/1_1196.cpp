arma::mat
peer_method::encode_counts(const arma::mat &counts, size_t snp1_onestart, size_t snp2_onestart)
{
    int dd = ( snp1_onestart == 1 ) && ( snp2_onestart == 1 );
    int rd = ( snp1_onestart == 1 ) && ( snp2_onestart == 2 );
    int dr = ( snp1_onestart == 2 ) && ( snp2_onestart == 1 );
    int rr = ( snp1_onestart == 2 ) && ( snp2_onestart == 2 );

    arma::mat encoded_counts( 4, 2 );
    for(int i = 0; i <= 1; i++)
    {
        encoded_counts( 0, i ) = counts( 0, i ) + (rd + rr) * counts( 1, i ) + (dr + rr) * counts( 3, i ) + rr * counts( 4, i );
        encoded_counts( 1, i ) = (dr + dd) * counts( 1, i ) + counts( 2, i ) + dr * counts( 4, i ) + (dr + rr) * counts( 5, i );
        encoded_counts( 2, i ) = (rd + dd) * counts( 3, i ) + rd * counts( 4, i ) + counts( 6, i ) + (rd + rr) * counts( 7, i );
        encoded_counts( 3, i ) = dd * counts( 4, i ) + (rd + dd) * counts( 5, i ) + (dr + dd) * counts( 7, i ) + counts( 8, i );
    }

    return encoded_counts;
}