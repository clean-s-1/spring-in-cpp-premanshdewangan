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
