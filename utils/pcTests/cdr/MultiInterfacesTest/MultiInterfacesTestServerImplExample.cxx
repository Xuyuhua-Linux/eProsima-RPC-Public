/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file MultiInterfacesTestServerImplExample.cxx
 * This source file contains the definition of the skeleton for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "MultiInterfacesTestServerImplExample.h"

#include "ndds/ndds_namespace_cpp.h"

DDS_Octet BasicTypeTestServerImplExample::getOctet(/*in*/ DDS_Octet oc1, /*inout*/ DDS_Octet& oc2, /*out*/ DDS_Octet& oc3)
{
    DDS_Octet  getOctet_ret = 0;

    oc3 = oc2;
    getOctet_ret = oc1;
    oc2 = oc1 + oc2;

    return getOctet_ret;
} 

DDS_Char BasicTypeTestServerImplExample::getChar(/*in*/ DDS_Char ch1, /*inout*/ DDS_Char& ch2, /*out*/ DDS_Char& ch3)
{
    DDS_Char  getChar_ret = 0;

    ch3 = ch2;
    getChar_ret = ch1;
    ch2 = ch1 + ch2;

    return getChar_ret;
} 

DDS_Wchar BasicTypeTestServerImplExample::getWChar(/*in*/ DDS_Wchar wch1, /*inout*/ DDS_Wchar& wch2, /*out*/ DDS_Wchar& wch3)
{
    DDS_Wchar  getWChar_ret = 0;

    wch3 = wch2;
    getWChar_ret = wch1;
    wch2 = wch1 + wch2;

    return getWChar_ret;
} 

DDS_Short BasicTypeTestServerImplExample::getShort(/*in*/ DDS_Short sh1, /*inout*/ DDS_Short& sh2, /*out*/ DDS_Short& sh3)
{
    DDS_Short  getShort_ret = 0;

    sh3 = sh2;
    getShort_ret = sh1;
    sh2 = sh1 + sh2;

    return getShort_ret;
} 

DDS_UnsignedShort BasicTypeTestServerImplExample::getUShort(/*in*/ DDS_UnsignedShort ush1, /*inout*/ DDS_UnsignedShort& ush2, /*out*/ DDS_UnsignedShort& ush3)
{
    DDS_UnsignedShort  getUShort_ret = 0;

    ush3 = ush2;
    getUShort_ret = ush1;
    ush2 = ush1 + ush2;

    return getUShort_ret;
} 

DDS_Long BasicTypeTestServerImplExample::getLong(/*in*/ DDS_Long lo1, /*inout*/ DDS_Long& lo2, /*out*/ DDS_Long& lo3)
{
    DDS_Long  getLong_ret = 0;

    lo3 = lo2;
    getLong_ret = lo1;
    lo2 = lo1 + lo2;

    return getLong_ret;
} 

DDS_UnsignedLong BasicTypeTestServerImplExample::getULong(/*in*/ DDS_UnsignedLong ulo1, /*inout*/ DDS_UnsignedLong& ulo2, /*out*/ DDS_UnsignedLong& ulo3)
{
    DDS_UnsignedLong  getULong_ret = 0;

    ulo3 = ulo2;
    getULong_ret = ulo1;
    ulo2 = ulo1 + ulo2;

    return getULong_ret;
} 

DDS_LongLong BasicTypeTestServerImplExample::getLLong(/*in*/ DDS_LongLong llo1, /*inout*/ DDS_LongLong& llo2, /*out*/ DDS_LongLong& llo3)
{
    DDS_LongLong  getLLong_ret = 0;

    llo3 = llo2;
    getLLong_ret = llo1;
    llo2 = llo1 + llo2;

    return getLLong_ret;
} 

DDS_UnsignedLongLong BasicTypeTestServerImplExample::getULLong(/*in*/ DDS_UnsignedLongLong ullo1, /*inout*/ DDS_UnsignedLongLong& ullo2, /*out*/ DDS_UnsignedLongLong& ullo3)
{
    DDS_UnsignedLongLong  getULLong_ret = 0;

    ullo3 = ullo2;
    getULLong_ret = ullo1;
    ullo2 = ullo1 + ullo2;

    return getULLong_ret;
} 

DDS_Float BasicTypeTestServerImplExample::getFloat(/*in*/ DDS_Float fl1, /*inout*/ DDS_Float& fl2, /*out*/ DDS_Float& fl3)
{
    DDS_Float  getFloat_ret = 0;

    fl3 = fl2;
    getFloat_ret = fl1;
    fl2 = fl1 + fl2;

    return getFloat_ret;
} 

DDS_Double BasicTypeTestServerImplExample::getDouble(/*in*/ DDS_Double do1, /*inout*/ DDS_Double& do2, /*out*/ DDS_Double& do3)
{
    DDS_Double  getDouble_ret = 0;

    do3 = do2;
    getDouble_ret = do1;
    do2 = do1 + do2;

    return getDouble_ret;
} 

DDS_Boolean BasicTypeTestServerImplExample::getBoolean(/*in*/ DDS_Boolean bo1, /*inout*/ DDS_Boolean& bo2, /*out*/ DDS_Boolean& bo3)
{
    DDS_Boolean  getBoolean_ret = 0;

    bo3 = bo2;
    getBoolean_ret = bo1;
    bo2 = bo1 | bo2;

    return getBoolean_ret;
} 

Struct::Recepcion StructTestServerImplExample::duplicate(/*in*/ const Struct::Envio& ev)
{
    Struct::Recepcion duplicate_ret;

    duplicate_ret.devolucion = ev.dato;
    duplicate_ret.message = DDS::String_dup(ev.message);

    return duplicate_ret;
} 

Struct::Recepcion StructTestServerImplExample::suma(/*in*/ const Struct::Envio& ev1, /*in*/ const Struct::Envio& ev2)
{
    Struct::Recepcion suma_ret;

    suma_ret.devolucion = ev1.dato + ev2.dato;
    suma_ret.message = DDS::String_alloc(strlen(ev1.message) + strlen(ev2.message) + 1);
#if defined(RTI_WIN32)
    _snprintf(suma_ret.message, strlen(ev1.message) + strlen(ev2.message) + 1, "%s%s", ev1.message, ev2.message);
#elif defined(RTI_LINUX)
    snprintf(suma_ret.message, strlen(ev1.message) + strlen(ev2.message) + 1, "%s%s", ev1.message, ev2.message);
#endif
    return suma_ret;
} 
