/********
* ec2c version 0.67
* context   method = HEAP
* ext call  method = PROCEDURES
* c header file generated for node : Portillon 
* to be used with : Portillon.c 
********/
#ifndef _Portillon_EC2C_H_FILE
#define _Portillon_EC2C_H_FILE
/*-------- Predefined types ---------*/
#ifndef _EC2C_PREDEF_TYPES
#define _EC2C_PREDEF_TYPES
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef double _real;
typedef double _double;
typedef float _float;
#define _false 0
#define _true 1
#endif
/*--------- Pragmas ----------------*/
//MODULE: Portillon 2 1
//IN: _boolean A
//IN: _boolean B
//OUT: _boolean alarm
#ifndef _Portillon_EC2C_SRC_FILE
/*--------Context type -------------*/
struct Portillon_ctx;
/*-------- Input procedures -------------*/
extern void Portillon_I_A(struct Portillon_ctx* ctx, _boolean);
extern void Portillon_I_B(struct Portillon_ctx* ctx, _boolean);
/*-------- Reset procedure -----------*/
extern void Portillon_reset(struct Portillon_ctx* ctx);
/*--------Context copy -------------*/
extern void Portillon_copy_ctx(struct Portillon_ctx* dest, struct Portillon_ctx
* src);
/*--------Context allocation --------*/
extern struct Portillon_ctx* Portillon_new_ctx(void* client_data);
/*-------- Step procedure -----------*/
extern void Portillon_step(struct Portillon_ctx* ctx);
#endif
#endif
