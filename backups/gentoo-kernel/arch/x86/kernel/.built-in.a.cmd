cmd_arch/x86/kernel/built-in.a := rm -f arch/x86/kernel/built-in.a;  printf "arch/x86/kernel/%s " process_64.o signal.o signal_compat.o traps.o idt.o irq.o irq_64.o dumpstack_64.o time.o ioport.o dumpstack.o nmi.o ldt.o setup.o x86_init.o i8259.o irqinit.o jump_label.o irq_work.o probe_roms.o sys_ia32.o sys_x86_64.o espfix_64.o ksysfs.o bootflag.o e820.o pci-dma.o quirks.o topology.o kdebugfs.o alternative.o i8253.o hw_breakpoint.o tsc.o tsc_msr.o io_delay.o rtc.o resource.o irqflags.o static_call.o process.o fpu/built-in.a ptrace.o tls.o step.o i8237.o stacktrace.o cpu/built-in.a acpi/built-in.a reboot.o msr.o cpuid.o early-quirks.o smp.o smpboot.o tsc_sync.o setup_percpu.o apic/built-in.a trace_clock.o trace.o rethook.o crash_core_64.o machine_kexec_64.o relocate_kernel_64.o crash.o crash_dump_64.o kprobes/built-in.a module.o early_printk.o hpet.o amd_nb.o pcspeaker.o uprobes.o perf_regs.o tracepoint.o umip.o unwind_orc.o mmconf-fam10h_64.o vsmp_64.o | xargs ar cDPrST arch/x86/kernel/built-in.a