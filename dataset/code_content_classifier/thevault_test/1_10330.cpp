bool Triangulate(const Array<Array<Vec2>>& inputPolygons, const Array<Vec2>& boundingPolygon, Array<Float2> &vertices, Array<uint32>& indices)
	{
		// Use clipper to clean.  This upscales the floating point input
		PolyTree polyTree;
		MergePolysToPolyTree(inputPolygons, polyTree);

		Path outline = UpscaleClipperPoints(boundingPolygon);

		PolyNode tempNode;
		PolyNode* rootNode = (polyTree.Total() == 0) ? &tempNode : polyTree.GetFirst()->Parent;
		rootNode->Contour = outline;

		Array<p2t::Point> base;

		// Now traverse our polyline nodes and triangulate them with only their children holes
		for (PolyNode *currentNode = rootNode; currentNode != nullptr; currentNode = currentNode->GetNext())
		{
			if (!currentNode->IsHole())
			{
				continue;
			}

			// A Clipper hole is actually what we want to build zones for; they become our bounding
			// polylines.  poly2tri holes are therefore the inverse
			const size_t contourSize = currentNode->Contour.size();

			for (size_t i = 0; i < contourSize; ++i)
			{
				base.emplace_back(static_cast<double>(currentNode->Contour[i].X), static_cast<double>(currentNode->Contour[i].Y));
			}

			size_t holeBaseSize = 0;

			for (const auto& childNode : currentNode->Childs)
			{
				//edgeShrink(childNode->Contour); // Slightly modify the polygon to guarantee no duplicate points

				holeBaseSize += childNode->Contour.size();
			}

			base.reserve(contourSize + holeBaseSize);

			// Build up this polyline in poly2tri's format (downscale Clipper points)
			std::vector<p2t::Point*> polyline(base.size());

			for (size_t i = 0; i < contourSize; ++i)
			{
				polyline[i] = &base[i];
			}

			// Set our polyline in poly2tri
			p2t::CDT cdt(polyline);

			for (const auto& childNode : currentNode->Childs)
			{
				const size_t holeSize = childNode->Contour.size();

				std::vector<p2t::Point*> hole(holeSize);

				for (size_t i = 0; i < holeSize; ++i)
				{
					base.emplace_back(double(childNode->Contour[i].X), double(childNode->Contour[i].Y));

					hole[i] = &base.back();
				}

				cdt.AddHole(hole);
			}

			cdt.Triangulate();

			if (base.isEmpty())
			{
				return false;
			}

			for (const auto& v : base)
			{
				vertices.emplace_back(v.x * CLIPPER_SCALE_FACT_INVERSE, v.y * CLIPPER_SCALE_FACT_INVERSE);
			}

			const size_t num_triangles = cdt.GetTriangles().size();
			indices.resize(num_triangles * 3);
			const auto begin = &base[0];
			uint32* pDstIndex = indices.data();

			for (auto& currentTriangle : cdt.GetTriangles())
			{
				*pDstIndex++ = static_cast<uint32>(currentTriangle->GetPoint(0) - begin);
				*pDstIndex++ = static_cast<uint32>(currentTriangle->GetPoint(1) - begin);
				*pDstIndex++ = static_cast<uint32>(currentTriangle->GetPoint(2) - begin);
			}

			break;
		}

		return true;
	}