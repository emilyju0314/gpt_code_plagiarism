void AliCaloPhotonCuts::SplitEnergy(Int_t absCellId1, Int_t absCellId2,
                                    AliVCluster* cluster,
                                    AliVEvent* event,
                                    Int_t isMC,
                                    AliAODCaloCluster* cluster1,
                                    AliAODCaloCluster* cluster2){

  const Int_t ncells      = cluster->GetNCells();
  Int_t absCellIdList[ncells];

  AliVCaloCells* cells    = NULL;
  if (fClusterType == 1 || fClusterType == 3 || fClusterType == 4)
    cells                 = event->GetEMCALCells();
  else if (fClusterType ==2 )
    cells                 = event->GetPHOSCells();

  Float_t e1              = 0;
  Float_t e2              = 0;
  Float_t eCluster        = 0;

  for(Int_t iCell    = 0;iCell < ncells;iCell++ ) {
    absCellIdList[iCell]  = cluster->GetCellsAbsId()[iCell];
    Float_t ec            = cells->GetCellAmplitude(absCellIdList[iCell]);
    eCluster+=ec;
  }

  UShort_t absCellIdList1 [12];
  Double_t fracList1      [12];
  UShort_t absCellIdList2 [12];
  Double_t fracList2      [12];

  // Init counters and variables
  Int_t ncells1         = 1 ;
  absCellIdList1[0]     = absCellId1 ;
  fracList1 [0]         = 1. ;

  Float_t ecell1        = cells->GetCellAmplitude(absCellId1);
  e1                    = ecell1;

  Int_t ncells2         = 1 ;
  absCellIdList2[0]     = absCellId2 ;
  fracList2 [0]         = 1. ;

  Float_t ecell2        = cells->GetCellAmplitude(absCellId2);
  e2                    = ecell2;

//   cout << "Cluster: " << eCluster << "\t cell1: " << absCellId1 << "\t" << e1 << "\t cell2: " << absCellId2 << "\t" << e2 << endl;
  // Very rough way to share the cluster energy
  Float_t eRemain           = (eCluster-ecell1-ecell2)/2;
  Float_t shareFraction1    = (ecell1+eRemain)/eCluster;
  Float_t shareFraction2    = (ecell2+eRemain)/eCluster;

//   cout << eRemain << "\t" << shareFraction1<< "\t" << shareFraction2 << endl;

  for(Int_t iCell = 0;iCell < ncells;iCell++){

    Int_t absId         = absCellIdList[iCell];
    if ( absId==absCellId1 || absId==absCellId2 || absId < 0 ) continue;

    Float_t ecell = cells->GetCellAmplitude(absId);
    if(AreNeighbours(absCellId1,absId )){
      absCellIdList1[ncells1] = absId;
      if(AreNeighbours(absCellId2,absId )){
        fracList1[ncells1] = shareFraction1;
        e1 += ecell*shareFraction1;
      } else {
        fracList1[ncells1] = 1.;
        e1 += ecell;
      }
      ncells1++;
    } // neigbour to cell1

    if(AreNeighbours(absCellId2,absId )) {
      absCellIdList2[ncells2]= absId;

      if(AreNeighbours(absCellId1,absId )){
        fracList2[ncells2] = shareFraction2;
        e2 += ecell*shareFraction2;
      } else {
        fracList2[ncells2] = 1.;
        e2 += ecell;
      }
      ncells2++;
    } // neigbour to cell2
  }
//   cout << "Cluster: " << eCluster << "\t cell1: " << absCellId1 << "\t" << e1 << "\t cell2: " << absCellId2 << "\t" << e2 << endl;

  cluster1->SetE(e1);
  cluster2->SetE(e2);

  cluster1->SetNCells(ncells1);
  cluster2->SetNCells(ncells2);

  cluster1->SetCellsAbsId(absCellIdList1);
  cluster2->SetCellsAbsId(absCellIdList2);

  cluster1->SetCellsAmplitudeFraction(fracList1);
  cluster2->SetCellsAmplitudeFraction(fracList2);

  // Correct linearity
  ApplyNonLinearity(cluster1, isMC) ;
  ApplyNonLinearity(cluster2, isMC) ;

  // Initialize EMCAL rec utils if not initialized
  if(!fEMCALInitialized && (fClusterType == 1 || fClusterType == 3 || fClusterType == 4) ) InitializeEMCAL(event);

  if(fEMCALInitialized && (fClusterType == 1 || fClusterType == 3 || fClusterType == 4) ){
    fEMCALRecUtils->RecalculateClusterPosition(fGeomEMCAL, cells, cluster1);
    fEMCALRecUtils->RecalculateClusterPosition(fGeomEMCAL, cells, cluster2);
  }
}