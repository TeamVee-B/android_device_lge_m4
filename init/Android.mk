LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_C_INCLUDES := system/core/init
LOCAL_SRC_FILES := init_m4.c
LOCAL_MODULE := libinit_m4
include $(BUILD_STATIC_LIBRARY)
