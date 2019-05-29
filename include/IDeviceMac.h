#ifndef XTC_IDEVICEMAC_H
#define XTC_IDEVICEMAC_H
 
#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <utils/String8.h>
#include <android/log.h>

#ifdef TAG
#undef TAG
#endif
#define TAG "DeviceMac"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)

namespace android {

class IDeviceMac : public IInterface {
public:
    enum {
        SET_BT_MAC = IBinder::FIRST_CALL_TRANSACTION,
        GET_BT_MAC,
    };
 
    virtual int setBTMac(String8 bt) = 0; 
    virtual String8 getBTMac() = 0;

    DECLARE_META_INTERFACE(DeviceMac);
};

class BpDeviceMac : public BpInterface<IDeviceMac>
{
public:
    BpDeviceMac(const sp<IBinder>& impl) : BpInterface<IDeviceMac>(impl)
    {
    }
 
    int setBTMac(String8 bt);
    String8 getBTMac();
};

class BnDeviceMac : public BnInterface<IDeviceMac> 
{
public:
    virtual status_t onTransact( uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags);
};

} // end namespace android

#endif