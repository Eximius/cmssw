/*! \class   TTStubAlgorithmRecord
 *  \brief   Class to store the TTStubAlgorithm used
 *           in TTStubBuilder
 *
 *  \author Andrew W. Rose
 *  \author Nicola Pozzobon
 *  \date   2013, Jul 18
 *
 */

#ifndef L1_TRACK_TRIGGER_STUB_ALGO_RECORD_H
#define L1_TRACK_TRIGGER_STUB_ALGO_RECORD_H

#include "FWCore/Framework/interface/EventSetupRecordImplementation.h"
#include "FWCore/Framework/interface/DependentRecordImplementation.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"

#include "boost/mpl/vector.hpp"

class TTStubAlgorithmRecord
  : public edm::eventsetup::DependentRecordImplementation< TTStubAlgorithmRecord, boost::mpl::vector< TrackerDigiGeometryRecord, IdealGeometryRecord, IdealMagneticFieldRecord > >{};

#endif


