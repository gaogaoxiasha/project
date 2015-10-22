NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0054   0038 =     56. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __func_lit_start
       008C  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   008C   0008 =      8. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __lit_start
       0094  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0094   00D8 =    216. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0094  __idata_start
       016C  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   016C   1330 =   4912. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00B6  __text_start
       00B6  __start
       00D8  _exit
       00D9  _LEDOnBoardInit
       00E0  _SET_LED_D10
       00EC  _SET_LED_D11
       00F9  _port_init
       0103  _timer2_50Hz
       010D  _timer2_100Hz
       0117  _init_devices
       0123  _main
       02C9  _Delay_us
       02E3  _Delay_us1
       02F9  _Delay_ms
       0310  _Delay_ms1
       0326  _DS18B20Init
       0337  _write_1820
       0359  _read_1820
       0370  _gettemp
       038F  _init_7279
       03A7  _write7279
       03B2  _read7279
       03B5  _get_key7279
       03C6  _long_delay
       03CC  _short_delay
       03D2  _delay10ms
       03E8  _send_byte
       0401  _receive_byte
       0418  _num_change7279
       0456  _test_7279
       063F  _dis_data
       0684  _dis_data_RP
       06DA  _get_data
       072F  _FC04Init
       0731  _Read_FC04
       0735  _MH_B_Init
       0737  _Read_MH_B
       073B  push_arg4
       073D  push_arg2
       0740  div32u
       0742  mod32u
       0746  div32s
       0748  mod32s
       0774  long_div_prolog
       0787  long_div_epilog
       0797  tst_R16_R19
       079C  tst_R24_R27
       07A1  neg_R24_R27
       07AA  empy16s
       07BA  empy32u
       07BA  empy32s
       07EE  pop_xgset003C
       07F3  pop_xgsetF0FC
       07FE  push_xgsetF0FC
       0800  push_xgset30FC
       0802  push_xgset00FC
       0804  push_xgset003C
       0809  push_xgset300C
       080E  pop_xgset300C
       0813  push_xgsetF000
       0818  pop_xgsetF000
       081D  push_xgsetF00C
       0824  pop_xgsetF00C
       082B  neg32
       0834  long_prolog
       0842  long_epilog
       084D  tstzero1
       0853  tstzero2
       0859  lpm32
       086D  lsl16
       0874  fpint
       08A6  uint2fp
       08A8  int2fp
       08B1  ulong2fp
       08B3  long2fp
       08CA  fpdiv1
       08D3  fpdiv2
       08DD  fpdiv1x
       08E9  fpdiv2x
       0964  unpacks
       096C  tstR16_R19
       0974  unpacku
       098D  normalize_and_pack
       09C2  pack
       09D2  saveFPRegs
       09E1  restoreFPRegs
       09F0  fpmule
       0A43  fpmule2
       0A4E  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   00D8 =    216. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _note_n
       0060  __data_start
       0062  _int_n
       0064  _t
       009C  _d
       00D4  _music
       0138  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
Delay.o	[ Delay.c ]
DS18B20.o	[ DS18B20.c ]
HD7279.o	[ HD7279.C ]
FC04.o	[ FC04.c ]
MH_B.o	[ MH_B.c ]
<library>	[ asave.s, div32.s, emul16s.s, emul32.s, gpop2.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s, lneg.s ]
[ longutil.s, lpm32.s, lsl16.s, fpint.s, int2fp.s, fpdiv_new.s, fputil.s, fpmule.s, fpmule2.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

