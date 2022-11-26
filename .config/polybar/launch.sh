#!/bin/bash

# Terminate already running bar instances
killall -q polybar
# If all your bars have ipc enabled, you can also use 
# polybar-msg cmd quit

# Launch Polybar, using default config location ~/.config/polybar/config
polybar tags1 &
polybar alsa1 &
polybar date1 &
polybar powermenu1 &

if [[ $(xrandr -q | grep 'DP-3 connected') ]]; then
    polybar tags2 &
    polybar alsa2 &
    polybar date2 &
    polybar powermenu2 &
fi

if [[ $(xrandr -q | grep 'HDMI-0 connected') ]]; then
    polybar tags3 &
    polybar alsa3 &
    polybar date3 &
    polybar powermenu3 &
fi

echo "Polybar launched..."

