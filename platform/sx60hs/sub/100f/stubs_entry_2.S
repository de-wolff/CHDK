#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB 0xfc0008fb // bx lr
#DEF(orig_CreateTask                           ,0x010E5089)
NHSTUB(LogCameraEvent                        ,0xfc3362b7)
NHSTUB(displaybusyonscreen                   , 0xfc319671) //0xfc31987d?
NHSTUB(undisplaybusyonscreen                   ,0xfc319709)//0xfc3198fb ?
NHSTUB(SetZoomActuatorSpeedPercent                   , NULL_SUB)
NHSTUB(MakeSDCardBootable                   , 0xfc33284d)
NHSTUB(GetImageFolder                   , 0xfc30ba5d)
NHSTUB(EnterToCompensationEVF                ,0xfc2766c5) //corrected,from 0xFC2766c4)
NHSTUB(ExitFromCompensationEVF               ,0xFC2766ff)
NHSTUB(ExpCtrlTool_StartContiAE              ,0xFC264e5b)
NHSTUB(ExpCtrlTool_StopContiAE               ,0xFC264F47)
NHSTUB(Feof_Fut                              ,0xFC301Dad)
NHSTUB(Fflush_Fut                            ,0xFC301Dd5)
NHSTUB(get_dial_hw_position                  ,0xfc119805) 
NHSTUB(GetDrive_TotalClusters               ,0xfc3324eb)
//NHSTUB(GetFocusLensSubjectDistance          ,0xfc4b4a73)
//NHSTUB(GetFocusLensSubjectDistance          ,0xfc2fa8df) //stubs_entry.S
NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xFC2FABc1)
//NHSTUB(PT_PlaySound                         ,0xFC333df1)
NHSTUB(RefreshPhysicalScreen                  ,NULL_SUB) // NOT FOUND put to null, original in sx280 102b was 0xfc143599 
NHSTUB(RenameFile_Fut                       ,0xFC301B5d)
NHSTUB(Restart                              ,0xFC0B96E5)
NHSTUB(SetFileAttributes                    ,0xFC332C01)
NHSTUB(SetFileTimeStamp                     ,0xFC332Bb9)
NHSTUB(SetParameterData                     ,0xfc322acf)
//NHSTUB(TurnOffBackLight                     ,0xFC0E786B)
//NHSTUB(TurnOnBackLight                      ,0xFC0E7859)
NHSTUB(WriteSDCard                          ,0xFCD1D6B7)
NHSTUB(apex2us                              ,0xFC3468bb)
//NHSTUB(rand                                 ,0xFC1619CF)
NHSTUB(reboot_fw_update                     ,0xfc3a1177 ) // xxxcorrected from,0xfc3a1175)
//NHSTUB(srand                                ,0xFC1619C1)
NHSTUB(CancelHPTimer                        ,0xFC15BBFD)
//NHSTUB(SetHPTimerAfterNow                   ,0xFC15BB65)
// required because DryOS >=54 functions assert on unitialized event flag, sem etc
// see https://chdk.setepontos.com/index.php?topic=12516.0
NHSTUB(init_focus_eventflag,    0xfc4b54e7) // InitializeAdjustmentSystem->fc39f870->fc4b54e6 event flag matches MoveFocusLensToDistance
NHSTUB(init_nd_eventflag,               0xfc4b55c9) // InitializeAdjustmentSystem->fc3d31c4->fc4b55c8 event flag matches PutInNdFilter
NHSTUB(CreateBinarySemaphoreStrictly,0x010e5b8b) // for av_override_semaphore


