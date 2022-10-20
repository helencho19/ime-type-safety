import sys, subprocess


def main():
    # Assume the binary already exists; we just take in the name of the binary
    # -o flag for binary name
    i = 1
    binary_name = ""
    while i < len(sys.argv):
        input = sys.argv[i]
        if input == "-o":
            binary_name = sys.argv[i + 1]
            i += 1
        i += 1
    
    subprocess.run(["gdb", binary_name])

if __name__ == "__main__":
    main()
    
