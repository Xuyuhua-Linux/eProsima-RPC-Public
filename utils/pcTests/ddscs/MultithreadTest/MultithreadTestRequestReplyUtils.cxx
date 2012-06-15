/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "MultithreadTestRequestReplyUtils.h"
#include "MultithreadTestRequestReplyPlugin.h"


const char* testRequestUtils::registerType(DDSDomainParticipant *clientParticipant)
{
    const char *typeName = NULL;

    if(clientParticipant != NULL)
    {
        typeName = testRequestTypeSupport::get_type_name();

        if(testRequestTypeSupport::register_type(clientParticipant, typeName) != DDS_RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

testRequest* testRequestUtils::createTypeData(Dato & dato1)
{
    testRequest* instance = testRequestTypeSupport::create_data();

    DatoPluginSupport_copy_data(&instance->dato1, &dato1);
    
    
    return instance;
}

void testRequestUtils::extractTypeData(testRequest* data , Dato  &dato1)
{
    DatoPluginSupport_copy_data(&dato1, &data->dato1);
    
    
}


const char* testReplyUtils::registerType(DDSDomainParticipant *clientParticipant)
{
    const char *typeName = NULL;

    if(clientParticipant != NULL)
    {
        typeName = testReplyTypeSupport::get_type_name();

        if(testReplyTypeSupport::register_type(clientParticipant, typeName) != DDS_RETCODE_OK)
        {
            return NULL;
        }
    }

    return typeName;
}

testReply* testReplyUtils::createTypeData(Dato & dato2, DDS_Long& returnedValue)
{
    testReply* instance = testReplyTypeSupport::create_data();

    DatoPluginSupport_copy_data(&instance->dato2, &dato2);
    
    instance->returnedValue = returnedValue;            
    return instance;
}

void testReplyUtils::extractTypeData(testReply* data , Dato  &dato2, DDS_Long& returnedValue)
{
    DatoPluginSupport_copy_data(&dato2, &data->dato2);
    
    returnedValue = data->returnedValue;            
}

 