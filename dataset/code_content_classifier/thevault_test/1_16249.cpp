bool RCNeighbourList::doCoarsePatch(int n_neigh)
  {
    FUNCNAME("RCNeighbourList::doCoarsePatch()");

    for (int i = 0; i < n_neigh; i++)
    {
      Element* lel = rclist[i]->el;

      if (lel->getMark() >= 0 || lel->isLeaf())
      {
        /****************************************************************************/
        /*  element must not be coarsend or element is a leaf element, reset the    */
        /*  the coarsening flag on all those elements that have to be coarsend with */
        /*  this element                                                            */
        /****************************************************************************/
        lel->setMark(0);
        for (int j = 0; j < n_neigh; j++)
          if (rclist[j]->flag)
            rclist[j]->el->setMark(0);

        return false;
      }
      else if (lel->getFirstChild()->getMark() >= 0 ||
               lel->getSecondChild()->getMark() >= 0)
      {

        /****************************************************************************/
        /*  one of the element's children must not be coarsend; reset the coarsening*/
        /*  flag on all those elements that have to be coarsend with this element   */
        /****************************************************************************/
        lel->setMark(0);
        for (int j = 0; j < n_neigh; j++)
          if (rclist[j]->flag)
            rclist[j]->el->setMark(0);

        return false;
      }
      else if (!lel->getFirstChild()->isLeaf() ||
               !lel->getSecondChild()->isLeaf())
      {
        /****************************************************************************/
        /*  one of the element's children is not a leaf element;                    */
        /*  element may be coarsend after coarsening one of the children; try again */
        /****************************************************************************/
        coarseningManager->doMore = true;

        return false;
      }
      else
      {
        /****************************************************************************/
        /*  either one element is a macro element or we can coarsen the patch       */
        /****************************************************************************/
        if (rclist[i]->flag == 0)
        {
          Mesh* coarse_mesh = coarseningManager->getMesh();
          std::deque<MacroElement*>::const_iterator mel;
          // set in Mesh::coarsen()
          for (mel = coarse_mesh->firstMacroElement();
               mel!=coarse_mesh->endOfMacroElements(); ++mel)
            if ((*mel)->getElement() == lel)
              break;

          TEST_EXIT(mel != coarse_mesh->endOfMacroElements())
          ("incompatible coarsening patch found\n");
        }
      }
    }

    return true;
  }