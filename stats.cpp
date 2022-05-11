#include "stats.h"
#include "cmath"

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double> &v ) {
    //Implement statistics here
    Statistics::Stats obj;
    
    if(v.size()==0)
    {
        obj.average = 0/0;
        obj.max = 0/0;
        obj.min = 0/0;
        
        return obj;
    }
    
    obj.min = 0;
    obj.max = 0;
    obj.average = 0;
    
    double sum = 0;
    int len = v.size();
    
    for(auto itr : v)
    {
        if(itr < obj.min)
            obj.min = itr;
        
        if(itr > obj.max)
            obj.max = itr;
        
        sum += itr;
        
    }
    
    
    obj.average = sum/len ;
    
    return obj;
    
    
}
