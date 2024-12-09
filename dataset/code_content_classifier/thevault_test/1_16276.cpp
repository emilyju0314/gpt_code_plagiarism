Projection(int id, ProjectionType type)
      : projectionID(id),
        projectionType(type)
    {
      TEST_EXIT(id != 0)("don't use 0 as projection id. is used as no projection\n");
      TEST_EXIT(projectionMap[id] == NULL)
      ("there is already a projection with this id\n");
      projectionMap[id] = this;
    }