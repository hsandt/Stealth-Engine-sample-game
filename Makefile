.ONESHELL:

# try to rebuild 'stealth' recipe whatever, and let Xcode find if it is up-to-date
.PHONY: stealth

stealth:
	xcodebuild

debug:
	xcodebuild -configuration Debug

run: stealth
	build/Debug/Stealth &
	echo $$! > "pid.tmp"  # $$! -> $! on execution

stop:
	kill -KILL `cat pid.tmp`
	rm pid.tmp