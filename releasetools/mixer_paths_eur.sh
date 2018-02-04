#!/system/bin/sh

MIXER_PATHS=/tmp/install/bin/mixer_paths_tblte_eur.xml

if [ "$VARIANT" = "xx" ] ; then
    cp -f "$MIXER_PATHS" "/system/vendor/etc/mixer_paths.xml"
fi

