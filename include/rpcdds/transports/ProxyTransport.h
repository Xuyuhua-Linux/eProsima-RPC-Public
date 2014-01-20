/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************/

#ifndef _TRANSPORTS_PROXYTRANSPORT_H_
#define _TRANSPORTS_PROXYTRANSPORT_H_

#include "rpcdds/rpcdds_dll.h"
#include "rpcdds/transports/Transport.h"

namespace eprosima
{
    namespace rpcdds
    {
        namespace transport
        {
            /*!
             * @brief This interface is the base of all classes that implement a transport
             *        that can be used by the proxy.
             * @ingroup TRANSPORTMODULE
             */
            class RPCDDS_DllAPI ProxyTransport : public Transport
            {
                public:

                    //! \brief Default constructor.
                    ProxyTransport(){}

                    //! \brief Default destructor.
                    virtual ~ProxyTransport(){}

                    /*!
                     * @brief This function returns the type of the transport.
                     *        This function has to be implemented by the child classes.
                     */
                    virtual const char* getType() const = 0;

                    /*!
                     * @brief This function returns the behaviour of the transport.
                     * @return The behaviour of the transport.
                     */
                    TransportBehaviour getBehaviour() const
                    {
                        return PROXY_BEHAVIOUR;
                    }

					/*!
					 * @brief Abstract method. It must start a connection with the server.
					 * @return true if the operation is successful, false otherwise.
					 */
                    virtual bool connect() = 0;

					/*!
					 * @brief Abstract method. It must send a request to the server.
					 * @param buffer Buffer containing the request
					 * @param bufferSize Buffer size
					 * @return true if the operation is successful, false otherwise.
					 */
                    virtual bool send(const void* buffer, const size_t bufferSize) = 0;

					/*!
					 * @brief Abstract method. It must receive a reply from the server.
					 * @param buffer Buffer that will contain the HTTP message.
					 * @param bufferSize Size of the buffer.
					 * @param dataToRead Number of bytes received.
					 * @return -1 if the operation fails.
					 */
                    virtual int receive(void *buffer, const size_t bufferSize, size_t &dataToRead) = 0;
            };
        }
        // namespace transport
    }// namespace rpcdds
} // namespace eprosima
#endif // _TRANSPORTS_PROXYTRANSPORT_H_