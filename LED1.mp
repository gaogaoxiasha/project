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
                             lit   008C   001C =     28. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __lit_start
       00A8  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   00A8   039A =    922. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00A8  __idata_start
       0442  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0442   1804 =   6148. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0221  __start
       0221  __text_start
       0243  _exit
       0244  _LEDOnBoardInit
       024B  _SET_LED_D10
       0257  _SET_LED_D11
       0264  _port_init
       026E  _timer2_init
       0276  _timer2_comp_isr
       0393  _init_devices
       03A0  _main
       0598  _FC04Init
       059A  _Read_FC04
       059E  _MH_B_Init
       05A0  _Read_MH_B
       05A4  _init_7279
       05BC  _write7279
       05C7  _read7279
       05CA  _get_key7279
       05DB  _long_delay
       05E1  _short_delay
       05E7  _delay10ms
       05FD  _send_byte
       0616  _receive_byte
       062D  _num_change7279
       066B  _test_7279
       0854  _dis_data
       0899  _dis_data_RP
       08EF  _get_data
       0944  _DS18B20Init
       0955  _write_1820
       0977  _read_1820
       098E  _gettemp
       09AD  _Delay_us
       09C7  _Delay_us1
       09DD  _Delay_ms
       09F4  _Delay_ms1
       0A0A  _HC_SR04_Init
       0A0E  _timer1_init
       0A21  _timer1_ovf_isr
       0A31  _GetDistance
       0A99  _MQ2_Init
       0AA4  _Read_MQ2_DO
       0AA8  _Read_MQ2_AO
       0AC1  push_arg4
       0AC3  push_arg2
       0AC6  asr16
       0ACD  mod16s
       0AD1  div16s
       0AEB  mod16u
       0AED  div16u
       0AEE  xdiv16u
       0B07  div32u
       0B09  mod32u
       0B0D  div32s
       0B0F  mod32s
       0B3B  long_div_prolog
       0B4E  long_div_epilog
       0B5E  tst_R16_R19
       0B63  tst_R24_R27
       0B68  neg_R24_R27
       0B71  empy16s
       0B81  empy32u
       0B81  empy32s
       0BB5  pop_xgset003C
       0BBA  pop_xgsetF0FC
       0BC5  push_xgsetF0FC
       0BC7  push_xgset30FC
       0BC9  push_xgset00FC
       0BCB  push_xgset003C
       0BD0  push_xgset300C
       0BD5  pop_xgset300C
       0BDA  push_xgsetF000
       0BDF  pop_xgsetF000
       0BE4  push_xgsetF00C
       0BEB  pop_xgsetF00C
       0BF2  neg32
       0BFB  long_prolog
       0C09  long_epilog
       0C14  tstzero1
       0C1A  tstzero2
       0C20  lpm32
       0C34  lsl16
       0C3B  fpint
       0C6D  uint2fp
       0C6F  int2fp
       0C78  ulong2fp
       0C7A  long2fp
       0C91  fpdiv1
       0C9A  fpdiv2
       0CA4  fpdiv1x
       0CB0  fpdiv2x
       0D2B  unpacks
       0D33  tstR16_R19
       0D3B  unpacku
       0D54  normalize_and_pack
       0D89  pack
       0D99  saveFPRegs
       0DA8  restoreFPRegs
       0DB7  fpmule
       0E0A  fpmule2
       0E15  fpmule2x
       0E23  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   039A =    922. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  _note_n
       0060  __data_start
       0062  _int_n
       0064  _distance_mm
       0066  _play_on
       0067  _LED_N
       0069  _song
       006B  _song_note
       006D  _t
       00A5  _d
       00DD  _music
       0141  _music_1
       01BF  _music_2
       0311  _music_3
       0389  _music_4
       03F9  _TimerOut_Flag
       03FA  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   03FA   0002 =      2. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       03FA  __bss_start
       03FA  _song_music
       03FC  __bss_end

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
MQ_2.o	[ MQ_2.c ]
<library>	[ asave.s, asr16.s, div16s.s, div16u.s, div32.s, emul16s.s, emul32.s, gpop2.s, gpop5.s, gpush.s, gpushx.s ]
[ gpushy.s, gpushz.s, lneg.s, longutil.s, lpm32.s, lsl16.s, fpint.s, int2fp.s, fpdiv_new.s, fputil.s ]
[ fpmule.s, fpmule2.s, fpmule2x.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

