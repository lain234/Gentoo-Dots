cmd_net/ipv4/netfilter/built-in.a := rm -f net/ipv4/netfilter/built-in.a;  printf "net/ipv4/netfilter/%s " nf_defrag_ipv4.o nf_reject_ipv4.o ip_tables.o iptable_filter.o iptable_mangle.o ipt_REJECT.o | xargs ar cDPrST net/ipv4/netfilter/built-in.a