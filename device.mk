#
# Copyright (C) 2017-2018 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Get non-open-source specific aspects
$(call inherit-product-if-exists, vendor/samsung/tblte/tblte-vendor.mk)

# Overlays
DEVICE_PACKAGE_OVERLAYS += device/samsung/tblte/overlay

# Variant blobs script
PRODUCT_COPY_FILES += \
    device/samsung/tblte/releasetools/variant_blobs_hook.sh:install/bin/variant_blobs_hook.sh \
    device/samsung/tblte-common/releasetools/variant_blobs.sh:install/bin/variant_blobs.sh

# common tblte
$(call inherit-product, device/samsung/tblte-common/tblte.mk)
