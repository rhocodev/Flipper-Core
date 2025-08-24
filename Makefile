all:
	arduino-cli compile -b arduino:avr:nano -p /dev/ttyUSB0 --clean --library ./include --upload 

esp32:
	arduino-cli compile -b esp32:esp32:esp32dev -p /dev/ttyUSB0 --clean --library ./include --upload
