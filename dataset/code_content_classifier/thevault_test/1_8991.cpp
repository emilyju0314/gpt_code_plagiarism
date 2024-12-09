Particle::Particle (darray position, Spin spin, Specie specie)
     : position_(position), spin_(spin), specie_(specie), nbh_()
    {
        // la carga depende del tipo de particula
        if (specie == Specie::Ion) charge_ = 1.0;
        if (specie == Specie::Electron) charge_ = - 1.0;
    }