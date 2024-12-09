void print(const boost::multi_array<double, 3>& array)
{
    for(int i=0; i<array.shape()[0]; i++) {
        for(int j=0; j<array.shape()[1]; j++) {
            for(int k=0; k<array.shape()[2]; k++) {
                std::cout << array[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}