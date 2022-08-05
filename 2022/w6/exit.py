#Exit from function

import sys

if len(sys.argv) != 2:
    print("misseling commond-line arguments")
    sys.exit(1)
else:
    print("hello, world")
    sys.exit(0)