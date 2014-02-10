/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file BasicTypeTestClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "UnionTestProxy.h"
#include "UnionTestCDRProtocol.h"
#include "rpcdds/transports/TCPProxyTransport.h"
#include "rpcdds/exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::rpcdds;
using namespace ::exception;
using namespace ::transport;
using namespace ::protocol::cdr;

int main(int argc, char **argv)
{
    UnionTestProtocol *protocol = NULL;
    TCPProxyTransport *transport = NULL;
    UnionTestProxy *proxy = NULL;
    
    // Creation of the proxy for interface "UnionTest".
    try
    {
        protocol = new UnionTestProtocol();
        transport = new TCPProxyTransport("127.0.0.1:8080");
        proxy = new UnionTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    Empleado em1;
    Empleado em2;
    Empleado em3;
    Empleado getEmpleado_ret;

    Empleado_initialize(&em1);    
    Empleado_initialize(&em2);    
    Empleado_initialize(&em3);    
    Empleado_initialize(&getEmpleado_ret);    

    em1._d = 1;
    em1._u.id = 1;
    em2._d = 2;
    em2._u.name = DDS::String_dup("PRUEBA");

    try
    {
        getEmpleado_ret = proxy->getEmpleado(em1, em2, em3);

        if(em3._d != 2 || strcmp(em3._u.name, "PRUEBA") != 0 ||
                getEmpleado_ret._d != 1 || getEmpleado_ret._u.id != 1 ||
                em2._d != 1 || em2._u.id != 1 ||
                em1._d != 1 || em1._u.id != 1)
        {
            std::cout << "TEST FAILED<getEmpleado>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout <<  "TEST FAILED<getEmpleado>: " << ex.what() << std::endl;
        _exit(-1);
    }

    Empleado_finalize(&em1);    
    Empleado_finalize(&em2);    
    Empleado_finalize(&em3);    
    Empleado_finalize(&getEmpleado_ret);    

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete proxy;
    delete transport;
    delete protocol;

    _exit(0);
    return 0;
}
