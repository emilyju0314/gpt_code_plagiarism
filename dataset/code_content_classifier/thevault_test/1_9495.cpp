void Image::Visualize(const char* name)
{
   MPI_Comm comm = pmesh->GetComm();
   std::string sname(name);

   PetscErrorCode ierr;
   PetscMPIInt rank,size;
   ierr = MPI_Comm_rank(comm,&rank); CCHKERRQ(comm,ierr);
   ierr = MPI_Comm_size(comm,&size); CCHKERRQ(comm,ierr);

   Array<ParGridFunction*> gfs;
   for (int i = 0; i < vdim; i++)
   {
      gfs.Append(new ParGridFunction(sfes));
   }
   if (vdim > 1)
   {
      for (int i = 0; i < vdim; i++)
      {
         ComponentCoefficient coeff(*imgcoeffv,i);
         gfs[i]->ProjectDiscCoefficient(coeff,GridFunction::ARITHMETIC);
      }
   }
   else
   {
      gfs[0]->ProjectDiscCoefficient(*imgcoeff,GridFunction::ARITHMETIC);
   }

   for (int i = 0; i < vdim; i++)
   {
      char vishost[] = "localhost";
      int  visport   = 19916;
      socketstream sock(vishost, visport);
      sock << "parallel " << size << " " << rank << "\n";
      sock.precision(8);
      sock << "solution\n" << *pmesh << *(gfs[i]) << std::flush;
      sock << "window_size 800 800\n";
      if (vdim > 1)
      {
         sock << "window_title '" << sname << "-" << i << "'\n";
      }
      else
      {
         sock << "window_title '" << sname << "'\n";
      }
      sock << "keys RJlc\n" << std::flush;
   }
   for (int i = 0; i < vdim; i++)
   {
      delete gfs[i];
   }
}