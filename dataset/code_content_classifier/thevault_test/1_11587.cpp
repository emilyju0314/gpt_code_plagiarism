MatrixXd VandermondeGHsurf(int N, int Npsurf, VectorXd r, VectorXd s, VectorXd t){
  int Np = (N+1)*(N+2)*(N+3)/6;
  int Npts = r.rows();
  MatrixXd V(Npts,Npsurf);

  // vertex functions
  V.col(0) = -(1.0 + r.array() + s.array() + t.array())/2.0;
  V.col(1) = (1.0 + r.array())/2.0;
  V.col(2) = (1.0 + s.array())/2.0;
  V.col(3) = (1.0 + t.array())/2.0;

  MatrixXi edges(6,2);
  edges << 0,3,
    1, 3,
    2, 3,
    0, 1,
    1, 2,
    2, 0;

  // edge basis functions
  int sk = 4;
  for (int edge =0; edge < 6; ++edge){
    for (int i = 0; i <= N-2; ++i){
      int vertex1 = edges(edge,0);
      int vertex2 = edges(edge,1);
      VectorXd V1,V2;
      V1 = V.col(vertex1);
      V2 = V.col(vertex2);
      VectorXd JP = JacobiP(V1.array()-V2.array(),0,0,i);
      V.col(sk) = V1.array()*V2.array()*JacobiP(V1.array()-V2.array(),0,0,i).array();
      ++sk;
    }
  }

  MatrixXi faces(4,3);
  faces << 0,1,3,
    1,2,3,
    2,0,3,
    0,1,2;

  // face basis functions
  VectorXd rr,ss;
  for (int f = 0; f < 4; ++f){

    int vertex1 = faces(f,0);
    int vertex2 = faces(f,1);
    int vertex3 = faces(f,2);

    VectorXd V1 = V.col(vertex1);
    VectorXd V2 = V.col(vertex2);
    VectorXd V3 = V.col(vertex3);

    barytors(V1,V2,V3,rr,ss); // convert affine coords to r,s
    MatrixXd Vface = Vandermonde2D(N-3,rr,ss);
    for (int i = 0; i < Vface.cols(); ++i){
      V.col(sk) = V1.array()*V2.array()*V3.array()*Vface.col(i).array();
      ++sk;
    }
  }
  return V;
}