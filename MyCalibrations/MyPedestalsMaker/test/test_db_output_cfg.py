import FWCore.ParameterSet.Config as cms

process = cms.Process("test")

process.load("CondCore.CondDB.CondDB_cfi")
# output database (in this case local sqlite file)
process.CondDB.connect = 'sqlite_file:MyPedestals.db'

process.source = cms.Source("EmptyIOVSource",
    timetype = cms.string('runnumber'),
    firstValue = cms.uint64(1),
    lastValue = cms.uint64(1),
    interval = cms.uint64(1)
)

process.PoolDBOutputService = cms.Service("PoolDBOutputService",
    process.CondDB,
    timetype = cms.untracked.string('runnumber'),
    toPut = cms.VPSet(cms.PSet(
        record = cms.string('MyPedestalsRcd'),
        tag = cms.string('myPedestal_test')
    ))
)

process.mytest = cms.EDAnalyzer("MyPedestalsMaker",
    record = cms.string('MyPedestalsRcd'),
    loggingOn= cms.untracked.bool(True),
    SinceAppendMode=cms.bool(True),
    Source=cms.PSet(
    IOVRun=cms.untracked.uint32(1)
    )
)

process.p = cms.Path(process.mytest)

'''process.PoolDBESSource = cms.ESSource("PoolDBESSource",
    process.CondDB,
    DumpStat=cms.untracked.bool(True),
    toGet = cms.VPSet(cms.PSet(
        record = cms.string('MyPedestalsRcd'),
        tag = cms.string('myPedestal_test')
    )),
)'''
