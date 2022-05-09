#include "stats.h"
using namespace Statistics;

Stats Statistics::ComputeStatistics(const std::vector<T>& values ) {
    T sum = 0;
    T max = 0;
    T min = 0;
    Stats<T> data;
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
