#include "main.hpp"
#include "server.hpp"

int main (void)
{

    server::redisUniquePtr ctx = server::connectRedis();

    if (ctx.get() == nullptr) {

        std::cout << "redis error" << std::endl;
        return 1;
    }


    // FILL TEST STRINGS
    std::vector<std::string> testCodes(NUMBER_OF_TEST_DM);
    for (int i = 0; i < NUMBER_OF_TEST_DM; ++i ) {

        testCodes[i] = std::to_string(i);
        if( testCodes[i].size() < DM_SIZE ) {

            testCodes[i].insert(0, DM_SIZE - testCodes[i].size(), '0' );
        }

    }

    // FILL TEST REDIS
    for (int i = 0; i < NUMBER_OF_TEST_DM; ++i) {

        std::string code = testCodes[i];
        std::string used = "used";
        std::string false_ = "false";
        std::string package = "package";
        std::string _1 = "1";
        redisReply * reply = reinterpret_cast<redisReply *> (redisCommand(ctx.get(),
                                                                "HSET %s %s %s %s %s",
                                                                code.c_str(),
                                                                used.c_str(), false_.c_str(),
                                                                package.c_str(), _1.c_str()));
        freeReplyObject(reply);
    }


    /* ZMQ */
    //  Socket to talk to clients
    void * context = zmq_ctx_new ();
    void * socket = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (socket, "tcp://*:5555");

    while (1) {
        char buffer [10];
        zmq_recv (socket, buffer, 10, 0);
        printf ("Received Hello\n");
        sleep(3);
        zmq_send (socket, "World", 5, 0);
    }
    return 0;
}