cmd_drivers/pci/modules.order := {   cat drivers/pci/msi/modules.order;   cat drivers/pci/pcie/modules.order;   cat drivers/pci/hotplug/modules.order;   cat drivers/pci/controller/modules.order;   cat drivers/pci/switch/modules.order; :; } | awk '!x[$$0]++' - > drivers/pci/modules.order