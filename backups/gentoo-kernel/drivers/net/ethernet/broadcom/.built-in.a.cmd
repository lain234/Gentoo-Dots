cmd_drivers/net/ethernet/broadcom/built-in.a := rm -f drivers/net/ethernet/broadcom/built-in.a;  printf "drivers/net/ethernet/broadcom/%s " tg3.o | xargs ar cDPrST drivers/net/ethernet/broadcom/built-in.a