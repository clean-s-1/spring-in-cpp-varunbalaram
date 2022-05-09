#include "stats.h"
using namespace Statistics;

Stats Statistics::ComputeStatistics(const std::vector<float>& values ) {
    float sum = 0.0;
    float max = 0.0;
    float min = 0.0;
    Stats data;
    if(!values.empty())
    {
        for (auto itr = values.begin(); itr != values.end(); itr++)
        {
            sum += *itr;
            if (*itr > max)
            {
                max = *itr;
            }
            if (*itr < min)
            {
                min = *itr;
            }
        }
        data.average = sum / values.size();
        data.max = max;
        data.min = min;
    }
    return data;
}
