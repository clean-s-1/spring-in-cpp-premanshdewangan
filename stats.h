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
        virtual void alertMessage(string) = 0;
};

class EmailAlert : public IAlerter{
    public:
        bool emailSent;
        void alertMessage(string);
};

class LEDAlert : public IAlerter{
    public:
        bool ledGlows;
        void alertMessage(string);
};


class StatsAlerter{
    private:
        float threshold;
        std::vector<IAlerter*> alerters;
            
    public:
        StatsAlerter(float, std::vector<IAlerter*> &);
    
        void checkAndAlert(vector<float> &);
};
