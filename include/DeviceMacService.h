#ifndef XTC_DEVICEMACSERVICE_H
#define XTC_DEVICEMACSERVICE_H
 
#include "IDeviceMac.h"
 
#define SERVER_NAME "DeviceMacService"
 
namespace android {
 
class DeviceMacService : public BnDeviceMac {
public:
    DeviceMacService();
    virtual ~DeviceMacService();
    //IDeviceMac
    virtual int setBTMac(String8 bt);
    virtual String8 getBTMac();
};
 
} // end namespace android
#endif

