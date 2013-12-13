/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this RPCDDS distribution.
 *
 *************************************************************************
 * 
 * @file BankRESTProtocol.cxx
 * This source file contains the definition of the protocol used to create REST messages.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "BankRESTProtocol.h"
#include "exceptions/Exceptions.h"
#include "transports/ProxyTransport.h"
#include "transports/ServerTransport.h"
#include "protocols/rest/RESTSerializer.h"

using namespace eprosima::rpcdds;
using namespace ::protocol::rest;
using namespace ::transport;
using namespace eprosima::rpcdds::exception;

#include <sstream>

using namespace std;

BankProtocol::BankProtocol() {}

BankProtocol::~BankProtocol() {}

bool BankProtocol::setTransport(Transport &transport)
{    
    if(strcmp(transport.getType(), "HTTP") != 0)
    {
        throw IncompatibleException("protocol and transport are incompatibles");
    }
    
    if(transport.getBehaviour() == SERVER_BEHAVIOUR)
    {
        // If this is a server transport, we set its callback
        eprosima::rpcdds::transport::ServerTransport &serverTransport = dynamic_cast<eprosima::rpcdds::transport::ServerTransport&>(transport);
        serverTransport.setCallback(&BankProtocol::worker);
    }
        
    _setTransport(transport);
        
    return true;
}

bool BankProtocol::activateInterface(const char* interfaceName)
{
    return true;
}

int BankProtocol::deserializeContentLength(char* buffer) {
	char contentLength[16];
	strcpy(contentLength, "Content-Length:");
	char *p = strtok(buffer, "\r\n");
	while(p) {
		p[strlen(p)] = '\r'; // strtok puts a '\0', we don't want it
		if(memcmp(p, contentLength, 15) == 0) {
			return atoi(p+15); // 15 = "Content-Length:"
		}
		p = strtok(NULL, "\r\n");
	}

	return 0;
}

void BankProtocol::worker(Protocol& protocol, void *data, size_t dataLength, eprosima::rpcdds::transport::Endpoint *endpoint)
{
    // TODO : Call the protocol
    eprosima::rpcdds::protocol::rest::BankProtocol &restProtocol = dynamic_cast<eprosima::rpcdds::protocol::rest::BankProtocol&>( protocol );
    HttpMessage *httpMessage = reinterpret_cast<HttpMessage*>(data);

    HttpMessage response = restProtocol.processRequest(*httpMessage);
    
    dynamic_cast<ServerTransport&>(restProtocol.getTransport()).sendReply(&response, 0, endpoint);
}





string BankProtocol::expandPath_getAccountDetails(string &&path, account_accountNumber account_accountNumber)
{
    RESTSerializer restSerializer;
    stringstream stream;
    string expandedPath;
    
    restSerializer.beginSerializeTemplateParameters(std::move(path));


            // Expand accountNumber_
            stream << account_accountNumber.accountNumber_;
            restSerializer.serializeTemplateParameter(stream.str());
            stream.str(std::string());
            stream.clear();
             
    
    restSerializer.endSerializeTemplateParameters(expandedPath);
        
    return expandedPath;
}
GetAccountDetailsResponse BankProtocol::account_accountNumberResource_getAccountDetails(/*in*/ const account_accountNumber& account_accountNumber, /*in*/ const char* user, /*in*/ const GetAccountDetailsRequest& GetAccountDetailsRequest)
{
     stringstream stream;
     RESTSerializer restSerializer;
     eprosima::rpcdds::transport::ProxyTransport &proxyTransport = dynamic_cast<eprosima::rpcdds::transport::ProxyTransport&>( getTransport() );
     GetAccountDetailsResponse getAccountDetails_ret;
     GetAccountDetailsResponse_initialize(&getAccountDetails_ret);
     // XXX TODO if NULL -> error
     
     // Resource Base URI = /resources/
     // Path = account/{accountNumber}
     // Method = POST
     // Body Parameter = GetAccountDetailsRequest

     HttpMessage httpMessage;
     
     httpMessage.setMethod(HttpMessage::HTTP_METHOD_POST);
     //TODO Chequear host en el transport.
     httpMessage.setHost("example.com");
     std::string uri(expandPath_getAccountDetails("/resources/account/{accountNumber}", account_accountNumber)); 
     
        std::string paramValue;
        stream << user;
        paramValue = stream.str();
        stream.str(std::string());
        stream.clear();
        restSerializer.serializeQueryParameter(uri, "user", paramValue);

               

     
     httpMessage.setUri(uri);
     



     // Serializing body parameter GetAccountDetailsRequest
     switch(GetAccountDetailsRequest._d)
     {
     case 1:
         httpMessage.setBodyData(GetAccountDetailsRequest._u.xmlRepresentation);
         break;

     }

     if(!httpMessage.getBodyData().empty())
     {
         if(GetAccountDetailsRequest._d == 1)
             httpMessage.setBodyContentType("application/xml");
         else if(GetAccountDetailsRequest._d == 2)
             httpMessage.setBodyContentType("application/json");
     }

     
     // HTTP connection
     // TODO Check connection error.
     proxyTransport.connect();
     proxyTransport.send(&httpMessage, 0);
     HttpMessage httpResponse;
     size_t dump;
     proxyTransport.receive(&httpResponse, 0, dump);
     
     int discriminator = 0;

     if(httpResponse.getBodyContentType().find("xml") != string::npos)
     {
        discriminator = 1;
     } 
     else if(httpResponse.getBodyContentType().find("json") != string::npos)
     {
        discriminator = 2;
     }
    
     getAccountDetails_ret._d = discriminator;
     
     switch(discriminator)
     {
     case 1:
          getAccountDetails_ret._u.xmlGetAccountDetailsResponse.status = httpResponse.getResponseCode();
          getAccountDetails_ret._u.xmlGetAccountDetailsResponse.xmlRepresentation = strdup(httpResponse.getBodyData().c_str());
          break;
          
     }
              
     return getAccountDetails_ret;
}

void BankProtocol::deserializePath_getAccountDetails(RESTSerializer &restSerializer, account_accountNumber& account_accountNumber)
{
    stringstream stream;
    

            // Deserialize accountNumber_
            stream << restSerializer.getTag(1);
            stream >> account_accountNumber.accountNumber_;
            stream.str(std::string());
            stream.clear();

            
}
HttpMessage BankProtocol::deserialize_account_accountNumberResource_getAccountDetails(RESTSerializer &restSerializer, HttpMessage &httpMessage)
{
    std::stringstream stream;
    
    account_accountNumber account_accountNumber;
    deserializePath_getAccountDetails(restSerializer, account_accountNumber);

    // Deserialize user
    std::string user = restSerializer.getQueryParameter("user");



    





    // Deserializing body parameter GetAccountDetailsRequest
    GetAccountDetailsRequest GetAccountDetailsRequest;
    std::string mediaType = httpMessage.getBodyContentType();
    int discriminator = 0;
    if(mediaType.find("xml") != string::npos)
        discriminator = 1;
    if(mediaType.find("json") != string::npos)
        discriminator = 2;
        
    GetAccountDetailsRequest._d = discriminator;
    switch(discriminator) {

    case 1:
    GetAccountDetailsRequest._u.xmlRepresentation = (char*)httpMessage.getBodyData().c_str();
    break;

    }
    
    // TODO Check implementation.
    GetAccountDetailsResponse GetAccountDetailsResponse = _account_accountNumberResource_impl->getAccountDetails(  account_accountNumber , user.c_str() , GetAccountDetailsRequest   );
    
    HttpMessage httpResponse;
    switch(GetAccountDetailsResponse._d)
    {
    case 1:
        httpResponse.setResponseCode(GetAccountDetailsResponse._u.xmlGetAccountDetailsResponse.status);
    httpResponse.setBodyData(GetAccountDetailsResponse._u.xmlGetAccountDetailsResponse.xmlRepresentation); 
        break;

    }

    if(httpResponse.getBodyData().size() > 0)
    {
        if(GetAccountDetailsResponse._d == 1)
            httpResponse.setBodyContentType("application/xml");
        else if(GetAccountDetailsResponse._d == 2)
            httpResponse.setBodyContentType("application/json");
    }

    
    return httpResponse;
}

// Server
HttpMessage BankProtocol::processRequest(HttpMessage &httpMessage)
{
    RESTSerializer restSerializer;
    
    restSerializer.deserializeUri(httpMessage.getUri(), "/resources/");
    
    // TODO Siempre se crea aunque no haya un error. Cambiar
    HttpMessage http404Response;
    http404Response.setResponseCode(404);
    http404Response.setResponseStatus("Resource not found");
    
    // BEGIN ITERATION 
    string tag;
    char *p = NULL;
    if(!restSerializer.existsTagLevel(0)) {
    return http404Response; // ERROR NO OPERATIONS
    }
    if(restSerializer.getTag(0).compare("account") == 0) {
    // BEGIN ITERATION account
    if(!restSerializer.existsTagLevel(1)) {
    return http404Response; // ERROR NO OPERATIONS
    }
    strtol(strdup(restSerializer.getTag(1).c_str()), &p, 10);
    if(!*p) {
    // BEGIN ITERATION {accountNumber}
    if(!restSerializer.existsTagLevel(2)) {
    if(httpMessage.getMethod() == HttpMessage::HTTP_METHOD_POST) {
    if(restSerializer.existsQueryParameter("user")) {
    return deserialize_account_accountNumberResource_getAccountDetails(restSerializer, httpMessage); // MATCHING
    }
    }
    }
    // END ITERATION {accountNumber}
    }
    // END ITERATION account
    }
    // ERROR NO MATCH FOUND
    // END ITERATION 

    
    return http404Response;
}