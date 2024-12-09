void push2(int x)  
{  
//  Condition to check whether the stack2 is full or not  
if(top2==N-1)  
{  
   printf("\nStack is full..");  
}  
else  
{  
    top2++;   // incrementing the value of top2.  
    stack2[top2]=x;  // assigning the 'x' value to the Stack2  
  
}  
}