bool MergePolysToPolyTree(const Array<Array<Vec2>>& inputPolygons, PolyTree& solution)
	{
		Paths input = UpscaleClipperPoints(inputPolygons);

		// Fire up clipper and union!
		Clipper clipper;
		clipper.StrictlySimple(true);

		try  // there is a "throw" in AddPolygon
		{
			clipper.AddPaths(input, ptSubject, true);
		}
		catch (...)
		{
			printf("clipper.AddPaths, something went wrong\n");
		}

		return clipper.Execute(ctUnion, solution, pftNonZero, pftNonZero);
	}