import FWCore.ParameterSet.Config as cms

process = cms.Process("test")

process.load("CondCore.CondDB.CondDB_cfi")
# output database (in this case local sqlite file)
process.CondDB.connect = 'sqlite_file:MyPedestals.db'


process.PoolDBOutputService = cms.Service("PoolDBOutputService",
    process.CondDB,
    timetype = cms.untracked.string('runnumber'),
    toPut = cms.VPSet(cms.PSet(
        record = cms.string('MyPedestalsRcd'),
        tag = cms.string('myPedestal_test"')
    ))
)
process.PoolDBESSource = cms.ESSource("PoolDBESSource",
    process.CondDB,
    DumpStat=cms.untracked.bool(True),
    toGet = cms.VPSet(cms.PSet(
        record = cms.string('MyPedestalsRcd'),
        tag = cms.string('myPedestal_test')
    )),
)