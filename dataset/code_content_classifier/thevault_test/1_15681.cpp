void Unwrapper::findTriangleNeighbors(const Mesh3D& _mesh, std::vector<unsigned int>& _adj_count, std::vector<int>& _triNeighbor){

    const unsigned int nTri = _mesh.getNTri();
    const unsigned int nVtx = _mesh.getNVtx();

	// which triangles contain each vertex
    std::vector<int> *vtx2tri = new std::vector<int> [nVtx];
    for (unsigned int i = 0; i < nTri; i++) {
    	const Triangle& thistri = _mesh.getTriangle(i);
        for (unsigned int j = 0; j < 3; j++){
            vtx2tri[thistri.getIndex(j)].push_back(i);
        }
    }


    for(unsigned int i = 0; i < nVtx; i++){
        std::vector<int>::iterator ita = vtx2tri[i].begin();

        for(; ita != vtx2tri[i].end(); ++ita){
            std::vector<int>::iterator itb = vtx2tri[i].begin();

            for(; itb != vtx2tri[i].end(); ++itb){

            	// in case both iterators are pointing to the same triangle
                if ((*ita)==(*itb))
                    continue;

                // Variables needed for the identification of adjacent triangles
                int va0, va1, va2;
                int vb0, vb1, vb2;

                va0 = _mesh.getTriangle(*ita).getIndex(0);
                va1 = _mesh.getTriangle(*ita).getIndex(1);
                va2 = _mesh.getTriangle(*ita).getIndex(2);
                vb0 = _mesh.getTriangle(*itb).getIndex(0);
                vb1 = _mesh.getTriangle(*itb).getIndex(1);
                vb2 = _mesh.getTriangle(*itb).getIndex(2);


                // In case an edge of each triangle is the same
                if ((((va0==vb0)||(va0==vb1)||(va0==vb2))&&((va1==vb0)||(va1==vb1)||(va1==vb2)))||
                    (((va0==vb0)||(va0==vb1)||(va0==vb2))&&((va2==vb0)||(va2==vb1)||(va2==vb2)))||
                    (((va2==vb0)||(va2==vb1)||(va2==vb2))&&((va1==vb0)||(va1==vb1)||(va1==vb2)))) {

                    // The values number of adj triangles is updated
                    // for both pointed triangles and the neighbor
                    // triangle index as well

                    // case it-A
                    switch (_adj_count[*ita]){
                    case 0:
                        _triNeighbor[3*(*ita)] = *itb;
                        _adj_count[*ita] = 1;
                        break;
                    case 1:
                        if (_triNeighbor[3*(*ita)] != *itb){
                            _triNeighbor[3*(*ita)+1] = *itb;
                            _adj_count[*ita] = 2;
                        }
                        break;
                    case 2:
                        if ((_triNeighbor[3*(*ita)] != *itb) && (_triNeighbor[3*(*ita)+1] != *itb)){
                            _triNeighbor[3*(*ita)+2] = *itb;
                            _adj_count[*ita] = 3;
                        }
                    }

                    // case it-B
                    switch (_adj_count[*itb]){
                    case 0:
                        _triNeighbor[3*(*itb)] = *ita;
                        _adj_count[*itb] = 1;
                        break;
                    case 1:
                        if (_triNeighbor[3*(*itb)] != *ita){
                            _triNeighbor[3*(*itb)+1] = *ita;
                            _adj_count[*itb] = 2;
                        }
                        break;
                    case 2:
                        if ((_triNeighbor[3*(*itb)] != *ita) && (_triNeighbor[3*(*itb)+1] != *ita)){
                            _triNeighbor[3*(*itb)+2] = *ita;
                            _adj_count[*itb] = 3;
                        }
                    }
                }
            }
        }
    }
    delete [] vtx2tri;

}