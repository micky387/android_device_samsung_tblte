#!/system/bin/sh

MIXER_PATHS=/tmp/install/bin/mixer_paths_eur.xml

if [ "$VARIANT" = "xx" ] ; then
    cp -f "$MIXER_PATHS" "/system/etc/mixer_paths.xml"
fi

