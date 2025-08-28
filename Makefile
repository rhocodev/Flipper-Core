upload:
	arduino-cli compile -b arduino:avr:nano -p /dev/ttyUSB0 --clean --library ./include --upload 

compile:
	arduino-cli compile -b arduino:avr:nano --clean --library ./include

compile_esp32:
	arduino-cli compile -b esp32:esp32:esp32 --clean --library ./include

