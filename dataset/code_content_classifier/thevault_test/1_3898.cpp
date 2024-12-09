void simu_env_init(int np, int rank)
{
    B2R_B_X = ENV_DIM_X / BLOCK_DIM_X;
    B2R_B_Y = ENV_DIM_Y / BLOCK_DIM_Y;
    B2R_B_Z = ENV_DIM_Z / BLOCK_DIM_Z;

#if _ENV_3D_
    if(B2R_R*B2R_D > min(B2R_B_X, min(B2R_B_Y, B2R_B_Z))/2){
        if(rank == 0){
            cout << "should meet condition: 1 <= B2R_R*B2R_D <= min(B2R_B_X, B2R_B_Y, B2R_B_Z)/2" << endl;
        }
        exit(1);
    }
#endif
    B2R_BLOCK_SIZE_X = (B2R_B_X + 2*B2R_D*B2R_R);
    B2R_BLOCK_SIZE_Y = (B2R_B_Y + 2*B2R_D*B2R_R);
#if _ENV_3D_
    B2R_BLOCK_SIZE_Z = (B2R_B_Z + 2*B2R_D*B2R_R);
#else
    B2R_BLOCK_SIZE_Z = 1;
#endif

/*
    int Rd = B2R_R * B2R_D;
    int buffer_size = sizeof(CELL_DT) * max(max(Rd*B2R_B_Y*B2R_B_Z, B2R_BLOCK_SIZE_X*Rd*B2R_B_Z), 
                                            B2R_BLOCK_SIZE_X*B2R_BLOCK_SIZE_Y*Rd);
    // sending buffer                                        
    pad_send_buf[0] = new char[buffer_size]();    // direction 1(to: left/up/infront)
    pad_send_buf[1] = new char[buffer_size]();    // direction 2(to: right/down/behind)
    // receiving buffer
    pad_recv_buf[0] = new char[buffer_size]();    // direction 1(from: left/up/infront)
    pad_recv_buf[1] = new char[buffer_size]();    // direction 2(from: right/down/behind)    
*/
    b2r_sync_init(); // allocate send/recv buffer in device memory 

    char filename[100];
#if _DEBUG_
    sprintf( filename, "R-%d-stdout-%d.txt", B2R_R, rank );
    freopen( filename, "w", stdout );
#else
    if(rank == 0)
    {
#if _MDL_DEV_ == 0
        sprintf(filename, "R-%d-D-%d-ENV-%dX%dX%d-BLOCK-%dX%dX%d-CPU.txt", B2R_R, B2R_D, 
                B2R_B_X*BLOCK_DIM_X, B2R_B_Y*BLOCK_DIM_Y, B2R_B_Z*BLOCK_DIM_Z, BLOCK_DIM_X, BLOCK_DIM_Y, BLOCK_DIM_Z );
#else
        sprintf(filename, "R-%d-D-%d-ENV-%dX%dX%d-BLOCK-%dX%dX%d-GPU.txt", B2R_R, B2R_D, 
                B2R_B_X*BLOCK_DIM_X, B2R_B_Y*BLOCK_DIM_Y, B2R_B_Z*BLOCK_DIM_Z, BLOCK_DIM_X, BLOCK_DIM_Y, BLOCK_DIM_Z );
#endif                
        freopen( filename, "w", stdout );
    }
#endif
}