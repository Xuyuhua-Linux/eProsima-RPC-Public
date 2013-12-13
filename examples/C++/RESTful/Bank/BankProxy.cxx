/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file BankProxy.cxx
 * This source file contains the definition of the proxy for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "BankProxy.h"
#include "transports/ProxyTransport.h"
#include "BankProtocol.h"
//#include "BankAsyncSupport.h"

account_accountNumberResourceProxy::account_accountNumberResourceProxy(eprosima::rpcdds::transport::ProxyTransport &transport,
    eprosima::rpcdds::protocol::BankProtocol &protocol) : Proxy(transport, protocol)
{
    protocol.activateInterface("account_accountNumberResource");
}

account_accountNumberResourceProxy::~account_accountNumberResourceProxy()
{
}





GetAccountDetailsResponse account_accountNumberResourceProxy::getAccountDetails(/*in*/ const account_accountNumber& account_accountNumber, /*in*/ const char* user, /*in*/ const GetAccountDetailsRequest& GetAccountDetailsRequest)
{
    GetAccountDetailsResponse getAccountDetails_ret =
    dynamic_cast<eprosima::rpcdds::protocol::BankProtocol&>(getProtocol()).account_accountNumberResource_getAccountDetails(account_accountNumber, user, GetAccountDetailsRequest);
    return getAccountDetails_ret;
}

