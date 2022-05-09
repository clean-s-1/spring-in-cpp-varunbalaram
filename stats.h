#include <vector>
#include <math.h>

namespace Statistics {
    class Stats
    {
        public:
        Stats():average(NAN),max(NAN),min(NAN){}
        float average;
        float max;
        float min;
    };
    
    Stats ComputeStatistics(const std::vector<float>& );
    
    class IAlerter
    {
        public:
        virtual void SetAlert(bool value) = 0;
    };
    
    class EmailAlert: public IAlerter
    {
    public:
        EmailAlert():emailSent(false){}
        void SetAlert(bool value)
        {
            emailSent = value;
        }
        bool emailSent;
    };
    
    class LEDAlert: public IAlerter
    {
    public:
        LEDAlert():ledGlows(false){}
        void SetAlert(bool value)
        {
            ledGlows = value;
        }
        bool ledGlows;
    };
    
    class StatsAlerter
    {
        private:
        float maxLimit;
        std::vector<IAlerter*> notifiers;
        public:
        StatsAlerter(float limit, std::vector<IAlerter*>& values):maxLimit(limit),notifiers(values){}
        void checkAndAlert(const std::vector<float>& values)
        {
            float max = 0.0;
            bool alert = false;
            if(!values.empty())
            {
                for (auto itr = values.begin(); itr != values.end(); itr++)
                {
                    if (*itr > max)
                    {
                        max = *itr;
                    }
                }
                if(max > maxLimit)
                {
                    alert = true;
                }
                
                for (auto itr = notifiers.begin(); itr != notifiers.end(); itr++)
                {
                    itr->SetAlert(alert);
                }
                
            }
        }
    };
}
