#include <string>
#include <vector>
#include <map>

#define VENDOR_ID_LENGTH 10
#define GTIN_LENGTH 16
#define CRYPTO_TAIL_LENGTH 8

struct DmCode
{
    char vendorId[VENDOR_ID_LENGTH];
    char gtin[GTIN_LENGTH];
    char cryptoTail[CRYPTO_TAIL_LENGTH];
};

struct PackageCodes
{
    int packageNum;
    std::vector<DmCode> codes;
};

// или
using PackageCodes2 = std::multimap<int,std::vector<DmCode>>;
