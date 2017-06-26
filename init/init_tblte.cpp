/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2018, The LineageOS Project. All rights reserved.

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
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_apq8084.h"

void gsm_properties()
{
    property_override("telephony.lteOnGsmDevice", "1");
    property_override("ro.telephony.default_network", "9");
}

void cdma_properties(char const *operator_alpha,
                     char const *operator_numeric,
                     char const *cdma_sub)
{
    /* Dynamic CDMA Properties */
    property_set("ro.cdma.home.operator.alpha", operator_alpha);
    property_set("ro.cdma.home.operator.numeric", operator_numeric);
    property_set("ro.telephony.default_cdma_sub", cdma_sub);

    /* Static CDMA Properties */
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.telephony.default_network", "10");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void init_target_properties()
{
    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = property_get("ro.bootloader");

    if (bootloader.find("N915F") == 0) {
        /* tbltexx */
        property_override("ro.build.fingerprint", "samsung/tblte/tblte:6.0.1/MMB29M/N915FYXXS1DPG1:user/release-keys");
        property_override("ro.build.description", "tbltexx-user 6.0.1 MMB29M N915FYXXS1DPG1 release-keys");
        property_override("ro.product.model", "SM-N915F");
        property_override("ro.product.device", "tblte");
        gsm_properties();
    } else if (bootloader.find("N915FY") == 0) {
        /* tbltedt */
        property_override("ro.build.fingerprint", "samsung/tbltebtu/tblte:6.0.1/MMB29M/N915FYXXS1DPG1:user/release-keys");
        property_override("ro.build.description", "tbltebtu-user 6.0.1 MMB29M N915FYXXS1DPG1 release-keys");
        property_override("ro.product.model", "SM-N915FY");
        property_override("ro.product.device", "tbltexx");
        gsm_properties();
    } else if (bootloader.find("N915G") == 0) {
        /* tbltedt */
        property_override("ro.build.fingerprint", "samsung/tbltedt/tblte:6.0.1/MMB29M/N915GDTS1DQE1:user/release-keys");
        property_override("ro.build.description", "tbltedt-user 6.0.1 MMB29M N915GDTS1DQE1 release-keys");
        property_override("ro.product.model", "SM-N915G");
        property_override("ro.product.device", "tbltedt");
        gsm_properties();
    } else if (bootloader.find("N915R4") == 0) {
        /* tblteusc */
        property_override("ro.build.fingerprint", "samsung/tblteusc/tblte:6.0.1/MMB29M/N915R4TYS1CQC1:user/release-keys");
        property_override("ro.build.description", "tblteusc-user 6.0.1 MMB29M N915R4TYS1CQC1 release-keys");
        property_override("ro.product.model", "SM-N915R4");
        property_override("ro.product.device", "tblteusc");
        cdma_properties("U.S. Cellular", "311580", "0");
    } else if (bootloader.find("N915P") == 0) {
        /* tbltespr */
        property_override("ro.build.fingerprint", "samsung/tbltespr/tblte:6.0.1/MMB29M/N915PVPS4DQC1:user/release-keys");
        property_override("ro.build.description", "tbltespr-user 6.0.1 MMB29M N915PVPS4DQC1 release-keys");
        property_override("ro.product.model", "SM-N915P");
        property_override("ro.product.device", "tbltespr");
        cdma_properties("Sprint", "310120", "1");
    } else if (bootloader.find("N915T") == 0) {
        /* tbltetmo */
        property_override("ro.build.fingerprint", "samsung/tbltetmo/tblte:6.0.1/MMB29M/N915TUVS2EQE2:user/release-keys");
        property_override("ro.build.description", "tbltetmo-user 6.0.1 MMB29M N915TUVS2EQE2 release-keys");
        property_override("ro.product.model", "SM-N915T");
        property_override("ro.product.device", "tbltetmo");
        gsm_properties();
    } else if (bootloader.find("N915V") == 0) {
        /* tbltevzw */
        property_override("ro.build.fingerprint", "samsung/tbltevzw/tblte:6.0.1/MMB29M/N915VVRS2CQE1:user/release-keys");
        property_override("ro.build.description", "tbltevzw-user 6.0.1 MMB29M N915VVRS2CQE1 release-keys");
        property_override("ro.product.model", "SM-N915V");
        property_override("ro.product.device", "tbltevzw");
        cdma_properties("Verizon", "311480", "0");
    } else if (bootloader.find("N915W8") == 0) {
        /* tbltecan */
        property_override("ro.build.fingerprint", "samsung/tbltecan/tblte:6.0.1/MMB29M/N915W8VLS1DQD1:user/release-keys");
        property_override("ro.build.description", "tbltecan-user 6.0.1 MMB29M N915W8VLS1DQD1 release-keys");
        property_override("ro.product.model", "SM-N915W8");
        property_override("ro.product.device", "tbltecan");
        gsm_properties();
    } else {
        ERROR("Setting product info FAILED\n");
    }

    std::string device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}
