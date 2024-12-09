int pop1()  
{  
// Condition to check whether the stack1 is empty or not.    
if(top1==-1)  
{  
   printf("\nStack is empty..");  
}  
else  
{  
   int a=stack1[top1];  // Assigning the topmost value of stack1 to 'a' variable.   
   top1--;  // decrementing the value of top1.  
   return a;   
}  
}