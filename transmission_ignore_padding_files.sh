#!/bin/bash

# Excludes the padding file created by BitComet from all torrents
# For: Transmission
# By: MCUmbrella

if ! command -v transmission-remote &> /dev/null
then
    echo "[ERROR] Command not found: transmission-remote"
    exit -1
fi

REMOTE="127.0.0.1:8888"
AUTH="admin:111111"
CMD="transmission-remote $REMOTE --auth $AUTH"

torrentIds=$($CMD --list | awk '!/ID|Sum/ {print $1}')
for i in $torrentIds
do
    echo "[INFO] Checking torrent #$i"
    paddingFileIds=$($CMD --torrent $i --info-files | grep Yes.*padding_file | awk '{print $1}' | sed 's/.$//')
    if [ "$paddingFileIds" ]
    then
        echo "[WARNING] Padding file found in torrent #$i"
        for j in $paddingFileIds
        do
            echo "[INFO] Excluding file #$j in torrent #$i"
            $CMD --torrent $i --no-get $j
        done
    fi
done
echo "[INFO] OK"
