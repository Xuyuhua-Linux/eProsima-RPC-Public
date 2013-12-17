/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorRESTProtocol.h
 * This header file contains the declaration of the protocol used to create REST messages.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Calculator_REST_PROTOCOL_H_
#define _Calculator_REST_PROTOCOL_H_

#include "CalculatorProtocol.h"
#include "transports/messages/HttpMessage.h"
#include "utils/Messages.h"
#include <string>

using namespace std;

namespace eprosima
{
    namespace rpcdds
    {
        namespace protocol
        {
            namespace rest
            {
                // TODO Quitar
                class RESTSerializer;
            
                /*!
                 * @brief This class is responsible for serializing and deserializing the requests and responses of this application.
                 *  It uses a RESTful protocol.
                 */
                class RPCDDSUSERDllExport CalculatorProtocol : public eprosima::rpcdds::protocol::CalculatorProtocol
                {
                    public:
                    
                       /*!
                        * @brief Default constructor
                        */
                        CalculatorProtocol();
                        
                       /*!
                        * @brief Default destructor
                        */
                        virtual ~CalculatorProtocol();
                        
                       /*!
                        * @brief This method sets the transport for the communications.
                        *        It must be an HTTP transport.
                        * @param transport Transport to use
                        * @return True if the assignment is successful, false otherwise
                        */
                        bool setTransport(eprosima::rpcdds::transport::Transport &transport);
                        
                       /*!
                        * @brief This method does not apply to this class
                        */
                        bool activateInterface(const char* interfaceName);
                        
                       /*!
                        * @brief This callback receives the requests and calls the specific protocol to process them
                        * @param protocol Protocol that must process the request
                        * @param data Received data
                        * @param dataLength received data length
                        * @param endpoint Proxy endpoint where the request came from
                        */
                        static void worker(Protocol& protocol, void *&data, size_t dataLength, eprosima::rpcdds::transport::Endpoint *endpoint);
                        



                        /*!
                         * @brief This method implements the server part of the protocol for the operation add
                         */
                        eprosima::rpcdds::transport::HttpMessage deserialize_addResource_add(RESTSerializer &restSerializer, eprosima::rpcdds::transport::HttpMessage &httpMessage);

                        /*!
                         * @brief This method implements the proxy part of the protocol for the operation add
                         */
                        Calculator::AddResponse Calculator_addResource_add(/*in*/ DDS_Long a, /*in*/ DDS_Long b);





                        /*!
                         * @brief This method implements the server part of the protocol for the operation substract
                         */
                        eprosima::rpcdds::transport::HttpMessage deserialize_substractResource_substract(RESTSerializer &restSerializer, eprosima::rpcdds::transport::HttpMessage &httpMessage);

                        /*!
                         * @brief This method implements the proxy part of the protocol for the operation substract
                         */
                        Calculator::SubstractResponse Calculator_substractResource_substract(/*in*/ DDS_Long a, /*in*/ DDS_Long b);





                        /*!
                         * @brief This method implements the server part of the protocol for the operation multiply
                         */
                        eprosima::rpcdds::transport::HttpMessage deserialize_multiplyResource_multiply(RESTSerializer &restSerializer, eprosima::rpcdds::transport::HttpMessage &httpMessage);

                        /*!
                         * @brief This method implements the proxy part of the protocol for the operation multiply
                         */
                        Calculator::MultiplyResponse Calculator_multiplyResource_multiply(/*in*/ DDS_Long a, /*in*/ DDS_Long b);





                        /*!
                         * @brief This method implements the server part of the protocol for the operation divide
                         */
                        eprosima::rpcdds::transport::HttpMessage deserialize_divideResource_divide(RESTSerializer &restSerializer, eprosima::rpcdds::transport::HttpMessage &httpMessage);

                        /*!
                         * @brief This method implements the proxy part of the protocol for the operation divide
                         */
                        Calculator::DivideResponse Calculator_divideResource_divide(/*in*/ DDS_Long a, /*in*/ DDS_Long b);




                        
                        // Server
                        eprosima::rpcdds::transport::HttpMessage processRequest(eprosima::rpcdds::transport::HttpMessage &httpMessage);
                        
                    private:
                    
                    	static int deserializeContentLength(char* buffer);
                    	
                    	static bool isNumeric(string&& myString);
                    
                };
            } // namespace rest
        } // namespace protocol
    } // namespace rpcdds
} // namespace eprosima

#endif // _Calculator_REST_PROTOCOL_H_