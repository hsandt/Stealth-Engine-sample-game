import os, signal
from subprocess import Popen

# read PID
with open('pid.tmp', 'r') as f:
    pid = f.readline().rstrip()

# kill process
os.kill(int(pid), signal.SIGKILL)

# remove temp file
os.remove('pid.tmp')
