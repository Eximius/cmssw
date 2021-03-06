#include <algorithm>
#include "DataFormats/HcalRecHit/interface/HFQIE10Info.h"

HFQIE10Info::HFQIE10Info()
    : charge_(0.f),
      energy_(0.f),
      timeRising_(0.f),
      timeFalling_(-1.f),
      raw_{INVALID_RAW, INVALID_RAW, INVALID_RAW, INVALID_RAW, INVALID_RAW},
      nRaw_(0),
      soi_(0)
{
}

HFQIE10Info::HFQIE10Info(const HcalDetId& id,
                         const float i_charge, const float i_energy,
                         const float i_timeRising, const float i_timeFalling,
                         const raw_type* rawData, const unsigned nData,
                         const unsigned i_soi)
    : id_(id),
      charge_(i_charge),
      energy_(i_energy),
      timeRising_(i_timeRising),
      timeFalling_(i_timeFalling),
      raw_{INVALID_RAW, INVALID_RAW, INVALID_RAW, INVALID_RAW, INVALID_RAW},
      nRaw_(std::min(nData, N_RAW_MAX)),
      soi_(0)
{
    if (nData)
    {
        unsigned tbegin = 0;
        if (i_soi >= nData)
        {
            // No SOI in the data. This situation is not normal
            // but can not be addressed in this code.
            if (nData > nRaw_)
                tbegin = nData - nRaw_;
            soi_ = nRaw_;
        }
        else
        {
            if (nData > nRaw_)
            {
                // Want to keep at least 2 presamples
                if (i_soi > 2U)
                {
                    tbegin = i_soi - 2U;
                    if (tbegin + nRaw_ > nData)
                        tbegin = nData - nRaw_;
                }
            }
            soi_ = i_soi - tbegin;
        }

        raw_type* to = &raw_[0];
        const raw_type* from = rawData + tbegin;
        for (unsigned i=0; i<nRaw_; ++i)
            *to++ = *from++;
    }
}
