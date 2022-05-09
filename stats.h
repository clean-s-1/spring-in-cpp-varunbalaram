#include <vector>

namespace Statistics {
    class Stats
    {
        public:
        Stats():average(0.0),max(0.0),min(0.0){}
        float average;
        float max;
        float min;
    };
    
    Stats ComputeStatistics(const std::vector<float>& );
}
