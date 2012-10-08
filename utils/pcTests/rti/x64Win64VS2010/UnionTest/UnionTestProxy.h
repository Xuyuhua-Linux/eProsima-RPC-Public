#ifndef _UnionTest_PROXY_H_
#define _UnionTest_PROXY_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "client/Client.h"
#include "UnionTestRequestReplyUtils.h"
#include "UnionTestClientRPCSupport.h"

class UnionTest_getEmpleado
{
    public:
        virtual void getEmpleado(/*inout*/ const Empleado* em2, /*out*/ const Empleado* em3, /*out*/ const Empleado* getEmpleado_ret)
        {
        }
   
        virtual void error(eProsima::DDSRPC::ReturnMessage message)
        {
        }
};

/**
 * \brief This class implements a specific client's proxy for the defined interface by user.
 */
class UnionTestProxyH : public eProsima::DDSRPC::Client
{
    public:

        /**
         * \brief Default constructor. The client's proxy has to know what network transport
         *        it should use.
         *
         * \param transport The network transport that client's proxy has to use. Cannot be NULL.
         * \param domainId The DDS domain that DDS will use to work. Default value: 0
         * \param timeout Timeout used in each call to remotely procedures.
         *        If the call exceeds the time, the call return a eProsima::DDSRPC::SERVER_TIMEOUT.
         */
        UnionTestProxyH(eProsima::DDSRPC::Transport *transport, int domainId = 0, long timeout = 10000);

        /// \brief The default destructor.
        virtual ~UnionTestProxyH();
        
         
        eProsima::DDSRPC::ReturnMessage getEmpleado(/*in*/ const Empleado* em1, /*inout*/ Empleado* &em2, /*out*/ Empleado* &em3, /*out*/ Empleado* &getEmpleado_ret);
        
         
        eProsima::DDSRPC::ReturnMessage getEmpleado_async(UnionTest_getEmpleado &obj, /*in*/ const Empleado* em1, /*inout*/ const Empleado* em2);
        
    private:
        eProsima::DDSRPC::ClientRPC *getEmpleado_Service; 
};

/**
 * \brief This class implements a specific client's proxy for the defined interface by user.
 *        This client's proxy uses the UDPv4 transport.
 */
class UnionTestProxy : public UnionTestProxyH
{
    public:
    
        /**
         * \brief Default constructor.
         *
         * \param domainId The DDS domain that DDS will use to work. Default value: 0
         * \param timeout Timeout used in each call to remotely procedures.
         *        If the call exceeds the time, the call return a eProsima::DDSRPC::SERVER_TIMEOUT.
         */
        UnionTestProxy(int domainId = 0, long timeout = 10000);
        
        virtual ~UnionTestProxy();
};

/**
 * \brief This class implements a specific client's proxy for the defined interface by user.
 *        This client's proxy uses the TCPv4 transport.
 */
class UnionTestWANProxy : public UnionTestProxyH
{
    public:
    
        /**
         * \brief Default constructor.
         *
         * \param to_connect Public address and port for the server. By example: "218.18.3.133:7600"
         * \param domainId The DDS domain that DDS will use to work. Default value: 0
         * \param timeout Timeout used in each call to remotely procedures.
         *        If the call exceeds the time, the call return a eProsima::DDSRPC::SERVER_TIMEOUT.
         */
        UnionTestWANProxy(const char *to_connect, int domainId = 0, long timeout = 10000);
        
        virtual ~UnionTestWANProxy();
};

#endif // _UnionTest_PROXY_H_