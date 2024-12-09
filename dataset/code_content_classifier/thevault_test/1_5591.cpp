bool compare(Interval i1,Interval i2)
{   
       if(i1.arrival!=i2.arrival)
        return i1.arrival<i2.arrival;
       else if(i1.priority!=i2.priority)
        return i1.priority>i2.priority;
       else
        return i1.process<i2.process;
}