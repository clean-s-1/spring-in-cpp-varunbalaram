#include "stats.h"
using namespace Statistics;

Stats Statistics::ComputeStatistics(const std::vector<double>& values ) {
    double sum = 0;
    double max = 0;
    double min;
    Stats data;
    if(!values.empty())
    {
        min = values[0];
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
