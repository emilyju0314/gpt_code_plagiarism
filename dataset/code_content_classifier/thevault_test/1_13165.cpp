const long double neural_networks::utilities::Neuron::set(const neural_networks::utilities::Neuron::ld input) {
    data = input;
    function = activation_function(input);
    function_derivative = activation_function_prime(input);
    return function;
}