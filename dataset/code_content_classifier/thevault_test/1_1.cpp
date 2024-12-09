void Camera::placement(){

    E << eye[0], eye[1], eye[2];
    Vector3d L;
    L << look[0], look[1], look[2];
    Vector3d UP;
    UP << up[0], up[1], up[2];
    W = E - L; 
    W.normalize();
    U = UP.cross(W); 
    U.normalize();
    V = W.cross(U);
    
}