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

# Include MSM7x27a Common
include device/lge/msm7x27a-common/BoardConfigCommon.mk

LGE_PROJECT := l

# inherit from the proprietary version
-include vendor/lge/m4/BoardConfigVendor.mk

# Kernel
TARGET_KERNEL_CONFIG := cyanogenmod_m4_defconfig
BOARD_KERNEL_CMDLINE := androidboot.hardware=m4 androidboot.selinux=permissive

# BT
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/lge/m4/bluetooth

# Recovery
DEVICE_RESOLUTION := 320x480
BOARD_CUSTOM_GRAPHICS := ../../../device/lge/m4/recovery/graphics.c

# FSTAB
TARGET_RECOVERY_FSTAB := device/lge/m4/rootdir/fstab.m4
#TARGET_RECOVERY_FSTAB := device/lge/m4/recovery/recovery.fstab

