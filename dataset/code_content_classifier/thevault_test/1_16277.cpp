DOFIteratorBase(DOFAdmin* admin, DOFIteratorType t)
      : dofAdmin(admin),
        dofFree(&(dofAdmin->getDofFree())),
        type(t)
    {}