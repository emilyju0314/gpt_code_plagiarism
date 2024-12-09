void push1(int data)  
{  
// Condition to check whether the stack1 is full or not.    
 if(top1==N-1)  
{  
   printf("\n Stack is overflow...");  
}  
else  
{  
   top1++;   // Incrementing the value of top1  
   stack1[top1]=data;  // pushing the data into stack1  
}  
}