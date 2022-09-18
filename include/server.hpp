#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <unistd.h>
#include <hiredis/hiredis.h>

#define NUMBER_OF_TEST_DM 100
#define DM_SIZE 32

namespace server
{

struct RedisCtxDestroy
{

    void operator() (redisContext * ctx)
    {
        if (ctx) {
            free (ctx);
        }
    }
};


using redisUniquePtr = std::unique_ptr<redisContext, RedisCtxDestroy>;

redisUniquePtr
connectRedis(void);






} // namespace server