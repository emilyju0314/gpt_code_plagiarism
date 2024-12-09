inline void print_info(const scene* scn) {
      auto nverts = 0, nnorms = 0, ntexcoords = 0, npoints = 0, nlines = 0,
          ntriangles = 0, nquads = 0;
      for (auto shp : scn->shapes) {
        nverts += shp->pos.size();
        nnorms += shp->norm.size();
        ntexcoords += shp->texcoord.size();
        npoints += shp->points.size();
        nlines += shp->lines.size();
        ntriangles += shp->triangles.size();
        nquads += shp->quads.size();
      }

      auto bbox = scn->bbox;
      auto bboxc = vec3f{(bbox.max[0] + bbox.min[0]) / 2,
                         (bbox.max[1] + bbox.min[1]) / 2, (bbox.max[2] + bbox.min[2]) / 2};
      auto bboxs = vec3f{bbox.max[0] - bbox.min[0], bbox.max[1] - bbox.min[1],
                         bbox.max[2] - bbox.min[2]};

      printf("number of cameras:      %d\n", (int)scn->cameras.size());
      printf("number of shapes:       %d\n", (int)scn->shapes.size());
      printf("number of instances:    %d\n", (int)scn->instances.size());
      printf("number of materials:    %d\n", (int)scn->materials.size());
      printf("number of textures:     %d\n", (int)scn->textures.size());
      printf("number of environments: %d\n", (int)scn->environments.size());
      printf("number of vertices:     %d\n", nverts);
      printf("number of normals:      %d\n", nnorms);
      printf("number of texcoords:    %d\n", ntexcoords);
      printf("number of points:       %d\n", npoints);
      printf("number of lines:        %d\n", nlines);
      printf("number of triangles:    %d\n", ntriangles);
      printf("number of quads:        %d\n", nquads);
      printf("\n");
      printf("bbox min:    %g %g %g\n", bbox.min[0], bbox.min[1], bbox.min[2]);
      printf("bbox max:    %g %g %g\n", bbox.max[0], bbox.max[1], bbox.max[2]);
      printf("bbox center: %g %g %g\n", bboxc[0], bboxc[1], bboxc[2]);
      printf("bbox size:   %g %g %g\n", bboxs[0], bboxs[1], bboxs[2]);
      printf("\n");
    }