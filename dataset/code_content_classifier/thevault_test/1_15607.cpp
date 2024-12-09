int graphPrintWalk(nodePtr rootp, int &pos, int level, 
                   vector<string>& output)
{
    if(rootp == NULL) 
        return pos;
    else
    {
        // Expand the size of the output array if this is the first
        // node on a new level
        if(output.size() <= (level*2))
        {
            output.push_back("");
            output.push_back("");
        }
        
        // Calculate the x position of both child nodes and the current node
        int leftPos = graphPrintWalk(rootp->left, pos, level+1, output);
    
        int currPos = pos;
        
        ostringstream currDatum;
        currDatum << rootp;
        pos += currDatum.str().length()+1;
    
        int rightPos = graphPrintWalk(rootp->right, pos, level+1, output);
        
        // initialize the output streams with the current output for the level
        
        ostringstream linkLine, nodeLine;
    
        linkLine << output[level*2];
        nodeLine << output[level*2+1];

        // calculate the center of the current node
        int currOffset = currPos + (currDatum.str().length() / 2) - 1;
        
        // add the left node and its link to the current output for the level
        if(rootp->left != NULL)
        {
            // calculate the center of the left child node
            ostringstream leftDatum;
            leftDatum << rootp->left;
            int leftOffset = leftPos + (leftDatum.str().length() / 2) - 1;
            
            nodeLine << string(leftPos - nodeLine.str().length(), ' ') 
                     << rootp->left;
            
            // draw a link from this node to the left child node
            linkLine << string((leftOffset+1) - linkLine.str().length(), ' ') 
                     << string((currOffset)-(leftOffset+1), '_') << "/";
			
        }
    
        // add the right node and its link to the current output for the level
        if(rootp->right != NULL)
        {
            // calculate the center of the right child node
            ostringstream rightDatum;
            rightDatum << rootp->right;
            int rightOffset = rightPos + (rightDatum.str().length() / 2) - 1;
            
            nodeLine << string(rightPos - nodeLine.str().length(),' ') 
                     << rootp->right;
            
            // draw a link from this node to the right child node
            linkLine << string((currOffset+1) - linkLine.str().length(),' ') 
                     << "\\" <<	string((rightOffset-1) - (currOffset), '_') 
                     << " ";
        }
    
        // save the results for the current level
        output[level*2]   = linkLine.str();
        output[level*2+1] = nodeLine.str();
        
        return currPos;
    }
}