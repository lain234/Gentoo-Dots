cmd_sound/core/built-in.a := rm -f sound/core/built-in.a;  printf "sound/core/%s " sound.o init.o memory.o control.o misc.o device.o info.o isadma.o vmaster.o ctljack.o jack.o control_led.o hwdep.o timer.o pcm.o pcm_native.o pcm_lib.o pcm_misc.o pcm_memory.o memalloc.o pcm_timer.o seq_device.o rawmidi.o seq/built-in.a | xargs ar cDPrST sound/core/built-in.a