cmd_sound/pci/ac97/built-in.a := rm -f sound/pci/ac97/built-in.a;  printf "sound/pci/ac97/%s " ac97_codec.o ac97_pcm.o ac97_proc.o | xargs ar cDPrST sound/pci/ac97/built-in.a
