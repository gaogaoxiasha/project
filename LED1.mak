CC = iccavr
LIB = ilibw
CFLAGS =  -IC:\Users\HaiPiao\Desktop\附小实验\程序\LED1 -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = main.o Delay.o DS18B20.o HD7279.o FC04.o MH_B.o 

LED1:	$(FILES)
	$(CC) -o LED1 $(LFLAGS) @LED1.lk   -lcatmega
main.o: .\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\AVRDefs.h .\AVRTypes.h .\HD7279.h .\DS18B20.h .\Delay.h .\FC04.h .\MH_B.h
main.o:	main.c
	$(CC) -c $(CFLAGS) main.c
Delay.o: .\Delay.h .\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\AVRDefs.h .\AVRTypes.h .\HD7279.h .\DS18B20.h .\FC04.h .\MH_B.h
Delay.o:	Delay.c
	$(CC) -c $(CFLAGS) Delay.c
DS18B20.o: .\DS18B20.h .\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\AVRDefs.h .\AVRTypes.h .\HD7279.h .\Delay.h .\FC04.h .\MH_B.h
DS18B20.o:	DS18B20.c
	$(CC) -c $(CFLAGS) DS18B20.c
HD7279.o: .\HD7279.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h
HD7279.o:	HD7279.C
	$(CC) -c $(CFLAGS) HD7279.C
FC04.o: .\FC04.h .\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\AVRDefs.h .\AVRTypes.h .\HD7279.h .\DS18B20.h .\Delay.h .\MH_B.h
FC04.o:	FC04.c
	$(CC) -c $(CFLAGS) FC04.c
MH_B.o: .\MH_B.h .\Includes.h D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\AVRDefs.h .\AVRTypes.h .\HD7279.h .\DS18B20.h .\Delay.h .\FC04.h
MH_B.o:	MH_B.c
	$(CC) -c $(CFLAGS) MH_B.c
