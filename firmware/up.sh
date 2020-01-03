
#cppcheck  --force --std=c99 --language=c src/
make clean
rm -rf bin obj
make all
#fuser -k /dev/ttyACM0
#avrdude -c arduino -P /dev/ttyUSB0 -p m328p -D -U flash:w:bin/firmware.elf
avrdude -c arduino -P /dev/ttyACM0 -p m328p -D -U flash:w:bin/firmware.elf
# testando com arduino nano
avrdude -c arduino -P /dev/ttyUSB0 -b 57600 -p m328p -D -U flash:w:bin/firmware.elf
figlet "MVC19"
