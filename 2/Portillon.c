/********
* ec2c version 0.67
* c file generated for node : Portillon 
* context   method = HEAP
* ext call  method = PROCEDURES
********/
#include <stdlib.h>
#include <string.h>
#define _Portillon_EC2C_SRC_FILE
#include "Portillon.h"
/*--------
Internal structure for the call
--------*/
typedef struct  {
   void* client_data;
   //INPUTS
   _boolean _A;
   _boolean _B;
   //OUTPUTS
   _boolean _alarm;
   //REGISTERS
   _boolean M10;
   _boolean M10_nil;
   _boolean M5;
} Portillon_ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Portillon_I_A(Portillon_ctx* ctx, _boolean V){
   ctx->_A = V;
}
void Portillon_I_B(Portillon_ctx* ctx, _boolean V){
   ctx->_B = V;
}
extern void Portillon_O_alarm(void* cdata, _boolean);
#ifdef CKCHECK
extern void Portillon_BOT_alarm(void* cdata);
#endif
/*--------
Internal reset input procedure
--------*/
static void Portillon_reset_input(Portillon_ctx* ctx){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Portillon_reset(Portillon_ctx* ctx){
   ctx->M10_nil = _true;
   ctx->M5 = _true;
   Portillon_reset_input(ctx);
}
/*--------
Copy the value of an internal structure
--------*/
void Portillon_copy_ctx(Portillon_ctx* dest, Portillon_ctx* src){
   memcpy((void*)dest, (void*)src, sizeof(Portillon_ctx));
}
/*--------
Dynamic allocation of an internal structure
--------*/
Portillon_ctx* Portillon_new_ctx(void* cdata){
   Portillon_ctx* ctx = (Portillon_ctx*)calloc(1, sizeof(Portillon_ctx));
   ctx->client_data = cdata;
   Portillon_reset(ctx);
   return ctx;
}
/*--------
Step procedure
--------*/
void Portillon_step(Portillon_ctx* ctx){
//LOCAL VARIABLES
   _boolean L9;
   _boolean L8;
   _boolean L4;
   _boolean L3;
   _boolean L2;
   _boolean T10;
//CODE
   if (ctx->_B) {
      L9 = _false;
   } else {
      L9 = ctx->M10;
   }
   if (ctx->_A) {
      L8 = _true;
   } else {
      L8 = L9;
   }
   if (ctx->M5) {
      L4 = _false;
   } else {
      L4 = L8;
   }
   L3 = (ctx->_B && L4);
   if (L3) {
      L2 = _true;
   } else {
      L2 = _false;
   }
   Portillon_O_alarm(ctx->client_data, L2);
   T10 = L4;
   ctx->M10 = T10;
   ctx->M10_nil = _false;
   ctx->M5 = ctx->M5 && !(_true);
}
