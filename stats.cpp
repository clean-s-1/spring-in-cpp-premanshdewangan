#include "stats.h"
#include <cmath>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double> &v ) {
    //Implement statistics here
    Statistics::Stats obj;
    
    if(v.size()==0)
    {
        obj.average = sqrt(-1);
        obj.max = sqrt(-1);
        obj.min = sqrt(-1);
        
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


void EmailAlert :: alertMessage(std::string msg)
{
    std::cout << msg << std::endl;
}


void LEDAlert :: alertMessage(std::string msg)
{
    std::cout << msg << std::endl;
}


StatsAlerter :: StatsAlerter(float threshold, std::vector<IAlerter*> &v) : alerters({})
{
    this->threshold = threshold;
    for(auto itr : v)
    {
        alerts.push_back(itr);
    }
}


void StatsAlerter :: checkAndAlert(std::vector<float> &v){
    float max = 0.0;
    for(auto itr : v )
    {
        if(max < itr)
            max = itr;
    }    
    
    if(max > this->threshold)
    {
        this->alerters[0]->emailSent = true;
        this->alerters[1]->ledGlows = true;
    }  
}
