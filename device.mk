# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# 	http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# This file includes all definitions that apply to all L5 devices.
#
# Everything in this directory will become public

$(call inherit-product, frameworks/native/build/phone-hdpi-512-dalvik-heap.mk)

# Include MSM7x27a Common
$(call inherit-product, device/lge/msm7x27a-common/msm7x27a-common.mk)

# Include NFC
$(call inherit-product, device/lge/msm7x27a-common/nfc.mk)

# inherit from the proprietary version
$(call inherit-product, vendor/lge/m4/m4-vendor.mk)

# Rootdir files
PRODUCT_COPY_FILES += $(call find-copy-subdir-files,*,device/lge/m4/rootdir,root)

# Config Files
PRODUCT_COPY_FILES += $(call find-copy-subdir-files,*,device/lge/m4/configs,system)

PRODUCT_AAPT_CONFIG := normal mdpi hdpi
PRODUCT_AAPT_PREF_CONFIG := mdpi

include device/lge/m4/system_prop.mk
