/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file HelloWorldClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "HelloWorldProxy.h"
#include "HelloWorldRESTProtocol.h"
#include "transports/HttpProxyTransport.h"
#include "exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::rpcdds;
using namespace eprosima::rpcdds::exception;
using namespace eprosima::rpcdds::transport;
using namespace eprosima::rpcdds::protocol::rest;

int main(int argc, char **argv)
{
    HelloWorldProtocol *protocol = NULL;
    ProxyTransport *transport = NULL;
    HelloWorld::HelloWorldResourceProxy *proxy = NULL;
    
    // Creation of the proxy for interface "HelloWorld::HelloWorldResource".
    try
    {
        protocol = new HelloWorldProtocol();
        transport = new HttpProxyTransport("127.0.0.1:8080");
        proxy = new HelloWorld::HelloWorldResourceProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }
    
    // Create and initialize parameters.
    char*  name = strdup("Richard");

    // Create and initialize return value.
    HelloWorld::HelloResponse hello_ret;
    HelloWorld::HelloResponse_initialize(&hello_ret);

    // Call to remote procedure "hello".
    try
    {
        hello_ret = proxy->hello(name);
		if(hello_ret._d == 1) {
			std::cout << hello_ret._u.xmlHelloResponse.xmlRepresentation << std::endl;
		}
    }
    catch(SystemException &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    
    if(name != NULL) free(name);

    HelloWorld::HelloResponse_finalize(&hello_ret);
    
    delete(proxy);
    delete(transport);
    delete(protocol);
   
    return 0;
}




