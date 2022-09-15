#include <main.hpp>
#include <iostream>
#include <thread>
#include <unistd.h>






int main (void)
{
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");

    while (1) {
        char buffer [10];
        zmq_recv (responder, buffer, 10, 0);
        printf ("Received Hello\n");
        sleep(3);
        zmq_send (responder, "World", 5, 0);
    }
    return 0;
}