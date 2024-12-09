void BuildFaceNodeMaps(Mesh *mesh, MatrixXd xf, MatrixXd yf, MatrixXd zf, MatrixXi &mapP){

  int K       = mesh->K;
  int Nfaces  = mesh->Nfaces;

  mapP.resize(xf.rows(),K);
  mapP.fill(-1);

  int Nfpts = xf.rows() / Nfaces; // assume same # qpts per face (i.e. not hybrid meshes)

  double x1, y1, z1, x2, y2, z2, d12;

  //  cout << "EToF = " << endl << mesh->EToF << endl;
  //  cout << "EToE = " << endl << mesh->EToE << endl;  
  
  printf("Building face node maps\n");

  for(int k1=0;k1<K;++k1){

    for(int f1=0;f1<Nfaces;++f1){

      // find neighbor                                           
      int k2 = mesh->EToE(k1,f1);
      int f2 = mesh->EToF(k1,f1);

      //printf("k1 = %d, k2 = %d\n",k1,k2);

      if(k1==k2){
        for(int i = 0; i < Nfpts; ++i){
          mapP(i + f1*Nfpts,k1) = i + f1*Nfpts + xf.rows()*k1;
        }
      }else{

	//printf("Looking for matches on elem %d, face %d to elem %d, face %d\n",k1,f1,k2,f2);

        MatrixXd xM(Nfpts,3);
        MatrixXd xP(Nfpts,3);
        for(int i = 0; i < Nfpts; ++i){
          int id1 = i + Nfpts * f1;
          x1 = xf(id1,k1); y1 = yf(id1,k1); z1 = zf(id1,k1);
          int id2 = i + Nfpts * f2;
          x2 = xf(id2,k2); y2 = yf(id2,k2); z2 = zf(id2,k2);

          xM(i,0) = x1; xM(i,1) = y1; xM(i,2) = z1;
          xP(i,0) = x2; xP(i,1) = y2; xP(i,2) = z2;
        }

        for(int i = 0; i < Nfpts; ++i){

          double minDist = 1000.0;

          int id1 = i + Nfpts * f1;
          x1 = xf(id1,k1); y1 = yf(id1,k1); z1 = zf(id1,k1);
          bool node_found = false;
          for(int j = 0; j < Nfpts; ++j){

            int id2 = j + Nfpts * f2;
            x2 = xf(id2,k2); y2 = yf(id2,k2); z2 = zf(id2,k2);
            // find distance between these nodes                 
            d12 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
            minDist = min(minDist,d12);
            if (d12<NODETOL){
              mapP(id1,k1) = id2 + xf.rows()*k2;
              node_found = true;
              break;
            }
          }
          if(!node_found){
            printf("BuildFaceNodeMaps: lost node %d on elems %d, %d. min dist = %g\n",i,k1,k2,minDist);
            cout << "xM = " << endl << xM << endl;
            cout << "xP = " << endl << xP << endl;
          }
        }
      }

    }// faces
  }// k                                                                                                        

  return;
}