/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorProxy.h
 * This header file contains the declaration of the proxy for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Calculator_PROXY_H_
#define _Calculator_PROXY_H_

#include "client/Proxy.h"
#include "exceptions/SystemException.h"
#include "exceptions/UserException.h"
#include "utils/dds/Middleware.h"
#include "Calculator.h"

namespace eprosima
{
    namespace rpcdds
    {
        namespace protocol
        {
            class CalculatorProtocol;
        }
    }
}

namespace Calculator
{
    /*!
     * @brief This abstract class defines the callbacks that RPCDDS will call in an asynchronous call.
     *        These callback has to be implemented in a derived class.
     */
    class addResource_addCallbackHandler
    {
        public:
            /*!
             * This function is called when is received the reply from the server.
             */
            virtual void add(/*out*/ const Calculator::AddResponse& add_ret) = 0;
            
            /*!
             * @brief This function is called when an exception occurs.
             *        This exception can be launched in the server's side or in the client's side.
             *
             * @param ex The exception that will be launched.
             */
            virtual void on_exception(const eprosima::rpcdds::exception::SystemException &ex) = 0;
    };


    /*!
     * @brief This class implements a specific server's proxy for the defined interface addResource.
     */
    class RPCDDSUSERDllExport addResourceProxy : public eprosima::rpcdds::proxy::Proxy
    {
        public:
       
            /*!
             * @brief This constructor sets the transport that will be used by the server's proxy.
             *
             * @param transport The network transport that server's proxy has to use.
             *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
             * @param protocol The protocol used to send the information over the transport.
             *        This protocol's object is not deleted by this class in its destructor. Cannot be NULL.
             * @exception eprosima::rpcdds::exception::InitializeException This exception is thrown when the initialization was wrong.
             */
            addResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
                eprosima::rpcdds::protocol::CalculatorProtocol &protocol);

            //! @brief The default destructor.
            virtual ~addResourceProxy();
            



            //! @brief Proxy method for the operation add
            Calculator::AddResponse add(/*in*/ DDS_Long a, /*in*/ DDS_Long b);

            
            ////! @brief Proxy asynchronous method for the operation add
            void add_async(addResource_addCallbackHandler &obj, /*in*/ DDS_Long a, /*in*/ DDS_Long b);

    };

    /*!
     * @brief This abstract class defines the callbacks that RPCDDS will call in an asynchronous call.
     *        These callback has to be implemented in a derived class.
     */
    class substractResource_substractCallbackHandler
    {
        public:
            /*!
             * This function is called when is received the reply from the server.
             */
            virtual void substract(/*out*/ const Calculator::SubstractResponse& substract_ret) = 0;
            
            /*!
             * @brief This function is called when an exception occurs.
             *        This exception can be launched in the server's side or in the client's side.
             *
             * @param ex The exception that will be launched.
             */
            virtual void on_exception(const eprosima::rpcdds::exception::SystemException &ex) = 0;
    };


    /*!
     * @brief This class implements a specific server's proxy for the defined interface substractResource.
     */
    class RPCDDSUSERDllExport substractResourceProxy : public eprosima::rpcdds::proxy::Proxy
    {
        public:
       
            /*!
             * @brief This constructor sets the transport that will be used by the server's proxy.
             *
             * @param transport The network transport that server's proxy has to use.
             *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
             * @param protocol The protocol used to send the information over the transport.
             *        This protocol's object is not deleted by this class in its destructor. Cannot be NULL.
             * @exception eprosima::rpcdds::exception::InitializeException This exception is thrown when the initialization was wrong.
             */
            substractResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
                eprosima::rpcdds::protocol::CalculatorProtocol &protocol);

            //! @brief The default destructor.
            virtual ~substractResourceProxy();
            



            //! @brief Proxy method for the operation substract
            Calculator::SubstractResponse substract(/*in*/ DDS_Long a, /*in*/ DDS_Long b);

            
            ////! @brief Proxy asynchronous method for the operation substract
            void substract_async(substractResource_substractCallbackHandler &obj, /*in*/ DDS_Long a, /*in*/ DDS_Long b);

    };

    /*!
     * @brief This abstract class defines the callbacks that RPCDDS will call in an asynchronous call.
     *        These callback has to be implemented in a derived class.
     */
    class multiplyResource_multiplyCallbackHandler
    {
        public:
            /*!
             * This function is called when is received the reply from the server.
             */
            virtual void multiply(/*out*/ const Calculator::MultiplyResponse& multiply_ret) = 0;
            
            /*!
             * @brief This function is called when an exception occurs.
             *        This exception can be launched in the server's side or in the client's side.
             *
             * @param ex The exception that will be launched.
             */
            virtual void on_exception(const eprosima::rpcdds::exception::SystemException &ex) = 0;
    };


    /*!
     * @brief This class implements a specific server's proxy for the defined interface multiplyResource.
     */
    class RPCDDSUSERDllExport multiplyResourceProxy : public eprosima::rpcdds::proxy::Proxy
    {
        public:
       
            /*!
             * @brief This constructor sets the transport that will be used by the server's proxy.
             *
             * @param transport The network transport that server's proxy has to use.
             *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
             * @param protocol The protocol used to send the information over the transport.
             *        This protocol's object is not deleted by this class in its destructor. Cannot be NULL.
             * @exception eprosima::rpcdds::exception::InitializeException This exception is thrown when the initialization was wrong.
             */
            multiplyResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
                eprosima::rpcdds::protocol::CalculatorProtocol &protocol);

            //! @brief The default destructor.
            virtual ~multiplyResourceProxy();
            



            //! @brief Proxy method for the operation multiply
            Calculator::MultiplyResponse multiply(/*in*/ DDS_Long a, /*in*/ DDS_Long b);

            
            ////! @brief Proxy asynchronous method for the operation multiply
            void multiply_async(multiplyResource_multiplyCallbackHandler &obj, /*in*/ DDS_Long a, /*in*/ DDS_Long b);

    };

    /*!
     * @brief This abstract class defines the callbacks that RPCDDS will call in an asynchronous call.
     *        These callback has to be implemented in a derived class.
     */
    class divideResource_divideCallbackHandler
    {
        public:
            /*!
             * This function is called when is received the reply from the server.
             */
            virtual void divide(/*out*/ const Calculator::DivideResponse& divide_ret) = 0;
            
            /*!
             * @brief This function is called when an exception occurs.
             *        This exception can be launched in the server's side or in the client's side.
             *
             * @param ex The exception that will be launched.
             */
            virtual void on_exception(const eprosima::rpcdds::exception::SystemException &ex) = 0;
    };


    /*!
     * @brief This class implements a specific server's proxy for the defined interface divideResource.
     */
    class RPCDDSUSERDllExport divideResourceProxy : public eprosima::rpcdds::proxy::Proxy
    {
        public:
       
            /*!
             * @brief This constructor sets the transport that will be used by the server's proxy.
             *
             * @param transport The network transport that server's proxy has to use.
             *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
             * @param protocol The protocol used to send the information over the transport.
             *        This protocol's object is not deleted by this class in its destructor. Cannot be NULL.
             * @exception eprosima::rpcdds::exception::InitializeException This exception is thrown when the initialization was wrong.
             */
            divideResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
                eprosima::rpcdds::protocol::CalculatorProtocol &protocol);

            //! @brief The default destructor.
            virtual ~divideResourceProxy();
            



            //! @brief Proxy method for the operation divide
            Calculator::DivideResponse divide(/*in*/ DDS_Long a, /*in*/ DDS_Long b);

            
            ////! @brief Proxy asynchronous method for the operation divide
            void divide_async(divideResource_divideCallbackHandler &obj, /*in*/ DDS_Long a, /*in*/ DDS_Long b);

    };

};


#endif // _Calculator_PROXY_H_