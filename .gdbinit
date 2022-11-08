set startup-with-shell off
set auto-load safe-path /
# set disassemble-next-line on
# show disassemble-next-line
define hook-quit
    set confirm off
end
tui enable
layout src
layout regs
focus regs
b main