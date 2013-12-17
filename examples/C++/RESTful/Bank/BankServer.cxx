/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file BankServer.cxx
 * This source file contains the definition of the server for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "BankServer.h"
#include "strategies/ServerStrategy.h"
#include "transports/ServerTransport.h"
#include "BankProtocol.h"
#include "exceptions/ServerInternalException.h"

namespace Bank
{
    account_accountNumberResourceServer::account_accountNumberResourceServer(eprosima::rpcdds::strategy::ServerStrategy &strategy, eprosima::rpcdds::transport::ServerTransport &transport,
                eprosima::rpcdds::protocol::BankProtocol &protocol, account_accountNumberResourceServerImpl &servant) :
        Server(strategy, transport, protocol), _impl(servant)
    {
       protocol.activateInterface("Bank::account_accountNumberResource");
       protocol.linkBank_account_accountNumberResourceImpl(servant);
    }

    account_accountNumberResourceServer::~account_accountNumberResourceServer()
    {
        //TODO Unlink an deactivate.
    }






    /*void account_accountNumberResourceServer::getAccountDetails(eProsima::RPCDDS::Server *server, void *requestData, eProsima::RPCDDS::ServerRPC *service)
    { 
        account_accountNumberResourceServer *srv = dynamic_cast<account_accountNumberResourceServer*>(server);
        Bank::account_accountNumber account_accountNumber;
        char*  user = NULL;
        Bank::GetAccountDetailsRequest GetAccountDetailsRequest;
        Bank::GetAccountDetailsResponse getAccountDetails_ret;
        memset(&getAccountDetails_ret, 0, sizeof(Bank::GetAccountDetailsResponse));   
        account_accountNumberResource_getAccountDetailsReply replyData;
        

        account_accountNumberResource_getAccountDetailsRequestUtils::extractTypeData(*(account_accountNumberResource_getAccountDetailsRequest*)requestData, account_accountNumber, user, GetAccountDetailsRequest);

        try
        {
            getAccountDetails_ret = srv->_impl.getAccountDetails(account_accountNumber, user, GetAccountDetailsRequest);

            account_accountNumberResource_getAccountDetailsReplyUtils::setTypeData(replyData, getAccountDetails_ret);
            replyData.header.rpcddsRetCode = eProsima::RPCDDS::OPERATION_SUCCESSFUL;
            replyData.header.rpcddsRetMsg = (char*)"";

            service->sendReply(requestData, &replyData);
        }
        catch(const eProsima::RPCDDS::ServerInternalException &ex)
        {
            memset((char*)&replyData + sizeof(replyData.header), 0, sizeof(replyData) - sizeof(replyData.header));
            replyData.header.rpcddsRetCode = eProsima::RPCDDS::SERVER_INTERNAL_ERROR;
            replyData.header.rpcddsRetMsg = (char*)ex.what();
            
            service->sendReply(requestData, &replyData);
        }
        
        account_accountNumberResource_getAccountDetailsRequestTypeSupport::delete_data((account_accountNumberResource_getAccountDetailsRequest*)requestData);
        
        Bank::GetAccountDetailsResponse_finalize(&getAccountDetails_ret);
    }*/


};
