/********
* poc version 1.1
* c header file generated from : metronome.oc 
* to be used with : metronome.c 
********/
#ifndef _metronome_POC_H_FILE
#define _metronome_POC_H_FILE
/*-------- Predefined types ---------*/
#ifndef _metronome_POC_PREDEF_TYPES
#define _metronome_POC_PREDEF_TYPES
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef float _float;
typedef double _double;
#define _false 0
#define _true 1
#endif
/*--------Context type -------------*/
/*--------
Internal structure for the call
--------*/
typedef struct  {
   void* client_data;
   int current_state;
   _boolean _V0;
   _boolean _V1;
   _integer _V2;
   _integer _V3;
   _integer _V4;
   _boolean _V5;
   _boolean _V6;
   _boolean _V7;
   _boolean _V8;
} metronome_ctx;
#ifndef _metronome_POC_SRC_FILE
/*--------- Pragmas ----------------*/
//MODULE: metronome 2 2
//IN: _boolean reset
//IN: _integer delay
//OUT: _boolean tic
//OUT: _boolean tac
/*--------Context allocation --------*/
extern metronome_ctx* metronome_new_ctx(void* client_data);
/*--------Context copy -------------*/
extern void metronome_copy_ctx(metronome_ctx* dest, metronome_ctx* src);
/*-------- Input procedures ---------*/
extern void metronome_I_reset(metronome_ctx* ctx, _boolean __V);
extern void metronome_I_delay(metronome_ctx* ctx, _integer __V);
/*-------- Reset procedure ----------*/
extern void  metronome_reset(metronome_ctx* ctx);
/*-------- Step procedure ----------*/
extern void  metronome_step(metronome_ctx* ctx);
#endif
#endif
