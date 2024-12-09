double
find_max(const arma::vec &v, const arma::uvec &inactive, unsigned int *max_index)
{
    double max_value = 0;
    *max_index = v.n_elem;
    for(int i = 0; i < inactive.n_elem; i++)
    {
        unsigned int cur_index = inactive[ i ];
        double cur_value = v[ cur_index ];

        // Notice the order of these two statements
        *max_index = ( cur_value > max_value ) ? cur_index : *max_index;
        max_value = ( cur_value > max_value ) ? cur_value : max_value;
    }

    return max_value;
}