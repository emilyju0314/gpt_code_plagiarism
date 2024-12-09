int ComakTarget::constraintJacobian(const SimTK::Vector &parameters,
    bool new_parameters, SimTK::Matrix &jac) const
{
    jac = _constraint_matrix;

    return 0;
}