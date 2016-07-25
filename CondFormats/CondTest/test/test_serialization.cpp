#include "CondFormats/Serialization/interface/Test.h"

#include "../src/headers.h"

int main()
{
    testSerialization<MyPedestals>();
    testSerialization<std::vector<MyPedestals>>();
    testSerialization<std::vector<MyPedestals::Item>>();
}