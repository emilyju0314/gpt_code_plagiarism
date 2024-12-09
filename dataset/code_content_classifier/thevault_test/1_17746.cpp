Material::Material(const std::string &code) :
        diffRefl(Vector3(0, 0, 0)), specRefl(Vector3(0, 0, 0)),
        transmission(Vector3(0.4, 0.4, 0.4)),    // based on 99% transmittance for 25mm thick BK7 std glass plate
        diffCase(0.0f), specCase(0.0f), powerEmitting(0.0f), n_u(100000),
        n_v(100000), shaderID(1), texShaderID(0), contribution(false), dispersive(true) {
    //code.copy(name,16);
    if (!initSellmeier(code))
        exit(1);

    verify();
}