#include <main.hpp>
#include "server.hpp"


// REDIS IS HERE

namespace server
{

redisUniquePtr
connectRedis()
{

    redisContext * ctx;
    uint32_t isunix = 1;
    const char * hostName = "127.0.0.1";
    const int port = 6379;
    struct timeval timeout = { 1, 500000 };
    
    ctx = redisConnectWithTimeout(hostName, port, timeout);
    if (ctx == nullptr || ctx->err) {
        if (ctx) {

            printf("Connection error: %s\n", ctx->errstr);
            return server::redisUniquePtr(ctx);

        } else {

            printf("Connection error: can't allocate redis context\n");
            return server::redisUniquePtr(ctx);
        }
    }
    printf("Connection to redis is OK!\n");
    return server::redisUniquePtr(ctx);

}

} // namespace server