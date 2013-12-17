/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldServerExample.cxx
 * This source file shows a simple example of how to create a server for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "HelloWorldServer.h"
#include "strategies/ThreadPoolStrategy.h"
#include "HelloWorldRESTProtocol.h"
#include "transports/HttpServerTransport.h"
#include "exceptions/Exceptions.h"
#include "utils/Utilities.h"
#include "HelloWorldServerImplExample.h"

#include <iostream>

using namespace eprosima::rpcdds;
using namespace eprosima::rpcdds::exception;
using namespace eprosima::rpcdds::strategy;
using namespace eprosima::rpcdds::transport;
using namespace eprosima::rpcdds::protocol::rest;

int main(int argc, char **argv)
{
    unsigned int threadPoolSize = 5;
    ThreadPoolStrategy *pool = NULL;
    HelloWorldProtocol *protocol = NULL;
    HttpServerTransport *transport = NULL;
    HelloWorld::HelloWorldResourceServer *server = NULL;
    HelloWorldResourceServerImplExample servant;
    
    // Create and initialize the server for interface "HelloWorld::HelloWorldResource".
    try
    {
        pool = new ThreadPoolStrategy(threadPoolSize);
        protocol = new HelloWorldProtocol();
        transport = new HttpServerTransport("127.0.0.1:8080");
        server = new HelloWorld::HelloWorldResourceServer(*pool, *transport, *protocol, servant);
        server->serve();
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    while(1)
    {
        eprosima::rpcdds::sleep(10000);
    }
    
    // Stop and delete the server.
    server->stop();
    delete server;
    delete protocol;
    delete transport;
    delete pool;
    
    return 0;
}




