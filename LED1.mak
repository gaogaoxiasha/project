CC = iccavr
LIB = ilibw
CFLAGS =  -IC:\Users\HaiPiao\Desktop\附小实验\程序\LED1 -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = main.o FC04.o MH_B.o HD7279.o DS18B20.o Delay.o HC_SR04.o MQ_2.o 

LED1:	$(FILES)
	$(CC) -o LED1 $(LFLAGS) @LED1.lk   -lcatmega
main.o: .\Headers\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\Headers\AVRDefs.h .\Headers\AVRTypes.h .\HD7279\HD7279.h .\DS18B20\DS18B20.h .\Delay\Delay.h .\FC04\FC04.h .\MH_B\MH_B.h .\HC_SR04\HC_SR04.h .\MQ_2\MQ_2.h
main.o:	main\main.c
	$(CC) -c $(CFLAGS) main\main.c
FC04.o: .\FC04\FC04.h .\Headers\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\Headers\AVRDefs.h .\Headers\AVRTypes.h .\HD7279\HD7279.h .\DS18B20\DS18B20.h .\Delay\Delay.h .\MH_B\MH_B.h .\HC_SR04\HC_SR04.h .\MQ_2\MQ_2.h
FC04.o:	FC04\FC04.c
	$(CC) -c $(CFLAGS) FC04\FC04.c
MH_B.o: .\MH_B\MH_B.h .\Headers\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\Headers\AVRDefs.h .\Headers\AVRTypes.h .\HD7279\HD7279.h .\DS18B20\DS18B20.h .\Delay\Delay.h .\FC04\FC04.h .\HC_SR04\HC_SR04.h .\MQ_2\MQ_2.h
MH_B.o:	MH_B\MH_B.c
	$(CC) -c $(CFLAGS) MH_B\MH_B.c
HD7279.o: .\HD7279\HD7279.h .\Headers\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\Headers\AVRDefs.h .\Headers\AVRTypes.h .\DS18B20\DS18B20.h .\Delay\Delay.h .\FC04\FC04.h .\MH_B\MH_B.h .\HC_SR04\HC_SR04.h .\MQ_2\MQ_2.h
HD7279.o:	HD7279\HD7279.C
	$(CC) -c $(CFLAGS) HD7279\HD7279.C
DS18B20.o: .\DS18B20\DS18B20.h .\Headers\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\Headers\AVRDefs.h .\Headers\AVRTypes.h .\HD7279\HD7279.h .\Delay\Delay.h .\FC04\FC04.h .\MH_B\MH_B.h .\HC_SR04\HC_SR04.h .\MQ_2\MQ_2.h
DS18B20.o:	DS18B20\DS18B20.c
	$(CC) -c $(CFLAGS) DS18B20\DS18B20.c
Delay.o: .\Delay\Delay.h .\Headers\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\Headers\AVRDefs.h .\Headers\AVRTypes.h .\HD7279\HD7279.h .\DS18B20\DS18B20.h .\FC04\FC04.h .\MH_B\MH_B.h .\HC_SR04\HC_SR04.h .\MQ_2\MQ_2.h
Delay.o:	Delay\Delay.c
	$(CC) -c $(CFLAGS) Delay\Delay.c
HC_SR04.o: .\HC_SR04\HC_SR04.h .\Headers\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\Headers\AVRDefs.h .\Headers\AVRTypes.h .\HD7279\HD7279.h .\DS18B20\DS18B20.h .\Delay\Delay.h .\FC04\FC04.h .\MH_B\MH_B.h .\MQ_2\MQ_2.h
HC_SR04.o:	HC_SR04\HC_SR04.c
	$(CC) -c $(CFLAGS) HC_SR04\HC_SR04.c
MQ_2.o: .\MQ_2\MQ_2.h .\Headers\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\Headers\AVRDefs.h .\Headers\AVRTypes.h .\HD7279\HD7279.h .\DS18B20\DS18B20.h .\Delay\Delay.h .\FC04\FC04.h .\MH_B\MH_B.h .\HC_SR04\HC_SR04.h
MQ_2.o:	MQ_2\MQ_2.c
	$(CC) -c $(CFLAGS) MQ_2\MQ_2.c
