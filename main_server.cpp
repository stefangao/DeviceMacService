#include "DeviceMacService.h"
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
 
using namespace android;
 
sp<IDeviceMac> getService() {
    sp<IServiceManager> sm = defaultServiceManager();
    if (sm == NULL) {
        LOGE("can not get service manager");
    }
    sp<IBinder> binder = sm->getService(String16(SERVER_NAME));
    if (binder == NULL) {
        LOGE("can not get service");
    }
    sp<IDeviceMac> service = interface_cast<IDeviceMac>(binder);
    if (service == NULL) {
        LOGE("can not cast interface");
    }
    return service;
}
 
int main(int argc, char** argv __unused) {
    if (argc == 1) {
        LOGI("start DeviceMacService");
        defaultServiceManager()->addService(String16(SERVER_NAME), new DeviceMacService());
        android::ProcessState::self()->startThreadPool();
        IPCThreadState::self()->joinThreadPool();
    } else if (argc == 2) {
        sp<IDeviceMac> devMacServer = getService();
 
        devMacServer->setBTMac(String8("1a:1b:1c:1a:1b:1c"));
        String8 bt = devMacServer->getBTMac();
        LOGI("get bt mac:%s", bt.string());
    }
    return 0;
}
