cmd_drivers/leds/trigger/built-in.a := rm -f drivers/leds/trigger/built-in.a;  printf "drivers/leds/trigger/%s " ledtrig-audio.o | xargs ar cDPrST drivers/leds/trigger/built-in.a
