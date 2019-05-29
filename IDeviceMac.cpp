#include "IDeviceMac.h"

namespace android {
//-------------BpDeviceMac--------
int BpDeviceMac::setBTMac(String8 bt) 
{
    LOGI("Bp setBT");
    Parcel data, reply;
    data.writeInterfaceToken(IDeviceMac::getInterfaceDescriptor());
    data.writeString8(bt);
    remote()->transact(SET_BT_MAC, data, &reply);
    return reply.readInt32();
}

String8 BpDeviceMac::getBTMac()
{
    LOGI("Bp getBT");
    Parcel data, reply;
    data.writeInterfaceToken(IDeviceMac::getInterfaceDescriptor());
    remote()->transact(GET_BT_MAC, data, &reply);
    return reply.readString8();
}

IMPLEMENT_META_INTERFACE(DeviceMac, "DeviceMac");
/* Macro above expands to code below.
const android::String16 IDeviceMac::descriptor("DeviceMac");
const android::String16& IDeviceMac::getInterfaceDescriptor() const {
    return IDeviceMac::descriptor;
}
android::sp<IDeviceMac> IDeviceMac::asInterface(const android::sp<android::IBinder>& obj) {
    android::sp<IDeviceMac> intr;
    if (obj != NULL) {
        intr = static_cast<IDeviceMac*>(obj->queryLocalInterface(IDeviceMac::descriptor).get());
        if (intr == NULL) {
            intr = new BpDeviceMac(obj);
        }
    }
    return intr;
}
*/

//-------------BnDeviceMac--------
status_t BnDeviceMac::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    CHECK_INTERFACE(IDeviceMac, data, reply);
    LOGI("Bn onTransact code:%d", code);
    switch(code) {
        case SET_BT_MAC:
            reply->writeInt32(setBTMac(data.readString8()));
            return NO_ERROR;
        case GET_BT_MAC:
            reply->writeString8(getBTMac());
            return NO_ERROR;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

} //end namespace android