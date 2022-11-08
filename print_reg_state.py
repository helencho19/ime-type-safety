import gdb
import argparse

# class RegState(gdb.Command):
#     """Prints values of general-purpose registers"""

#     def __init__(self):
#         super(RegState, self).__init__("regstate", gdb.COMMAND_USER)
    
#     def invoke(self, args, from_tty):
#         print("args: ")

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--filename", 
        type=str, 
        default="gdb_trace.log", 
        help="Name of file for storing register state"
    )
    return parser.parse_args()

def main(args):
    f = open(args.filename, "w")
    # Need to source this file in gdb, like "source print_reg_state.py"

    # Start at the main method (or the first breakpoint) set in .gdbinit
    gdb.execute("r", True, False)

    # Run the program step by step until it is done
    #   at each step, print register state using "info registers general"
    #   redirect output to python string and then print that out to a log file?
    # Thread is valid if it has not yet exited or if the inferior has not been deleted
    while not gdb.selected_inferior().threads()[0].is_exited():
        register_state = gdb.execute("info registers general", True, True)
        f.write(register_state + "\n")
        # I don't know how to detect if this is the last instruction to be executed
        # so let's just wrap it in a try-catch
        try:
            gdb.execute("n", True, False)
        except:
            break
    f.close()

if __name__ == "__main__":
    main(parse_args())