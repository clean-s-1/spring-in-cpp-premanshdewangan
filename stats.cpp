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


void EmailAlert :: setAlert()
{
    emailSent = true;
}


void LEDAlert :: setAlert()
{
    ledGlows = true;
}


StatsAlerter :: StatsAlerter(float threshold, std::vector<IAlerter*> &v)
{
    this->threshold = threshold;
    this->alerters[0] = v[0];
    this->alerters[1] = v[1];
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
        this->alerters[0]->setAlert();
        this->alerters[1]->setAlert();
    } 
       
}
