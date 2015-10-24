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
                             lit   008C   0018 =     24. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __lit_start
       00A4  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   00A4   00DB =    219. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00A4  __idata_start
       017F  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0180   14BE =   5310. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00C0  __text_start
       00C0  __start
       00E2  _exit
       00E3  _LEDOnBoardInit
       00EA  _SET_LED_D10
       00F6  _SET_LED_D11
       0103  _port_init
       010D  _timer2_50Hz
       0117  _timer2_100Hz
       0121  _init_devices
       012D  _main
       02FD  _FC04Init
       02FF  _Read_FC04
       0303  _MH_B_Init
       0305  _Read_MH_B
       0309  _init_7279
       0321  _write7279
       032C  _read7279
       032F  _get_key7279
       0340  _long_delay
       0346  _short_delay
       034C  _delay10ms
       0362  _send_byte
       037B  _receive_byte
       0392  _num_change7279
       03D0  _test_7279
       05B9  _dis_data
       05FE  _dis_data_RP
       0654  _get_data
       06A9  _DS18B20Init
       06BA  _write_1820
       06DC  _read_1820
       06F3  _gettemp
       0712  _Delay_us
       072C  _Delay_us1
       0742  _Delay_ms
       0759  _Delay_ms1
       076F  _HC_SR04_Init
       0773  _timer1_init
       0786  _timer1_ovf_isr
       0796  _GetDistance
       07FE  push_arg4
       0800  push_arg2
       0803  div32u
       0805  mod32u
       0809  div32s
       080B  mod32s
       0837  long_div_prolog
       084A  long_div_epilog
       085A  tst_R16_R19
       085F  tst_R24_R27
       0864  neg_R24_R27
       086D  empy16s
       087D  empy32s
       087D  empy32u
       08B1  pop_xgset003C
       08B6  pop_xgsetF0FC
       08C1  push_xgsetF0FC
       08C3  push_xgset30FC
       08C5  push_xgset00FC
       08C7  push_xgset003C
       08CC  push_xgset300C
       08D1  pop_xgset300C
       08D6  push_xgsetF000
       08DB  pop_xgsetF000
       08E0  push_xgsetF00C
       08E7  pop_xgsetF00C
       08EE  neg32
       08F7  long_prolog
       0905  long_epilog
       0910  tstzero1
       0916  tstzero2
       091C  lpm32
       0930  lsl16
       0937  fpint
       0969  uint2fp
       096B  int2fp
       0974  ulong2fp
       0976  long2fp
       098D  fpdiv1
       0996  fpdiv2
       09A0  fpdiv1x
       09AC  fpdiv2x
       0A27  unpacks
       0A2F  tstR16_R19
       0A37  unpacku
       0A50  normalize_and_pack
       0A85  pack
       0A95  saveFPRegs
       0AA4  restoreFPRegs
       0AB3  fpmule
       0B06  fpmule2
       0B11  fpmule2x
       0B1F  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   00DB =    219. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __data_start
       0060  _note_n
       0062  _int_n
       0064  _distance_mm
       0066  _t
       009E  _d
       00D6  _music
       013A  _TimerOut_Flag
       013B  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0024 =     36. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
FC04.o	[ FC04.c ]
MH_B.o	[ MH_B.c ]
HD7279.o	[ HD7279.C ]
DS18B20.o	[ DS18B20.c ]
Delay.o	[ Delay.c ]
HC_SR04.o	[ HC_SR04.c ]
<library>	[ asave.s, div32.s, emul16s.s, emul32.s, gpop2.s, gpop5.s, gpush.s, gpushx.s, gpushy.s, gpushz.s, lneg.s ]
[ longutil.s, lpm32.s, lsl16.s, fpint.s, int2fp.s, fpdiv_new.s, fputil.s, fpmule.s, fpmule2.s, fpmule2x.s ]


User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

