cmd_drivers/ptp/built-in.a := rm -f drivers/ptp/built-in.a;  printf "drivers/ptp/%s " ptp_clock.o ptp_chardev.o ptp_sysfs.o ptp_vclock.o | xargs ar cDPrST drivers/ptp/built-in.a
