import gdb

class RegState(gdb.Command):
    """Prints values of general-purpose registers"""

    def __init__(self):
        super(RegState, self).__init__("regstate", gdb.COMMAND_USER)
    
    def invoke(self, args, from_tty):
        print("args: ")