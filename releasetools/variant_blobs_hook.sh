#
# Copyright (C) 2017 The LineageOS Project
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

case $BOOTLOADER in
  N915F*)  VARIANT="xx"  ;;
  N915G*)  VARIANT="xx"  ;;
  N915R4*) VARIANT="spr" ;;
  N915P*)  VARIANT="spr" ;;
  N915T*)  VARIANT="tmo" ;;
  N915V*)  VARIANT="vzw" ;;
  N915W8*) VARIANT="tmo" ;;
esac
