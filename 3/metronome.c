/********
* poc version 1.1
* c file generated from : metronome.oc 
********/
#include <stdlib.h>
#include <string.h>
#define _metronome_POC_SRC_FILE
#include "metronome.h"
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void metronome_I_reset(metronome_ctx* ctx, _boolean __V){
   ctx->_V1 = __V;
   ctx->_V0 = _true;
}
void metronome_I_delay(metronome_ctx* ctx, _integer __V){
   ctx->_V2 = __V;
   ctx->_V0 = _true;
}
extern void metronome_O_tic(void*, _boolean);
extern void metronome_O_tac(void*, _boolean);
/*--------
Internal reset input procedure
--------*/
static void metronome_reset_input(metronome_ctx* ctx){
   ctx->_V0 = _false;
   ctx->_V0 = _false;
}
/*--------
Reset procedure
--------*/
void metronome_reset(metronome_ctx* ctx){
   ctx->current_state = 0;
   metronome_reset_input(ctx);
}
/*--------
Dynamic allocation of an internal structure
--------*/
metronome_ctx* metronome_new_ctx(void* cdata){
   metronome_ctx* ctx = (metronome_ctx*)calloc(1, sizeof(metronome_ctx));
   ctx->client_data = cdata;
   metronome_reset(ctx);
   return ctx;
}
/*--------
Copy the value of an internal structure
--------*/
void metronome_copy_ctx(metronome_ctx* dest, metronome_ctx* src){
   memcpy((void*)dest, (void*)src, sizeof(metronome_ctx));
}
/*--------
Step procedure
--------*/
void metronome_step(metronome_ctx* ctx){
   switch(ctx->current_state){
   case 0:
      ctx->_V4 = ((ctx->_V1 && (ctx->_V2 > 0))? ctx->_V2 : 1);
      ctx->_V3 = ((ctx->_V1 && (ctx->_V2 > 0))? 0 : 1);
      ctx->_V5 = _false;
      ctx->_V6 = ctx->_V1;
      ctx->_V7 = (((ctx->_V3 == 0) && ctx->_V5) && ctx->_V6);
      metronome_O_tic(ctx->client_data, ctx->_V7);
      ctx->_V8 = (((ctx->_V3 == 0) && (!ctx->_V5)) && ctx->_V6);
      metronome_O_tac(ctx->client_data, ctx->_V8);
      ctx->current_state = 1; break;
   break;
   
   case 1:
      ctx->_V4 = ((ctx->_V1 && (ctx->_V2 > 0))? ctx->_V2 : ctx->_V4);
      ctx->_V3 = ((ctx->_V1 && (ctx->_V2 > 0))? 0 : ((ctx->_V3 + 1) % ctx->_V4)
);
      ctx->_V5 = ((ctx->_V3 == 0)? (!ctx->_V5) : ctx->_V5);
      ctx->_V6 = (ctx->_V1? _true : (ctx->_V1 || ctx->_V6));
      ctx->_V7 = (((ctx->_V3 == 0) && ctx->_V5) && ctx->_V6);
      metronome_O_tic(ctx->client_data, ctx->_V7);
      ctx->_V8 = (((ctx->_V3 == 0) && (!ctx->_V5)) && ctx->_V6);
      metronome_O_tac(ctx->client_data, ctx->_V8);
      ctx->current_state = 1; break;
   break;
   } /* END SWITCH */
   metronome_reset_input(ctx);
}
