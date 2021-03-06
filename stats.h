#include<iostream>
#include <vector>


namespace Statistics {
    
    struct Stats{
        double max;
        double min;
        double average;
    };

    typedef struct Stats Stats;
    
    Stats ComputeStatistics(const std::vector<double>& );
}


class IAlerter{
    public:
        virtual void setAlert() = 0;
};

class EmailAlert : public IAlerter{
    public:
        bool emailSent;
        virtual void setAlert();
};

class LEDAlert : public IAlerter{
    public:
        bool ledGlows;
        virtual void setAlert();
};


class StatsAlerter{
    private:
        float threshold;
        std::vector<IAlerter*> alerters;
            
    public:
        StatsAlerter(float, std::vector<IAlerter*> &);
    
        void checkAndAlert(std::vector<float> &v);
};
