
#ifndef PEDESTALS_H
#define PEDESTALS_H
#include "CondFormats/Serialization/interface/Serializable.h"


#include <vector>

class MyPedestals{
public:
	struct Item {
		float m_mean;
		float m_variance;
  		COND_SERIALIZABLE;
	};

  typedef std::vector<Item>::const_iterator ItemIterator;
	std::vector<Item> m_pedestals;
  	COND_SERIALIZABLE;
};
#endif