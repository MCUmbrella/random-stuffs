#! /bin/bash

# This script is used to apply the newest tracker list to all torrents
# By: MCUmbrella

if ! command -v transmission-edit &> /dev/null
then
    echo "[ERROR] Do you have transmission-daemon installed?"
    exit -1
else
    echo "[OK] Transmission daemon check successful"
    echo "STEP1: create temp files"
    echo > tmp_tracker.txt && echo > tmp_tracker.txt.new && echo "[OK] STEP1 completed"

    echo "STEP2: get tracker list file from trackerlist.com"
    wget "https://trackerslist.com/all.txt" -O tmp_tracker.txt &> /dev/null && echo "[OK] STEP2 completed"

    echo "STEP3: process original list file for further use"
    tr -s '\n' '\n' < tmp_tracker.txt > tmp_tracker.txt.new
    echo >> tmp_tracker.txt.new && echo "[OK] STEP3 completed"

    echo "STEP4: add tracker(s) to all torrents"
    a=0
    for t in $(grep --invert-match "\\[" tmp_tracker.txt.new)
    do
        transmission-edit --add $t /var/lib/transmission/.config/transmission-daemon/torrents/*.torrent > /dev/null
            echo "Added tracker $t to all torrents"
            a=$(expr $a + 1)
    done && chown transmission:transmission /var/lib/transmission/.config/transmission-daemon/torrents/*.torrent && echo "[OK] STEP4 completed"

    echo "STEP5: delete temp files"
    rm -f tmp_tracker.txt* && echo "[OK] STEP5 completed"
    echo "[OK] $a tracker(s) added"
    systemctl restart transmission-daemon.service && echo "[OK] restarted Transmission daemon"
fi
