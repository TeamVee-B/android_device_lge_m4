/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties() {
    char device[PROP_VALUE_MAX];
    char bbversion[92];
    FILE *fp;

    fp = popen("/system/xbin/strings /dev/block/mmcblk0p12 | /system/bin/grep -e '-V10.-' -e '-V20.-' | /system/bin/grep -o -e 'E610' -e 'E612' -e 'E617' | /system/xbin/head -1", "r");
    fgets(bbversion, sizeof(bbversion), fp);
    pclose(fp);

    if (strstr(bbversion, "E610")) {
        property_set("ro.product.device", "E610");
        property_set("ro.product.model", "E610 (L5 Single NFC)");
        property_set("ro.build.description", "m4-userdebug 4.4.4 KTU84Q test-keys");
        property_set("ro.build.fingerprint", "LGE/m4/m4:4.4.4/KTU84Q:userdebug/test-keys");
    } else if (strstr(bbversion, "E612")) {
        property_set("ro.product.device", "E612");
        property_set("ro.product.model", "E612 (L5 Single)");
        property_set("ro.build.description", "m4-userdebug 4.4.4 KTU84Q test-keys");
        property_set("ro.build.fingerprint", "LGE/m4/m4:4.4.4/KTU84Q:userdebug/test-keys");
    } else if (strstr(bbversion, "E617")) {
        property_set("ro.product.device", "E617");
        property_set("ro.product.model", "E617 (L5 Single)");
        property_set("ro.build.description", "m4-userdebug 4.4.4 KTU84Q test-keys");
        property_set("ro.build.fingerprint", "LGE/m4/m4:4.4.4/KTU84Q:userdebug/test-keys");
    };

    property_get("ro.product.device", device);
    ERROR("Found %s baseband setting build properties for %s device\n", bbversion, device);
}
