import os, signal, sys
from subprocess import check_call, CalledProcessError, Popen


def build():
    # build with Xcode
    check_call(["xcodebuild", "-configuration", "Debug"])


def run():
    # run process as child and get pit (still receive process output)
    pid = Popen(['build/Debug/TestEngine']).pid

    # store pid
    with open('pid.tmp', 'w') as f:
        f.write(str(pid))


def stop():
    # read PID
    with open('pid.tmp', 'r') as f:
        pid = f.readline().rstrip()

    # kill process
    try:
        os.kill(int(pid), signal.SIGKILL)
    except OSError as e:
        if e.errno == 3:
            print("No process found with PID {}, removing temp file anyway.".format(pid))
        else:
            raise e
    finally:
        # remove temp file
        os.remove('pid.tmp')


if __name__ == '__main__':
    if len(sys.argv) == 1:
        # python build.py
        try:
            build()
        except CalledProcessError, e:
            print("Build failed, do not run.")
        else:
            run()
    elif sys.argv[1] == 'run':
        # python build.py run
        run()
    elif sys.argv[1] == 'stop':
        # python build.py stop
        stop()
    else:
        print "unknown argument: " + sys.argv[1]
