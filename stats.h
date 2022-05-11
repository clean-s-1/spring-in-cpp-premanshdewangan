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

/*
class IAlerter{
//     public:
//         virtual void alertMessage(std::string) = 0;
};

class EmailAlert : public IAlerter{
    public:
        bool emailSent;
//         void alertMessage(std::string);
};

class LEDAlert : public IAlerter{
    public:
        bool ledGlows;
//         void alertMessage(std::string);
};
*/

class EmailAlert{
    protected:
        bool emailSent;
};

class LEDAlert{
    protected:
        bool ledGlows;
};

class IAlerter : public EmailAlert, public LEDAlert{
    public:
        setALerts(bool e, bool l)
        {
            EmailAlert::emailSent = true;
            LEDAlert::ledGlows = true;
        }
};


class StatsAlerter{
    private:
        float threshold;
        std::vector<IAlerter*> alerters;
            
    public:
        StatsAlerter(float, std::vector<IAlerter*> &);
    
        void checkAndAlert(std::vector<float> &v);
};
