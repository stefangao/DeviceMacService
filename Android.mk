LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
 
LOCAL_MODULE := macserver
LOCAL_MODULE_TAGS := optional
 
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include \
        frameworks/native/include \
        system/core/include
 
LOCAL_SRC_FILES := IDeviceMac.cpp DeviceMacService.cpp main_server.cpp
LOCAL_SHARED_LIBRARIES := libutils libcutils libbinder libhardware liblog
 
include $(BUILD_EXECUTABLE)
