cmd_fs/udf/modules.order := {  :; } | awk '!x[$$0]++' - > fs/udf/modules.order
