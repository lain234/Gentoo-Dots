xrandr --output DP-0 --mode 1920x1080 --output DP-3 --mode 1920x1080 --left-of DP-0 --output HDMI-0 --mode 3840x2160 --right-of DP-0

# AUTOSTART

setxkbmap de &

# WINDOW MANAGER

# exec dbus-launch --sh-syntax --exit-with-session bspwm

exec dbus-launch --sh-syntax --exit-with-session /home/lain/scripts/startdwm
