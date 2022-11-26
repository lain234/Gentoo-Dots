cmd_kernel/power/built-in.a := rm -f kernel/power/built-in.a;  printf "kernel/power/%s " qos.o process.o poweroff.o | xargs ar cDPrST kernel/power/built-in.a
