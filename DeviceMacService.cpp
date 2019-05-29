#include "DeviceMacService.h"

namespace android {

DeviceMacService::DeviceMacService() {

}

DeviceMacService::~DeviceMacService() {

}

int DeviceMacService::setBTMac(String8 bt) {
    LOGI("Bn setBT, bt:%s", bt.string());
    return NO_ERROR;
}

String8 DeviceMacService::getBTMac() {
    LOGI("Bn getBT");
    return String8("4a:4b:4c:3a:3b:3c");
}

} // end namespace android
