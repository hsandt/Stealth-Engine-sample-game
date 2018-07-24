from subprocess import Popen

# run process as child (still receive process output)
pid = Popen(['build/Debug/TestEngine']).pid

# store pid
with open('pid.tmp', 'w') as f:
    f.write(str(pid))
