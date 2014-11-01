#define nx_struct struct
#define nx_union union
#define dbg(mode, format, ...) ((void)0)
#define dbg_clear(mode, format, ...) ((void)0)
#define dbg_active(mode) 0
# 149 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stddef.h" 3
typedef int ptrdiff_t;
#line 211
typedef unsigned int size_t;
#line 323
typedef int wchar_t;
# 8 "/usr/lib/ncc/deputy_nodeputy.h"
struct __nesc_attr_nonnull {
#line 8
  int dummy;
}  ;
#line 9
struct __nesc_attr_bnd {
#line 9
  void *lo, *hi;
}  ;
#line 10
struct __nesc_attr_bnd_nok {
#line 10
  void *lo, *hi;
}  ;
#line 11
struct __nesc_attr_count {
#line 11
  int n;
}  ;
#line 12
struct __nesc_attr_count_nok {
#line 12
  int n;
}  ;
#line 13
struct __nesc_attr_one {
#line 13
  int dummy;
}  ;
#line 14
struct __nesc_attr_one_nok {
#line 14
  int dummy;
}  ;
#line 15
struct __nesc_attr_dmemset {
#line 15
  int a1, a2, a3;
}  ;
#line 16
struct __nesc_attr_dmemcpy {
#line 16
  int a1, a2, a3;
}  ;
#line 17
struct __nesc_attr_nts {
#line 17
  int dummy;
}  ;
# 37 "/usr/include/stdint.h" 3
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;



__extension__ 
typedef long long int int64_t;




typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;





__extension__ 
typedef unsigned long long int uint64_t;






typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;



__extension__ 
typedef long long int int_least64_t;



typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;



__extension__ 
typedef unsigned long long int uint_least64_t;






typedef signed char int_fast8_t;





typedef int int_fast16_t;
typedef int int_fast32_t;
__extension__ 
typedef long long int int_fast64_t;



typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
__extension__ 
typedef unsigned long long int uint_fast64_t;
#line 126
typedef int intptr_t;


typedef unsigned int uintptr_t;








__extension__ 
typedef long long int intmax_t;
__extension__ 
typedef unsigned long long int uintmax_t;
# 35 "/usr/include/inttypes.h" 3
typedef int __gwchar_t;
#line 292
#line 288
typedef struct __nesc_unnamed4242 {

  long long int quot;
  long long int rem;
} imaxdiv_t;
# 281 "/usr/lib/ncc/nesc_nx.h"
static __inline uint8_t __nesc_ntoh_uint8(const void * source)  ;




static __inline uint8_t __nesc_hton_uint8(void * target, uint8_t value)  ;
#line 303
static __inline int8_t __nesc_hton_int8(void * target, int8_t value)  ;






static __inline uint16_t __nesc_ntoh_uint16(const void * source)  ;




static __inline uint16_t __nesc_hton_uint16(void * target, uint16_t value)  ;
#line 431
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_int8_t;typedef int8_t __nesc_nxbase_nx_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_int16_t;typedef int16_t __nesc_nxbase_nx_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_int32_t;typedef int32_t __nesc_nxbase_nx_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_int64_t;typedef int64_t __nesc_nxbase_nx_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_uint8_t;typedef uint8_t __nesc_nxbase_nx_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_uint16_t;typedef uint16_t __nesc_nxbase_nx_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_uint32_t;typedef uint32_t __nesc_nxbase_nx_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_uint64_t;typedef uint64_t __nesc_nxbase_nx_uint64_t  ;


typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_int8_t;typedef int8_t __nesc_nxbase_nxle_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_int16_t;typedef int16_t __nesc_nxbase_nxle_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_int32_t;typedef int32_t __nesc_nxbase_nxle_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_int64_t;typedef int64_t __nesc_nxbase_nxle_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_uint8_t;typedef uint8_t __nesc_nxbase_nxle_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_uint16_t;typedef uint16_t __nesc_nxbase_nxle_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_uint32_t;typedef uint32_t __nesc_nxbase_nxle_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_uint64_t;typedef uint64_t __nesc_nxbase_nxle_uint64_t  ;
# 43 "/usr/include/string.h" 3
extern void *memcpy(void *__restrict __dest, 
const void *__restrict __src, size_t __n) 
__attribute((__nothrow__)) __attribute((__nonnull__(1, 2))) ;
#line 64
extern void *memset(void *__s, int __c, size_t __n) __attribute((__nothrow__)) __attribute((__nonnull__(1))) ;


extern int memcmp(const void *__s1, const void *__s2, size_t __n) 
__attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1, 2))) ;
#line 127
extern char *strcpy(char *__restrict __dest, const char *__restrict __src) 
__attribute((__nothrow__)) __attribute((__nonnull__(1, 2))) ;
#line 142
extern int strcmp(const char *__s1, const char *__s2) 
__attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1, 2))) ;
# 40 "/usr/include/xlocale.h" 3
#line 28
typedef struct __locale_struct {


  struct locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 260 "/usr/include/string.h"
extern char *strrchr(const char *__s, int __c) 
__attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1))) ;
#line 397
extern size_t strlen(const char *__s) 
__attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1))) ;
# 102 "/usr/include/stdlib.h" 3
#line 98
typedef struct __nesc_unnamed4243 {

  int quot;
  int rem;
} div_t;







#line 106
typedef struct __nesc_unnamed4244 {

  long int quot;
  long int rem;
} ldiv_t;







__extension__ 



#line 118
typedef struct __nesc_unnamed4245 {

  long long int quot;
  long long int rem;
} lldiv_t;
#line 158
__extension__ 
#line 195
__extension__ 




__extension__ 








__extension__ 




__extension__ 
# 31 "/usr/include/bits/types.h" 3
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ 
#line 47
typedef signed long long int __int64_t;
__extension__ 
#line 48
typedef unsigned long long int __uint64_t;







__extension__ 
#line 56
typedef long long int __quad_t;
__extension__ 
#line 57
typedef unsigned long long int __u_quad_t;
#line 134
__extension__ 
#line 134
typedef __u_quad_t __dev_t;
__extension__ 
#line 135
typedef unsigned int __uid_t;
__extension__ 
#line 136
typedef unsigned int __gid_t;
__extension__ 
#line 137
typedef unsigned long int __ino_t;
__extension__ 
#line 138
typedef __u_quad_t __ino64_t;
__extension__ 
#line 139
typedef unsigned int __mode_t;
__extension__ 
#line 140
typedef unsigned int __nlink_t;
__extension__ 
#line 141
typedef long int __off_t;
__extension__ 
#line 142
typedef __quad_t __off64_t;
__extension__ 
#line 143
typedef int __pid_t;
__extension__ 
#line 144
typedef struct __nesc_unnamed4246 {
#line 144
  int __val[2];
} 
#line 144
__fsid_t;
__extension__ 
#line 145
typedef long int __clock_t;
__extension__ 
#line 146
typedef unsigned long int __rlim_t;
__extension__ 
#line 147
typedef __u_quad_t __rlim64_t;
__extension__ 
#line 148
typedef unsigned int __id_t;
__extension__ 
#line 149
typedef long int __time_t;
__extension__ 
#line 150
typedef unsigned int __useconds_t;
__extension__ 
#line 151
typedef long int __suseconds_t;

__extension__ 
#line 153
typedef int __daddr_t;
__extension__ 
#line 154
typedef long int __swblk_t;
__extension__ 
#line 155
typedef int __key_t;


__extension__ 
#line 158
typedef int __clockid_t;


__extension__ 
#line 161
typedef void *__timer_t;


__extension__ 
#line 164
typedef long int __blksize_t;




__extension__ 
#line 169
typedef long int __blkcnt_t;
__extension__ 
#line 170
typedef __quad_t __blkcnt64_t;


__extension__ 
#line 173
typedef unsigned long int __fsblkcnt_t;
__extension__ 
#line 174
typedef __u_quad_t __fsblkcnt64_t;


__extension__ 
#line 177
typedef unsigned long int __fsfilcnt_t;
__extension__ 
#line 178
typedef __u_quad_t __fsfilcnt64_t;

__extension__ 
#line 180
typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ 
#line 189
typedef int __intptr_t;


__extension__ 
#line 192
typedef unsigned int __socklen_t;
# 35 "/usr/include/sys/types.h" 3
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
#line 62
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
#line 100
typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 76 "/usr/include/time.h" 3
typedef __time_t time_t;
#line 92
typedef __clockid_t clockid_t;
#line 104
typedef __timer_t timer_t;
# 151 "/usr/include/sys/types.h" 3
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
#line 201
typedef unsigned int u_int8_t __attribute((__mode__(__QI__))) ;
typedef unsigned int u_int16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int u_int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int u_int64_t __attribute((__mode__(__DI__))) ;

typedef int register_t __attribute((__mode__(__word__))) ;
# 24 "/usr/include/bits/sigset.h" 3
typedef int __sig_atomic_t;







#line 29
typedef struct __nesc_unnamed4247 {

  unsigned long int __val[1024 / (8 * sizeof(unsigned long int ))];
} __sigset_t;
# 38 "/usr/include/sys/select.h" 3
typedef __sigset_t sigset_t;
# 120 "/usr/include/time.h" 3
struct timespec {

  __time_t tv_sec;
  long int tv_nsec;
};
# 69 "/usr/include/bits/time.h" 3
struct timeval {

  __time_t tv_sec;
  __suseconds_t tv_usec;
};
# 49 "/usr/include/sys/select.h" 3
typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
#line 78
#line 67
typedef struct __nesc_unnamed4248 {







  __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))];
} 

fd_set;






typedef __fd_mask fd_mask;
# 30 "/usr/include/sys/sysmacros.h" 3
__extension__ 


__extension__ 


__extension__ 
# 235 "/usr/include/sys/types.h" 3
typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 50 "/usr/include/bits/pthreadtypes.h" 3
typedef unsigned long int pthread_t;






#line 53
typedef union __nesc_unnamed4249 {

  char __size[36];
  long int __align;
} pthread_attr_t;
#line 70
#line 67
typedef struct __pthread_internal_slist {

  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
#line 104
#line 76
typedef union __nesc_unnamed4250 {

  struct __pthread_mutex_s {

    int __lock;
    unsigned int __count;
    int __owner;





    int __kind;





    unsigned int __nusers;
    __extension__ union  {

      int __spins;
      __pthread_slist_t __list;
    } ;
  } 
  __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;





#line 106
typedef union __nesc_unnamed4251 {

  char __size[4];
  int __align;
} pthread_mutexattr_t;
#line 130
#line 115
typedef union __nesc_unnamed4252 {

  struct __nesc_unnamed4253 {

    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





#line 132
typedef union __nesc_unnamed4254 {

  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;
#line 189
#line 150
typedef union __nesc_unnamed4255 {
#line 170
  struct __nesc_unnamed4256 {

    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;


    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;

  char __size[32];
  long int __align;
} pthread_rwlock_t;





#line 191
typedef union __nesc_unnamed4257 {

  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;








#line 206
typedef union __nesc_unnamed4258 {

  char __size[20];
  long int __align;
} pthread_barrier_t;





#line 212
typedef union __nesc_unnamed4259 {

  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 349 "/usr/include/stdlib.h" 3
struct random_data {

  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
};
#line 418
struct drand48_data {

  unsigned short int __x[3];
  unsigned short int __old_x[3];
  unsigned short int __c;
  unsigned short int __init;
  unsigned long long int __a;
};
#line 471
extern void *malloc(size_t __size) __attribute((__nothrow__)) __attribute((__malloc__)) ;
#line 488
extern void free(void *__ptr) __attribute((__nothrow__)) ;
#line 737
typedef int (*__compar_fn_t)(const void *arg_0x4032ebc8, const void *arg_0x4032ed60);
#line 771
__extension__ 
#line 788
__extension__ 
# 38 "/usr/include/bits/mathdef.h" 3
typedef long double float_t;

typedef long double double_t;
# 110 "/usr/include/bits/mathcalls.h" 3
extern double log(double __x) __attribute((__nothrow__)) ;
#line 154
extern double pow(double __x, double __y) __attribute((__nothrow__)) ;


extern double sqrt(double __x) __attribute((__nothrow__)) ;
#line 185
extern double floor(double __x) __attribute((__nothrow__)) __attribute((const)) ;
#line 251
extern double erfc(double arg_0x4037ae88) __attribute((__nothrow__)) ;
# 202 "/usr/include/math.h" 3
enum __nesc_unnamed4260 {

  FP_NAN, 

  FP_INFINITE, 

  FP_ZERO, 

  FP_SUBNORMAL, 

  FP_NORMAL
};
#line 302
#line 295
typedef enum __nesc_unnamed4261 {

  _IEEE_ = -1, 
  _SVID_, 
  _XOPEN_, 
  _POSIX_, 
  _ISOC_
} _LIB_VERSION_TYPE;
#line 320
struct exception {


  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
};
# 48 "/usr/include/ctype.h" 3
enum __nesc_unnamed4262 {

  _ISupper = 0 < 8 ? (1 << 0) << 8 : (1 << 0) >> 8, 
  _ISlower = 1 < 8 ? (1 << 1) << 8 : (1 << 1) >> 8, 
  _ISalpha = 2 < 8 ? (1 << 2) << 8 : (1 << 2) >> 8, 
  _ISdigit = 3 < 8 ? (1 << 3) << 8 : (1 << 3) >> 8, 
  _ISxdigit = 4 < 8 ? (1 << 4) << 8 : (1 << 4) >> 8, 
  _ISspace = 5 < 8 ? (1 << 5) << 8 : (1 << 5) >> 8, 
  _ISprint = 6 < 8 ? (1 << 6) << 8 : (1 << 6) >> 8, 
  _ISgraph = 7 < 8 ? (1 << 7) << 8 : (1 << 7) >> 8, 
  _ISblank = 8 < 8 ? (1 << 8) << 8 : (1 << 8) >> 8, 
  _IScntrl = 9 < 8 ? (1 << 9) << 8 : (1 << 9) >> 8, 
  _ISpunct = 10 < 8 ? (1 << 10) << 8 : (1 << 10) >> 8, 
  _ISalnum = 11 < 8 ? (1 << 11) << 8 : (1 << 11) >> 8
};
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE;



typedef struct _IO_FILE FILE;
#line 65
typedef struct _IO_FILE __FILE;
# 95 "/usr/include/wchar.h" 3
#line 83
typedef struct __nesc_unnamed4263 {

  int __count;
  union __nesc_unnamed4264 {


    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 26 "/usr/include/_G_config.h" 3
#line 22
typedef struct __nesc_unnamed4265 {

  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;




#line 27
typedef struct __nesc_unnamed4266 {

  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
#line 53
typedef int _G_int16_t __attribute((__mode__(__HI__))) ;
typedef int _G_int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int _G_uint16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int _G_uint32_t __attribute((__mode__(__SI__))) ;
# 40 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
# 170 "/usr/include/libio.h" 3
struct _IO_jump_t;
#line 170
struct _IO_FILE;









typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
};
#line 206
enum __codecvt_result {

  __codecvt_ok, 
  __codecvt_partial, 
  __codecvt_error, 
  __codecvt_noconv
};
#line 271
struct _IO_FILE {
  int _flags;




  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;








  __off64_t _offset;








  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof(int ) - 4 * sizeof(void *) - sizeof(size_t )];
};



typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

struct _IO_FILE_plus;
struct _IO_FILE_plus;
struct _IO_FILE_plus;
#line 364
typedef __ssize_t __io_read_fn(void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn(void *__cookie, const char *__buf, 
size_t __n);







typedef int __io_seek_fn(void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn(void *__cookie);
# 91 "/usr/include/stdio.h" 3
typedef _G_fpos_t fpos_t;
#line 145
struct _IO_FILE;
struct _IO_FILE;
struct _IO_FILE;
#line 219
extern int fflush(FILE *__stream);
#line 283
extern FILE *fdopen(int __fd, const char *__modes) __attribute((__nothrow__)) ;
#line 333
extern int fprintf(FILE *__restrict __stream, 
const char *__restrict __format, ...);




extern int printf(const char *__restrict __format, ...);








extern int vfprintf(FILE *__restrict __s, const char *__restrict __format, 
__gnuc_va_list __arg);
#line 363
extern int snprintf(char *__restrict __s, size_t __maxlen, 
const char *__restrict __format, ...) 
__attribute((__nothrow__)) __attribute((__format__(__printf__, 3, 4))) ;
#line 831
extern int fileno(FILE *__stream) __attribute((__nothrow__)) ;
# 65 "/root/local/tinyos-2.1.1/tos/lib/tossim/tos.h"
typedef uint8_t bool;










enum __nesc_unnamed4267 {
#line 76
  FALSE = 0, TRUE = 1
};
extern uint16_t TOS_NODE_ID;
# 51 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_tossim.h"
typedef long long int sim_time_t;

void sim_init();

void sim_end();

void sim_random_seed(int seed);
int sim_random();

sim_time_t sim_time();
void sim_set_time(sim_time_t time);
sim_time_t sim_ticks_per_sec();

unsigned long sim_node();
void sim_set_node(unsigned long node);

int sim_print_time(char *buf, int bufLen, sim_time_t time);
int sim_print_now(char *buf, int bufLen);
char *sim_time_string();

void sim_add_channel(char *channel, FILE *file);
bool sim_remove_channel(char *channel, FILE *file);

bool sim_run_next_event();
# 50 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_event_queue.h"
struct sim_event;
typedef struct sim_event sim_event_t;

struct sim_event {
  sim_time_t time;
  unsigned long mote;
  bool force;

  bool cancelled;
  void *data;

  void (*handle)(sim_event_t *e);
  void (*cleanup)(sim_event_t *e);
};

static sim_event_t *sim_queue_allocate_event();

void sim_queue_init();
void sim_queue_insert(sim_event_t *event);
bool sim_queue_is_empty();
long long int sim_queue_peek_time();
sim_event_t *sim_queue_pop();

void sim_queue_cleanup_none(sim_event_t *e);
void sim_queue_cleanup_event(sim_event_t *e);
void sim_queue_cleanup_data(sim_event_t *e);
void sim_queue_cleanup_total(sim_event_t *e);
# 53 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_mote.h"
long long int sim_mote_euid(int mote);
void sim_mote_set_euid(int mote, long long int euid);

long long int sim_mote_start_time(int mote);
void sim_mote_set_start_time(int mote, long long int t);

bool sim_mote_is_on(int mote);
void sim_mote_turn_on(int mote);
void sim_mote_turn_off(int mote);
int sim_mote_get_variable_info(int mote, char *name, void **addr, size_t *len);
void sim_mote_enqueue_boot_event(int mote);
# 65 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_log.h"
static inline void sim_log_init();
static inline void sim_log_add_channel(char *output, FILE *file);
static inline bool sim_log_remove_channel(char *output, FILE *file);
static void sim_log_commit_change();

static void sim_log_debug(uint16_t id, char *string, const char *format, ...);
static void sim_log_error(uint16_t id, char *string, const char *format, ...);
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...);
# 97 "/root/local/tinyos-2.1.1/tos/lib/tossim/tos.h"
struct __nesc_attr_atmostonce {
};
#line 98
struct __nesc_attr_atleastonce {
};
#line 99
struct __nesc_attr_exactlyonce {
};
# 102 "/usr/lib/gcc/i486-linux-gnu/4.4.3/include/stdarg.h" 3
typedef __gnuc_va_list va_list;
# 9 "/root/local/tinyos-2.1.1/tos/lib/tossim/hashtable.h"
struct hashtable;
typedef struct hashtable hashtable_t;
#line 78
struct hashtable *
create_hashtable(unsigned int minsize, 
unsigned int (*hashfunction)(void *arg_0x404c3c78), 
int (*key_eq_fn)(void *arg_0x404c10e8, void *arg_0x404c1260));
#line 103
#line 102
int 
hashtable_insert(struct hashtable *h, void *k, void *v);
#line 120
void *
hashtable_search(struct hashtable *h, void *k);
# 47 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_log.c"
enum __nesc_unnamed4268 {
  DEFAULT_CHANNEL_SIZE = 8
};




#line 51
typedef struct sim_log_output {
  int num;
  FILE **files;
} sim_log_output_t;






#line 56
typedef struct sim_log_channel {
  const char *name;
  int numOutputs;
  int size;
  FILE **outputs;
} sim_log_channel_t;

enum __nesc_unnamed4269 {
  SIM_LOG_OUTPUT_COUNT = 254U
};

sim_log_output_t outputs[SIM_LOG_OUTPUT_COUNT];
struct hashtable *channelTable = (void *)0;


inline static unsigned int sim_log_hash(void *key);
inline static int sim_log_eq(void *key1, void *key2);
#line 84
static void fillInOutput(int id, char *name);
#line 159
static inline void sim_log_init();
#line 172
static inline void sim_log_add_channel(char *name, FILE *file);
#line 212
static inline bool sim_log_remove_channel(char *output, FILE *file);
#line 234
static void sim_log_commit_change();
#line 246
static void sim_log_debug(uint16_t id, char *string, const char *format, ...);
#line 261
static void sim_log_error(uint16_t id, char *string, const char *format, ...);
#line 276
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...);
#line 306
inline static unsigned int sim_log_hash(void *key);










inline static int sim_log_eq(void *key1, void *key2);
# 65 "/root/local/tinyos-2.1.1/tos/lib/tossim/heap.h"
#line 61
typedef struct heap {
  int size;
  void *data;
  int private_size;
} heap_t;

static inline void init_heap(heap_t *heap);

static inline int heap_is_empty(heap_t *heap);

static inline long long int heap_get_min_key(heap_t *heap);

static void *heap_pop_min_data(heap_t *heap, long long int *key);
static inline void heap_insert(heap_t *heap, void *data, long long int key);
# 58 "/root/local/tinyos-2.1.1/tos/lib/tossim/heap.c"
const int STARTING_SIZE = 511;






#line 62
typedef struct node {
  void *data;
  long long int key;
} node_t;

static void down_heap(heap_t *heap, int findex);
static void up_heap(heap_t *heap, int findex);
static void swap(node_t *first, node_t *second);








static inline void init_heap(heap_t *heap);









static inline int is_empty(heap_t *heap);



static inline int heap_is_empty(heap_t *heap);



static inline long long int heap_get_min_key(heap_t *heap);
#line 114
static void *heap_pop_min_data(heap_t *heap, long long int *key);
#line 130
static inline void expand_heap(heap_t *heap);
#line 144
static inline void heap_insert(heap_t *heap, void *data, long long int key);
#line 158
static void swap(node_t *first, node_t *second);
#line 171
static void down_heap(heap_t *heap, int findex);
#line 197
static void up_heap(heap_t *heap, int findex);
# 44 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_event_queue.c"
static heap_t eventHeap;

void sim_queue_init()   ;



void sim_queue_insert(sim_event_t *event)   ;




sim_event_t *sim_queue_pop()   ;




bool sim_queue_is_empty()   ;



long long int sim_queue_peek_time()   ;









void sim_queue_cleanup_none(sim_event_t *event)   ;




void sim_queue_cleanup_event(sim_event_t *event)   ;




void sim_queue_cleanup_data(sim_event_t *event)   ;





void sim_queue_cleanup_total(sim_event_t *event)   ;






static sim_event_t *sim_queue_allocate_event();
# 57 "/usr/include/sys/time.h" 3
struct timezone {

  int tz_minuteswest;
  int tz_dsttime;
};

typedef struct timezone *__restrict __timezone_ptr_t;









extern int gettimeofday(struct timeval *__restrict __tv, 
__timezone_ptr_t __tz) __attribute((__nothrow__)) __attribute((__nonnull__(1))) ;
#line 93
enum __itimer_which {


  ITIMER_REAL = 0, 


  ITIMER_VIRTUAL = 1, 



  ITIMER_PROF = 2
};




struct itimerval {


  struct timeval it_interval;

  struct timeval it_value;
};






typedef int __itimer_which_t;
# 51 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_noise.h"
enum __nesc_unnamed4270 {
  NOISE_MIN = -115, 
  NOISE_MAX = -5, 
  NOISE_MIN_QUANTIZE = -115, 
  NOISE_QUANTIZE_INTERVAL = 5, 
  NOISE_BIN_SIZE = (NOISE_MAX - NOISE_MIN) / NOISE_QUANTIZE_INTERVAL + 1, 
  NOISE_HISTORY = 20, 
  NOISE_DEFAULT_ELEMENT_SIZE = 8, 
  NOISE_HASHTABLE_SIZE = 128, 
  NOISE_MIN_TRACE = 128, 
  NOISE_NUM_VALUES = NOISE_MAX - NOISE_MIN + 1
};








#line 64
typedef struct sim_noise_hash_t {
  char key[NOISE_HISTORY];
  int numElements;
  int size;
  char *elements;
  char flag;
  float dist[NOISE_NUM_VALUES];
} sim_noise_hash_t;
#line 83
#line 73
typedef struct sim_noise_node_t {
  char key[NOISE_HISTORY];
  char freqKey[NOISE_HISTORY];
  char lastNoiseVal;
  uint32_t noiseGenTime;
  struct hashtable *noiseTable;
  char *noiseTrace;
  uint32_t noiseTraceLen;
  uint32_t noiseTraceIndex;
  bool generated;
} sim_noise_node_t;

void sim_noise_init();

char sim_noise_generate(uint16_t node_id, uint32_t cur_t);
void sim_noise_trace_add(uint16_t node_id, char val);
void sim_noise_create_model(uint16_t node_id);
# 51 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_tossim.c"
static sim_time_t sim_ticks;
static unsigned long current_node;
static int sim_seed;

static int __nesc_nido_resolve(int mote, char *varname, uintptr_t *addr, size_t *size);

void sim_init()   ;
#line 80
void sim_end()   ;





int sim_random()   ;
#line 102
void sim_random_seed(int seed)   ;







sim_time_t sim_time()   ;


void sim_set_time(sim_time_t t)   ;



sim_time_t sim_ticks_per_sec()   ;



unsigned long sim_node()   ;


void sim_set_node(unsigned long node)   ;




bool sim_run_next_event()   ;
#line 156
int sim_print_time(char *buf, int len, sim_time_t ftime)   ;
#line 179
int sim_print_now(char *buf, int len)   ;



char simTimeBuf[128];
char *sim_time_string()   ;




void sim_add_channel(char *channel, FILE *file)   ;



bool sim_remove_channel(char *channel, FILE *file)   ;
# 99 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_csma.h"
int sim_csma_init_high();
int sim_csma_init_low();
int sim_csma_high();
int sim_csma_low();
int sim_csma_symbols_per_sec();
int sim_csma_bits_per_symbol();
int sim_csma_preamble_length();
int sim_csma_exponent_base();
int sim_csma_max_iterations();
int sim_csma_min_free_samples();
int sim_csma_rxtx_delay();
int sim_csma_ack_time();

void sim_csma_set_init_high(int val);
void sim_csma_set_init_low(int val);
void sim_csma_set_high(int val);
void sim_csma_set_low(int val);
void sim_csma_set_symbols_per_sec(int val);
void sim_csma_set_bits_per_symbol(int val);
void sim_csma_set_preamble_length(int val);
void sim_csma_set_exponent_base(int val);
void sim_csma_set_max_iterations(int val);
void sim_csma_set_min_free_samples(int val);
void sim_csma_set_rxtx_delay(int val);
void sim_csma_set_ack_time(int val);
# 44 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_csma.c"
int csmaInitHigh = 640;
int csmaInitLow = 20;
int csmaHigh = 160;
int csmaLow = 20;
int csmaSymbolsPerSec = 65536;
int csmaBitsPerSymbol = 4;
int csmaPreambleLength = 12;
int csmaExponentBase = 1;
int csmaMaxIterations = 0;
int csmaMinFreeSamples = 1;
int csmaRxTxDelay = 11;
int csmaAckTime = 34;

int sim_csma_init_high()   ;


int sim_csma_init_low()   ;


int sim_csma_high()   ;


int sim_csma_low()   ;


int sim_csma_symbols_per_sec()   ;


int sim_csma_bits_per_symbol()   ;


int sim_csma_preamble_length()   ;


int sim_csma_exponent_base()   ;


int sim_csma_max_iterations()   ;


int sim_csma_min_free_samples()   ;


int sim_csma_rxtx_delay()   ;


int sim_csma_ack_time()   ;





void sim_csma_set_init_high(int val)   ;


void sim_csma_set_init_low(int val)   ;


void sim_csma_set_high(int val)   ;


void sim_csma_set_low(int val)   ;


void sim_csma_set_symbols_per_sec(int val)   ;


void sim_csma_set_bits_per_symbol(int val)   ;


void sim_csma_set_preamble_length(int val)   ;


void sim_csma_set_exponent_base(int val)   ;


void sim_csma_set_max_iterations(int val)   ;


void sim_csma_set_min_free_samples(int val)   ;


void sim_csma_set_rxtx_delay(int val)   ;


void sim_csma_set_ack_time(int val)   ;
# 57 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_gain.h"
#line 53
typedef struct gain_entry {
  int mote;
  double gain;
  struct gain_entry *next;
} gain_entry_t;

void sim_gain_add(int src, int dest, double gain);
double sim_gain_value(int src, int dest);
bool sim_gain_connected(int src, int dest);
void sim_gain_remove(int src, int dest);
void sim_gain_set_noise_floor(int node, double mean, double range);
double sim_gain_sample_noise(int node);



void sim_gain_set_sensitivity(double value);
double sim_gain_sensitivity();

gain_entry_t *sim_gain_first(int src);
gain_entry_t *sim_gain_next(gain_entry_t *e);
# 6 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_gain.c"
#line 3
typedef struct sim_gain_noise {
  double mean;
  double range;
} sim_gain_noise_t;


gain_entry_t *connectivity[1000 + 1];
sim_gain_noise_t localNoise[1000 + 1];
double sensitivity = 4.0;

static inline gain_entry_t *sim_gain_allocate_link(int mote);
void sim_gain_deallocate_link(gain_entry_t *linkToDelete);

gain_entry_t *sim_gain_first(int src)   ;






gain_entry_t *sim_gain_next(gain_entry_t *currentLink)   ;



void sim_gain_add(int src, int dest, double gain)   ;
#line 55
double sim_gain_value(int src, int dest)   ;
#line 73
bool sim_gain_connected(int src, int dest)   ;
#line 89
void sim_gain_remove(int src, int dest)   ;
#line 124
void sim_gain_set_noise_floor(int node, double mean, double range)   ;
#line 148
double sim_gain_sample_noise(int node)   ;
#line 161
static inline gain_entry_t *sim_gain_allocate_link(int mote);







void sim_gain_deallocate_link(gain_entry_t *linkToDelete)   ;



void sim_gain_set_sensitivity(double s)   ;



double sim_gain_sensitivity()   ;
# 39 "/root/local/tinyos-2.1.1/tos/lib/tossim/randomlib.c"
static double randU[97];
#line 39
static double randC;
#line 39
static double randCD;
#line 39
static double randCM;
static int i97;
#line 40
static int j97;
static int test = FALSE;
#line 55
static inline void RandomInitialise(int ij, int kl);
#line 103
static double RandomUniform(void );
# 60 "/usr/include/time.h" 3
typedef __clock_t clock_t;
#line 133
struct tm {

  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  const char *tm_zone;
};
#line 161
struct itimerspec {

  struct timespec it_interval;
  struct timespec it_value;
};


struct sigevent;
#line 233
struct tm;



struct tm;





struct tm;




struct tm;
# 46 "/root/local/tinyos-2.1.1/tos/lib/tossim/randomlib.h"
static inline void RandomInitialise(int arg_0x405fb618, int arg_0x405fb770);
static double RandomUniform(void );
# 51 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_noise.c"
int numCase1 = 0;
int numCase2 = 0;
int numTotal = 0;


uint32_t FreqKeyNum = 0;

sim_noise_node_t noiseData[1000];

inline static unsigned int sim_noise_hash(void *key);
inline static int sim_noise_eq(void *key1, void *key2);

void makeNoiseModel(uint16_t node_id);
void makePmfDistr(uint16_t node_id);
uint8_t search_bin_num(char noise);

void sim_noise_init()   ;
#line 84
void sim_noise_create_model(uint16_t node_id)   ;
#line 97
void sim_noise_trace_add(uint16_t node_id, char noiseVal)   ;
#line 113
uint8_t search_bin_num(char noise)   ;









char search_noise_from_bin_num(int i)   ;






inline static unsigned int sim_noise_hash(void *key);









inline static int sim_noise_eq(void *key1, void *key2);



void sim_noise_add(uint16_t node_id, char noise)   ;
#line 192
void sim_noise_dist(uint16_t node_id)   ;
#line 245
void arrangeKey(uint16_t node_id)   ;









void makePmfDistr(uint16_t node_id)   ;
#line 283
int dummy;
static inline void sim_noise_alarm();



char sim_noise_gen(uint16_t node_id)   ;
#line 364
char sim_noise_generate(uint16_t node_id, uint32_t cur_t)   ;
#line 419
void makeNoiseModel(uint16_t node_id)   ;
# 59 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_packet.h"
typedef struct sim_packet {
} 
#line 59
sim_packet_t;

void sim_packet_set_source(sim_packet_t *msg, uint16_t src);
uint16_t sim_packet_source(sim_packet_t *msg);

void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest);
uint16_t sim_packet_destination(sim_packet_t *msg);

void sim_packet_set_length(sim_packet_t *msg, uint8_t len);
uint16_t sim_packet_length(sim_packet_t *msg);

void sim_packet_set_type(sim_packet_t *msg, uint8_t type);
uint8_t sim_packet_type(sim_packet_t *msg);

uint8_t *sim_packet_data(sim_packet_t *msg);
void sim_packet_set_strength(sim_packet_t *msg, uint16_t str);

void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t);
uint8_t sim_packet_max_length(sim_packet_t *msg);

sim_packet_t *sim_packet_allocate();
void sim_packet_free(sim_packet_t *m);
# 6 "/root/local/tinyos-2.1.1/tos/types/AM.h"
typedef nx_uint8_t nx_am_id_t;
typedef nx_uint8_t nx_am_group_t;
typedef nx_uint16_t nx_am_addr_t;

typedef uint8_t am_id_t;
typedef uint8_t am_group_t;
typedef uint16_t am_addr_t;

enum __nesc_unnamed4271 {
  AM_BROADCAST_ADDR = 0xffff
};









enum __nesc_unnamed4272 {
  TOS_AM_GROUP = 0x22, 
  TOS_AM_ADDRESS = 1
};
# 12 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimRadioMsg.h"
#line 6
typedef nx_struct tossim_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t length;
  nx_am_group_t group;
  nx_am_id_t type;
} __attribute__((packed)) tossim_header_t;



#line 14
typedef nx_struct tossim_footer {
  nxle_uint16_t crc;
} __attribute__((packed)) tossim_footer_t;





#line 18
typedef nx_struct tossim_metadata {
  nx_int8_t strength;
  nx_uint8_t ack;
  nx_uint16_t time;
} __attribute__((packed)) tossim_metadata_t;
# 83 "/root/local/tinyos-2.1.1/tos/lib/serial/Serial.h"
typedef uint8_t uart_id_t;



enum __nesc_unnamed4273 {
  HDLC_FLAG_BYTE = 0x7e, 
  HDLC_CTLESC_BYTE = 0x7d
};



enum __nesc_unnamed4274 {
  TOS_SERIAL_ACTIVE_MESSAGE_ID = 0, 
  TOS_SERIAL_CC1000_ID = 1, 
  TOS_SERIAL_802_15_4_ID = 2, 
  TOS_SERIAL_UNKNOWN_ID = 255
};


enum __nesc_unnamed4275 {
  SERIAL_PROTO_ACK = 67, 
  SERIAL_PROTO_PACKET_ACK = 68, 
  SERIAL_PROTO_PACKET_NOACK = 69, 
  SERIAL_PROTO_PACKET_UNKNOWN = 255
};
#line 121
#line 109
typedef struct radio_stats {
  uint8_t version;
  uint8_t flags;
  uint8_t reserved;
  uint8_t platform;
  uint16_t MTU;
  uint16_t radio_crc_fail;
  uint16_t radio_queue_drops;
  uint16_t serial_crc_fail;
  uint16_t serial_tx_fail;
  uint16_t serial_short_packets;
  uint16_t serial_proto_drops;
} radio_stats_t;







#line 123
typedef nx_struct serial_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t length;
  nx_am_group_t group;
  nx_am_id_t type;
} __attribute__((packed)) serial_header_t;




#line 131
typedef nx_struct serial_packet {
  serial_header_t header;
  nx_uint8_t data[];
} __attribute__((packed)) serial_packet_t;



#line 136
typedef nx_struct serial_metadata {
  nx_uint8_t ack;
} __attribute__((packed)) serial_metadata_t;
# 53 "/root/local/tinyos-2.1.1/tos/lib/tossim/platform_message.h"
#line 50
typedef union message_header {
  tossim_header_t tossim;
  serial_header_t serial;
} message_header_t;



#line 55
typedef union message_footer {
  tossim_footer_t tossim;
} message_footer_t;



#line 59
typedef union message_metadata {
  tossim_metadata_t tossim;
} message_metadata_t;
# 19 "/root/local/tinyos-2.1.1/tos/types/message.h"
#line 14
typedef nx_struct message_t {
  nx_uint8_t header[sizeof(message_header_t )];
  nx_uint8_t data[28];
  nx_uint8_t footer[sizeof(message_footer_t )];
  nx_uint8_t metadata[sizeof(message_metadata_t )];
} __attribute__((packed)) message_t;
# 48 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_packet.c"
void active_message_deliver(int node, message_t *m, sim_time_t t);

inline static tossim_header_t *getHeader(message_t *msg);



void sim_packet_set_source(sim_packet_t *msg, uint16_t src)   ;




uint16_t sim_packet_source(sim_packet_t *msg)   ;




void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest)   ;




uint16_t sim_packet_destination(sim_packet_t *msg)   ;




void sim_packet_set_length(sim_packet_t *msg, uint8_t length)   ;



uint16_t sim_packet_length(sim_packet_t *msg)   ;




void sim_packet_set_type(sim_packet_t *msg, uint8_t type)   ;




uint8_t sim_packet_type(sim_packet_t *msg)   ;




uint8_t *sim_packet_data(sim_packet_t *p)   ;



void sim_packet_set_strength(sim_packet_t *p, uint16_t str)   ;




void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t)   ;







uint8_t sim_packet_max_length(sim_packet_t *msg)   ;



sim_packet_t *sim_packet_allocate()   ;



void sim_packet_free(sim_packet_t *p)   ;
# 51 "/root/local/tinyos-2.1.1/tos/types/TinyError.h"
enum __nesc_unnamed4276 {
  SUCCESS = 0, 
  FAIL = 1, 
  ESIZE = 2, 
  ECANCEL = 3, 
  EOFF = 4, 
  EBUSY = 5, 
  EINVAL = 6, 
  ERETRY = 7, 
  ERESERVE = 8, 
  EALREADY = 9, 
  ENOMEM = 10, 
  ENOACK = 11, 
  ELAST = 11
};

typedef uint8_t error_t  ;

static inline error_t ecombine(error_t r1, error_t r2)  ;
# 41 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4277 {
#line 41
  int notUsed;
} 
#line 41
TSecond;
typedef struct __nesc_unnamed4278 {
#line 42
  int notUsed;
} 
#line 42
TMilli;
typedef struct __nesc_unnamed4279 {
#line 43
  int notUsed;
} 
#line 43
T32khz;
typedef struct __nesc_unnamed4280 {
#line 44
  int notUsed;
} 
#line 44
TMicro;
# 7 "/root/workspace/Project1/src/lib/modules/../../Headers/command.h"
enum __nesc_unnamed4281 {

  CMD_PING = '0', 
  CMD_NEIGHBOR_DUMP = '1', 
  CMD_LINKSTATE_DUMP = '2', 
  CMD_ROUTETABLE_DUMP = '3', 
  CMD_TEST_CLIENT = '4', 
  CMD_TEST_SERVER = '5', 
  CMD_KILL = '6', 
  CMD_ERROR = '9'
};

enum __nesc_unnamed4282 {

  CMD_LENGTH = 1
};
# 5 "/root/workspace/Project1/src/lib/modules/../../Headers/protocol.h"
enum __nesc_unnamed4283 {

  PROTOCOL_PING = 0, 
  PROTOCOL_PINGREPLY = 1, 
  PROTOCOL_LINKSTATE = 2, 
  PROTOCOL_NAME = 3, 
  PROTOCOL_TCP = 4, 
  PROTOCOL_DV = 5, 
  PROTOCOL_CMD = 99
};
# 5 "/root/workspace/Project1/src/lib/modules/../../Headers/packet.h"
enum __nesc_unnamed4284 {

  PACKET_HEADER_LENGTH = 8, 
  PACKET_MAX_PAYLOAD_SIZE8 = 28 - PACKET_HEADER_LENGTH, 
  PACKET_MAX_PAYLOAD_SIZE16 = PACKET_MAX_PAYLOAD_SIZE8 / 2, 
  PACKET_MAX_PAYLOAD_SIZE32 = PACKET_MAX_PAYLOAD_SIZE8 / 4, 

  UNSPECIFIED = 0, 
  MAX_TTL = 15
};










#line 16
typedef nx_struct pack {

  nx_uint16_t dest;
  nx_uint16_t src;
  nx_uint16_t seq;
  nx_uint8_t TTL;
  nx_uint8_t protocol;
  nx_uint8_t payload[PACKET_MAX_PAYLOAD_SIZE8];
} __attribute__((packed)) 
pack;







enum __nesc_unnamed4285 {

  AM_PACK = 6
};
# 8 "/root/workspace/Project1/src/lib/modules/../../Headers/neighbor.h"
enum __nesc_unnamed4286 {

  CONNECTION_NONE = 0x0 << 0, 

  CONNECTION_RECEIVE = 0x1 << 0, 
  CONNECTION_SEND = 0x1 << 1, 
  CONNECTION_WAITING_RESPONSE = 0x1 << 2, 
  CONNECTION_TIMED_OUT = 0x1 << 3
};


enum __nesc_unnamed4287 {

  EMPTY = 0, 
  NONE = 0
};


enum __nesc_unnamed4288 {

  NEIGHBOR_TABLE_SIZE = 20, 
  SEQUENCE_TABLE_SIZE = 192, 
  SEQUENCE_TABLE_MAX_AGE = 144
};
# 5 "/root/workspace/Project1/src/lib/modules/../../Headers/sendInfo.h"
enum __nesc_unnamed4289 {

  SEND_BUFFER_SIZE = 128
};







#line 10
typedef struct sendInfo {

  pack packet;
  uint16_t src;
  uint16_t dest;
} 
sendInfo;
# 5 "/root/workspace/Project1/src/lib/modules/../../Headers/linkstate.h"
enum __nesc_unnamed4290 {

  INF = 0, 
  NEIGHBOR_COST = 1, 
  ROUTING_TABLE_SIZE = 32
};
# 13 "/root/workspace/Project1/src/lib/modules/../../Headers/socket.h"
#line 4
typedef enum socketState {

  SOCK_ESTABLISHED = 0, 
  SOCK_LISTEN = 1, 
  SOCK_CLOSED = 2, 
  SOCK_SYN_SENT = 3, 
  SOCK_CLOSE_WAIT = 4, 
  SOCK_FIN_WAIT = 5
} 
socketState;

enum __nesc_unnamed4291 {

  SOCKET_SEND_BUFFER_SIZE = 128, 
  SOCKET_RECEIVE_BUFFER_SIZE = 128, 

  POINTER_NULL = 0, 
  NULL_SOCKET = 0, 
  LISTEN_PORT = 80, 
  TOTAL_PORTS = 255
};







#line 26
typedef nx_struct socket_addr_t {

  nx_uint8_t srcPort;
  nx_uint8_t destPort;
  nx_uint16_t srcAddr;
  nx_uint16_t destAddr;
} __attribute__((packed)) socket_addr_t;
#line 46
#line 34
typedef struct socket_storage_t {

  socketState state;
  socket_addr_t sockAddr;
  uint8_t sendBuff[SOCKET_SEND_BUFFER_SIZE];
  uint8_t recBuff[SOCKET_RECEIVE_BUFFER_SIZE];
  uint16_t lastByteSent;
  uint16_t lastByteWritten;
  uint16_t lastByteAck;
  uint16_t lastByteRec;
  uint16_t lastByteRead;
  uint16_t lastByteExpected;
} socket_storage_t;

typedef uint16_t socket_t;
# 25 "/root/local/tinyos-2.1.1/tos/chips/atm128/sim/atm128_sim.h"
enum __nesc_unnamed4292 {

  ATM128_PINF = 0x00, 


  ATM128_PINE = 0x01, 


  ATM128_DDRE = 0x02, 


  ATM128_PORTE = 0x03, 


  ATM128_ADCW = 0x04, 

  ATM128_ADC = 0x04, 

  ATM128_ADCL = 0x04, 
  ATM128_ADCH = 0x05, 


  ATM128_ADCSR = 0x06, 
  ATM128_ADCSRA = 0x06, 


  ATM128_ADMUX = 0x07, 


  ATM128_ACSR = 0x08, 


  ATM128_UBRR0L = 0x09, 


  ATM128_UCSR0B = 0x0A, 


  ATM128_UCSR0A = 0x0B, 


  ATM128_UDR0 = 0x0C, 


  ATM128_SPCR = 0x0D, 


  ATM128_SPSR = 0x0E, 


  ATM128_SPDR = 0x0F, 


  ATM128_PIND = 0x10, 


  ATM128_DDRD = 0x11, 


  ATM128_PORTD = 0x12, 


  ATM128_PINC = 0x13, 


  ATM128_DDRC = 0x14, 


  ATM128_PORTC = 0x15, 


  ATM128_PINB = 0x16, 


  ATM128_DDRB = 0x17, 


  ATM128_PORTB = 0x18, 


  ATM128_PINA = 0x19, 


  ATM128_DDRA = 0x1A, 


  ATM128_PORTA = 0x1B, 




  ATM128_SFIOR = 0x20, 


  ATM128_WDTCR = 0x21, 


  ATM128_OCDR = 0x22, 


  ATM128_OCR2 = 0x23, 


  ATM128_TCNT2 = 0x24, 


  ATM128_TCCR2 = 0x25, 


  ATM128_ICR1 = 0x26, 
  ATM128_ICR1L = 0x26, 
  ATM128_ICR1H = 0x27, 


  ATM128_OCR1B = 0x28, 
  ATM128_OCR1BL = 0x28, 
  ATM128_OCR1BH = 0x29, 


  ATM128_OCR1A = 0x2A, 
  ATM128_OCR1AL = 0x2A, 
  ATM128_OCR1AH = 0x2B, 


  ATM128_TCNT1 = 0x2C, 
  ATM128_TCNT1L = 0x2C, 
  ATM128_TCNT1H = 0x2D, 


  ATM128_TCCR1B = 0x2E, 


  ATM128_TCCR1A = 0x2F, 


  ATM128_ASSR = 0x30, 


  ATM128_OCR0 = 0x31, 


  ATM128_TCNT0 = 0x32, 


  ATM128_TCCR0 = 0x33, 


  ATM128_MCUSR = 0x34, 
  ATM128_MCUCSR = 0x34, 


  ATM128_MCUCR = 0x35, 


  ATM128_TIFR = 0x36, 


  ATM128_TIMSK = 0x37, 


  ATM128_EIFR = 0x38, 


  ATM128_EIMSK = 0x39, 


  ATM128_EICRB = 0x3A, 


  ATM128_RAMPZ = 0x3B, 


  ATM128_XDIV = 0x3C, 




  ATM128_SREG = 0x3F, 




  ATM128_DDRF = 0x61, 


  ATM128_PORTF = 0x62, 


  ATM128_PING = 0x63, 


  ATM128_DDRG = 0x64, 


  ATM128_PORTG = 0x65, 


  ATM128_SPMCR = 0x68, 
  ATM128_SPMCSR = 0x68, 


  ATM128_EICRA = 0x6A, 


  ATM128_XMCRB = 0x6C, 


  ATM128_XMCRA = 0x6D, 


  ATM128_OSCCAL = 0x6F, 


  ATM128_TWBR = 0x70, 


  ATM128_TWSR = 0x71, 


  ATM128_TWAR = 0x72, 


  ATM128_TWDR = 0x73, 


  ATM128_TWCR = 0x74, 


  ATM128_OCR1C = 0x78, 
  ATM128_OCR1CL = 0x78, 
  ATM128_OCR1CH = 0x79, 


  ATM128_TCCR1C = 0x7A, 


  ATM128_ETIFR = 0x7C, 


  ATM128_ETIMSK = 0x7D, 


  ATM128_ICR3 = 0x80, 
  ATM128_ICR3L = 0x80, 
  ATM128_ICR3H = 0x81, 


  ATM128_OCR3C = 0x82, 
  ATM128_OCR3CL = 0x82, 
  ATM128_OCR3CH = 0x83, 


  ATM128_OCR3B = 0x84, 
  ATM128_OCR3BL = 0x84, 
  ATM128_OCR3BH = 0x85, 


  ATM128_OCR3A = 0x86, 
  ATM128_OCR3AL = 0x86, 
  ATM128_OCR3AH = 0x87, 


  ATM128_TCNT3 = 0x88, 
  ATM128_TCNT3L = 0x88, 
  ATM128_TCNT3H = 0x89, 


  ATM128_TCCR3B = 0x8A, 


  ATM128_TCCR3A = 0x8B, 


  ATM128_TCCR3C = 0x8C, 


  ATM128_UBRR0H = 0x90, 


  ATM128_UCSR0C = 0x95, 


  ATM128_UBRR1H = 0x98, 


  ATM128_UBRR1L = 0x99, 


  ATM128_UCSR1B = 0x9A, 


  ATM128_UCSR1A = 0x9B, 


  ATM128_UDR1 = 0x9C, 


  ATM128_UCSR1C = 0x9D
};
#line 673
enum __nesc_unnamed4293 {

  TWINT = 7, 
  TWEA = 6, 
  TWSTA = 5, 
  TWSTO = 4, 
  TWWC = 3, 
  TWEN = 2, 
  TWIE = 0, 


  TWA6 = 7, 
  TWA5 = 6, 
  TWA4 = 5, 
  TWA3 = 4, 
  TWA2 = 3, 
  TWA1 = 2, 
  TWA0 = 1, 
  TWGCE = 0, 


  TWS7 = 7, 
  TWS6 = 6, 
  TWS5 = 5, 
  TWS4 = 4, 
  TWS3 = 3, 
  TWPS1 = 1, 
  TWPS0 = 0, 


  SRL2 = 6, 
  SRL1 = 5, 
  SRL0 = 4, 
  SRW01 = 3, 
  SRW00 = 2, 
  SRW11 = 1, 


  XMBK = 7, 
  XMM2 = 2, 
  XMM1 = 1, 
  XMM0 = 0, 


  XDIVEN = 7, 
  XDIV6 = 6, 
  XDIV5 = 5, 
  XDIV4 = 4, 
  XDIV3 = 3, 
  XDIV2 = 2, 
  XDIV1 = 1, 
  XDIV0 = 0, 


  RAMPZ0 = 0, 


  ISC31 = 7, 
  ISC30 = 6, 
  ISC21 = 5, 
  ISC20 = 4, 
  ISC11 = 3, 
  ISC10 = 2, 
  ISC01 = 1, 
  ISC00 = 0, 


  ISC71 = 7, 
  ISC70 = 6, 
  ISC61 = 5, 
  ISC60 = 4, 
  ISC51 = 3, 
  ISC50 = 2, 
  ISC41 = 1, 
  ISC40 = 0, 


  SPMIE = 7, 
  RWWSB = 6, 
  RWWSRE = 4, 
  BLBSET = 3, 
  PGWRT = 2, 
  PGERS = 1, 
  SPMEN = 0, 


  INT7 = 7, 
  INT6 = 6, 
  INT5 = 5, 
  INT4 = 4, 
  INT3 = 3, 
  INT2 = 2, 
  INT1 = 1, 
  INT0 = 0, 


  INTF7 = 7, 
  INTF6 = 6, 
  INTF5 = 5, 
  INTF4 = 4, 
  INTF3 = 3, 
  INTF2 = 2, 
  INTF1 = 1, 
  INTF0 = 0, 


  OCIE2 = 7, 
  TOIE2 = 6, 
  TICIE1 = 5, 
  OCIE1A = 4, 
  OCIE1B = 3, 
  TOIE1 = 2, 
  OCIE0 = 1, 
  TOIE0 = 0, 


  OCF2 = 7, 
  TOV2 = 6, 
  ICF1 = 5, 
  OCF1A = 4, 
  OCF1B = 3, 
  TOV1 = 2, 
  OCF0 = 1, 
  TOV0 = 0, 


  TICIE3 = 5, 
  OCIE3A = 4, 
  OCIE3B = 3, 
  TOIE3 = 2, 
  OCIE3C = 1, 
  OCIE1C = 0, 


  ICF3 = 5, 
  OCF3A = 4, 
  OCF3B = 3, 
  TOV3 = 2, 
  OCF3C = 1, 
  OCF1C = 0, 


  SRE = 7, 
  SRW = 6, 
  SRW10 = 6, 
  SE = 5, 
  SM1 = 4, 
  SM0 = 3, 
  SM2 = 2, 
  IVSEL = 1, 
  IVCE = 0, 


  JTD = 7, 
  JTRF = 4, 
  WDRF = 3, 
  BORF = 2, 
  EXTRF = 1, 
  PORF = 0, 


  FOC = 7, 
  WGM0 = 6, 
  COM1 = 5, 
  COM0 = 4, 
  WGM1 = 3, 
  CS2 = 2, 
  CS1 = 1, 
  CS0 = 0, 


  FOC0 = 7, 
  WGM00 = 6, 
  COM01 = 5, 
  COM00 = 4, 
  WGM01 = 3, 
  CS02 = 2, 
  CS01 = 1, 
  CS00 = 0, 


  FOC2 = 7, 
  WGM20 = 6, 
  COM21 = 5, 
  COM20 = 4, 
  WGM21 = 3, 
  CS22 = 2, 
  CS21 = 1, 
  CS20 = 0, 


  AS0 = 3, 
  TCN0UB = 2, 
  OCR0UB = 1, 
  TCR0UB = 0, 


  COMA1 = 7, 
  COMA0 = 6, 
  COMB1 = 5, 
  COMB0 = 4, 
  COMC1 = 3, 
  COMC0 = 2, 
  WGMA1 = 1, 
  WGMA0 = 0, 


  COM1A1 = 7, 
  COM1A0 = 6, 
  COM1B1 = 5, 
  COM1B0 = 4, 
  COM1C1 = 3, 
  COM1C0 = 2, 
  WGM11 = 1, 
  WGM10 = 0, 


  COM3A1 = 7, 
  COM3A0 = 6, 
  COM3B1 = 5, 
  COM3B0 = 4, 
  COM3C1 = 3, 
  COM3C0 = 2, 
  WGM31 = 1, 
  WGM30 = 0, 


  ICNC = 7, 
  ICES = 6, 
  WGMB3 = 4, 
  WGMB2 = 3, 
  CSB2 = 2, 
  CSB1 = 1, 
  CSB0 = 0, 


  ICNC1 = 7, 
  ICES1 = 6, 
  WGM13 = 4, 
  WGM12 = 3, 
  CS12 = 2, 
  CS11 = 1, 
  CS10 = 0, 


  ICNC3 = 7, 
  ICES3 = 6, 
  WGM33 = 4, 
  WGM32 = 3, 
  CS32 = 2, 
  CS31 = 1, 
  CS30 = 0, 


  FOCA = 7, 
  FOCB = 6, 
  FOCC = 5, 


  FOC3A = 7, 
  FOC3B = 6, 
  FOC3C = 5, 


  FOC1A = 7, 
  FOC1B = 6, 
  FOC1C = 5, 


  IDRD = 7, 
  OCDR7 = 7, 
  OCDR6 = 6, 
  OCDR5 = 5, 
  OCDR4 = 4, 
  OCDR3 = 3, 
  OCDR2 = 2, 
  OCDR1 = 1, 
  OCDR0 = 0, 


  WDCE = 4, 
  WDE = 3, 
  WDP2 = 2, 
  WDP1 = 1, 
  WDP0 = 0, 


  TSM = 7, 
  ADHSM = 4, 
  ACME = 3, 
  PUD = 2, 
  PSR0 = 1, 
  PSR321 = 0, 


  SPIF = 7, 
  WCOL = 6, 
  SPI2X = 0, 


  SPIE = 7, 
  SPE = 6, 
  DORD = 5, 
  MSTR = 4, 
  CPOL = 3, 
  CPHA = 2, 
  SPR1 = 1, 
  SPR0 = 0, 


  UMSEL = 6, 
  UPM1 = 5, 
  UPM0 = 4, 
  USBS = 3, 
  UCSZ1 = 2, 
  UCSZ0 = 1, 
  UCPOL = 0, 


  UMSEL1 = 6, 
  UPM11 = 5, 
  UPM10 = 4, 
  USBS1 = 3, 
  UCSZ11 = 2, 
  UCSZ10 = 1, 
  UCPOL1 = 0, 


  UMSEL0 = 6, 
  UPM01 = 5, 
  UPM00 = 4, 
  USBS0 = 3, 
  UCSZ01 = 2, 
  UCSZ00 = 1, 
  UCPOL0 = 0, 


  RXC = 7, 
  TXC = 6, 
  UDRE = 5, 
  FE = 4, 
  DOR = 3, 
  UPE = 2, 
  U2X = 1, 
  MPCM = 0, 


  RXC1 = 7, 
  TXC1 = 6, 
  UDRE1 = 5, 
  FE1 = 4, 
  DOR1 = 3, 
  UPE1 = 2, 
  U2X1 = 1, 
  MPCM1 = 0, 


  RXC0 = 7, 
  TXC0 = 6, 
  UDRE0 = 5, 
  FE0 = 4, 
  DOR0 = 3, 
  UPE0 = 2, 
  U2X0 = 1, 
  MPCM0 = 0, 


  RXCIE = 7, 
  TXCIE = 6, 
  UDRIE = 5, 
  RXEN = 4, 
  TXEN = 3, 
  UCSZ = 2, 
  UCSZ2 = 2, 
  RXB8 = 1, 
  TXB8 = 0, 


  RXCIE1 = 7, 
  TXCIE1 = 6, 
  UDRIE1 = 5, 
  RXEN1 = 4, 
  TXEN1 = 3, 
  UCSZ12 = 2, 
  RXB81 = 1, 
  TXB81 = 0, 


  RXCIE0 = 7, 
  TXCIE0 = 6, 
  UDRIE0 = 5, 
  RXEN0 = 4, 
  TXEN0 = 3, 
  UCSZ02 = 2, 
  RXB80 = 1, 
  TXB80 = 0, 


  ACD = 7, 
  ACBG = 6, 
  ACO = 5, 
  ACI = 4, 
  ACIE = 3, 
  ACIC = 2, 
  ACIS1 = 1, 
  ACIS0 = 0, 


  ADEN = 7, 
  ADSC = 6, 
  ADFR = 5, 
  ADIF = 4, 
  ADIE = 3, 
  ADPS2 = 2, 
  ADPS1 = 1, 
  ADPS0 = 0, 


  REFS1 = 7, 
  REFS0 = 6, 
  ADLAR = 5, 
  MUX4 = 4, 
  MUX3 = 3, 
  MUX2 = 2, 
  MUX1 = 1, 
  MUX0 = 0, 


  PA7 = 7, 
  PA6 = 6, 
  PA5 = 5, 
  PA4 = 4, 
  PA3 = 3, 
  PA2 = 2, 
  PA1 = 1, 
  PA0 = 0, 


  DDA7 = 7, 
  DDA6 = 6, 
  DDA5 = 5, 
  DDA4 = 4, 
  DDA3 = 3, 
  DDA2 = 2, 
  DDA1 = 1, 
  DDA0 = 0, 


  PINA7 = 7, 
  PINA6 = 6, 
  PINA5 = 5, 
  PINA4 = 4, 
  PINA3 = 3, 
  PINA2 = 2, 
  PINA1 = 1, 
  PINA0 = 0, 


  PB7 = 7, 
  PB6 = 6, 
  PB5 = 5, 
  PB4 = 4, 
  PB3 = 3, 
  PB2 = 2, 
  PB1 = 1, 
  PB0 = 0, 


  DDB7 = 7, 
  DDB6 = 6, 
  DDB5 = 5, 
  DDB4 = 4, 
  DDB3 = 3, 
  DDB2 = 2, 
  DDB1 = 1, 
  DDB0 = 0, 


  PINB7 = 7, 
  PINB6 = 6, 
  PINB5 = 5, 
  PINB4 = 4, 
  PINB3 = 3, 
  PINB2 = 2, 
  PINB1 = 1, 
  PINB0 = 0, 


  PC7 = 7, 
  PC6 = 6, 
  PC5 = 5, 
  PC4 = 4, 
  PC3 = 3, 
  PC2 = 2, 
  PC1 = 1, 
  PC0 = 0, 


  DDC7 = 7, 
  DDC6 = 6, 
  DDC5 = 5, 
  DDC4 = 4, 
  DDC3 = 3, 
  DDC2 = 2, 
  DDC1 = 1, 
  DDC0 = 0, 


  PINC7 = 7, 
  PINC6 = 6, 
  PINC5 = 5, 
  PINC4 = 4, 
  PINC3 = 3, 
  PINC2 = 2, 
  PINC1 = 1, 
  PINC0 = 0, 


  PD7 = 7, 
  PD6 = 6, 
  PD5 = 5, 
  PD4 = 4, 
  PD3 = 3, 
  PD2 = 2, 
  PD1 = 1, 
  PD0 = 0, 


  DDD7 = 7, 
  DDD6 = 6, 
  DDD5 = 5, 
  DDD4 = 4, 
  DDD3 = 3, 
  DDD2 = 2, 
  DDD1 = 1, 
  DDD0 = 0, 


  PIND7 = 7, 
  PIND6 = 6, 
  PIND5 = 5, 
  PIND4 = 4, 
  PIND3 = 3, 
  PIND2 = 2, 
  PIND1 = 1, 
  PIND0 = 0, 


  PE7 = 7, 
  PE6 = 6, 
  PE5 = 5, 
  PE4 = 4, 
  PE3 = 3, 
  PE2 = 2, 
  PE1 = 1, 
  PE0 = 0, 


  DDE7 = 7, 
  DDE6 = 6, 
  DDE5 = 5, 
  DDE4 = 4, 
  DDE3 = 3, 
  DDE2 = 2, 
  DDE1 = 1, 
  DDE0 = 0, 


  PINE7 = 7, 
  PINE6 = 6, 
  PINE5 = 5, 
  PINE4 = 4, 
  PINE3 = 3, 
  PINE2 = 2, 
  PINE1 = 1, 
  PINE0 = 0, 


  PF7 = 7, 
  PF6 = 6, 
  PF5 = 5, 
  PF4 = 4, 
  PF3 = 3, 
  PF2 = 2, 
  PF1 = 1, 
  PF0 = 0, 


  DDF7 = 7, 
  DDF6 = 6, 
  DDF5 = 5, 
  DDF4 = 4, 
  DDF3 = 3, 
  DDF2 = 2, 
  DDF1 = 1, 
  DDF0 = 0, 


  PINF7 = 7, 
  PINF6 = 6, 
  PINF5 = 5, 
  PINF4 = 4, 
  PINF3 = 3, 
  PINF2 = 2, 
  PINF1 = 1, 
  PINF0 = 0, 


  PG4 = 4, 
  PG3 = 3, 
  PG2 = 2, 
  PG1 = 1, 
  PG0 = 0, 


  DDG4 = 4, 
  DDG3 = 3, 
  DDG2 = 2, 
  DDG1 = 1, 
  DDG0 = 0, 


  PING4 = 4, 
  PING3 = 3, 
  PING2 = 2, 
  PING1 = 1, 
  PING0 = 0
};
# 51 "/root/local/tinyos-2.1.1/tos/chips/atm128/sim/atm128hardware.h"
uint8_t atm128RegFile[1000][0xa0];
#line 85
static __inline void __nesc_enable_interrupt();



static __inline void __nesc_disable_interrupt();




typedef uint8_t __nesc_atomic_t;



#line 97
__inline __nesc_atomic_t 
__nesc_atomic_start(void )  ;








#line 106
__inline void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)  ;
#line 120
typedef uint8_t mcu_power_t  ;





enum __nesc_unnamed4294 {
  ATM128_POWER_IDLE = 0, 
  ATM128_POWER_ADC_NR = 1, 
  ATM128_POWER_EXT_STANDBY = 2, 
  ATM128_POWER_SAVE = 3, 
  ATM128_POWER_STANDBY = 4, 
  ATM128_POWER_DOWN = 5
};
# 43 "/root/local/tinyos-2.1.1/tos/chips/atm128/adc/Atm128Adc.h"
enum __nesc_unnamed4295 {
  ATM128_ADC_VREF_OFF = 0, 
  ATM128_ADC_VREF_AVCC = 1, 
  ATM128_ADC_VREF_RSVD, 
  ATM128_ADC_VREF_2_56 = 3
};


enum __nesc_unnamed4296 {
  ATM128_ADC_RIGHT_ADJUST = 0, 
  ATM128_ADC_LEFT_ADJUST = 1
};



enum __nesc_unnamed4297 {
  ATM128_ADC_SNGL_ADC0 = 0, 
  ATM128_ADC_SNGL_ADC1, 
  ATM128_ADC_SNGL_ADC2, 
  ATM128_ADC_SNGL_ADC3, 
  ATM128_ADC_SNGL_ADC4, 
  ATM128_ADC_SNGL_ADC5, 
  ATM128_ADC_SNGL_ADC6, 
  ATM128_ADC_SNGL_ADC7, 
  ATM128_ADC_DIFF_ADC00_10x, 
  ATM128_ADC_DIFF_ADC10_10x, 
  ATM128_ADC_DIFF_ADC00_200x, 
  ATM128_ADC_DIFF_ADC10_200x, 
  ATM128_ADC_DIFF_ADC22_10x, 
  ATM128_ADC_DIFF_ADC32_10x, 
  ATM128_ADC_DIFF_ADC22_200x, 
  ATM128_ADC_DIFF_ADC32_200x, 
  ATM128_ADC_DIFF_ADC01_1x, 
  ATM128_ADC_DIFF_ADC11_1x, 
  ATM128_ADC_DIFF_ADC21_1x, 
  ATM128_ADC_DIFF_ADC31_1x, 
  ATM128_ADC_DIFF_ADC41_1x, 
  ATM128_ADC_DIFF_ADC51_1x, 
  ATM128_ADC_DIFF_ADC61_1x, 
  ATM128_ADC_DIFF_ADC71_1x, 
  ATM128_ADC_DIFF_ADC02_1x, 
  ATM128_ADC_DIFF_ADC12_1x, 
  ATM128_ADC_DIFF_ADC22_1x, 
  ATM128_ADC_DIFF_ADC32_1x, 
  ATM128_ADC_DIFF_ADC42_1x, 
  ATM128_ADC_DIFF_ADC52_1x, 
  ATM128_ADC_SNGL_1_23, 
  ATM128_ADC_SNGL_GND
};







#line 94
typedef struct __nesc_unnamed4298 {

  uint8_t mux : 5;
  uint8_t adlar : 1;
  uint8_t refs : 2;
} Atm128Admux_t;




enum __nesc_unnamed4299 {
  ATM128_ADC_PRESCALE_2 = 0, 
  ATM128_ADC_PRESCALE_2b, 
  ATM128_ADC_PRESCALE_4, 
  ATM128_ADC_PRESCALE_8, 
  ATM128_ADC_PRESCALE_16, 
  ATM128_ADC_PRESCALE_32, 
  ATM128_ADC_PRESCALE_64, 
  ATM128_ADC_PRESCALE_128, 



  ATM128_ADC_PRESCALE
};


enum __nesc_unnamed4300 {
  ATM128_ADC_ENABLE_OFF = 0, 
  ATM128_ADC_ENABLE_ON
};


enum __nesc_unnamed4301 {
  ATM128_ADC_START_CONVERSION_OFF = 0, 
  ATM128_ADC_START_CONVERSION_ON
};


enum __nesc_unnamed4302 {
  ATM128_ADC_FREE_RUNNING_OFF = 0, 
  ATM128_ADC_FREE_RUNNING_ON
};


enum __nesc_unnamed4303 {
  ATM128_ADC_INT_FLAG_OFF = 0, 
  ATM128_ADC_INT_FLAG_ON
};


enum __nesc_unnamed4304 {
  ATM128_ADC_INT_ENABLE_OFF = 0, 
  ATM128_ADC_INT_ENABLE_ON
};










#line 150
typedef struct __nesc_unnamed4305 {

  uint8_t adps : 3;
  uint8_t adie : 1;
  uint8_t adif : 1;
  uint8_t adfr : 1;
  uint8_t adsc : 1;
  uint8_t aden : 1;
} Atm128Adcsra_t;

typedef uint8_t Atm128_ADCH_t;
typedef uint8_t Atm128_ADCL_t;
# 54 "/root/local/tinyos-2.1.1/tos/platforms/micaz/sim/platform_hardware.h"
enum __nesc_unnamed4306 {
  CHANNEL_RSSI = ATM128_ADC_SNGL_ADC0, 
  CHANNEL_THERMISTOR = ATM128_ADC_SNGL_ADC1, 
  CHANNEL_BATTERY = ATM128_ADC_SNGL_ADC7, 
  CHANNEL_BANDGAP = 30, 
  CHANNEL_GND = 31, 

  ATM128_TIMER0_TICKSPPS = 32768
};
# 41 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMainP.nc"
static void __nesc_nido_initialise(int node);
# 52 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128Timer.h"
enum __nesc_unnamed4307 {
  ATM128_CLK8_OFF = 0x0, 
  ATM128_CLK8_NORMAL = 0x1, 
  ATM128_CLK8_DIVIDE_8 = 0x2, 
  ATM128_CLK8_DIVIDE_32 = 0x3, 
  ATM128_CLK8_DIVIDE_64 = 0x4, 
  ATM128_CLK8_DIVIDE_128 = 0x5, 
  ATM128_CLK8_DIVIDE_256 = 0x6, 
  ATM128_CLK8_DIVIDE_1024 = 0x7
};

enum __nesc_unnamed4308 {
  ATM128_CLK16_OFF = 0x0, 
  ATM128_CLK16_NORMAL = 0x1, 
  ATM128_CLK16_DIVIDE_8 = 0x2, 
  ATM128_CLK16_DIVIDE_64 = 0x3, 
  ATM128_CLK16_DIVIDE_256 = 0x4, 
  ATM128_CLK16_DIVIDE_1024 = 0x5, 
  ATM128_CLK16_EXTERNAL_FALL = 0x6, 
  ATM128_CLK16_EXTERNAL_RISE = 0x7
};


enum __nesc_unnamed4309 {
  AVR_CLOCK_OFF = 0, 
  AVR_CLOCK_ON = 1, 
  AVR_CLOCK_DIVIDE_8 = 2
};


enum __nesc_unnamed4310 {
  ATM128_WAVE8_NORMAL = 0, 
  ATM128_WAVE8_PWM, 
  ATM128_WAVE8_CTC, 
  ATM128_WAVE8_PWM_FAST
};


enum __nesc_unnamed4311 {
  ATM128_COMPARE_OFF = 0, 
  ATM128_COMPARE_TOGGLE, 
  ATM128_COMPARE_CLEAR, 
  ATM128_COMPARE_SET
};
#line 108
#line 98
typedef union __nesc_unnamed4312 {

  uint8_t flat;
  struct __nesc_unnamed4313 {
    uint8_t cs : 3;
    uint8_t wgm1 : 1;
    uint8_t com : 2;
    uint8_t wgm0 : 1;
    uint8_t foc : 1;
  } bits;
} Atm128TimerControl_t;

typedef Atm128TimerControl_t Atm128_TCCR0_t;
typedef uint8_t Atm128_TCNT0_t;
typedef uint8_t Atm128_OCR0_t;

typedef Atm128TimerControl_t Atm128_TCCR2_t;
typedef uint8_t Atm128_TCNT2_t;
typedef uint8_t Atm128_OCR2_t;
#line 130
#line 120
typedef union __nesc_unnamed4314 {

  uint8_t flat;
  struct __nesc_unnamed4315 {
    uint8_t tcr0ub : 1;
    uint8_t ocr0ub : 1;
    uint8_t tcn0ub : 1;
    uint8_t as0 : 1;
    uint8_t rsvd : 4;
  } bits;
} Atm128Assr_t;
#line 146
#line 133
typedef union __nesc_unnamed4316 {

  uint8_t flat;
  struct __nesc_unnamed4317 {
    uint8_t toie0 : 1;
    uint8_t ocie0 : 1;
    uint8_t toie1 : 1;
    uint8_t ocie1b : 1;
    uint8_t ocie1a : 1;
    uint8_t ticie1 : 1;
    uint8_t toie2 : 1;
    uint8_t ocie2 : 1;
  } bits;
} Atm128_TIMSK_t;
#line 163
#line 150
typedef union __nesc_unnamed4318 {

  uint8_t flat;
  struct __nesc_unnamed4319 {
    uint8_t tov0 : 1;
    uint8_t ocf0 : 1;
    uint8_t tov1 : 1;
    uint8_t ocf1b : 1;
    uint8_t ocf1a : 1;
    uint8_t icf1 : 1;
    uint8_t tov2 : 1;
    uint8_t ocf2 : 1;
  } bits;
} Atm128_TIFR_t;
#line 178
#line 167
typedef union __nesc_unnamed4320 {

  uint8_t flat;
  struct __nesc_unnamed4321 {
    uint8_t psr321 : 1;
    uint8_t psr0 : 1;
    uint8_t pud : 1;
    uint8_t acme : 1;
    uint8_t rsvd : 3;
    uint8_t tsm : 1;
  } bits;
} Atm128_SFIOR_t;






enum __nesc_unnamed4322 {
  ATM128_TIMER_COMPARE_NORMAL = 0, 
  ATM128_TIMER_COMPARE_TOGGLE, 
  ATM128_TIMER_COMPARE_CLEAR, 
  ATM128_TIMER_COMPARE_SET
};
#line 202
#line 193
typedef union __nesc_unnamed4323 {

  uint8_t flat;
  struct __nesc_unnamed4324 {
    uint8_t wgm10 : 2;
    uint8_t comC : 2;
    uint8_t comB : 2;
    uint8_t comA : 2;
  } bits;
} Atm128TimerCtrlCompare_t;


typedef Atm128TimerCtrlCompare_t Atm128_TCCR1A_t;


typedef Atm128TimerCtrlCompare_t Atm128_TCCR3A_t;


enum __nesc_unnamed4325 {
  ATM128_WAVE16_NORMAL = 0, 
  ATM128_WAVE16_PWM_8BIT, 
  ATM128_WAVE16_PWM_9BIT, 
  ATM128_WAVE16_PWM_10BIT, 
  ATM128_WAVE16_CTC_COMPARE, 
  ATM128_WAVE16_PWM_FAST_8BIT, 
  ATM128_WAVE16_PWM_FAST_9BIT, 
  ATM128_WAVE16_PWM_FAST_10BIT, 
  ATM128_WAVE16_PWM_CAPTURE_LOW, 
  ATM128_WAVE16_PWM_COMPARE_LOW, 
  ATM128_WAVE16_PWM_CAPTURE_HIGH, 
  ATM128_WAVE16_PWM_COMPARE_HIGH, 
  ATM128_WAVE16_CTC_CAPTURE, 
  ATM128_WAVE16_RESERVED, 
  ATM128_WAVE16_PWM_FAST_CAPTURE, 
  ATM128_WAVE16_PWM_FAST_COMPARE
};
#line 241
#line 231
typedef union __nesc_unnamed4326 {

  uint8_t flat;
  struct __nesc_unnamed4327 {
    uint8_t cs : 3;
    uint8_t wgm32 : 2;
    uint8_t rsvd : 1;
    uint8_t ices1 : 1;
    uint8_t icnc1 : 1;
  } bits;
} Atm128TimerCtrlCapture_t;


typedef Atm128TimerCtrlCapture_t Atm128_TCCR1B_t;


typedef Atm128TimerCtrlCapture_t Atm128_TCCR3B_t;
#line 259
#line 250
typedef union __nesc_unnamed4328 {

  uint8_t flat;
  struct __nesc_unnamed4329 {
    uint8_t rsvd : 5;
    uint8_t focC : 1;
    uint8_t focB : 1;
    uint8_t focA : 1;
  } bits;
} Atm128TimerCtrlClock_t;


typedef Atm128TimerCtrlClock_t Atm128_TCCR1C_t;


typedef Atm128TimerCtrlClock_t Atm128_TCCR3C_t;



typedef uint8_t Atm128_TCNT1H_t;
typedef uint8_t Atm128_TCNT1L_t;
typedef uint8_t Atm128_TCNT3H_t;
typedef uint8_t Atm128_TCNT3L_t;


typedef uint8_t Atm128_OCR1AH_t;
typedef uint8_t Atm128_OCR1AL_t;
typedef uint8_t Atm128_OCR1BH_t;
typedef uint8_t Atm128_OCR1BL_t;
typedef uint8_t Atm128_OCR1CH_t;
typedef uint8_t Atm128_OCR1CL_t;


typedef uint8_t Atm128_OCR3AH_t;
typedef uint8_t Atm128_OCR3AL_t;
typedef uint8_t Atm128_OCR3BH_t;
typedef uint8_t Atm128_OCR3BL_t;
typedef uint8_t Atm128_OCR3CH_t;
typedef uint8_t Atm128_OCR3CL_t;


typedef uint8_t Atm128_ICR1H_t;
typedef uint8_t Atm128_ICR1L_t;
typedef uint8_t Atm128_ICR3H_t;
typedef uint8_t Atm128_ICR3L_t;
#line 309
#line 297
typedef union __nesc_unnamed4330 {

  uint8_t flat;
  struct __nesc_unnamed4331 {
    uint8_t ocie1c : 1;
    uint8_t ocie3c : 1;
    uint8_t toie3 : 1;
    uint8_t ocie3b : 1;
    uint8_t ocie3a : 1;
    uint8_t ticie3 : 1;
    uint8_t rsvd : 2;
  } bits;
} Atm128_ETIMSK_t;
#line 324
#line 312
typedef union __nesc_unnamed4332 {

  uint8_t flat;
  struct __nesc_unnamed4333 {
    uint8_t ocf1c : 1;
    uint8_t ocf3c : 1;
    uint8_t tov3 : 1;
    uint8_t ocf3b : 1;
    uint8_t ocf3a : 1;
    uint8_t icf3 : 1;
    uint8_t rsvd : 2;
  } bits;
} Atm128_ETIFR_t;
typedef uint16_t Node$neighborTable$t;
typedef TMilli Node$RareUpdate$precision_tag;
typedef TMilli Node$ModerateUpdate$precision_tag;
typedef uint16_t Node$sequenceTable$t;
typedef TMilli Node$FrequentUpdate$precision_tag;
typedef uint32_t Node$routingTable$t;
typedef socket_storage_t *Node$TCPTablePTR$t;
typedef TMilli Node$SparseUpdate$precision_tag;
typedef sendInfo PacketHandlerP$Pool$t;
typedef sendInfo *PacketHandlerP$Queue$t;
typedef uint16_t PacketHandlerP$sequenceTable$t;
typedef uint32_t PacketHandlerP$routingTable$t;
typedef TMilli PacketHandlerP$sendTimer$precision_tag;
typedef TMilli /*AlarmCounterMilliP.Atm128AlarmAsyncC*/Atm128AlarmAsyncC$0$precision;
typedef /*AlarmCounterMilliP.Atm128AlarmAsyncC*/Atm128AlarmAsyncC$0$precision /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$precision;
typedef /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$precision /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$precision_tag;
typedef uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type;
typedef /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$precision /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$precision_tag;
typedef uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$size_type;
typedef uint8_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type;
typedef uint8_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$timer_size;
typedef uint8_t HplAtm128Timer0AsyncP$Timer0$timer_size;
typedef uint8_t HplAtm128Timer0AsyncP$Compare$size_type;
typedef TMilli /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$precision_tag;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$precision_tag;
typedef uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$precision_tag;
typedef TMilli /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$precision_tag;
typedef TMilli /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$LocalTime$precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$precision_tag;
typedef uint32_t /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$size_type;
typedef sendInfo */*PacketHandlerC.QueueC*/QueueC$0$queue_t;
typedef /*PacketHandlerC.QueueC*/QueueC$0$queue_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$t;
typedef sendInfo /*PacketHandlerC.PoolC*/PoolC$0$pool_t;
typedef /*PacketHandlerC.PoolC*/PoolC$0$pool_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool_t;
typedef /*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$t;
enum AMQueueP$__nesc_unnamed4334 {
  AMQueueP$NUM_CLIENTS = 1U
};
typedef uint16_t NeighborDiscoveryP$neighborTable$t;
typedef uint16_t LinkStateRoutingP$neighborTable$t;
typedef uint32_t LinkStateRoutingP$routingTable$t;
typedef TMilli TransportP$AttemptConnection$precision_tag;
typedef socket_storage_t *TransportP$TCPTablePTR$t;
typedef uint16_t /*NodeC.neighborTable*/HashmapC$0$t;
typedef /*NodeC.neighborTable*/HashmapC$0$t /*NodeC.neighborTable*/HashmapC$0$Hashmap$t;
typedef uint16_t /*NodeC.sequenceTable*/HashmapC$1$t;
typedef /*NodeC.sequenceTable*/HashmapC$1$t /*NodeC.sequenceTable*/HashmapC$1$Hashmap$t;
typedef uint32_t /*NodeC.routingTable*/HashmapC$2$t;
typedef /*NodeC.routingTable*/HashmapC$2$t /*NodeC.routingTable*/HashmapC$2$Hashmap$t;
typedef socket_storage_t */*NodeC.TCPTablePTR*/HashmapC$3$t;
typedef /*NodeC.TCPTablePTR*/HashmapC$3$t /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$t;
typedef uint16_t RandomMlcgC$SeedInit$parameter;
# 113 "/root/local/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static void Node$SplitControl$startDone(error_t error);
#line 138
static void Node$SplitControl$stopDone(error_t error);
# 60 "/root/local/tinyos-2.1.1/tos/interfaces/Boot.nc"
static void Node$Boot$booted(void );
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void Node$doModerateEvents$runTask(void );
# 83 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void Node$RareUpdate$fired(void );
#line 83
static void Node$ModerateUpdate$fired(void );
# 78 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



Node$Receive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void Node$doSparseEvents$runTask(void );
# 83 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void Node$FrequentUpdate$fired(void );
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void Node$doFrequentEvents$runTask(void );
#line 75
static void Node$doRareEvents$runTask(void );
# 83 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void Node$SparseUpdate$fired(void );
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t PlatformP$Init$init(void );
#line 62
static error_t MotePlatformP$SubInit$default$init(void );
#line 62
static error_t MotePlatformP$PlatformInit$init(void );
# 44 "/root/local/tinyos-2.1.1/tos/interfaces/GeneralIO.nc"
static void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput(void );
#line 41
static void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr(void );
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t MeasureClockC$Init$init(void );
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t SimSchedulerBasicP$TaskBasic$postTask(
# 49 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x4068f1b8);
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void SimSchedulerBasicP$TaskBasic$default$runTask(
# 49 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x4068f1b8);
# 57 "/root/local/tinyos-2.1.1/tos/interfaces/Scheduler.nc"
static void SimSchedulerBasicP$Scheduler$init(void );







static bool SimSchedulerBasicP$Scheduler$runNextTask(void );
# 44 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMote.nc"
static void SimMoteP$SimMote$setEuid(long long int euid);


static int SimMoteP$SimMote$getVariableInfo(char *name, void **ptr, size_t *len);

static void SimMoteP$SimMote$turnOff(void );
#line 48
static void SimMoteP$SimMote$turnOn(void );
#line 43
static long long int SimMoteP$SimMote$getEuid(void );


static bool SimMoteP$SimMote$isOn(void );
#line 45
static long long int SimMoteP$SimMote$getStartTime(void );
# 80 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static error_t TossimActiveMessageC$AMSend$send(
# 47 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408c8a60, 
# 80 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 78 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



TossimActiveMessageC$Snoop$default$receive(
# 49 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408d6b00, 
# 71 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 78 "/root/local/tinyos-2.1.1/tos/interfaces/Packet.nc"
static uint8_t TossimActiveMessageC$Packet$payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


TossimActiveMessageC$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t TossimActiveMessageC$Packet$maxPayloadLength(void );
#line 94
static void TossimActiveMessageC$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 78 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



TossimActiveMessageC$Receive$default$receive(
# 48 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408d6468, 
# 71 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 85 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModel.nc"
static void TossimActiveMessageC$Model$receive(message_t *msg);
#line 76
static void TossimActiveMessageC$Model$sendDone(message_t *msg, error_t error);










static bool TossimActiveMessageC$Model$shouldAck(message_t *msg);
# 68 "/root/local/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
static am_addr_t TossimActiveMessageC$AMPacket$address(void );









static am_addr_t TossimActiveMessageC$AMPacket$destination(
#line 74
message_t * amsg);
#line 103
static void TossimActiveMessageC$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 147
static am_id_t TossimActiveMessageC$AMPacket$type(
#line 143
message_t * amsg);
#line 162
static void TossimActiveMessageC$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
#line 136
static bool TossimActiveMessageC$AMPacket$isForMe(
#line 133
message_t * amsg);
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC$stopDoneTask$runTask(void );
# 57 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModel.nc"
static error_t TossimPacketModelC$Packet$send(int node, message_t *msg, uint8_t len);
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC$sendDoneTask$runTask(void );
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t TossimPacketModelC$Init$init(void );
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC$startDoneTask$runTask(void );
# 104 "/root/local/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static error_t TossimPacketModelC$Control$start(void );
#line 130
static error_t TossimPacketModelC$Control$stop(void );
# 60 "/root/local/tinyos-2.1.1/tos/lib/tossim/GainRadioModel.nc"
static void TossimPacketModelC$GainRadioModel$receive(message_t *msg);
#line 59
static void TossimPacketModelC$GainRadioModel$acked(message_t *msg);

static bool TossimPacketModelC$GainRadioModel$shouldAck(message_t *msg);
#line 48
static void CpmModelC$Model$putOnAirTo(int dest, 
message_t *msg, 
bool ack, 
sim_time_t endTime, 
double gain, 
double reverseGain);


static bool CpmModelC$Model$clearChannel(void );
static void CpmModelC$Model$setPendingTransmission(void );
# 60 "/root/local/tinyos-2.1.1/tos/lib/tossim/ActiveMessageAddressC.nc"
static am_addr_t ActiveMessageAddressC$amAddress(void );
# 50 "/root/local/tinyos-2.1.1/tos/interfaces/ActiveMessageAddress.nc"
static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void );
# 15 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
static void PacketHandlerP$PacketHandler$reply(uint16_t destination);
#line 11
static error_t PacketHandlerP$PacketHandler$send(uint16_t dest, bool updateTTL);
#line 7
static error_t PacketHandlerP$PacketHandler$receive(pack *Packet);

static void PacketHandlerP$PacketHandler$makePack(uint16_t dest, uint8_t protocol, uint8_t *payload);







static void PacketHandlerP$PacketHandler$ageSequenceTable(void );



static bool PacketHandlerP$PacketHandler$containsSrcSeqPair(uint32_t src, uint16_t seq);
static void PacketHandlerP$PacketHandler$processSequence(pack *Package);
#line 5
static void PacketHandlerP$PacketHandler$initialize(void );






static error_t PacketHandlerP$PacketHandler$actuallySend(uint16_t src, uint16_t dest, pack *message);






static void PacketHandlerP$PacketHandler$insertAge(uint32_t src, uint16_t seq, uint16_t age);
static void PacketHandlerP$PacketHandler$decreaseAge(uint32_t key);
#line 8
static bool PacketHandlerP$PacketHandler$isPacketDuplicate(pack *Packet);




static void PacketHandlerP$PacketHandler$postSendTask(void );
static void PacketHandlerP$PacketHandler$createAndSend(uint8_t *payload, uint16_t destination);
# 110 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static void PacketHandlerP$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void PacketHandlerP$sendBufferTask$runTask(void );
# 83 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void PacketHandlerP$sendTimer$fired(void );
# 109 "/root/local/tinyos-2.1.1/tos/lib/timer/Alarm.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow(void );
#line 103
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type t0, /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type dt);
#line 116
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm(void );
#line 73
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop(void );
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init(void );
# 64 "/root/local/tinyos-2.1.1/tos/lib/timer/Counter.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get(void );
# 58 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired(void );
# 70 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Timer.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow(void );
#line 61
static HplAtm128Timer0AsyncP$Timer0$timer_size HplAtm128Timer0AsyncP$Timer0$get(void );
#line 110
static uint8_t HplAtm128Timer0AsyncP$Timer0$getScale(void );
#line 67
static void HplAtm128Timer0AsyncP$Timer0$set(HplAtm128Timer0AsyncP$Timer0$timer_size t);
# 44 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
static int HplAtm128Timer0AsyncP$TimerAsync$compareBusy(void );
#line 32
static void HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous(void );
# 53 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
static Atm128_TIFR_t HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag(void );
#line 46
static void HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(Atm128TimerControl_t control);
# 48 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Compare.nc"
static HplAtm128Timer0AsyncP$Compare$size_type HplAtm128Timer0AsyncP$Compare$get(void );





static void HplAtm128Timer0AsyncP$Compare$set(HplAtm128Timer0AsyncP$Compare$size_type t);










static void HplAtm128Timer0AsyncP$Compare$start(void );
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask(void );
# 78 "/root/local/tinyos-2.1.1/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired(void );
# 136 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow(void );
#line 129
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop(void );
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void );
# 83 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void );
#line 83
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(
# 48 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b7e3a8);
# 92 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static bool /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(
# 48 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b7e3a8);
# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(
# 48 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b7e3a8, 
# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
uint32_t dt);
# 82 "/root/local/tinyos-2.1.1/tos/lib/timer/Counter.nc"
static void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow(void );
# 73 "/root/local/tinyos-2.1.1/tos/interfaces/Queue.nc"
static 
#line 71
/*PacketHandlerC.QueueC*/QueueC$0$Queue$t  

/*PacketHandlerC.QueueC*/QueueC$0$Queue$head(void );
#line 90
static error_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$enqueue(
#line 86
/*PacketHandlerC.QueueC*/QueueC$0$Queue$t  newVal);
#line 65
static uint8_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$maxSize(void );
#line 81
static 
#line 79
/*PacketHandlerC.QueueC*/QueueC$0$Queue$t  

/*PacketHandlerC.QueueC*/QueueC$0$Queue$dequeue(void );
#line 50
static bool /*PacketHandlerC.QueueC*/QueueC$0$Queue$empty(void );







static uint8_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$size(void );
# 97 "/root/local/tinyos-2.1.1/tos/interfaces/Pool.nc"
static 
#line 94
/*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$t * 


/*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$get(void );
#line 61
static bool /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$empty(void );
#line 89
static error_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$put(
#line 85
/*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$t * newVal);
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Init$init(void );
# 80 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static error_t /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/root/local/tinyos-2.1.1/tos/interfaces/Send.nc"
static void /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(
#line 96
message_t * msg, 



error_t error);
# 110 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(
# 48 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40bea498, 
# 103 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/Send.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(
# 46 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40beda98, 
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 100
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(
# 46 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40beda98, 
# 96 "/root/local/tinyos-2.1.1/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void );
#line 75
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void );
# 6 "/root/workspace/Project1/src/lib/interfaces/CommandHandler.nc"
static error_t CommandHandlerP$CommandHandler$receive(pack *Packet);




static void CommandHandlerP$CommandHandler$printLinkState(void );
#line 9
static void CommandHandlerP$CommandHandler$printNeighbors(void );





static void CommandHandlerP$CommandHandler$setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t destPort, uint16_t *transfer);
#line 14
static void CommandHandlerP$CommandHandler$setTestServer(uint8_t listenPort);
#line 5
static void CommandHandlerP$CommandHandler$initialize(void );




static void CommandHandlerP$CommandHandler$printRouteTable(void );
#line 8
static void CommandHandlerP$CommandHandler$ping(uint8_t *payload, uint16_t destination);
# 5 "/root/workspace/Project1/src/lib/interfaces/NeighborDiscovery.nc"
static error_t NeighborDiscoveryP$NeighborDiscovery$receive(pack *Packet);



static void NeighborDiscoveryP$NeighborDiscovery$discoverNeighbors(void );
#line 8
static void NeighborDiscoveryP$NeighborDiscovery$printNeighbors(void );
#line 7
static void NeighborDiscoveryP$NeighborDiscovery$timeOutCheck(void );
#line 6
static void NeighborDiscoveryP$NeighborDiscovery$initialize(void );
# 7 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
static void LinkStateRoutingP$LinkStateRouting$neighborChanged(void );



static void LinkStateRoutingP$LinkStateRouting$insertCostHop(uint32_t src, uint16_t cost, uint16_t hop);
#line 6
static error_t LinkStateRoutingP$LinkStateRouting$receive(pack *Packet);


static void LinkStateRoutingP$LinkStateRouting$calculateRoute(void );





static uint16_t LinkStateRoutingP$LinkStateRouting$getRoutingHop(uint32_t src);

static void LinkStateRoutingP$LinkStateRouting$printLinkState(void );
#line 5
static void LinkStateRoutingP$LinkStateRouting$initialize(void );


static void LinkStateRoutingP$LinkStateRouting$shareLinkState(bool forcedShare);









static void LinkStateRoutingP$LinkStateRouting$printRoutingTable(void );
#line 14
static uint16_t LinkStateRoutingP$LinkStateRouting$getRoutingCost(uint32_t src);
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void LinkStateRoutingP$SendNeighbors$runTask(void );
# 153 "/root/workspace/Project1/src/lib/interfaces/Transport.nc"
static error_t TransportP$Transport$listen(socket_t fd);
#line 32
static void TransportP$Transport$updateHeader(uint32_t connectionKey, uint16_t src, uint8_t srcPort, uint16_t dest, uint8_t destPort);
#line 91
static error_t TransportP$Transport$receive(pack *package);
#line 30
static socket_storage_t *TransportP$Transport$getConnectionState(uint32_t connectionKey);
#line 24
static void TransportP$Transport$setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t transfer);








static void TransportP$Transport$setConnectionState(uint32_t connectionKey, uint8_t state);
#line 55
static error_t TransportP$Transport$bind(socket_t fd, socket_addr_t *addr);
#line 25
static void TransportP$Transport$setTestServer(uint8_t listenPort);
#line 68
static socket_t TransportP$Transport$accept(socket_t fd);
#line 20
static void TransportP$Transport$initialize(void );

static void TransportP$Transport$createAndSend(socket_storage_t *TCPHeader, uint16_t destination);





static void TransportP$Transport$setConnectionPTR(uint32_t connectionKey, uint8_t initialState);
# 83 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void TransportP$AttemptConnection$fired(void );
# 6 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
static /*NodeC.neighborTable*/HashmapC$0$Hashmap$t /*NodeC.neighborTable*/HashmapC$0$Hashmap$get(uint32_t key);
#line 3
static void /*NodeC.neighborTable*/HashmapC$0$Hashmap$insert(uint32_t key, /*NodeC.neighborTable*/HashmapC$0$Hashmap$t input);







static uint32_t */*NodeC.neighborTable*/HashmapC$0$Hashmap$getKeys(void );
#line 8
static bool /*NodeC.neighborTable*/HashmapC$0$Hashmap$contains(uint32_t key);
#line 6
static /*NodeC.sequenceTable*/HashmapC$1$Hashmap$t /*NodeC.sequenceTable*/HashmapC$1$Hashmap$get(uint32_t key);
#line 4
static void /*NodeC.sequenceTable*/HashmapC$1$Hashmap$remove(uint32_t key);
#line 3
static void /*NodeC.sequenceTable*/HashmapC$1$Hashmap$insert(uint32_t key, /*NodeC.sequenceTable*/HashmapC$1$Hashmap$t input);







static uint32_t */*NodeC.sequenceTable*/HashmapC$1$Hashmap$getKeys(void );
#line 8
static bool /*NodeC.sequenceTable*/HashmapC$1$Hashmap$contains(uint32_t key);
#line 5
static void /*NodeC.routingTable*/HashmapC$2$Hashmap$clear(void );
static /*NodeC.routingTable*/HashmapC$2$Hashmap$t /*NodeC.routingTable*/HashmapC$2$Hashmap$get(uint32_t key);
#line 3
static void /*NodeC.routingTable*/HashmapC$2$Hashmap$insert(uint32_t key, /*NodeC.routingTable*/HashmapC$2$Hashmap$t input);







static uint32_t */*NodeC.routingTable*/HashmapC$2$Hashmap$getKeys(void );
#line 8
static bool /*NodeC.routingTable*/HashmapC$2$Hashmap$contains(uint32_t key);
#line 3
static void /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$insert(uint32_t key, /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$t input);




static bool /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$contains(uint32_t key);
#line 7
static uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$getIndex(uint32_t key);
# 52 "/root/local/tinyos-2.1.1/tos/interfaces/Random.nc"
static uint16_t RandomMlcgC$Random$rand16(void );
#line 46
static uint32_t RandomMlcgC$Random$rand32(void );
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t RandomMlcgC$Init$init(void );
# 104 "/root/local/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static error_t Node$SplitControl$start(void );
#line 130
static error_t Node$SplitControl$stop(void );
# 7 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
static error_t Node$PacketHandler$receive(pack *Packet);









static void Node$PacketHandler$ageSequenceTable(void );
#line 5
static void Node$PacketHandler$initialize(void );


static bool Node$PacketHandler$isPacketDuplicate(pack *Packet);
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t Node$doModerateEvents$postTask(void );
# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void Node$RareUpdate$startOneShot(uint32_t dt);
# 6 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
static error_t Node$LinkStateRouting$receive(pack *Packet);


static void Node$LinkStateRouting$calculateRoute(void );
#line 5
static void Node$LinkStateRouting$initialize(void );


static void Node$LinkStateRouting$shareLinkState(bool forcedShare);
# 46 "/root/local/tinyos-2.1.1/tos/interfaces/Random.nc"
static uint32_t Node$Random$rand32(void );
# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void Node$ModerateUpdate$startOneShot(uint32_t dt);
# 91 "/root/workspace/Project1/src/lib/interfaces/Transport.nc"
static error_t Node$Transport$receive(pack *package);
#line 20
static void Node$Transport$initialize(void );
# 5 "/root/workspace/Project1/src/lib/interfaces/NeighborDiscovery.nc"
static error_t Node$NeighborDiscovery$receive(pack *Packet);



static void Node$NeighborDiscovery$discoverNeighbors(void );
#line 7
static void Node$NeighborDiscovery$timeOutCheck(void );
#line 6
static void Node$NeighborDiscovery$initialize(void );
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t Node$doSparseEvents$postTask(void );
# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void Node$FrequentUpdate$startOneShot(uint32_t dt);
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t Node$doFrequentEvents$postTask(void );
#line 67
static error_t Node$doRareEvents$postTask(void );
# 6 "/root/workspace/Project1/src/lib/interfaces/CommandHandler.nc"
static error_t Node$CommandHandler$receive(pack *Packet);
#line 5
static void Node$CommandHandler$initialize(void );
# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void Node$SparseUpdate$startOneShot(uint32_t dt);
# 107 "/root/workspace/Project1/src/Node.nc"
enum Node$__nesc_unnamed4335 {
#line 107
  Node$doFrequentEvents = 0U
};
#line 107
typedef int Node$__nesc_sillytask_doFrequentEvents[Node$doFrequentEvents];






enum Node$__nesc_unnamed4336 {
#line 114
  Node$doModerateEvents = 1U
};
#line 114
typedef int Node$__nesc_sillytask_doModerateEvents[Node$doModerateEvents];







enum Node$__nesc_unnamed4337 {
#line 122
  Node$doSparseEvents = 2U
};
#line 122
typedef int Node$__nesc_sillytask_doSparseEvents[Node$doSparseEvents];






enum Node$__nesc_unnamed4338 {
#line 129
  Node$doRareEvents = 3U
};
#line 129
typedef int Node$__nesc_sillytask_doRareEvents[Node$doRareEvents];
#line 36
uint32_t Node$PeriodFrequent[1000];
uint32_t Node$PeriodModerate[1000];
uint32_t Node$PeriodSparse[1000];
uint32_t Node$PeriodRare[1000];





static inline void Node$Boot$booted(void );
#line 75
static inline message_t *Node$Receive$receive(message_t *msg, void *payload, uint8_t len);
#line 107
static inline void Node$doFrequentEvents$runTask(void );






static inline void Node$doModerateEvents$runTask(void );







static inline void Node$doSparseEvents$runTask(void );






static inline void Node$doRareEvents$runTask(void );








static inline void Node$FrequentUpdate$fired(void );






static inline void Node$ModerateUpdate$fired(void );






static inline void Node$SparseUpdate$fired(void );






static inline void Node$RareUpdate$fired(void );









static inline void Node$SplitControl$startDone(error_t err);
#line 183
static inline void Node$SplitControl$stopDone(error_t err);
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t PlatformP$MoteInit$init(void );
#line 62
static error_t PlatformP$MeasureClock$init(void );
# 51 "/root/local/tinyos-2.1.1/tos/platforms/mica/PlatformP.nc"
static inline error_t PlatformP$Init$init(void );
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t MotePlatformP$SubInit$init(void );
# 44 "/root/local/tinyos-2.1.1/tos/interfaces/GeneralIO.nc"
static void MotePlatformP$SerialIdPin$makeInput(void );
#line 41
static void MotePlatformP$SerialIdPin$clr(void );
# 49 "/root/local/tinyos-2.1.1/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP$PlatformInit$init(void );
#line 61
static inline error_t MotePlatformP$SubInit$default$init(void );
# 59 "/root/local/tinyos-2.1.1/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr(void );


static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput(void );
# 21 "/root/local/tinyos-2.1.1/tos/platforms/mica/sim/MeasureClockC.nc"
static inline error_t MeasureClockC$Init$init(void );
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t SimMainP$SoftwareInit$init(void );
# 60 "/root/local/tinyos-2.1.1/tos/interfaces/Boot.nc"
static void SimMainP$Boot$booted(void );
# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
static error_t SimMainP$PlatformInit$init(void );
# 57 "/root/local/tinyos-2.1.1/tos/interfaces/Scheduler.nc"
static void SimMainP$Scheduler$init(void );







static bool SimMainP$Scheduler$runNextTask(void );
# 51 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMainP.nc"
int sim_main_start_mote(void )   ;
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static void SimSchedulerBasicP$TaskBasic$runTask(
# 49 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x4068f1b8);



enum SimSchedulerBasicP$__nesc_unnamed4339 {

  SimSchedulerBasicP$NUM_TASKS = 13U, 
  SimSchedulerBasicP$NO_TASK = 255
};

uint8_t SimSchedulerBasicP$m_head[1000];
uint8_t SimSchedulerBasicP$m_tail[1000];
uint8_t SimSchedulerBasicP$m_next[1000][SimSchedulerBasicP$NUM_TASKS];




bool SimSchedulerBasicP$sim_scheduler_event_pending[1000];
sim_event_t SimSchedulerBasicP$sim_scheduler_event[1000];

static inline int SimSchedulerBasicP$sim_config_task_latency(void );







static void SimSchedulerBasicP$sim_scheduler_submit_event(void );







static inline void SimSchedulerBasicP$sim_scheduler_event_handle(sim_event_t *e);
#line 103
static inline void SimSchedulerBasicP$sim_scheduler_event_init(sim_event_t *e);
#line 120
static inline uint8_t SimSchedulerBasicP$popTask(void );
#line 139
static inline bool SimSchedulerBasicP$isWaiting(uint8_t id);




static inline bool SimSchedulerBasicP$pushTask(uint8_t id);
#line 166
static inline void SimSchedulerBasicP$Scheduler$init(void );
#line 180
static bool SimSchedulerBasicP$Scheduler$runNextTask(void );
#line 205
static error_t SimSchedulerBasicP$TaskBasic$postTask(uint8_t id);
#line 221
static inline void SimSchedulerBasicP$TaskBasic$default$runTask(uint8_t id);
# 50 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMoteP.nc"
long long int SimMoteP$euid[1000];
long long int SimMoteP$startTime[1000];
bool SimMoteP$isOn[1000];
sim_event_t *SimMoteP$bootEvent[1000];

static inline long long int SimMoteP$SimMote$getEuid(void );


static inline void SimMoteP$SimMote$setEuid(long long int e);


static inline long long int SimMoteP$SimMote$getStartTime(void );


static inline bool SimMoteP$SimMote$isOn(void );



static inline int SimMoteP$SimMote$getVariableInfo(char *name, void **addr, size_t *size);



static void SimMoteP$SimMote$turnOn(void );
#line 85
static inline void SimMoteP$SimMote$turnOff(void );




long long int sim_mote_euid(int mote)   ;








void sim_mote_set_euid(int mote, long long int id)   ;






long long int sim_mote_start_time(int mote)   ;








int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)   ;









void sim_mote_set_start_time(int mote, long long int t)   ;








bool sim_mote_is_on(int mote)   ;








void sim_mote_turn_on(int mote)   ;






void sim_mote_turn_off(int mote)   ;






static inline void SimMoteP$sim_mote_boot_handle(sim_event_t *e);








void sim_mote_enqueue_boot_event(int mote)   ;
# 57 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static am_addr_t TossimActiveMessageC$amAddress(void );
# 110 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static void TossimActiveMessageC$AMSend$sendDone(
# 47 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408c8a60, 
# 103 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 78 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



TossimActiveMessageC$Snoop$receive(
# 49 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408d6b00, 
# 71 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
#line 78
static 
#line 74
message_t * 



TossimActiveMessageC$Receive$receive(
# 48 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408d6468, 
# 71 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 57 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModel.nc"
static error_t TossimActiveMessageC$Model$send(int node, message_t *msg, uint8_t len);
# 62 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
message_t TossimActiveMessageC$buffer[1000];
message_t *TossimActiveMessageC$bufferPointer[1000];

static inline tossim_header_t *TossimActiveMessageC$getHeader(message_t *amsg);







static error_t TossimActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len);
#line 103
static inline void TossimActiveMessageC$Model$sendDone(message_t *msg, error_t result);





static void TossimActiveMessageC$Model$receive(message_t *msg);
#line 127
static inline bool TossimActiveMessageC$Model$shouldAck(message_t *msg);








static inline am_addr_t TossimActiveMessageC$AMPacket$address(void );



static am_addr_t TossimActiveMessageC$AMPacket$destination(message_t *amsg);




static inline void TossimActiveMessageC$AMPacket$setDestination(message_t *amsg, am_addr_t addr);
#line 160
static inline bool TossimActiveMessageC$AMPacket$isForMe(message_t *amsg);




static am_id_t TossimActiveMessageC$AMPacket$type(message_t *amsg);




static inline void TossimActiveMessageC$AMPacket$setType(message_t *amsg, am_id_t t);






static inline uint8_t TossimActiveMessageC$Packet$payloadLength(message_t *msg);



static inline void TossimActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len);



static inline uint8_t TossimActiveMessageC$Packet$maxPayloadLength(void );



static inline void *TossimActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len);
#line 212
static inline message_t *TossimActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);



static inline message_t *TossimActiveMessageC$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);
#line 236
static inline void TossimActiveMessageC$active_message_deliver_handle(sim_event_t *evt);





static inline sim_event_t *TossimActiveMessageC$allocate_deliver_event(int node, message_t *msg, sim_time_t t);
#line 254
void active_message_deliver(int node, message_t *msg, sim_time_t t)   ;
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t TossimPacketModelC$stopDoneTask$postTask(void );
# 85 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModel.nc"
static void TossimPacketModelC$Packet$receive(message_t *msg);
#line 76
static void TossimPacketModelC$Packet$sendDone(message_t *msg, error_t error);










static bool TossimPacketModelC$Packet$shouldAck(message_t *msg);
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t TossimPacketModelC$startDoneTask$postTask(void );
# 113 "/root/local/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
static void TossimPacketModelC$Control$startDone(error_t error);
#line 138
static void TossimPacketModelC$Control$stopDone(error_t error);
# 48 "/root/local/tinyos-2.1.1/tos/lib/tossim/GainRadioModel.nc"
static void TossimPacketModelC$GainRadioModel$putOnAirTo(int dest, 
message_t *msg, 
bool ack, 
sim_time_t endTime, 
double gain, 
double reverseGain);


static bool TossimPacketModelC$GainRadioModel$clearChannel(void );
static void TossimPacketModelC$GainRadioModel$setPendingTransmission(void );
# 96 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
enum TossimPacketModelC$__nesc_unnamed4340 {
#line 96
  TossimPacketModelC$startDoneTask = 4U
};
#line 96
typedef int TossimPacketModelC$__nesc_sillytask_startDoneTask[TossimPacketModelC$startDoneTask];




enum TossimPacketModelC$__nesc_unnamed4341 {
#line 101
  TossimPacketModelC$stopDoneTask = 5U
};
#line 101
typedef int TossimPacketModelC$__nesc_sillytask_stopDoneTask[TossimPacketModelC$stopDoneTask];
#line 145
enum TossimPacketModelC$__nesc_unnamed4342 {
#line 145
  TossimPacketModelC$sendDoneTask = 6U
};
#line 145
typedef int TossimPacketModelC$__nesc_sillytask_sendDoneTask[TossimPacketModelC$sendDoneTask];
#line 70
bool TossimPacketModelC$initialized[1000];
bool TossimPacketModelC$running[1000];
uint8_t TossimPacketModelC$backoffCount[1000];
uint8_t TossimPacketModelC$neededFreeSamples[1000];
message_t *TossimPacketModelC$sending[1000];
bool TossimPacketModelC$transmitting[1000];
uint8_t TossimPacketModelC$sendingLength[1000];
int TossimPacketModelC$destNode[1000];
sim_event_t TossimPacketModelC$sendEvent[1000];



static inline tossim_metadata_t *TossimPacketModelC$getMetadata(message_t *msg);



static inline error_t TossimPacketModelC$Init$init(void );









static inline void TossimPacketModelC$startDoneTask$runTask(void );




static inline void TossimPacketModelC$stopDoneTask$runTask(void );




static error_t TossimPacketModelC$Control$start(void );








static inline error_t TossimPacketModelC$Control$stop(void );
#line 145
static inline void TossimPacketModelC$sendDoneTask$runTask(void );
#line 159
static inline void TossimPacketModelC$start_csma(void );

static inline error_t TossimPacketModelC$Packet$send(int dest, message_t *msg, uint8_t len);
#line 183
static inline void TossimPacketModelC$send_backoff(sim_event_t *evt);
static inline void TossimPacketModelC$send_transmit(sim_event_t *evt);
static inline void TossimPacketModelC$send_transmit_done(sim_event_t *evt);

static inline void TossimPacketModelC$start_csma(void );
#line 211
static inline void TossimPacketModelC$send_backoff(sim_event_t *evt);
#line 253
static inline void TossimPacketModelC$send_transmit(sim_event_t *evt);
#line 280
static inline void TossimPacketModelC$send_transmit_done(sim_event_t *evt);







static inline void TossimPacketModelC$GainRadioModel$receive(message_t *msg);





uint8_t TossimPacketModelC$error[1000];

static inline void TossimPacketModelC$GainRadioModel$acked(message_t *msg);










static bool TossimPacketModelC$GainRadioModel$shouldAck(message_t *msg);
# 60 "/root/local/tinyos-2.1.1/tos/lib/tossim/GainRadioModel.nc"
static void CpmModelC$Model$receive(message_t *msg);
#line 59
static void CpmModelC$Model$acked(message_t *msg);

static bool CpmModelC$Model$shouldAck(message_t *msg);
# 58 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
message_t *CpmModelC$outgoing[1000];
bool CpmModelC$requestAck[1000];
bool CpmModelC$receiving[1000];
bool CpmModelC$transmitting[1000];
sim_time_t CpmModelC$transmissionEndTime[1000];
struct CpmModelC$receive_message;
typedef struct CpmModelC$receive_message CpmModelC$receive_message_t;

struct CpmModelC$receive_message {
  int source;
  sim_time_t start;
  sim_time_t end;
  double power;
  double reversePower;
  int8_t strength;
  bool lost;
  bool ack;
  message_t *msg;
  CpmModelC$receive_message_t *next;
};

CpmModelC$receive_message_t *CpmModelC$outstandingReceptionHead[1000];

static inline CpmModelC$receive_message_t *CpmModelC$allocate_receive_message(void );
static inline void CpmModelC$free_receive_message(CpmModelC$receive_message_t *msg);
static inline sim_event_t *CpmModelC$allocate_receive_event(sim_time_t t, CpmModelC$receive_message_t *m);

static bool CpmModelC$shouldReceive(double SNR);
static inline bool CpmModelC$checkReceive(CpmModelC$receive_message_t *msg);
static double CpmModelC$packetNoise(CpmModelC$receive_message_t *msg);


static inline double CpmModelC$timeInMs(void );
#line 126
static double CpmModelC$noise_hash_generation(void );
#line 151
static inline double CpmModelC$arr_estimate_from_snr(double SNR);
#line 166
static inline int CpmModelC$shouldAckReceive(double snr);
#line 178
static inline void CpmModelC$sim_gain_ack_handle(sim_event_t *evt);
#line 200
double CpmModelC$clearThreshold[1000];










static inline bool CpmModelC$Model$clearChannel(void );




static void CpmModelC$sim_gain_schedule_ack(int source, sim_time_t t, CpmModelC$receive_message_t *r);
#line 230
static inline double CpmModelC$prr_estimate_from_snr(double SNR);
#line 248
static bool CpmModelC$shouldReceive(double SNR);
#line 260
static inline bool CpmModelC$checkReceive(CpmModelC$receive_message_t *msg);
#line 274
static double CpmModelC$packetNoise(CpmModelC$receive_message_t *msg);
#line 296
static inline void CpmModelC$sim_gain_receive_handle(sim_event_t *evt);
#line 369
static inline void CpmModelC$enqueue_receive_event(int source, sim_time_t endTime, message_t *msg, bool receive, double power, double reversePower);
#line 428
static inline void CpmModelC$sim_gain_put(int dest, message_t *msg, sim_time_t endTime, bool receive, double power, double reversePower);







static inline void CpmModelC$Model$putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double power, double reversePower);
#line 459
static inline void CpmModelC$Model$setPendingTransmission(void );







static inline sim_event_t *CpmModelC$allocate_receive_event(sim_time_t endTime, CpmModelC$receive_message_t *msg);
#line 479
static inline CpmModelC$receive_message_t *CpmModelC$allocate_receive_message(void );



static inline void CpmModelC$free_receive_message(CpmModelC$receive_message_t *msg);
# 65 "/root/local/tinyos-2.1.1/tos/lib/tossim/ActiveMessageAddressC.nc"
bool ActiveMessageAddressC$set[1000];
am_addr_t ActiveMessageAddressC$addr[1000];









static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void );
#line 88
static inline am_addr_t ActiveMessageAddressC$amAddress(void );
# 97 "/root/local/tinyos-2.1.1/tos/interfaces/Pool.nc"
static 
#line 94
PacketHandlerP$Pool$t * 


PacketHandlerP$Pool$get(void );
#line 61
static bool PacketHandlerP$Pool$empty(void );
#line 89
static error_t PacketHandlerP$Pool$put(
#line 85
PacketHandlerP$Pool$t * newVal);
# 80 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static error_t PacketHandlerP$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 126 "/root/local/tinyos-2.1.1/tos/interfaces/Packet.nc"
static 
#line 123
void * 


PacketHandlerP$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
# 52 "/root/local/tinyos-2.1.1/tos/interfaces/Random.nc"
static uint16_t PacketHandlerP$Random$rand16(void );
# 73 "/root/local/tinyos-2.1.1/tos/interfaces/Queue.nc"
static 
#line 71
PacketHandlerP$Queue$t  

PacketHandlerP$Queue$head(void );
#line 90
static error_t PacketHandlerP$Queue$enqueue(
#line 86
PacketHandlerP$Queue$t  newVal);
#line 81
static 
#line 79
PacketHandlerP$Queue$t  

PacketHandlerP$Queue$dequeue(void );
#line 50
static bool PacketHandlerP$Queue$empty(void );
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t PacketHandlerP$sendBufferTask$postTask(void );
# 6 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
static PacketHandlerP$sequenceTable$t PacketHandlerP$sequenceTable$get(uint32_t key);
#line 4
static void PacketHandlerP$sequenceTable$remove(uint32_t key);
#line 3
static void PacketHandlerP$sequenceTable$insert(uint32_t key, PacketHandlerP$sequenceTable$t input);







static uint32_t *PacketHandlerP$sequenceTable$getKeys(void );
#line 8
static bool PacketHandlerP$sequenceTable$contains(uint32_t key);
#line 6
static PacketHandlerP$routingTable$t PacketHandlerP$routingTable$get(uint32_t key);

static bool PacketHandlerP$routingTable$contains(uint32_t key);
# 92 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static bool PacketHandlerP$sendTimer$isRunning(void );
#line 73
static void PacketHandlerP$sendTimer$startOneShot(uint32_t dt);
# 257 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
enum PacketHandlerP$__nesc_unnamed4343 {
#line 257
  PacketHandlerP$sendBufferTask = 7U
};
#line 257
typedef int PacketHandlerP$__nesc_sillytask_sendBufferTask[PacketHandlerP$sendBufferTask];
#line 25
pack PacketHandlerP$sendPackage[1000];
uint8_t PacketHandlerP$pingPacket[1000][PACKET_MAX_PAYLOAD_SIZE8];

uint16_t PacketHandlerP$SEQUENCE_NUM[1000];
bool PacketHandlerP$busy[1000];
message_t PacketHandlerP$pkt[1000];

static inline void PacketHandlerP$PacketHandler$initialize(void );
#line 48
static inline void PacketHandlerP$PacketHandler$insertAge(uint32_t src, uint16_t seq, uint16_t age);






static inline void PacketHandlerP$PacketHandler$decreaseAge(uint32_t key);
#line 70
static inline bool PacketHandlerP$PacketHandler$containsSrcSeqPair(uint32_t src, uint16_t seq);






static void PacketHandlerP$PacketHandler$processSequence(pack *Package);







static void PacketHandlerP$PacketHandler$ageSequenceTable(void );
#line 109
static inline error_t PacketHandlerP$PacketHandler$receive(pack *Package);
#line 156
static inline bool PacketHandlerP$PacketHandler$isPacketDuplicate(pack *Package);
#line 168
static void PacketHandlerP$PacketHandler$makePack(uint16_t dest, uint8_t protocol, uint8_t *payload);
#line 188
static inline void PacketHandlerP$PacketHandler$createAndSend(uint8_t *payload, uint16_t destination);







static inline void PacketHandlerP$PacketHandler$reply(uint16_t destination);







static void PacketHandlerP$PacketHandler$postSendTask(void );








static error_t PacketHandlerP$PacketHandler$send(uint16_t dest, bool updateTTL);
#line 257
static inline void PacketHandlerP$sendBufferTask$runTask(void );
#line 280
static inline void PacketHandlerP$sendTimer$fired(void );





static inline error_t PacketHandlerP$PacketHandler$actuallySend(uint16_t src, uint16_t dest, pack *message);
#line 310
static inline void PacketHandlerP$AMSend$sendDone(message_t *msg, error_t error);
# 53 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
static Atm128_TIFR_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag(void );
#line 46
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$setControl(Atm128TimerControl_t control);
# 78 "/root/local/tinyos-2.1.1/tos/lib/timer/Alarm.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$fired(void );
# 82 "/root/local/tinyos-2.1.1/tos/lib/timer/Counter.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$overflow(void );
# 44 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
static int /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$compareBusy(void );
#line 32
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$setTimer0Asynchronous(void );
# 48 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Compare.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get(void );





static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type t);










static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$start(void );
# 61 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Timer.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$timer_size /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get(void );
# 38 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
uint8_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[1000];
uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[1000];
#line 39
uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[1000];
uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[1000];



enum /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$__nesc_unnamed4344 {
  Atm128AlarmAsyncP$0$MINDT = 2, 
  Atm128AlarmAsyncP$0$MAXT = 230
};



static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt(void );


static inline error_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init(void );
#line 74
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setOcr0(uint8_t n);
#line 90
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt(void );
#line 149
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired(void );
#line 161
static uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get(void );
#line 204
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop(void );







static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(uint32_t nt0, uint32_t ndt);









static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow(void );



static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm(void );



static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow(void );
# 70 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Timer.nc"
static void HplAtm128Timer0AsyncP$Timer0$overflow(void );
# 58 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void HplAtm128Timer0AsyncP$Compare$fired(void );
# 57 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
bool HplAtm128Timer0AsyncP$inOverflow[1000];




static inline void HplAtm128Timer0AsyncP$cancel_overflow(void );
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_overflow(void );
static void HplAtm128Timer0AsyncP$configure_overflow(sim_event_t *e);
static inline void HplAtm128Timer0AsyncP$schedule_new_overflow(void );

static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t);
static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t);
static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void );




sim_time_t HplAtm128Timer0AsyncP$lastZero[1000];





uint8_t HplAtm128Timer0AsyncP$oldScale[1000];



static inline void HplAtm128Timer0AsyncP$cancel_compare(void );
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_compare(void );
static void HplAtm128Timer0AsyncP$configure_compare(sim_event_t *e);
static void HplAtm128Timer0AsyncP$schedule_new_compare(void );

static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t);
static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t);
static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void );


void INTERRUPT_15(void )   ;





void INTERRUPT_16(void )   ;







static sim_time_t HplAtm128Timer0AsyncP$last_zero(void );







static inline void HplAtm128Timer0AsyncP$notify_changed(void );










static inline sim_time_t HplAtm128Timer0AsyncP$notify_clockTicksPerSec(void );
#line 148
static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t);





static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t);





static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void );
#line 185
sim_event_t *HplAtm128Timer0AsyncP$compare[1000];

static inline void HplAtm128Timer0AsyncP$timer0_compare_handle(sim_event_t *evt);
#line 223
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_compare(void );







static void HplAtm128Timer0AsyncP$configure_compare(sim_event_t *evt);
#line 267
static void HplAtm128Timer0AsyncP$schedule_new_compare(void );
#line 282
static uint8_t HplAtm128Timer0AsyncP$Timer0$get(void );
#line 297
static inline void HplAtm128Timer0AsyncP$Timer0$set(uint8_t newVal);
#line 321
static uint8_t HplAtm128Timer0AsyncP$Timer0$getScale(void );
#line 364
static inline void HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(Atm128TimerControl_t x);
#line 383
static Atm128_TIFR_t HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag(void );
#line 447
static inline void HplAtm128Timer0AsyncP$Compare$start(void );









static uint8_t HplAtm128Timer0AsyncP$Compare$get(void );





static void HplAtm128Timer0AsyncP$Compare$set(uint8_t t);
#line 480
sim_event_t *HplAtm128Timer0AsyncP$overflow[1000];
static inline void HplAtm128Timer0AsyncP$timer0_overflow_handle(sim_event_t *evt);
#line 500
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_overflow(void );







static void HplAtm128Timer0AsyncP$configure_overflow(sim_event_t *evt);
#line 534
static inline void HplAtm128Timer0AsyncP$schedule_new_overflow(void );










static inline void HplAtm128Timer0AsyncP$cancel_overflow(void );
#line 561
static inline void HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous(void );







static inline int HplAtm128Timer0AsyncP$TimerAsync$compareBusy(void );







static inline void HplAtm128Timer0AsyncP$cancel_compare(void );
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$postTask(void );
# 109 "/root/local/tinyos-2.1.1/tos/lib/timer/Alarm.nc"
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getNow(void );
#line 103
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type dt);
#line 116
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getAlarm(void );
#line 73
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$stop(void );
# 83 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$fired(void );
# 74 "/root/local/tinyos-2.1.1/tos/lib/timer/AlarmToTimerC.nc"
enum /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$__nesc_unnamed4345 {
#line 74
  AlarmToTimerC$0$fired = 8U
};
#line 74
typedef int /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$__nesc_sillytask_fired[/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired];
#line 55
uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[1000];
bool /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[1000];

static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(uint32_t t0, uint32_t dt, bool oneshot);
#line 71
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop(void );


static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask(void );






static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired(void );
#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(uint32_t t0, uint32_t dt);


static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow(void );
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask(void );
# 136 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(void );
#line 129
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(
# 48 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b7e3a8);
#line 71
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4346 {
#line 71
  VirtualizeTimerC$0$updateFromTimer = 9U
};
#line 71
typedef int /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_sillytask_updateFromTimer[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer];
#line 53
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4347 {

  VirtualizeTimerC$0$NUM_TIMERS = 7U, 
  VirtualizeTimerC$0$END_OF_LIST = 255
};








#line 59
typedef struct /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4348 {

  uint32_t t0;
  uint32_t dt;
  bool isoneshot : 1;
  bool isrunning : 1;
  bool _reserved : 6;
} /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t;

/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[1000][/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS];




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(uint32_t now);
#line 100
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void );
#line 139
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot);
#line 159
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(uint8_t num, uint32_t dt);









static inline bool /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(uint8_t num);
#line 204
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(uint8_t num);
# 58 "/root/local/tinyos-2.1.1/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow(void );
# 48 "/root/local/tinyos-2.1.1/tos/system/QueueC.nc"
/*PacketHandlerC.QueueC*/QueueC$0$queue_t  /*PacketHandlerC.QueueC*/QueueC$0$queue[1000][20];
uint8_t /*PacketHandlerC.QueueC*/QueueC$0$head[1000];
uint8_t /*PacketHandlerC.QueueC*/QueueC$0$tail[1000];
uint8_t /*PacketHandlerC.QueueC*/QueueC$0$size[1000];

static inline bool /*PacketHandlerC.QueueC*/QueueC$0$Queue$empty(void );



static inline uint8_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$size(void );



static inline uint8_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$maxSize(void );



static inline /*PacketHandlerC.QueueC*/QueueC$0$queue_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$head(void );



static void /*PacketHandlerC.QueueC*/QueueC$0$printQueue(void );
#line 85
static inline /*PacketHandlerC.QueueC*/QueueC$0$queue_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$dequeue(void );
#line 97
static inline error_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$enqueue(/*PacketHandlerC.QueueC*/QueueC$0$queue_t newVal);
# 60 "/root/local/tinyos-2.1.1/tos/system/PoolP.nc"
uint8_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[1000];
uint8_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[1000];
/*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool_t * /*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue[1000][20];
/*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool[1000][20];

static inline error_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Init$init(void );









static inline bool /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$empty(void );
#line 88
static inline /*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool_t */*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$get(void );
#line 103
static inline error_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$put(/*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool_t *newVal);
# 110 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static void /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/root/local/tinyos-2.1.1/tos/interfaces/Send.nc"
static error_t /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(
#line 67
message_t * msg, 







uint8_t len);
# 103 "/root/local/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
static void /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 162
static void /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
# 53 "/root/local/tinyos-2.1.1/tos/system/AMQueueEntryP.nc"
static inline error_t /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline void /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err);
# 80 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(
# 48 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40bea498, 
# 80 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/root/local/tinyos-2.1.1/tos/interfaces/Send.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(
# 46 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40beda98, 
# 96 "/root/local/tinyos-2.1.1/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 78 "/root/local/tinyos-2.1.1/tos/interfaces/Packet.nc"
static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(
#line 74
message_t * msg);
#line 94
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void );
# 78 "/root/local/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(
#line 74
message_t * amsg);
#line 147
static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(
#line 143
message_t * amsg);
# 126 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4349 {
#line 126
  AMQueueImplP$0$CancelTask = 10U
};
#line 126
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_sillytask_CancelTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask];
#line 169
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4350 {
#line 169
  AMQueueImplP$0$errorTask = 11U
};
#line 169
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_sillytask_errorTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask];
#line 57
#line 55
typedef struct /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4351 {
  message_t * msg;
} /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t;

uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[1000];
/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[1000][1];
uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[1000][1 / 8 + 1];

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void );

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void );
#line 90
static inline error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len);
#line 126
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void );
#line 163
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(uint8_t last, message_t * msg, error_t err);





static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void );




static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void );
#line 189
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err);
#line 215
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err);
# 14 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
static void CommandHandlerP$PacketHandler$createAndSend(uint8_t *payload, uint16_t destination);
# 17 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
static void CommandHandlerP$LinkStateRouting$printLinkState(void );
static void CommandHandlerP$LinkStateRouting$printRoutingTable(void );
# 24 "/root/workspace/Project1/src/lib/interfaces/Transport.nc"
static void CommandHandlerP$Transport$setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t transfer);
static void CommandHandlerP$Transport$setTestServer(uint8_t listenPort);
# 8 "/root/workspace/Project1/src/lib/interfaces/NeighborDiscovery.nc"
static void CommandHandlerP$NeighborDiscovery$printNeighbors(void );
# 16 "/root/workspace/Project1/src/lib/modules/CommandHandlerP.nc"
static inline void CommandHandlerP$CommandHandler$initialize(void );





static inline error_t CommandHandlerP$CommandHandler$receive(pack *Packet);
#line 80
static inline void CommandHandlerP$CommandHandler$ping(uint8_t *payload, uint16_t destination);





static inline void CommandHandlerP$CommandHandler$printNeighbors(void );





static inline void CommandHandlerP$CommandHandler$printRouteTable(void );






static inline void CommandHandlerP$CommandHandler$printLinkState(void );
#line 111
static inline void CommandHandlerP$CommandHandler$setTestServer(uint8_t listenPort);





static inline void CommandHandlerP$CommandHandler$setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t *transfer);
# 11 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
static error_t NeighborDiscoveryP$PacketHandler$send(uint16_t dest, bool updateTTL);
#line 9
static void NeighborDiscoveryP$PacketHandler$makePack(uint16_t dest, uint8_t protocol, uint8_t *payload);
# 6 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
static NeighborDiscoveryP$neighborTable$t NeighborDiscoveryP$neighborTable$get(uint32_t key);
#line 3
static void NeighborDiscoveryP$neighborTable$insert(uint32_t key, NeighborDiscoveryP$neighborTable$t input);







static uint32_t *NeighborDiscoveryP$neighborTable$getKeys(void );
#line 8
static bool NeighborDiscoveryP$neighborTable$contains(uint32_t key);
# 7 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
static void NeighborDiscoveryP$LinkStateRouting$neighborChanged(void );
# 18 "/root/workspace/Project1/src/lib/modules/NeighborDiscoveryP.nc"
uint8_t NeighborDiscoveryP$pingPacket[1000][PACKET_MAX_PAYLOAD_SIZE8];
bool NeighborDiscoveryP$TimeOutState[1000];

static inline void NeighborDiscoveryP$NeighborDiscovery$initialize(void );





static inline void NeighborDiscoveryP$NeighborDiscovery$discoverNeighbors(void );






static inline error_t NeighborDiscoveryP$NeighborDiscovery$receive(pack *Packet);
#line 88
static inline void NeighborDiscoveryP$NeighborDiscovery$timeOutCheck(void );
#line 142
static inline void NeighborDiscoveryP$NeighborDiscovery$printNeighbors(void );
# 11 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
static error_t LinkStateRoutingP$PacketHandler$send(uint16_t dest, bool updateTTL);
#line 9
static void LinkStateRoutingP$PacketHandler$makePack(uint16_t dest, uint8_t protocol, uint8_t *payload);
# 6 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
static LinkStateRoutingP$neighborTable$t LinkStateRoutingP$neighborTable$get(uint32_t key);




static uint32_t *LinkStateRoutingP$neighborTable$getKeys(void );
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
static error_t LinkStateRoutingP$SendNeighbors$postTask(void );
# 5 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
static void LinkStateRoutingP$routingTable$clear(void );
static LinkStateRoutingP$routingTable$t LinkStateRoutingP$routingTable$get(uint32_t key);
#line 3
static void LinkStateRoutingP$routingTable$insert(uint32_t key, LinkStateRoutingP$routingTable$t input);







static uint32_t *LinkStateRoutingP$routingTable$getKeys(void );
#line 8
static bool LinkStateRoutingP$routingTable$contains(uint32_t key);
# 254 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
enum LinkStateRoutingP$__nesc_unnamed4352 {
#line 254
  LinkStateRoutingP$SendNeighbors = 12U
};
#line 254
typedef int LinkStateRoutingP$__nesc_sillytask_SendNeighbors[LinkStateRoutingP$SendNeighbors];
#line 18
uint8_t LinkStateRoutingP$linkStatePacket[1000][PACKET_MAX_PAYLOAD_SIZE8];

uint16_t LinkStateRoutingP$linkStates[1000][ROUTING_TABLE_SIZE][ROUTING_TABLE_SIZE];
uint16_t LinkStateRoutingP$compareBuffer[1000][ROUTING_TABLE_SIZE];
uint16_t LinkStateRoutingP$hopThrough[1000][ROUTING_TABLE_SIZE];
bool LinkStateRoutingP$unconsidered[1000][ROUTING_TABLE_SIZE];
bool LinkStateRoutingP$existing[1000][ROUTING_TABLE_SIZE];

bool LinkStateRoutingP$NeighborsChanged[1000];
bool LinkStateRoutingP$LSChanged[1000];

static inline void LinkStateRoutingP$LinkStateRouting$initialize(void );
#line 41
static inline void LinkStateRoutingP$LinkStateRouting$neighborChanged(void );





static inline void LinkStateRoutingP$LinkStateRouting$insertCostHop(uint32_t src, uint16_t cost, uint16_t hop);
#line 71
static inline uint16_t LinkStateRoutingP$LinkStateRouting$getRoutingCost(uint32_t src);





static inline uint16_t LinkStateRoutingP$LinkStateRouting$getRoutingHop(uint32_t src);





static inline void LinkStateRoutingP$LinkStateRouting$calculateRoute(void );
#line 254
static inline void LinkStateRoutingP$SendNeighbors$runTask(void );
#line 266
static void LinkStateRoutingP$LinkStateRouting$shareLinkState(bool forcedShare);
#line 333
static inline error_t LinkStateRoutingP$LinkStateRouting$receive(pack *Packet);
#line 390
static void LinkStateRoutingP$LinkStateRouting$printLinkState(void );
#line 407
static inline void LinkStateRoutingP$LinkStateRouting$printRoutingTable(void );
# 11 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
static error_t TransportP$PacketHandler$send(uint16_t dest, bool updateTTL);
#line 9
static void TransportP$PacketHandler$makePack(uint16_t dest, uint8_t protocol, uint8_t *payload);
# 46 "/root/local/tinyos-2.1.1/tos/interfaces/Random.nc"
static uint32_t TransportP$Random$rand32(void );
# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void TransportP$AttemptConnection$startOneShot(uint32_t dt);
# 3 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
static void TransportP$TCPTablePTR$insert(uint32_t key, TransportP$TCPTablePTR$t input);




static bool TransportP$TCPTablePTR$contains(uint32_t key);
#line 7
static uint32_t TransportP$TCPTablePTR$getIndex(uint32_t key);
# 18 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
socket_storage_t TransportP$TCPTable[1000][TOTAL_PORTS];


uint32_t TransportP$Attempt_Connection_Time[1000];

static inline void TransportP$Transport$initialize(void );









static inline socket_storage_t *TransportP$Transport$getConnectionState(uint32_t connectionKey);







static inline void TransportP$Transport$updateHeader(uint32_t connectionKey, uint16_t src, uint8_t srcPort, uint16_t dest, uint8_t destPort);
#line 55
static inline void TransportP$Transport$setConnectionState(uint32_t connectionKey, uint8_t state);








static void TransportP$Transport$setConnectionPTR(uint32_t connectionKey, uint8_t initialState);
#line 82
static inline void TransportP$Transport$createAndSend(socket_storage_t *TCPHeader, uint16_t destination);
#line 110
static inline void TransportP$Transport$setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t transfer);
#line 131
static inline void TransportP$Transport$setTestServer(uint8_t listenPort);
#line 152
static inline void TransportP$AttemptConnection$fired(void );
#line 166
static inline error_t TransportP$Transport$receive(pack *Packet);
#line 216
static inline error_t TransportP$Transport$bind(socket_t fd, socket_addr_t *addr);
#line 236
static inline socket_t TransportP$Transport$accept(socket_t fd);
#line 272
static inline error_t TransportP$Transport$listen(socket_t fd);
# 8 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
uint16_t /*NodeC.neighborTable*/HashmapC$0$HASH_MAX_SIZE[1000];





#line 10
typedef struct /*NodeC.neighborTable*/HashmapC$0$hashmapEntry {

  uint32_t key;
  /*NodeC.neighborTable*/HashmapC$0$t value;
} /*NodeC.neighborTable*/HashmapC$0$hashmapEntry;

/*NodeC.neighborTable*/HashmapC$0$hashmapEntry /*NodeC.neighborTable*/HashmapC$0$map[1000][20];
uint32_t /*NodeC.neighborTable*/HashmapC$0$keys[1000][20];
uint16_t /*NodeC.neighborTable*/HashmapC$0$numofVals[1000];


static inline uint32_t /*NodeC.neighborTable*/HashmapC$0$hash2(uint32_t k);




static inline uint32_t /*NodeC.neighborTable*/HashmapC$0$hash3(uint32_t k);




static inline uint32_t /*NodeC.neighborTable*/HashmapC$0$hash(uint32_t k, uint32_t i);




static void /*NodeC.neighborTable*/HashmapC$0$Hashmap$insert(uint32_t k, /*NodeC.neighborTable*/HashmapC$0$t input);
#line 121
static /*NodeC.neighborTable*/HashmapC$0$t /*NodeC.neighborTable*/HashmapC$0$Hashmap$get(uint32_t k);
#line 159
static inline bool /*NodeC.neighborTable*/HashmapC$0$Hashmap$contains(uint32_t k);
#line 184
static inline uint32_t */*NodeC.neighborTable*/HashmapC$0$Hashmap$getKeys(void );
#line 8
uint16_t /*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[1000];





#line 10
typedef struct /*NodeC.sequenceTable*/HashmapC$1$hashmapEntry {

  uint32_t key;
  /*NodeC.sequenceTable*/HashmapC$1$t value;
} /*NodeC.sequenceTable*/HashmapC$1$hashmapEntry;

/*NodeC.sequenceTable*/HashmapC$1$hashmapEntry /*NodeC.sequenceTable*/HashmapC$1$map[1000][192];
uint32_t /*NodeC.sequenceTable*/HashmapC$1$keys[1000][192];
uint16_t /*NodeC.sequenceTable*/HashmapC$1$numofVals[1000];


static inline uint32_t /*NodeC.sequenceTable*/HashmapC$1$hash2(uint32_t k);




static inline uint32_t /*NodeC.sequenceTable*/HashmapC$1$hash3(uint32_t k);




static inline uint32_t /*NodeC.sequenceTable*/HashmapC$1$hash(uint32_t k, uint32_t i);




static void /*NodeC.sequenceTable*/HashmapC$1$Hashmap$insert(uint32_t k, /*NodeC.sequenceTable*/HashmapC$1$t input);
#line 77
static inline void /*NodeC.sequenceTable*/HashmapC$1$Hashmap$remove(uint32_t k);
#line 121
static inline /*NodeC.sequenceTable*/HashmapC$1$t /*NodeC.sequenceTable*/HashmapC$1$Hashmap$get(uint32_t k);
#line 159
static inline bool /*NodeC.sequenceTable*/HashmapC$1$Hashmap$contains(uint32_t k);
#line 184
static inline uint32_t */*NodeC.sequenceTable*/HashmapC$1$Hashmap$getKeys(void );
#line 8
uint16_t /*NodeC.routingTable*/HashmapC$2$HASH_MAX_SIZE[1000];





#line 10
typedef struct /*NodeC.routingTable*/HashmapC$2$hashmapEntry {

  uint32_t key;
  /*NodeC.routingTable*/HashmapC$2$t value;
} /*NodeC.routingTable*/HashmapC$2$hashmapEntry;

/*NodeC.routingTable*/HashmapC$2$hashmapEntry /*NodeC.routingTable*/HashmapC$2$map[1000][32];
uint32_t /*NodeC.routingTable*/HashmapC$2$keys[1000][32];
uint16_t /*NodeC.routingTable*/HashmapC$2$numofVals[1000];


static inline uint32_t /*NodeC.routingTable*/HashmapC$2$hash2(uint32_t k);




static inline uint32_t /*NodeC.routingTable*/HashmapC$2$hash3(uint32_t k);




static inline uint32_t /*NodeC.routingTable*/HashmapC$2$hash(uint32_t k, uint32_t i);




static void /*NodeC.routingTable*/HashmapC$2$Hashmap$insert(uint32_t k, /*NodeC.routingTable*/HashmapC$2$t input);
#line 70
static inline void /*NodeC.routingTable*/HashmapC$2$Hashmap$clear(void );
#line 121
static /*NodeC.routingTable*/HashmapC$2$t /*NodeC.routingTable*/HashmapC$2$Hashmap$get(uint32_t k);
#line 159
static bool /*NodeC.routingTable*/HashmapC$2$Hashmap$contains(uint32_t k);
#line 184
static inline uint32_t */*NodeC.routingTable*/HashmapC$2$Hashmap$getKeys(void );
#line 8
uint16_t /*NodeC.TCPTablePTR*/HashmapC$3$HASH_MAX_SIZE[1000];





#line 10
typedef struct /*NodeC.TCPTablePTR*/HashmapC$3$hashmapEntry {

  uint32_t key;
  /*NodeC.TCPTablePTR*/HashmapC$3$t value;
} /*NodeC.TCPTablePTR*/HashmapC$3$hashmapEntry;

/*NodeC.TCPTablePTR*/HashmapC$3$hashmapEntry /*NodeC.TCPTablePTR*/HashmapC$3$map[1000][255];
uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$keys[1000][255];
uint16_t /*NodeC.TCPTablePTR*/HashmapC$3$numofVals[1000];


static inline uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$hash2(uint32_t k);




static inline uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$hash3(uint32_t k);




static inline uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$hash(uint32_t k, uint32_t i);




static void /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$insert(uint32_t k, /*NodeC.TCPTablePTR*/HashmapC$3$t input);
#line 140
static uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$getIndex(uint32_t k);
#line 159
static bool /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$contains(uint32_t k);
# 52 "/root/local/tinyos-2.1.1/tos/system/RandomMlcgC.nc"
uint32_t RandomMlcgC$seed[1000];


static inline error_t RandomMlcgC$Init$init(void );
#line 69
static uint32_t RandomMlcgC$Random$rand32(void );
#line 89
static inline uint16_t RandomMlcgC$Random$rand16(void );
# 78 "/root/local/tinyos-2.1.1/tos/lib/tossim/heap.c"
static inline void init_heap(heap_t *heap)
#line 78
{
  heap->size = 0;
  heap->private_size = STARTING_SIZE;
  heap->data = malloc(sizeof(node_t ) * heap->private_size);
}

#line 130
static inline void expand_heap(heap_t *heap)
#line 130
{
  int new_size = heap->private_size * 2 + 1;
  void *new_data = malloc(sizeof(node_t ) * new_size);



  memcpy(new_data, heap->data, sizeof(node_t ) * heap->private_size);
  free(heap->data);

  heap->data = new_data;
  heap->private_size = new_size;
}


static inline void heap_insert(heap_t *heap, void *data, long long int key)
#line 144
{
  int findex = heap->size;

#line 146
  if (findex == heap->private_size) {
      expand_heap(heap);
    }

  findex = heap->size;
  ((node_t *)heap->data)[findex].key = key;
  ((node_t *)heap->data)[findex].data = data;
  up_heap(heap, findex);

  heap->size++;
}

#line 88
static inline int is_empty(heap_t *heap)
#line 88
{
  return heap->size == 0;
}

static inline int heap_is_empty(heap_t *heap)
#line 92
{
  return is_empty(heap);
}

static inline long long int heap_get_min_key(heap_t *heap)
#line 96
{
  if (is_empty(heap)) {
      return -1;
    }
  else {
      return ((node_t *)heap->data)[0].key;
    }
}

# 317 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_log.c"
inline static int sim_log_eq(void *key1, void *key2)
#line 317
{
  return strcmp((char *)key1, (char *)key2) == 0;
}

#line 306
inline static unsigned int sim_log_hash(void *key)
#line 306
{
  char *str = (char *)key;
  unsigned int hashVal = 0;
  int hashChar;

  while ((hashChar = * str++)) 
    hashVal = hashChar + (hashVal << 6) + (hashVal << 16) - hashVal;

  return hashVal;
}

#line 159
static inline void sim_log_init()
#line 159
{
  int i;

  channelTable = create_hashtable(128, sim_log_hash, sim_log_eq);

  for (i = 0; i < SIM_LOG_OUTPUT_COUNT; i++) {
      outputs[i].num = 1;
      outputs[i].files = (FILE **)malloc(sizeof(FILE *));
      outputs[i].files[0] = fdopen(1, "w");
    }
}

# 130 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_noise.c"
inline static unsigned int sim_noise_hash(void *key)
#line 130
{
  char *pt = (char *)key;
  unsigned int hashVal = 0;
  int i;

#line 134
  for (i = 0; i < NOISE_HISTORY; i++) {
      hashVal = pt[i] + (hashVal << 6) + (hashVal << 16) - hashVal;
    }
  return hashVal;
}

inline static int sim_noise_eq(void *key1, void *key2)
#line 140
{
  return memcmp((void *)key1, (void *)key2, NOISE_HISTORY) == 0;
}

# 64 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMoteP.nc"
static inline bool SimMoteP$SimMote$isOn(void )
#line 64
{
  return SimMoteP$isOn[sim_node()];
}

# 172 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_log.c"
static inline void sim_log_add_channel(char *name, FILE *file)
#line 172
{
  sim_log_channel_t *channel;

#line 174
  channel = (sim_log_channel_t *)hashtable_search(channelTable, name);



  if (channel == (void *)0) {
      char *newName = (char *)malloc(strlen(name) + 1);

#line 180
      strcpy(newName, name);
      newName[strlen(name)] = 0;

      channel = (sim_log_channel_t *)malloc(sizeof(sim_log_channel_t ));
      channel->name = newName;
      channel->numOutputs = 0;
      channel->size = DEFAULT_CHANNEL_SIZE;
      channel->outputs = (FILE **)malloc(sizeof(FILE *) * channel->size);
      memset(channel->outputs, 0, sizeof(FILE *) * channel->size);
      hashtable_insert(channelTable, newName, channel);
    }



  if (channel->numOutputs == channel->size) {
      FILE **newOutputs;
      int newSize = channel->size * 2;

      newOutputs = (FILE **)malloc(sizeof(FILE *) * newSize);
      memcpy(newOutputs, channel->outputs, channel->size * sizeof(FILE **));

      free(channel->outputs);

      channel->outputs = newOutputs;
      channel->size = newSize;
    }

  channel->outputs[channel->numOutputs] = file;
  channel->numOutputs++;
  sim_log_commit_change();
}

static inline bool sim_log_remove_channel(char *output, FILE *file)
#line 212
{
  sim_log_channel_t *channel;
  int i;

#line 215
  channel = (sim_log_channel_t *)hashtable_search(channelTable, output);

  if (channel == (void *)0) {
      return FALSE;
    }


  for (i = 0; i < channel->numOutputs; i++) {
      FILE *f = channel->outputs[i];

#line 224
      if (file == f) {
          memcpy(&channel->outputs[i], &channel->outputs[i + 1], channel->numOutputs - (i + 1));
          channel->outputs[channel->numOutputs - 1] = (void *)0;
          channel->numOutputs--;
        }
    }

  return TRUE;
}

# 161 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_gain.c"
static inline gain_entry_t *sim_gain_allocate_link(int mote)
#line 161
{
  gain_entry_t *newLink = (gain_entry_t *)malloc(sizeof(gain_entry_t ));

#line 163
  newLink->next = (void *)0;
  newLink->mote = mote;
  newLink->gain = -10000000.0;
  return newLink;
}

# 55 "/root/local/tinyos-2.1.1/tos/lib/tossim/randomlib.c"
static inline void RandomInitialise(int ij, int kl)
{
  double s;
#line 57
  double t;
  int ii;
#line 58
  int i;
#line 58
  int j;
#line 58
  int k;
#line 58
  int l;
#line 58
  int jj;
#line 58
  int m;






  if (((ij < 0 || ij > 31328) || kl < 0) || kl > 30081) {
      ij = 1802;
      kl = 9373;
    }

  i = ij / 177 % 177 + 2;
  j = ij % 177 + 2;
  k = kl / 169 % 178 + 1;
  l = kl % 169;

  for (ii = 0; ii < 97; ii++) {
      s = 0.0;
      t = 0.5;
      for (jj = 0; jj < 24; jj++) {
          m = i * j % 179 * k % 179;
          i = j;
          j = k;
          k = m;
          l = (53 * l + 1) % 169;
          if (l * m % 64 >= 32) {
            s += t;
            }
#line 86
          t *= 0.5;
        }
      randU[ii] = s;
    }

  randC = 362436.0 / 16777216.0;
  randCD = 7654321.0 / 16777216.0;
  randCM = 16777213.0 / 16777216.0;
  i97 = 97;
  j97 = 33;
  test = TRUE;
}

# 284 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_noise.c"
static inline void sim_noise_alarm()
#line 284
{
  dummy = 5;
}

# 50 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_packet.c"
inline static tossim_header_t *getHeader(message_t *msg)
#line 50
{
  return (tossim_header_t *)(msg->data - sizeof(tossim_header_t ));
}

# 236 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$active_message_deliver_handle(sim_event_t *evt)
#line 236
{
  message_t *m = (message_t *)evt->data;

#line 238
  sim_log_debug(113U, "Packet", "Delivering packet to %i at %s\n", (int )sim_node(), sim_time_string());
  TossimActiveMessageC$Model$receive(m);
}

static inline sim_event_t *TossimActiveMessageC$allocate_deliver_event(int node, message_t *msg, sim_time_t t)
#line 242
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 244
  evt->mote = node;
  evt->time = t;
  evt->handle = TossimActiveMessageC$active_message_deliver_handle;
  evt->cleanup = sim_queue_cleanup_event;
  evt->cancelled = 0;
  evt->force = 0;
  evt->data = msg;
  return evt;
}

#line 185
static inline uint8_t TossimActiveMessageC$Packet$maxPayloadLength(void )
#line 185
{
  return 28;
}

# 88 "/root/local/tinyos-2.1.1/tos/lib/tossim/ActiveMessageAddressC.nc"
static inline am_addr_t ActiveMessageAddressC$amAddress(void )
#line 88
{
  return ActiveMessageAddressC$ActiveMessageAddress$amAddress();
}

# 57 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
inline static am_addr_t TossimActiveMessageC$amAddress(void ){
#line 57
  unsigned short __nesc_result;
#line 57

#line 57
  __nesc_result = ActiveMessageAddressC$amAddress();
#line 57

#line 57
  return __nesc_result;
#line 57
}
#line 57
#line 136
static inline am_addr_t TossimActiveMessageC$AMPacket$address(void )
#line 136
{
  return TossimActiveMessageC$amAddress();
}

#line 160
static inline bool TossimActiveMessageC$AMPacket$isForMe(message_t *amsg)
#line 160
{
  return TossimActiveMessageC$AMPacket$destination(amsg) == TossimActiveMessageC$AMPacket$address() || 
  TossimActiveMessageC$AMPacket$destination(amsg) == AM_BROADCAST_ADDR;
}

# 281 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint8_t __nesc_ntoh_uint8(const void * source)
#line 281
{
  const uint8_t *base = source;

#line 283
  return base[0];
}

#line 310
static __inline  uint16_t __nesc_ntoh_uint16(const void * source)
#line 310
{
  const uint8_t *base = source;

#line 312
  return ((uint16_t )base[0] << 8) | base[1];
}

# 166 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
static inline error_t TransportP$Transport$receive(pack *Packet)
{
  socket_storage_t *TCPHeader;


  if (__nesc_ntoh_uint8(Packet->protocol.nxdata) != PROTOCOL_TCP || __nesc_ntoh_uint16(Packet->dest.nxdata) != TOS_NODE_ID) {
    return FAIL;
    }
  TCPHeader = (socket_storage_t *)Packet->payload;

  switch (TCPHeader->state) 
    {
      case SOCK_ESTABLISHED: 

        break;
      case SOCK_LISTEN: 

        break;
      case SOCK_CLOSED: 

        break;
      case SOCK_SYN_SENT: 
        sim_log_debug(230U, "Project3", "Recieved sync packet from from %d, %d to %d, %d\n", __nesc_ntoh_uint16(TCPHeader->sockAddr.srcAddr.nxdata), __nesc_ntoh_uint8(TCPHeader->sockAddr.srcPort.nxdata), __nesc_ntoh_uint16(TCPHeader->sockAddr.destAddr.nxdata), __nesc_ntoh_uint8(TCPHeader->sockAddr.destPort.nxdata));

      break;
      case SOCK_CLOSE_WAIT: 

        break;
      case SOCK_FIN_WAIT: 

        break;
    }




  {
  }


  return SUCCESS;
}

# 91 "/root/workspace/Project1/src/lib/interfaces/Transport.nc"
inline static error_t Node$Transport$receive(pack *package){
#line 91
  unsigned char __nesc_result;
#line 91

#line 91
  __nesc_result = TransportP$Transport$receive(package);
#line 91

#line 91
  return __nesc_result;
#line 91
}
#line 91
# 196 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static inline void PacketHandlerP$PacketHandler$reply(uint16_t destination)
{
  PacketHandlerP$PacketHandler$makePack(destination, PROTOCOL_PINGREPLY, PacketHandlerP$pingPacket[sim_node()]);
  PacketHandlerP$PacketHandler$send(destination, FALSE);
}

#line 109
static inline error_t PacketHandlerP$PacketHandler$receive(pack *Package)
{



  if (__nesc_ntoh_uint8(Package->protocol.nxdata) == PROTOCOL_PING) 
    {

      PacketHandlerP$PacketHandler$reply(__nesc_ntoh_uint16(Package->src.nxdata));


      if (__nesc_ntoh_uint16(Package->dest.nxdata) == UNSPECIFIED) {
        return FAIL;
        }

      PacketHandlerP$PacketHandler$processSequence(Package);

      if (__nesc_ntoh_uint16(Package->dest.nxdata) == TOS_NODE_ID) 
        {

          sim_log_debug(153U, "Project2", "\tReceived packet %d->%d. Payload: %s\n", __nesc_ntoh_uint16(Package->src.nxdata), TOS_NODE_ID, Package->payload);
        }
      else 
        {

          PacketHandlerP$sendPackage[sim_node()] = *Package;
          PacketHandlerP$PacketHandler$send(AM_BROADCAST_ADDR, TRUE);
        }

      return SUCCESS;
    }
  else {
#line 140
    if (__nesc_ntoh_uint8(Package->protocol.nxdata) == PROTOCOL_PINGREPLY) 
      {
      }
    else {
      if (__nesc_ntoh_uint8(Package->protocol.nxdata) == PROTOCOL_LINKSTATE) 
        {
          PacketHandlerP$PacketHandler$processSequence(Package);
          PacketHandlerP$sendPackage[sim_node()] = *Package;
          PacketHandlerP$PacketHandler$send(AM_BROADCAST_ADDR, TRUE);
          return SUCCESS;
        }
      }
    }
#line 152
  return FAIL;
}

# 7 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
inline static error_t Node$PacketHandler$receive(pack *Packet){
#line 7
  unsigned char __nesc_result;
#line 7

#line 7
  __nesc_result = PacketHandlerP$PacketHandler$receive(Packet);
#line 7

#line 7
  return __nesc_result;
#line 7
}
#line 7
# 333 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static inline error_t LinkStateRoutingP$LinkStateRouting$receive(pack *Packet)
{
  uint16_t *destinations;
  uint16_t destID;
  uint8_t payloadIndex;
  uint16_t ind;


  if (__nesc_ntoh_uint8(Packet->protocol.nxdata) != PROTOCOL_LINKSTATE) {
    return FAIL;
    }

  memcpy(LinkStateRoutingP$compareBuffer[sim_node()], LinkStateRoutingP$linkStates[sim_node()][__nesc_ntoh_uint16(Packet->src.nxdata)], sizeof(uint16_t ) * ROUTING_TABLE_SIZE);



  memset(LinkStateRoutingP$linkStates[sim_node()][__nesc_ntoh_uint16(Packet->src.nxdata)], 0, sizeof(uint16_t ) * ROUTING_TABLE_SIZE);


  LinkStateRoutingP$existing[sim_node()][__nesc_ntoh_uint16(Packet->src.nxdata)] = TRUE;


  destinations = (uint16_t *)&Packet->payload[0];


  for (payloadIndex = 0; payloadIndex < PACKET_MAX_PAYLOAD_SIZE16; payloadIndex++) 
    {

      destID = destinations[payloadIndex];


      if (destID == NONE) {
        continue;
        }
      LinkStateRoutingP$linkStates[sim_node()][__nesc_ntoh_uint16(Packet->src.nxdata)][destID] = 1;
    }


  for (ind = 0; ind < ROUTING_TABLE_SIZE; ind++) 
    {
      if (LinkStateRoutingP$compareBuffer[sim_node()][ind] != LinkStateRoutingP$linkStates[sim_node()][__nesc_ntoh_uint16(Packet->src.nxdata)][ind]) 
        {
          if (TOS_NODE_ID == 2) {
            sim_log_debug(219U, "Project2", "\tLS changed! %d to %d at %d, %d\n", LinkStateRoutingP$compareBuffer[sim_node()][ind], LinkStateRoutingP$linkStates[sim_node()][__nesc_ntoh_uint16(Packet->src.nxdata)][ind], __nesc_ntoh_uint16(Packet->src.nxdata), ind);
            }
#line 377
          LinkStateRoutingP$LSChanged[sim_node()] = TRUE;
          return SUCCESS;
        }
    }


  {
  }

  return SUCCESS;
}

# 6 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
inline static error_t Node$LinkStateRouting$receive(pack *Packet){
#line 6
  unsigned char __nesc_result;
#line 6

#line 6
  __nesc_result = LinkStateRoutingP$LinkStateRouting$receive(Packet);
#line 6

#line 6
  return __nesc_result;
#line 6
}
#line 6
# 3 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static void NeighborDiscoveryP$neighborTable$insert(uint32_t key, NeighborDiscoveryP$neighborTable$t input){
#line 3
  /*NodeC.neighborTable*/HashmapC$0$Hashmap$insert(key, input);
#line 3
}
#line 3
# 41 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static inline void LinkStateRoutingP$LinkStateRouting$neighborChanged(void )
{
  LinkStateRoutingP$NeighborsChanged[sim_node()] = TRUE;
}

# 7 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
inline static void NeighborDiscoveryP$LinkStateRouting$neighborChanged(void ){
#line 7
  LinkStateRoutingP$LinkStateRouting$neighborChanged();
#line 7
}
#line 7
# 6 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static NeighborDiscoveryP$neighborTable$t NeighborDiscoveryP$neighborTable$get(uint32_t key){
#line 6
  unsigned short __nesc_result;
#line 6

#line 6
  __nesc_result = /*NodeC.neighborTable*/HashmapC$0$Hashmap$get(key);
#line 6

#line 6
  return __nesc_result;
#line 6
}
#line 6
# 26 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline uint32_t /*NodeC.neighborTable*/HashmapC$0$hash3(uint32_t k)
{
  return 1 + k % 11;
}

#line 21
static inline uint32_t /*NodeC.neighborTable*/HashmapC$0$hash2(uint32_t k)
{
  return k % 13;
}






static inline uint32_t /*NodeC.neighborTable*/HashmapC$0$hash(uint32_t k, uint32_t i)
{
  return (/*NodeC.neighborTable*/HashmapC$0$hash2(k) + i * /*NodeC.neighborTable*/HashmapC$0$hash3(k)) % /*NodeC.neighborTable*/HashmapC$0$HASH_MAX_SIZE[sim_node()];
}

#line 159
static inline bool /*NodeC.neighborTable*/HashmapC$0$Hashmap$contains(uint32_t k)
{
  uint32_t i = 0;
  uint32_t j = 0;

  do 
    {
      j = /*NodeC.neighborTable*/HashmapC$0$hash(k, i);
      if (/*NodeC.neighborTable*/HashmapC$0$map[sim_node()][j].key == k) {
        return TRUE;
        }
#line 169
      i++;
    }
  while (i < /*NodeC.neighborTable*/HashmapC$0$HASH_MAX_SIZE[sim_node()]);

  return FALSE;
}

# 8 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static bool NeighborDiscoveryP$neighborTable$contains(uint32_t key){
#line 8
  unsigned char __nesc_result;
#line 8

#line 8
  __nesc_result = /*NodeC.neighborTable*/HashmapC$0$Hashmap$contains(key);
#line 8

#line 8
  return __nesc_result;
#line 8
}
#line 8
# 34 "/root/workspace/Project1/src/lib/modules/NeighborDiscoveryP.nc"
static inline error_t NeighborDiscoveryP$NeighborDiscovery$receive(pack *Packet)
{
  uint16_t connectionStateOriginal;
  uint16_t connectionState;


  if (__nesc_ntoh_uint8(Packet->TTL.nxdata) != MAX_TTL) {
    return FAIL;
    }

  if (__nesc_ntoh_uint8(Packet->protocol.nxdata) != PROTOCOL_PING && __nesc_ntoh_uint8(Packet->protocol.nxdata) != PROTOCOL_PINGREPLY) {
    return FAIL;
    }


  if (!NeighborDiscoveryP$neighborTable$contains(__nesc_ntoh_uint16(Packet->src.nxdata))) {
    NeighborDiscoveryP$neighborTable$insert(__nesc_ntoh_uint16(Packet->src.nxdata), CONNECTION_NONE);
    }

  connectionStateOriginal = connectionState = NeighborDiscoveryP$neighborTable$get(__nesc_ntoh_uint16(Packet->src.nxdata));
  connectionState &= ~CONNECTION_WAITING_RESPONSE;
  connectionState &= ~CONNECTION_TIMED_OUT;
  NeighborDiscoveryP$neighborTable$insert(__nesc_ntoh_uint16(Packet->src.nxdata), connectionState);

  if (__nesc_ntoh_uint8(Packet->protocol.nxdata) == PROTOCOL_PING) 
    {

      if (connectionState == CONNECTION_NONE || connectionStateOriginal & CONNECTION_TIMED_OUT) 
        {
          NeighborDiscoveryP$LinkStateRouting$neighborChanged();
          sim_log_debug(211U, "Project1N", "Connection discovered:\t %d -> %d\n", __nesc_ntoh_uint16(Packet->src.nxdata), TOS_NODE_ID);
        }

      connectionState |= CONNECTION_RECEIVE;
      NeighborDiscoveryP$neighborTable$insert(__nesc_ntoh_uint16(Packet->src.nxdata), connectionState);
    }
  else {
#line 70
    if (__nesc_ntoh_uint8(Packet->protocol.nxdata) == PROTOCOL_PINGREPLY) 
      {

        if ((connectionState & CONNECTION_SEND) == 0 || connectionStateOriginal & CONNECTION_TIMED_OUT) 
          {
            NeighborDiscoveryP$LinkStateRouting$neighborChanged();
            sim_log_debug(212U, "Project1N", "Conection discovered:\t %d <-> %d\n", __nesc_ntoh_uint16(Packet->src.nxdata), TOS_NODE_ID);
          }
        connectionState |= CONNECTION_SEND;
        NeighborDiscoveryP$neighborTable$insert(__nesc_ntoh_uint16(Packet->src.nxdata), connectionState);
      }
    }

  return SUCCESS;
}

# 5 "/root/workspace/Project1/src/lib/interfaces/NeighborDiscovery.nc"
inline static error_t Node$NeighborDiscovery$receive(pack *Packet){
#line 5
  unsigned char __nesc_result;
#line 5

#line 5
  __nesc_result = NeighborDiscoveryP$NeighborDiscovery$receive(Packet);
#line 5

#line 5
  return __nesc_result;
#line 5
}
#line 5
# 286 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint8_t __nesc_hton_uint8(void * target, uint8_t value)
#line 286
{
  uint8_t *base = target;

#line 288
  base[0] = value;
  return value;
}

#line 315
static __inline  uint16_t __nesc_hton_uint16(void * target, uint16_t value)
#line 315
{
  uint8_t *base = target;

#line 317
  base[1] = value;
  base[0] = value >> 8;
  return value;
}

# 222 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow(void )
#line 222
{
  return /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get();
}

# 109 "/root/local/tinyos-2.1.1/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getNow(void ){
#line 109
  unsigned int __nesc_result;
#line 109

#line 109
  __nesc_result = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow();
#line 109

#line 109
  return __nesc_result;
#line 109
}
#line 109
# 96 "/root/local/tinyos-2.1.1/tos/lib/timer/AlarmToTimerC.nc"
static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow(void )
{
#line 97
  return /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getNow();
}

# 136 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(void ){
#line 136
  unsigned int __nesc_result;
#line 136

#line 136
  __nesc_result = /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow();
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 159 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(uint8_t num, uint32_t dt)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(num, /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(), dt, TRUE);
}

# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static void TransportP$AttemptConnection$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(1U, dt);
#line 73
}
#line 73
# 272 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
static inline error_t TransportP$Transport$listen(socket_t fd)
{
  TransportP$Transport$setConnectionPTR(fd, SOCK_LISTEN);
  sim_log_debug(233U, "Project3", "\tOpened socket %d for listening\n", fd);
  return SUCCESS;
}

# 8 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static bool TransportP$TCPTablePTR$contains(uint32_t key){
#line 8
  unsigned char __nesc_result;
#line 8

#line 8
  __nesc_result = /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$contains(key);
#line 8

#line 8
  return __nesc_result;
#line 8
}
#line 8
# 216 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
static inline error_t TransportP$Transport$bind(socket_t fd, socket_addr_t *addr)
{
  if (fd == NULL_SOCKET) 
    {
      sim_log_debug(231U, "Project3", "\fd unable to allocate resources\n", __nesc_ntoh_uint8(addr->srcPort.nxdata));
      return FAIL;
    }

  if (TransportP$TCPTablePTR$contains(__nesc_ntoh_uint8(addr->srcPort.nxdata))) 
    {
      sim_log_debug(232U, "Project3", "\tSocket %d already open\n", __nesc_ntoh_uint8(addr->srcPort.nxdata));
      return FAIL;
    }

  TransportP$Transport$listen(__nesc_ntoh_uint8(addr->srcPort.nxdata));

  return SUCCESS;
}

#line 131
static inline void TransportP$Transport$setTestServer(uint8_t listenPort)
{
  socket_t fd;
  socket_addr_t address;


  fd = listenPort;
  __nesc_hton_uint16(address.srcAddr.nxdata, TOS_NODE_ID);
  __nesc_hton_uint8(address.srcPort.nxdata, listenPort);

  TransportP$Transport$bind(fd, &address);

  TransportP$AttemptConnection$startOneShot(TransportP$Attempt_Connection_Time[sim_node()]);
}

# 25 "/root/workspace/Project1/src/lib/interfaces/Transport.nc"
inline static void CommandHandlerP$Transport$setTestServer(uint8_t listenPort){
#line 25
  TransportP$Transport$setTestServer(listenPort);
#line 25
}
#line 25
# 111 "/root/workspace/Project1/src/lib/modules/CommandHandlerP.nc"
static inline void CommandHandlerP$CommandHandler$setTestServer(uint8_t listenPort)
{
  CommandHandlerP$Transport$setTestServer(listenPort);
}

# 11 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
inline static error_t TransportP$PacketHandler$send(uint16_t dest, bool updateTTL){
#line 11
  unsigned char __nesc_result;
#line 11

#line 11
  __nesc_result = PacketHandlerP$PacketHandler$send(dest, updateTTL);
#line 11

#line 11
  return __nesc_result;
#line 11
}
#line 11
#line 9
inline static void TransportP$PacketHandler$makePack(uint16_t dest, uint8_t protocol, uint8_t *payload){
#line 9
  PacketHandlerP$PacketHandler$makePack(dest, protocol, payload);
#line 9
}
#line 9
# 82 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
static inline void TransportP$Transport$createAndSend(socket_storage_t *TCPHeader, uint16_t destination)
{
  sim_log_debug(227U, "Project3", "\tSending with header %d, %d to %d, %d\n", __nesc_ntoh_uint16(TCPHeader->sockAddr.srcAddr.nxdata), __nesc_ntoh_uint8(TCPHeader->sockAddr.srcPort.nxdata), __nesc_ntoh_uint16(TCPHeader->sockAddr.destAddr.nxdata), __nesc_ntoh_uint8(TCPHeader->sockAddr.destPort.nxdata));

  TransportP$PacketHandler$makePack(destination, PROTOCOL_TCP, (uint8_t *)TCPHeader);
  TransportP$PacketHandler$send(AM_BROADCAST_ADDR, FALSE);
}

# 7 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static uint32_t TransportP$TCPTablePTR$getIndex(uint32_t key){
#line 7
  unsigned int __nesc_result;
#line 7

#line 7
  __nesc_result = /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$getIndex(key);
#line 7

#line 7
  return __nesc_result;
#line 7
}
#line 7
# 41 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
static inline void TransportP$Transport$updateHeader(uint32_t connectionKey, uint16_t src, uint8_t srcPort, uint16_t dest, uint8_t destPort)
{
  uint32_t tableIndex;

#line 44
  tableIndex = TransportP$TCPTablePTR$getIndex(connectionKey);

  __nesc_hton_uint16(TransportP$TCPTable[sim_node()][tableIndex].sockAddr.srcAddr.nxdata, src);
  __nesc_hton_uint8(TransportP$TCPTable[sim_node()][tableIndex].sockAddr.srcPort.nxdata, srcPort);
  __nesc_hton_uint16(TransportP$TCPTable[sim_node()][tableIndex].sockAddr.destAddr.nxdata, dest);
  __nesc_hton_uint8(TransportP$TCPTable[sim_node()][tableIndex].sockAddr.destPort.nxdata, destPort);

  sim_log_debug(225U, "Project3", "\tHeader saved for entry %d with key %d: %d, %d and %d, %d\n", TOS_NODE_ID, connectionKey, src, srcPort, dest, destPort);
}

#line 33
static inline socket_storage_t *TransportP$Transport$getConnectionState(uint32_t connectionKey)
{
  uint32_t tableIndex = TransportP$TCPTablePTR$getIndex(connectionKey);

#line 36
  sim_log_debug(224U, "Project3", "\tFetching ptr for %d, %d with index %d\n", TOS_NODE_ID, connectionKey, tableIndex);
  return &TransportP$TCPTable[sim_node()][tableIndex];
}

#line 110
static inline void TransportP$Transport$setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t transfer)
{

  socket_storage_t *connectionData;

  if (!TransportP$TCPTablePTR$contains(sendPort)) 
    {

      sim_log_debug(228U, "Project3", "\tTrying to connect from %d, %d to %d, %d with transfer %d\n", TOS_NODE_ID, sendPort, targetAddress, targetPort, transfer);
      TransportP$Transport$setConnectionPTR(sendPort, SOCK_SYN_SENT);
      connectionData = TransportP$Transport$getConnectionState(sendPort);
      TransportP$Transport$updateHeader(sendPort, TOS_NODE_ID, sendPort, targetAddress, targetPort);
      TransportP$Transport$createAndSend(connectionData, targetAddress);
    }
  else 
    {
      sim_log_debug(229U, "Project3", "\tConnection exists from %d, %d to %d, %d\n", TOS_NODE_ID, sendPort, targetAddress, targetPort);
    }
}

# 24 "/root/workspace/Project1/src/lib/interfaces/Transport.nc"
inline static void CommandHandlerP$Transport$setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t transfer){
#line 24
  TransportP$Transport$setTestClient(targetAddress, sendPort, targetPort, transfer);
#line 24
}
#line 24
# 117 "/root/workspace/Project1/src/lib/modules/CommandHandlerP.nc"
static inline void CommandHandlerP$CommandHandler$setTestClient(uint16_t targetAddress, uint8_t sendPort, uint8_t targetPort, uint16_t *transfer)
{
  CommandHandlerP$Transport$setTestClient(targetAddress, sendPort, targetPort, *transfer);
}

# 6 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static LinkStateRoutingP$routingTable$t LinkStateRoutingP$routingTable$get(uint32_t key){
#line 6
  unsigned int __nesc_result;
#line 6

#line 6
  __nesc_result = /*NodeC.routingTable*/HashmapC$2$Hashmap$get(key);
#line 6

#line 6
  return __nesc_result;
#line 6
}
#line 6
# 71 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static inline uint16_t LinkStateRoutingP$LinkStateRouting$getRoutingCost(uint32_t src)
{
  return LinkStateRoutingP$routingTable$get(src) >> 16;
}


static inline uint16_t LinkStateRoutingP$LinkStateRouting$getRoutingHop(uint32_t src)
{
  return (uint16_t )LinkStateRoutingP$routingTable$get(src);
}

# 184 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline uint32_t */*NodeC.routingTable*/HashmapC$2$Hashmap$getKeys(void )
{
  return /*NodeC.routingTable*/HashmapC$2$keys[sim_node()];
}

# 11 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static uint32_t *LinkStateRoutingP$routingTable$getKeys(void ){
#line 11
  unsigned int *__nesc_result;
#line 11

#line 11
  __nesc_result = /*NodeC.routingTable*/HashmapC$2$Hashmap$getKeys();
#line 11

#line 11
  return __nesc_result;
#line 11
}
#line 11
# 407 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static inline void LinkStateRoutingP$LinkStateRouting$printRoutingTable(void )
{
  uint32_t *routingKeys;
  uint32_t keyInd;

  uint16_t routingCost;
  uint16_t routingHop;

  routingKeys = LinkStateRoutingP$routingTable$getKeys();

  sim_log_debug(222U, "Project2", "Route Table (%d):\n", TOS_NODE_ID);
  for (keyInd = 0; keyInd < ROUTING_TABLE_SIZE; keyInd++) 
    {
      if (routingKeys[keyInd] == EMPTY) {
        continue;
        }
      routingHop = LinkStateRoutingP$LinkStateRouting$getRoutingHop(routingKeys[keyInd]);
      routingCost = LinkStateRoutingP$LinkStateRouting$getRoutingCost(routingKeys[keyInd]);

      sim_log_debug(223U, "Project2", "\tCost to %d\t is %d\t through %d\n", routingKeys[keyInd], routingCost, routingHop);
    }
}

# 18 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
inline static void CommandHandlerP$LinkStateRouting$printRoutingTable(void ){
#line 18
  LinkStateRoutingP$LinkStateRouting$printRoutingTable();
#line 18
}
#line 18
#line 17
inline static void CommandHandlerP$LinkStateRouting$printLinkState(void ){
#line 17
  LinkStateRoutingP$LinkStateRouting$printLinkState();
#line 17
}
#line 17
# 99 "/root/workspace/Project1/src/lib/modules/CommandHandlerP.nc"
static inline void CommandHandlerP$CommandHandler$printLinkState(void )
{
  CommandHandlerP$LinkStateRouting$printLinkState();
}

#line 92
static inline void CommandHandlerP$CommandHandler$printRouteTable(void )
{
  CommandHandlerP$CommandHandler$printLinkState();
  CommandHandlerP$LinkStateRouting$printRoutingTable();
}

# 184 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline uint32_t */*NodeC.neighborTable*/HashmapC$0$Hashmap$getKeys(void )
{
  return /*NodeC.neighborTable*/HashmapC$0$keys[sim_node()];
}

# 11 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static uint32_t *NeighborDiscoveryP$neighborTable$getKeys(void ){
#line 11
  unsigned int *__nesc_result;
#line 11

#line 11
  __nesc_result = /*NodeC.neighborTable*/HashmapC$0$Hashmap$getKeys();
#line 11

#line 11
  return __nesc_result;
#line 11
}
#line 11
# 142 "/root/workspace/Project1/src/lib/modules/NeighborDiscoveryP.nc"
static inline void NeighborDiscoveryP$NeighborDiscovery$printNeighbors(void )
{
  uint32_t *keys;
  uint32_t keyInd;
  uint16_t connectionState;

  keys = NeighborDiscoveryP$neighborTable$getKeys();

  sim_log_debug(214U, "Project1N", "Neighbors (%d):\n", TOS_NODE_ID);
  for (keyInd = 0; keyInd < NEIGHBOR_TABLE_SIZE; keyInd++) 
    {

      if (keys[keyInd] == EMPTY) {
        continue;
        }

      connectionState = NeighborDiscoveryP$neighborTable$get(keys[keyInd]);

      if (connectionState & CONNECTION_TIMED_OUT) {
        sim_log_debug(215U, "Project1N", "\tNeighbor %d -/- %d\n", keys[keyInd], TOS_NODE_ID);
        }
      else {
#line 162
        if (connectionState & CONNECTION_SEND) {
          sim_log_debug(216U, "Project1N", "\tNeighbor %d <-> %d\n", keys[keyInd], TOS_NODE_ID);
          }
        else {
#line 164
          if (connectionState & CONNECTION_RECEIVE) {
            sim_log_debug(217U, "Project1N", "\tNeighbor %d ->  %d\n", keys[keyInd], TOS_NODE_ID);
            }
          }
        }
    }
}

# 8 "/root/workspace/Project1/src/lib/interfaces/NeighborDiscovery.nc"
inline static void CommandHandlerP$NeighborDiscovery$printNeighbors(void ){
#line 8
  NeighborDiscoveryP$NeighborDiscovery$printNeighbors();
#line 8
}
#line 8
# 86 "/root/workspace/Project1/src/lib/modules/CommandHandlerP.nc"
static inline void CommandHandlerP$CommandHandler$printNeighbors(void )
{
  CommandHandlerP$NeighborDiscovery$printNeighbors();
}

# 188 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static inline void PacketHandlerP$PacketHandler$createAndSend(uint8_t *payload, uint16_t destination)
{
  PacketHandlerP$PacketHandler$makePack(destination, PROTOCOL_PING, payload);
  PacketHandlerP$PacketHandler$send(AM_BROADCAST_ADDR, FALSE);
}

# 14 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
inline static void CommandHandlerP$PacketHandler$createAndSend(uint8_t *payload, uint16_t destination){
#line 14
  PacketHandlerP$PacketHandler$createAndSend(payload, destination);
#line 14
}
#line 14
# 80 "/root/workspace/Project1/src/lib/modules/CommandHandlerP.nc"
static inline void CommandHandlerP$CommandHandler$ping(uint8_t *payload, uint16_t destination)
{
  CommandHandlerP$PacketHandler$createAndSend(payload, destination);
}

#line 22
static inline error_t CommandHandlerP$CommandHandler$receive(pack *Packet)
{
  uint8_t commandID;
  uint8_t *buff;


  if (__nesc_ntoh_uint8(Packet->protocol.nxdata) != PROTOCOL_CMD) {
    return FAIL;
    }
  sim_log_debug(201U, "cmdDebug", "A Command has been Issued.\n");

  buff = (uint8_t *)Packet->payload;
  commandID = buff[0];


  if (commandID == CMD_PING) 
    {
      sim_log_debug(202U, "cmdDebug", "Command Type: Ping\n");
      sim_log_debug(203U, "Project1F", "Sending packet %d->%d\n", TOS_NODE_ID, buff[1]);
      CommandHandlerP$CommandHandler$ping(&buff[2], buff[1]);
      return SUCCESS;
    }
  else {
#line 44
    if (commandID == CMD_NEIGHBOR_DUMP) 
      {
        sim_log_debug(204U, "cmdDebug", "Command Type: Neighbor Dump\n");
        CommandHandlerP$CommandHandler$printNeighbors();
        return SUCCESS;
      }
    else {
#line 50
      if (commandID == CMD_LINKSTATE_DUMP) 
        {
          sim_log_debug(205U, "cmdDebug", "Command Type: Link State Dump\n");
          CommandHandlerP$CommandHandler$printLinkState();
          return SUCCESS;
        }
      else {
#line 56
        if (commandID == CMD_ROUTETABLE_DUMP) 
          {
            sim_log_debug(206U, "cmdDebug", "Command Type: Route Table Dump\n");
            CommandHandlerP$CommandHandler$printRouteTable();
            return SUCCESS;
          }
        else {
#line 62
          if (commandID == CMD_TEST_CLIENT) 
            {
              sim_log_debug(207U, "cmdDebug", "Command Type: Client (Preparing for %d, %d connecting with %d, %d)\n", TOS_NODE_ID, buff[3], buff[2], buff[1]);
              CommandHandlerP$CommandHandler$setTestClient(buff[2], buff[3], buff[1], (uint16_t *)&buff[4]);
              return SUCCESS;
            }
          else {
#line 68
            if (commandID == CMD_TEST_SERVER) 
              {
                sim_log_debug(208U, "cmdDebug", "Command Type: Server (Opening socket %d for Listening)\n", buff[1]);
                CommandHandlerP$CommandHandler$setTestServer(buff[1]);
                return SUCCESS;
              }
            }
          }
        }
      }
    }
#line 75
  sim_log_debug(209U, "cmdDebug", "CMD_ERROR: \"%s\" does not match any known commands.\n", commandID);
  return FAIL;
}

# 6 "/root/workspace/Project1/src/lib/interfaces/CommandHandler.nc"
inline static error_t Node$CommandHandler$receive(pack *Packet){
#line 6
  unsigned char __nesc_result;
#line 6

#line 6
  __nesc_result = CommandHandlerP$CommandHandler$receive(Packet);
#line 6

#line 6
  return __nesc_result;
#line 6
}
#line 6
# 26 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline uint32_t /*NodeC.sequenceTable*/HashmapC$1$hash3(uint32_t k)
{
  return 1 + k % 11;
}

#line 21
static inline uint32_t /*NodeC.sequenceTable*/HashmapC$1$hash2(uint32_t k)
{
  return k % 13;
}






static inline uint32_t /*NodeC.sequenceTable*/HashmapC$1$hash(uint32_t k, uint32_t i)
{
  return (/*NodeC.sequenceTable*/HashmapC$1$hash2(k) + i * /*NodeC.sequenceTable*/HashmapC$1$hash3(k)) % /*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[sim_node()];
}

#line 159
static inline bool /*NodeC.sequenceTable*/HashmapC$1$Hashmap$contains(uint32_t k)
{
  uint32_t i = 0;
  uint32_t j = 0;

  do 
    {
      j = /*NodeC.sequenceTable*/HashmapC$1$hash(k, i);
      if (/*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].key == k) {
        return TRUE;
        }
#line 169
      i++;
    }
  while (i < /*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[sim_node()]);

  return FALSE;
}

# 8 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static bool PacketHandlerP$sequenceTable$contains(uint32_t key){
#line 8
  unsigned char __nesc_result;
#line 8

#line 8
  __nesc_result = /*NodeC.sequenceTable*/HashmapC$1$Hashmap$contains(key);
#line 8

#line 8
  return __nesc_result;
#line 8
}
#line 8
# 70 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static inline bool PacketHandlerP$PacketHandler$containsSrcSeqPair(uint32_t src, uint16_t seq)
{
  uint32_t key = (src << 16) | seq;

#line 73
  return PacketHandlerP$sequenceTable$contains(key);
}

#line 156
static inline bool PacketHandlerP$PacketHandler$isPacketDuplicate(pack *Package)
{

  if (PacketHandlerP$PacketHandler$containsSrcSeqPair(__nesc_ntoh_uint16(Package->src.nxdata), __nesc_ntoh_uint16(Package->seq.nxdata))) 
    {
      return TRUE;
    }

  return FALSE;
}

# 8 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
inline static bool Node$PacketHandler$isPacketDuplicate(pack *Packet){
#line 8
  unsigned char __nesc_result;
#line 8

#line 8
  __nesc_result = PacketHandlerP$PacketHandler$isPacketDuplicate(Packet);
#line 8

#line 8
  return __nesc_result;
#line 8
}
#line 8
# 75 "/root/workspace/Project1/src/Node.nc"
static inline message_t *Node$Receive$receive(message_t *msg, void *payload, uint8_t len)
{
  pack *Packet = (pack *)payload;


  if (len != sizeof(pack )) 
    {
      sim_log_debug(48U, "genDebug", "Unknown packet type %d\n", len);
      return msg;
    }


  if (Node$PacketHandler$isPacketDuplicate(Packet)) 
    {

      return msg;
    }

  Node$CommandHandler$receive(Packet);
  Node$NeighborDiscovery$receive(Packet);
  Node$LinkStateRouting$receive(Packet);
  Node$PacketHandler$receive(Packet);
  Node$Transport$receive(Packet);

  return msg;
}

# 212 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline message_t *TossimActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 212
{
  return msg;
}

# 78 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
inline static message_t * TossimActiveMessageC$Receive$receive(am_id_t arg_0x408d6468, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  switch (arg_0x408d6468) {
#line 78
    case 6:
#line 78
      __nesc_result = Node$Receive$receive(msg, payload, len);
#line 78
      break;
#line 78
    default:
#line 78
      __nesc_result = TossimActiveMessageC$Receive$default$receive(arg_0x408d6468, msg, payload, len);
#line 78
      break;
#line 78
    }
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 75 "/root/local/tinyos-2.1.1/tos/system/PoolP.nc"
static inline bool /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$empty(void )
#line 75
{
  sim_log_debug(192U, "PoolP", "%s size is %i\n", __FUNCTION__, (int )/*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()]);
  return /*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()] == 0;
}

# 61 "/root/local/tinyos-2.1.1/tos/interfaces/Pool.nc"
inline static bool PacketHandlerP$Pool$empty(void ){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$empty();
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 8 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static bool PacketHandlerP$routingTable$contains(uint32_t key){
#line 8
  unsigned char __nesc_result;
#line 8

#line 8
  __nesc_result = /*NodeC.routingTable*/HashmapC$2$Hashmap$contains(key);
#line 8

#line 8
  return __nesc_result;
#line 8
}
#line 8
# 26 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline uint32_t /*NodeC.routingTable*/HashmapC$2$hash3(uint32_t k)
{
  return 1 + k % 11;
}

#line 21
static inline uint32_t /*NodeC.routingTable*/HashmapC$2$hash2(uint32_t k)
{
  return k % 13;
}






static inline uint32_t /*NodeC.routingTable*/HashmapC$2$hash(uint32_t k, uint32_t i)
{
  return (/*NodeC.routingTable*/HashmapC$2$hash2(k) + i * /*NodeC.routingTable*/HashmapC$2$hash3(k)) % /*NodeC.routingTable*/HashmapC$2$HASH_MAX_SIZE[sim_node()];
}

# 6 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static PacketHandlerP$routingTable$t PacketHandlerP$routingTable$get(uint32_t key){
#line 6
  unsigned int __nesc_result;
#line 6

#line 6
  __nesc_result = /*NodeC.routingTable*/HashmapC$2$Hashmap$get(key);
#line 6

#line 6
  return __nesc_result;
#line 6
}
#line 6
# 88 "/root/local/tinyos-2.1.1/tos/system/PoolP.nc"
static inline /*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool_t */*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$get(void )
#line 88
{
  if (/*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()]) {
      /*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool_t *rval = /*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue[sim_node()][/*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[sim_node()]];

#line 91
      /*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue[sim_node()][/*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[sim_node()]] = (void *)0;
      /*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()]--;
      /*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[sim_node()]++;
      if (/*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[sim_node()] == 20) {
          /*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[sim_node()] = 0;
        }
      sim_log_debug(194U, "PoolP", "%s size is %i\n", __FUNCTION__, (int )/*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()]);
      return rval;
    }
  return (void *)0;
}

# 97 "/root/local/tinyos-2.1.1/tos/interfaces/Pool.nc"
inline static PacketHandlerP$Pool$t * PacketHandlerP$Pool$get(void ){
#line 97
  struct sendInfo *__nesc_result;
#line 97

#line 97
  __nesc_result = /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$get();
#line 97

#line 97
  return __nesc_result;
#line 97
}
#line 97
# 61 "/root/local/tinyos-2.1.1/tos/system/QueueC.nc"
static inline uint8_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$maxSize(void )
#line 61
{
  return 20;
}

#line 57
static inline uint8_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$size(void )
#line 57
{
  return /*PacketHandlerC.QueueC*/QueueC$0$size[sim_node()];
}

#line 97
static inline error_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$enqueue(/*PacketHandlerC.QueueC*/QueueC$0$queue_t newVal)
#line 97
{
  if (/*PacketHandlerC.QueueC*/QueueC$0$Queue$size() < /*PacketHandlerC.QueueC*/QueueC$0$Queue$maxSize()) {
      sim_log_debug(191U, "QueueC", "%s: size is %hhu\n", __FUNCTION__, /*PacketHandlerC.QueueC*/QueueC$0$size[sim_node()]);
      /*PacketHandlerC.QueueC*/QueueC$0$queue[sim_node()][/*PacketHandlerC.QueueC*/QueueC$0$tail[sim_node()]] = newVal;
      /*PacketHandlerC.QueueC*/QueueC$0$tail[sim_node()]++;
      if (/*PacketHandlerC.QueueC*/QueueC$0$tail[sim_node()] == 20) {
#line 102
        /*PacketHandlerC.QueueC*/QueueC$0$tail[sim_node()] = 0;
        }
#line 103
      /*PacketHandlerC.QueueC*/QueueC$0$size[sim_node()]++;
      /*PacketHandlerC.QueueC*/QueueC$0$printQueue();
      return SUCCESS;
    }
  else {
      return FAIL;
    }
}

# 90 "/root/local/tinyos-2.1.1/tos/interfaces/Queue.nc"
inline static error_t PacketHandlerP$Queue$enqueue(PacketHandlerP$Queue$t  newVal){
#line 90
  unsigned char __nesc_result;
#line 90

#line 90
  __nesc_result = /*PacketHandlerC.QueueC*/QueueC$0$Queue$enqueue(newVal);
#line 90

#line 90
  return __nesc_result;
#line 90
}
#line 90
# 169 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static inline bool /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(uint8_t num)
{
  return /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num].isrunning;
}

# 92 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static bool PacketHandlerP$sendTimer$isRunning(void ){
#line 92
  unsigned char __nesc_result;
#line 92

#line 92
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(0U);
#line 92

#line 92
  return __nesc_result;
#line 92
}
#line 92
#line 73
inline static void PacketHandlerP$sendTimer$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(0U, dt);
#line 73
}
#line 73
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 139 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline bool SimSchedulerBasicP$isWaiting(uint8_t id)
{
  return SimSchedulerBasicP$m_next[sim_node()][id] != SimSchedulerBasicP$NO_TASK || SimSchedulerBasicP$m_tail[sim_node()] == id;
}

static inline bool SimSchedulerBasicP$pushTask(uint8_t id)
{
  if (!SimSchedulerBasicP$isWaiting(id)) 
    {
      if (SimSchedulerBasicP$m_head[sim_node()] == SimSchedulerBasicP$NO_TASK) 
        {
          SimSchedulerBasicP$m_head[sim_node()] = id;
          SimSchedulerBasicP$m_tail[sim_node()] = id;
        }
      else 
        {
          SimSchedulerBasicP$m_next[sim_node()][SimSchedulerBasicP$m_tail[sim_node()]] = id;
          SimSchedulerBasicP$m_tail[sim_node()] = id;
        }
      return TRUE;
    }
  else 
    {
      return FALSE;
    }
}

#line 69
static inline int SimSchedulerBasicP$sim_config_task_latency(void )
#line 69
{
#line 69
  return 100;
}

# 61 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMoteP.nc"
static inline long long int SimMoteP$SimMote$getStartTime(void )
#line 61
{
  return SimMoteP$startTime[sim_node()];
}

# 127 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline sim_time_t HplAtm128Timer0AsyncP$notify_clockTicksPerSec(void )
#line 127
{
  return ATM128_TIMER0_TICKSPPS;
}

#line 154
static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t)
#line 154
{
  t *= HplAtm128Timer0AsyncP$notify_clockTicksPerSec();
  t /= sim_ticks_per_sec();
  return t;
}

# 53 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
inline static Atm128_TIFR_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag(void ){
#line 53
  union __nesc_unnamed4318 __nesc_result;
#line 53

#line 53
  __nesc_result = HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 89 "/root/local/tinyos-2.1.1/tos/system/RandomMlcgC.nc"
static inline uint16_t RandomMlcgC$Random$rand16(void )
#line 89
{
  return (uint16_t )RandomMlcgC$Random$rand32();
}

# 52 "/root/local/tinyos-2.1.1/tos/interfaces/Random.nc"
inline static uint16_t PacketHandlerP$Random$rand16(void ){
#line 52
  unsigned short __nesc_result;
#line 52

#line 52
  __nesc_result = RandomMlcgC$Random$rand16();
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 26 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$hash3(uint32_t k)
{
  return 1 + k % 11;
}

#line 21
static inline uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$hash2(uint32_t k)
{
  return k % 13;
}






static inline uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$hash(uint32_t k, uint32_t i)
{
  return (/*NodeC.TCPTablePTR*/HashmapC$3$hash2(k) + i * /*NodeC.TCPTablePTR*/HashmapC$3$hash3(k)) % /*NodeC.TCPTablePTR*/HashmapC$3$HASH_MAX_SIZE[sim_node()];
}

# 3 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static void TransportP$TCPTablePTR$insert(uint32_t key, TransportP$TCPTablePTR$t input){
#line 3
  /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$insert(key, input);
#line 3
}
#line 3
# 55 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
static inline void TransportP$Transport$setConnectionState(uint32_t connectionKey, uint8_t state)
{
  uint32_t tableIndex;

#line 58
  tableIndex = TransportP$TCPTablePTR$getIndex(connectionKey);

  TransportP$TCPTable[sim_node()][tableIndex].state = state;
}

# 184 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline uint32_t */*NodeC.sequenceTable*/HashmapC$1$Hashmap$getKeys(void )
{
  return /*NodeC.sequenceTable*/HashmapC$1$keys[sim_node()];
}

# 11 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static uint32_t *PacketHandlerP$sequenceTable$getKeys(void ){
#line 11
  unsigned int *__nesc_result;
#line 11

#line 11
  __nesc_result = /*NodeC.sequenceTable*/HashmapC$1$Hashmap$getKeys();
#line 11

#line 11
  return __nesc_result;
#line 11
}
#line 11
# 77 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline void /*NodeC.sequenceTable*/HashmapC$1$Hashmap$remove(uint32_t k)
{
  uint32_t i = 0;
  uint32_t j = 0;

  do 
    {
      j = /*NodeC.sequenceTable*/HashmapC$1$hash(k, i);
      if (/*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].key == k) 
        {
          /*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].key = 0;
          break;
        }

      i++;
    }
  while (i < /*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[sim_node()]);

  sim_log_debug(239U, "hashmap", "Removing entry %d\n", k);

  for (i = 0; i < /*NodeC.sequenceTable*/HashmapC$1$numofVals[sim_node()]; i++) 
    {
      if (/*NodeC.sequenceTable*/HashmapC$1$keys[sim_node()][i] == k) 
        {
          sim_log_debug(240U, "hashmap", "Key found at %d\n", i);

          for (j = i; j < /*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[sim_node()]; j++) 
            {
              if (/*NodeC.sequenceTable*/HashmapC$1$keys[sim_node()][j] == 0) {
                break;
                }
#line 107
              sim_log_debug(241U, "hashamp", "Moving %d to %d\n", j, j + 1);
              sim_log_debug(242U, "hashamp", "Replacing %d with %d\n", /*NodeC.sequenceTable*/HashmapC$1$keys[sim_node()][j], /*NodeC.sequenceTable*/HashmapC$1$keys[sim_node()][j + 1]);
              /*NodeC.sequenceTable*/HashmapC$1$keys[sim_node()][j] = /*NodeC.sequenceTable*/HashmapC$1$keys[sim_node()][j + 1];
            }

          /*NodeC.sequenceTable*/HashmapC$1$keys[sim_node()][/*NodeC.sequenceTable*/HashmapC$1$numofVals[sim_node()]] = 0;
          /*NodeC.sequenceTable*/HashmapC$1$numofVals[sim_node()]--;

          sim_log_debug(243U, "hashmap", "Done removing entry\n");
          return;
        }
    }
}

# 4 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static void PacketHandlerP$sequenceTable$remove(uint32_t key){
#line 4
  /*NodeC.sequenceTable*/HashmapC$1$Hashmap$remove(key);
#line 4
}
#line 4
#line 3
inline static void PacketHandlerP$sequenceTable$insert(uint32_t key, PacketHandlerP$sequenceTable$t input){
#line 3
  /*NodeC.sequenceTable*/HashmapC$1$Hashmap$insert(key, input);
#line 3
}
#line 3
# 121 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline /*NodeC.sequenceTable*/HashmapC$1$t /*NodeC.sequenceTable*/HashmapC$1$Hashmap$get(uint32_t k)
{
  uint32_t i = 0;
  uint32_t j = 0;

  do 
    {
      j = /*NodeC.sequenceTable*/HashmapC$1$hash(k, i);

      if (/*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].key == k) {
        return /*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].value;
        }
      i++;
    }
  while (i < /*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[sim_node()]);

  return /*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][0].value;
}

# 6 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static PacketHandlerP$sequenceTable$t PacketHandlerP$sequenceTable$get(uint32_t key){
#line 6
  unsigned short __nesc_result;
#line 6

#line 6
  __nesc_result = /*NodeC.sequenceTable*/HashmapC$1$Hashmap$get(key);
#line 6

#line 6
  return __nesc_result;
#line 6
}
#line 6
# 55 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static inline void PacketHandlerP$PacketHandler$decreaseAge(uint32_t key)
{
  uint16_t age = PacketHandlerP$sequenceTable$get(key) - 1;

  if (age > 0) 
    {
      PacketHandlerP$sequenceTable$insert(key, age);
    }
  else 
    {
      PacketHandlerP$sequenceTable$remove(key);
    }
}

#line 48
static inline void PacketHandlerP$PacketHandler$insertAge(uint32_t src, uint16_t seq, uint16_t age)
{
  uint32_t key = (src << 16) | seq;

#line 51
  PacketHandlerP$sequenceTable$insert(key, age);
}

# 216 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline message_t *TossimActiveMessageC$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 216
{
  return msg;
}

# 78 "/root/local/tinyos-2.1.1/tos/interfaces/Receive.nc"
inline static message_t * TossimActiveMessageC$Snoop$receive(am_id_t arg_0x408d6b00, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
    __nesc_result = TossimActiveMessageC$Snoop$default$receive(arg_0x408d6b00, msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 89 "/root/local/tinyos-2.1.1/tos/chips/atm128/sim/atm128hardware.h"
static __inline void __nesc_disable_interrupt()
#line 89
{
  atm128RegFile[sim_node()][* (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F]] &= ~(1 << 7);
}






#line 97
__inline  __nesc_atomic_t 
__nesc_atomic_start(void )
{
  __nesc_atomic_t result = * (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F];

#line 101
  __nesc_disable_interrupt();
  return result;
}



#line 106
__inline  void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)
{
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F] = original_SREG;
}

# 85 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline void SimSchedulerBasicP$sim_scheduler_event_handle(sim_event_t *e)
#line 85
{
  SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] = FALSE;








  if (SimSchedulerBasicP$Scheduler$runNextTask()) {
      SimSchedulerBasicP$sim_scheduler_submit_event();
    }
}




static inline void SimSchedulerBasicP$sim_scheduler_event_init(sim_event_t *e)
#line 103
{
  e->mote = sim_node();
  e->force = 0;
  e->data = (void *)0;
  e->handle = SimSchedulerBasicP$sim_scheduler_event_handle;
  e->cleanup = sim_queue_cleanup_none;
}

#line 166
static inline void SimSchedulerBasicP$Scheduler$init(void )
{
  sim_log_debug(100U, "Scheduler", "Initializing scheduler.\n");
  /* atomic removed: atomic calls only */
  {
    memset(SimSchedulerBasicP$m_next[sim_node()], SimSchedulerBasicP$NO_TASK, sizeof SimSchedulerBasicP$m_next[sim_node()]);
    SimSchedulerBasicP$m_head[sim_node()] = SimSchedulerBasicP$NO_TASK;
    SimSchedulerBasicP$m_tail[sim_node()] = SimSchedulerBasicP$NO_TASK;

    SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] = FALSE;
    SimSchedulerBasicP$sim_scheduler_event_init(&SimSchedulerBasicP$sim_scheduler_event[sim_node()]);
  }
}

# 57 "/root/local/tinyos-2.1.1/tos/interfaces/Scheduler.nc"
inline static void SimMainP$Scheduler$init(void ){
#line 57
  SimSchedulerBasicP$Scheduler$init();
#line 57
}
#line 57
# 120 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline uint8_t SimSchedulerBasicP$popTask(void )
{
  if (SimSchedulerBasicP$m_head[sim_node()] != SimSchedulerBasicP$NO_TASK) 
    {
      uint8_t id = SimSchedulerBasicP$m_head[sim_node()];

#line 125
      SimSchedulerBasicP$m_head[sim_node()] = SimSchedulerBasicP$m_next[sim_node()][SimSchedulerBasicP$m_head[sim_node()]];
      if (SimSchedulerBasicP$m_head[sim_node()] == SimSchedulerBasicP$NO_TASK) 
        {
          SimSchedulerBasicP$m_tail[sim_node()] = SimSchedulerBasicP$NO_TASK;
        }
      SimSchedulerBasicP$m_next[sim_node()][id] = SimSchedulerBasicP$NO_TASK;
      return id;
    }
  else 
    {
      return SimSchedulerBasicP$NO_TASK;
    }
}

# 11 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
inline static error_t NeighborDiscoveryP$PacketHandler$send(uint16_t dest, bool updateTTL){
#line 11
  unsigned char __nesc_result;
#line 11

#line 11
  __nesc_result = PacketHandlerP$PacketHandler$send(dest, updateTTL);
#line 11

#line 11
  return __nesc_result;
#line 11
}
#line 11
#line 9
inline static void NeighborDiscoveryP$PacketHandler$makePack(uint16_t dest, uint8_t protocol, uint8_t *payload){
#line 9
  PacketHandlerP$PacketHandler$makePack(dest, protocol, payload);
#line 9
}
#line 9
# 27 "/root/workspace/Project1/src/lib/modules/NeighborDiscoveryP.nc"
static inline void NeighborDiscoveryP$NeighborDiscovery$discoverNeighbors(void )
{
  NeighborDiscoveryP$PacketHandler$makePack(UNSPECIFIED, PROTOCOL_PING, NeighborDiscoveryP$pingPacket[sim_node()]);
  NeighborDiscoveryP$PacketHandler$send(AM_BROADCAST_ADDR, FALSE);
}

# 9 "/root/workspace/Project1/src/lib/interfaces/NeighborDiscovery.nc"
inline static void Node$NeighborDiscovery$discoverNeighbors(void ){
#line 9
  NeighborDiscoveryP$NeighborDiscovery$discoverNeighbors();
#line 9
}
#line 9
# 107 "/root/workspace/Project1/src/Node.nc"
static inline void Node$doFrequentEvents$runTask(void )
{
  Node$NeighborDiscovery$discoverNeighbors();
  Node$FrequentUpdate$startOneShot(Node$PeriodFrequent[sim_node()]);
}

# 8 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
inline static void Node$LinkStateRouting$shareLinkState(bool forcedShare){
#line 8
  LinkStateRoutingP$LinkStateRouting$shareLinkState(forcedShare);
#line 8
}
#line 8
# 88 "/root/workspace/Project1/src/lib/modules/NeighborDiscoveryP.nc"
static inline void NeighborDiscoveryP$NeighborDiscovery$timeOutCheck(void )
{
  uint32_t *keys;
  uint32_t keyInd;
  uint16_t connectionState;

  keys = NeighborDiscoveryP$neighborTable$getKeys();


  for (keyInd = 0; keyInd < NEIGHBOR_TABLE_SIZE; keyInd++) 
    {

      if (keys[keyInd] == EMPTY) {
        continue;
        }

      connectionState = NeighborDiscoveryP$neighborTable$get(keys[keyInd]);


      if (connectionState == CONNECTION_NONE) {
        continue;
        }


      if (NeighborDiscoveryP$TimeOutState[sim_node()]) 
        {

          connectionState |= CONNECTION_WAITING_RESPONSE;
        }
      else 

        {
          if ((connectionState & CONNECTION_WAITING_RESPONSE) != 0) 
            {

              if ((connectionState & CONNECTION_TIMED_OUT) == 0) 
                {
                  NeighborDiscoveryP$LinkStateRouting$neighborChanged();
                  sim_log_debug(213U, "Project1N", "Connection timed out:\t %d -> %d\n", TOS_NODE_ID, keys[keyInd]);
                }

              connectionState |= CONNECTION_TIMED_OUT;
            }
        }


      NeighborDiscoveryP$neighborTable$insert(keys[keyInd], connectionState);
    }


  NeighborDiscoveryP$TimeOutState[sim_node()] = !NeighborDiscoveryP$TimeOutState[sim_node()];
}

# 7 "/root/workspace/Project1/src/lib/interfaces/NeighborDiscovery.nc"
inline static void Node$NeighborDiscovery$timeOutCheck(void ){
#line 7
  NeighborDiscoveryP$NeighborDiscovery$timeOutCheck();
#line 7
}
#line 7
# 114 "/root/workspace/Project1/src/Node.nc"
static inline void Node$doModerateEvents$runTask(void )
{
  Node$NeighborDiscovery$timeOutCheck();
  Node$LinkStateRouting$shareLinkState(FALSE);
  Node$ModerateUpdate$startOneShot(Node$PeriodModerate[sim_node()]);
}

# 3 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static void LinkStateRoutingP$routingTable$insert(uint32_t key, LinkStateRoutingP$routingTable$t input){
#line 3
  /*NodeC.routingTable*/HashmapC$2$Hashmap$insert(key, input);
#line 3
}
#line 3
# 47 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static inline void LinkStateRoutingP$LinkStateRouting$insertCostHop(uint32_t src, uint16_t cost, uint16_t hop)
{
  uint32_t val = ((uint32_t )cost << 16) | hop;

#line 50
  LinkStateRoutingP$routingTable$insert(src, val);
}

# 8 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static bool LinkStateRoutingP$routingTable$contains(uint32_t key){
#line 8
  unsigned char __nesc_result;
#line 8

#line 8
  __nesc_result = /*NodeC.routingTable*/HashmapC$2$Hashmap$contains(key);
#line 8

#line 8
  return __nesc_result;
#line 8
}
#line 8
#line 6
inline static LinkStateRoutingP$neighborTable$t LinkStateRoutingP$neighborTable$get(uint32_t key){
#line 6
  unsigned short __nesc_result;
#line 6

#line 6
  __nesc_result = /*NodeC.neighborTable*/HashmapC$0$Hashmap$get(key);
#line 6

#line 6
  return __nesc_result;
#line 6
}
#line 6
# 70 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static inline void /*NodeC.routingTable*/HashmapC$2$Hashmap$clear(void )
{
  memset(/*NodeC.routingTable*/HashmapC$2$keys[sim_node()], 0, sizeof(uint32_t ) * 32);
  memset(/*NodeC.routingTable*/HashmapC$2$map[sim_node()], 0, sizeof(/*NodeC.routingTable*/HashmapC$2$hashmapEntry ) * 32);
  /*NodeC.routingTable*/HashmapC$2$numofVals[sim_node()] = 0;
}

# 5 "/root/workspace/Project1/src/dataStructures/interfaces/Hashmap.nc"
inline static void LinkStateRoutingP$routingTable$clear(void ){
#line 5
  /*NodeC.routingTable*/HashmapC$2$Hashmap$clear();
#line 5
}
#line 5






inline static uint32_t *LinkStateRoutingP$neighborTable$getKeys(void ){
#line 11
  unsigned int *__nesc_result;
#line 11

#line 11
  __nesc_result = /*NodeC.neighborTable*/HashmapC$0$Hashmap$getKeys();
#line 11

#line 11
  return __nesc_result;
#line 11
}
#line 11
# 83 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static inline void LinkStateRoutingP$LinkStateRouting$calculateRoute(void )
{

  uint32_t *NeighborKeys;
  uint16_t keyInd;
  uint16_t connectionState;


  uint32_t *RoutingKeys;
  uint16_t routingCost;
  uint16_t consideringCost;

  uint16_t considering;
  uint16_t lowestValue;
  uint16_t ind;


  if (!LinkStateRoutingP$LSChanged[sim_node()]) {
    return;
    }
  NeighborKeys = LinkStateRoutingP$neighborTable$getKeys();
  RoutingKeys = LinkStateRoutingP$routingTable$getKeys();


  LinkStateRoutingP$routingTable$clear();
  memset(LinkStateRoutingP$hopThrough[sim_node()], 0, sizeof(uint16_t ) * ROUTING_TABLE_SIZE);


  memcpy(LinkStateRoutingP$unconsidered[sim_node()], LinkStateRoutingP$existing[sim_node()], sizeof LinkStateRoutingP$unconsidered[sim_node()]);
  LinkStateRoutingP$unconsidered[sim_node()][TOS_NODE_ID] = FALSE;

  if (TOS_NODE_ID == 2) 
    {
      sim_log_debug(218U, "Project2", "Begin Dijkstra\n");
    }


  for (keyInd = 0; keyInd < NEIGHBOR_TABLE_SIZE; keyInd++) 
    {

      if (NeighborKeys[keyInd] == EMPTY) {
        continue;
        }

      connectionState = LinkStateRoutingP$neighborTable$get(NeighborKeys[keyInd]);



      if (((
#line 130
      connectionState == CONNECTION_NONE || !(connectionState & CONNECTION_SEND)) || 
      !(connectionState & CONNECTION_RECEIVE)) || connectionState & CONNECTION_TIMED_OUT) {
        continue;
        }

      LinkStateRoutingP$LinkStateRouting$insertCostHop(NeighborKeys[keyInd], NEIGHBOR_COST, NeighborKeys[keyInd]);
    }




  while (TRUE) 
    {
      lowestValue = 0;
      considering = NONE;


      for (ind = 0; ind < ROUTING_TABLE_SIZE; ind++) 
        {
          if (LinkStateRoutingP$unconsidered[sim_node()][ind] == TRUE) 
            {

              goto notEmpty;
            }
        }
      break;
      notEmpty: 


        for (keyInd = 0; keyInd < ROUTING_TABLE_SIZE; keyInd++) 
          {
            if (RoutingKeys[keyInd] == EMPTY) {
              continue;
              }

            if (LinkStateRoutingP$routingTable$contains(RoutingKeys[keyInd])) {
              routingCost = LinkStateRoutingP$LinkStateRouting$getRoutingCost(RoutingKeys[keyInd]);
              }
            else {
#line 168
              routingCost = INF;
              }

            if (!LinkStateRoutingP$unconsidered[sim_node()][RoutingKeys[keyInd]] || routingCost == INF) {
              continue;
              }
            if (routingCost < lowestValue || lowestValue == 0) 
              {
                considering = RoutingKeys[keyInd];
                lowestValue = routingCost;
              }
          }


      if (considering == NONE) {
        break;
        }



      if (LinkStateRoutingP$routingTable$contains(considering)) 
        {

          connectionState = LinkStateRoutingP$neighborTable$get(considering);



          if (((
#line 194
          connectionState == CONNECTION_NONE || !(connectionState & CONNECTION_SEND)) || 
          !(connectionState & CONNECTION_RECEIVE)) || connectionState & CONNECTION_TIMED_OUT) 
            {
            }
          else 

            {
              LinkStateRoutingP$hopThrough[sim_node()][considering] = considering;
            }
        }


      for (ind = 0; ind < ROUTING_TABLE_SIZE; ind++) 
        {

          if (LinkStateRoutingP$linkStates[sim_node()][considering][ind] == EMPTY) {
            continue;
            }

          if (LinkStateRoutingP$routingTable$contains(ind)) 
            {
              routingCost = LinkStateRoutingP$LinkStateRouting$getRoutingCost(ind);
            }
          else 
            {
              routingCost = INF;
            }


          if (LinkStateRoutingP$routingTable$contains(considering)) 
            {
              consideringCost = LinkStateRoutingP$LinkStateRouting$getRoutingCost(considering) + NEIGHBOR_COST;
            }
          else 
            {
              consideringCost = NEIGHBOR_COST;
            }


          if (routingCost == INF || consideringCost < routingCost) 
            {

              LinkStateRoutingP$hopThrough[sim_node()][ind] = LinkStateRoutingP$hopThrough[sim_node()][considering];


              LinkStateRoutingP$LinkStateRouting$insertCostHop(ind, consideringCost, LinkStateRoutingP$hopThrough[sim_node()][ind]);
            }
        }


      LinkStateRoutingP$LinkStateRouting$insertCostHop(TOS_NODE_ID, NONE, TOS_NODE_ID);
      LinkStateRoutingP$unconsidered[sim_node()][considering] = FALSE;
    }



  LinkStateRoutingP$LSChanged[sim_node()] = FALSE;
}

# 9 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
inline static void Node$LinkStateRouting$calculateRoute(void ){
#line 9
  LinkStateRoutingP$LinkStateRouting$calculateRoute();
#line 9
}
#line 9
# 122 "/root/workspace/Project1/src/Node.nc"
static inline void Node$doSparseEvents$runTask(void )
{
  Node$LinkStateRouting$calculateRoute();
  Node$SparseUpdate$startOneShot(Node$PeriodSparse[sim_node()]);
}

# 17 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
inline static void Node$PacketHandler$ageSequenceTable(void ){
#line 17
  PacketHandlerP$PacketHandler$ageSequenceTable();
#line 17
}
#line 17
# 129 "/root/workspace/Project1/src/Node.nc"
static inline void Node$doRareEvents$runTask(void )
{
  Node$LinkStateRouting$shareLinkState(TRUE);
  Node$PacketHandler$ageSequenceTable();
  Node$RareUpdate$startOneShot(Node$PeriodRare[sim_node()]);
}

# 104 "/root/local/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
inline static error_t Node$SplitControl$start(void ){
#line 104
  unsigned char __nesc_result;
#line 104

#line 104
  __nesc_result = TossimPacketModelC$Control$start();
#line 104

#line 104
  return __nesc_result;
#line 104
}
#line 104
# 169 "/root/workspace/Project1/src/Node.nc"
static inline void Node$SplitControl$startDone(error_t err)
{
  if (err == SUCCESS) 
    {
      sim_log_debug(49U, "genDebug", "Radio On\n");
    }
  else 
    {

      Node$SplitControl$start();
    }
}

# 113 "/root/local/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
inline static void TossimPacketModelC$Control$startDone(error_t error){
#line 113
  Node$SplitControl$startDone(error);
#line 113
}
#line 113
# 96 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$startDoneTask$runTask(void )
#line 96
{
  TossimPacketModelC$running[sim_node()] = TRUE;
  TossimPacketModelC$Control$startDone(SUCCESS);
}

# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t TossimPacketModelC$stopDoneTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(TossimPacketModelC$stopDoneTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 115 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static inline error_t TossimPacketModelC$Control$stop(void )
#line 115
{
  if (!TossimPacketModelC$initialized[sim_node()]) {
      sim_log_error(117U, "TossimPacketModelC", "TossimPacketModelC: Control.stop() called before initialization!\n");
      return FAIL;
    }
  TossimPacketModelC$running[sim_node()] = FALSE;
  sim_log_debug(118U, "TossimPacketModelC", "TossimPacketModelC: Control.stop() called.\n");
  TossimPacketModelC$stopDoneTask$postTask();
  return SUCCESS;
}

# 130 "/root/local/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
inline static error_t Node$SplitControl$stop(void ){
#line 130
  unsigned char __nesc_result;
#line 130

#line 130
  __nesc_result = TossimPacketModelC$Control$stop();
#line 130

#line 130
  return __nesc_result;
#line 130
}
#line 130
# 183 "/root/workspace/Project1/src/Node.nc"
static inline void Node$SplitControl$stopDone(error_t err)
{
  if (err == SUCCESS) 
    {
      sim_log_debug(50U, "genDebug", "Radio Off\n");
    }
  else 
    {

      Node$SplitControl$stop();
    }
}

# 138 "/root/local/tinyos-2.1.1/tos/interfaces/SplitControl.nc"
inline static void TossimPacketModelC$Control$stopDone(error_t error){
#line 138
  Node$SplitControl$stopDone(error);
#line 138
}
#line 138
# 101 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$stopDoneTask$runTask(void )
#line 101
{
  TossimPacketModelC$running[sim_node()] = FALSE;
  TossimPacketModelC$Control$stopDone(SUCCESS);
}

# 303 "/usr/lib/ncc/nesc_nx.h"
static __inline  int8_t __nesc_hton_int8(void * target, int8_t value)
#line 303
{
#line 303
  __nesc_hton_uint8(target, value);
#line 303
  return value;
}

# 110 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
inline static void TossimActiveMessageC$AMSend$sendDone(am_id_t arg_0x408c8a60, message_t * msg, error_t error){
#line 110
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(arg_0x408c8a60, msg, error);
#line 110
}
#line 110
# 103 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$Model$sendDone(message_t *msg, error_t result)
#line 103
{
  TossimActiveMessageC$AMSend$sendDone(TossimActiveMessageC$AMPacket$type(msg), msg, result);
}

# 76 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModel.nc"
inline static void TossimPacketModelC$Packet$sendDone(message_t *msg, error_t error){
#line 76
  TossimActiveMessageC$Model$sendDone(msg, error);
#line 76
}
#line 76
# 82 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static inline tossim_metadata_t *TossimPacketModelC$getMetadata(message_t *msg)
#line 82
{
  return (tossim_metadata_t *)& msg->metadata;
}

#line 145
static inline void TossimPacketModelC$sendDoneTask$runTask(void )
#line 145
{
  message_t *msg = TossimPacketModelC$sending[sim_node()];
  tossim_metadata_t *meta = TossimPacketModelC$getMetadata(msg);

#line 148
  __nesc_hton_uint8(meta->ack.nxdata, 0);
  __nesc_hton_int8(meta->strength.nxdata, 0);
  __nesc_hton_uint16(meta->time.nxdata, 0);
  TossimPacketModelC$sending[sim_node()] = FALSE;
  TossimPacketModelC$Packet$sendDone(msg, TossimPacketModelC$running[sim_node()] ? SUCCESS : EOFF);
}

# 53 "/root/local/tinyos-2.1.1/tos/system/QueueC.nc"
static inline bool /*PacketHandlerC.QueueC*/QueueC$0$Queue$empty(void )
#line 53
{
  return /*PacketHandlerC.QueueC*/QueueC$0$size[sim_node()] == 0;
}

# 50 "/root/local/tinyos-2.1.1/tos/interfaces/Queue.nc"
inline static bool PacketHandlerP$Queue$empty(void ){
#line 50
  unsigned char __nesc_result;
#line 50

#line 50
  __nesc_result = /*PacketHandlerC.QueueC*/QueueC$0$Queue$empty();
#line 50

#line 50
  return __nesc_result;
#line 50
}
#line 50
# 103 "/root/local/tinyos-2.1.1/tos/system/PoolP.nc"
static inline error_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$put(/*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool_t *newVal)
#line 103
{
  if (/*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()] >= 20) {
      return FAIL;
    }
  else {
      uint16_t emptyIndex = /*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[sim_node()] + /*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()];

#line 109
      if (emptyIndex >= 20) {
          emptyIndex -= 20;
        }
      /*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue[sim_node()][emptyIndex] = newVal;
      /*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()]++;
      sim_log_debug(195U, "PoolP", "%s size is %i\n", __FUNCTION__, (int )/*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()]);
      return SUCCESS;
    }
}

# 89 "/root/local/tinyos-2.1.1/tos/interfaces/Pool.nc"
inline static error_t PacketHandlerP$Pool$put(PacketHandlerP$Pool$t * newVal){
#line 89
  unsigned char __nesc_result;
#line 89

#line 89
  __nesc_result = /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Pool$put(newVal);
#line 89

#line 89
  return __nesc_result;
#line 89
}
#line 89
# 65 "/root/local/tinyos-2.1.1/tos/system/QueueC.nc"
static inline /*PacketHandlerC.QueueC*/QueueC$0$queue_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$head(void )
#line 65
{
  return /*PacketHandlerC.QueueC*/QueueC$0$queue[sim_node()][/*PacketHandlerC.QueueC*/QueueC$0$head[sim_node()]];
}

#line 85
static inline /*PacketHandlerC.QueueC*/QueueC$0$queue_t /*PacketHandlerC.QueueC*/QueueC$0$Queue$dequeue(void )
#line 85
{
  /*PacketHandlerC.QueueC*/QueueC$0$queue_t t = /*PacketHandlerC.QueueC*/QueueC$0$Queue$head();

#line 87
  sim_log_debug(190U, "QueueC", "%s: size is %hhu\n", __FUNCTION__, /*PacketHandlerC.QueueC*/QueueC$0$size[sim_node()]);
  if (!/*PacketHandlerC.QueueC*/QueueC$0$Queue$empty()) {
      /*PacketHandlerC.QueueC*/QueueC$0$head[sim_node()]++;
      if (/*PacketHandlerC.QueueC*/QueueC$0$head[sim_node()] == 20) {
#line 90
        /*PacketHandlerC.QueueC*/QueueC$0$head[sim_node()] = 0;
        }
#line 91
      /*PacketHandlerC.QueueC*/QueueC$0$size[sim_node()]--;
      /*PacketHandlerC.QueueC*/QueueC$0$printQueue();
    }
  return t;
}

# 81 "/root/local/tinyos-2.1.1/tos/interfaces/Queue.nc"
inline static PacketHandlerP$Queue$t  PacketHandlerP$Queue$dequeue(void ){
#line 81
  struct sendInfo *__nesc_result;
#line 81

#line 81
  __nesc_result = /*PacketHandlerC.QueueC*/QueueC$0$Queue$dequeue();
#line 81

#line 81
  return __nesc_result;
#line 81
}
#line 81
# 80 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(am_id_t arg_0x40bea498, am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = TossimActiveMessageC$AMSend$send(arg_0x40bea498, addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 78 "/root/local/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(message_t * amsg){
#line 78
  unsigned short __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$AMPacket$destination(amsg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
#line 147
inline static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(message_t * amsg){
#line 147
  unsigned char __nesc_result;
#line 147

#line 147
  __nesc_result = TossimActiveMessageC$AMPacket$type(amsg);
#line 147

#line 147
  return __nesc_result;
#line 147
}
#line 147
# 65 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline tossim_header_t *TossimActiveMessageC$getHeader(message_t *amsg)
#line 65
{
  return (tossim_header_t *)(amsg->data - sizeof(tossim_header_t ));
}

#line 181
static inline void TossimActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len)
#line 181
{
  __nesc_hton_uint8(TossimActiveMessageC$getHeader(msg)->length.nxdata, len);
}

# 94 "/root/local/tinyos-2.1.1/tos/interfaces/Packet.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(message_t * msg, uint8_t len){
#line 94
  TossimActiveMessageC$Packet$setPayloadLength(msg, len);
#line 94
}
#line 94
# 90 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len)
#line 91
{
  if (clientId >= 1) {
      return FAIL;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][clientId].msg != (void *)0) {
      return EBUSY;
    }
  sim_log_debug(196U, "AMQueue", "AMQueue: request to send from %hhu (%p): passed checks\n", clientId, msg);

  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][clientId].msg = msg;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(msg, len);

  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] >= 1) {
      error_t err;
      am_id_t amId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(msg);
      am_addr_t dest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(msg);

      sim_log_debug(197U, "AMQueue", "%s: request to send from %hhu (%p): queue empty\n", __FUNCTION__, clientId, msg);
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = clientId;

      err = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(amId, dest, msg, len);
      if (err != SUCCESS) {
          sim_log_debug(198U, "AMQueue", "%s: underlying send failed.\n", __FUNCTION__);
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = 1;
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][clientId].msg = (void *)0;
        }

      return err;
    }
  else {
      sim_log_debug(199U, "AMQueue", "AMQueue: request to send from %hhu (%p): queue not empty\n", clientId, msg);
    }
  return SUCCESS;
}

# 75 "/root/local/tinyos-2.1.1/tos/interfaces/Send.nc"
inline static error_t /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(0U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 170 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$AMPacket$setType(message_t *amsg, am_id_t t)
#line 170
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 172
  __nesc_hton_uint8(header->type.nxdata, t);
}

# 162 "/root/local/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
inline static void /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(message_t * amsg, am_id_t t){
#line 162
  TossimActiveMessageC$AMPacket$setType(amsg, t);
#line 162
}
#line 162
# 145 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$AMPacket$setDestination(message_t *amsg, am_addr_t addr)
#line 145
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 147
  __nesc_hton_uint16(header->dest.nxdata, addr);
}

# 103 "/root/local/tinyos-2.1.1/tos/interfaces/AMPacket.nc"
inline static void /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(message_t * amsg, am_addr_t addr){
#line 103
  TossimActiveMessageC$AMPacket$setDestination(amsg, addr);
#line 103
}
#line 103
# 53 "/root/local/tinyos-2.1.1/tos/system/AMQueueEntryP.nc"
static inline error_t /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 55
{
  /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(msg, dest);
  /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(msg, 6);
  return /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(msg, len);
}

# 80 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
inline static error_t PacketHandlerP$AMSend$send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 189 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void *TossimActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len)
#line 189
{
  if (len <= 28) {
      return msg->data;
    }
  else {
      return (void *)0;
    }
}

# 126 "/root/local/tinyos-2.1.1/tos/interfaces/Packet.nc"
inline static void * PacketHandlerP$Packet$getPayload(message_t * msg, uint8_t len){
#line 126
  void *__nesc_result;
#line 126

#line 126
  __nesc_result = TossimActiveMessageC$Packet$getPayload(msg, len);
#line 126

#line 126
  return __nesc_result;
#line 126
}
#line 126
# 286 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static inline error_t PacketHandlerP$PacketHandler$actuallySend(uint16_t src, uint16_t dest, pack *message)
{
  pack *msg;

  if (PacketHandlerP$busy[sim_node()]) 
    {
      sim_log_debug(156U, "genDebug", "The radio is busy");
      return EBUSY;
    }

  msg = (pack *)PacketHandlerP$Packet$getPayload(&PacketHandlerP$pkt[sim_node()], sizeof(pack ));
  *msg = *message;

  if (PacketHandlerP$AMSend$send(dest, &PacketHandlerP$pkt[sim_node()], sizeof(pack )) == SUCCESS) 
    {
      PacketHandlerP$busy[sim_node()] = TRUE;
      return SUCCESS;
    }

  sim_log_debug(157U, "genDebug", "The radio is busy, or something\n");
  return FAIL;
}

# 73 "/root/local/tinyos-2.1.1/tos/interfaces/Queue.nc"
inline static PacketHandlerP$Queue$t  PacketHandlerP$Queue$head(void ){
#line 73
  struct sendInfo *__nesc_result;
#line 73

#line 73
  __nesc_result = /*PacketHandlerC.QueueC*/QueueC$0$Queue$head();
#line 73

#line 73
  return __nesc_result;
#line 73
}
#line 73
# 257 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static inline void PacketHandlerP$sendBufferTask$runTask(void )
{
  sendInfo *info;

  if (!PacketHandlerP$Queue$empty() && !PacketHandlerP$busy[sim_node()]) 
    {
      info = PacketHandlerP$Queue$head();

      if (SUCCESS == PacketHandlerP$PacketHandler$actuallySend(info->src, info->dest, & info->packet)) 
        {

          PacketHandlerP$Queue$dequeue();
          PacketHandlerP$Pool$put(info);
        }
    }

  if (!PacketHandlerP$Queue$empty()) 
    {
      PacketHandlerP$PacketHandler$postSendTask();
    }
}

# 139 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void )
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow());
}

# 83 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$fired(void ){
#line 83
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired();
#line 83
}
#line 83
# 226 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm(void )
#line 226
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 227
    {
      unsigned int __nesc_temp = 
#line 227
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()] + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()];

      {
#line 227
        __nesc_atomic_end(__nesc_atomic); 
#line 227
        return __nesc_temp;
      }
    }
#line 229
    __nesc_atomic_end(__nesc_atomic); }
}

# 116 "/root/local/tinyos-2.1.1/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getAlarm(void ){
#line 116
  unsigned int __nesc_result;
#line 116

#line 116
  __nesc_result = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm();
#line 116

#line 116
  return __nesc_result;
#line 116
}
#line 116
#line 103
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type dt){
#line 103
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(t0, dt);
#line 103
}
#line 103
# 58 "/root/local/tinyos-2.1.1/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(uint32_t t0, uint32_t dt, bool oneshot)
{
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[sim_node()] = dt;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[sim_node()] = oneshot;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$startAt(t0, dt);
}










static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask(void )
{
  if (/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[sim_node()] == FALSE) {
    /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getAlarm(), /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[sim_node()], FALSE);
    }
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$fired();
}

#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(uint32_t t0, uint32_t dt)
{
#line 94
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(t0, dt, TRUE);
}

# 129 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(uint32_t t0, uint32_t dt){
#line 129
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(t0, dt);
#line 129
}
#line 129
# 204 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop(void )
#line 204
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 205
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()] = FALSE;
#line 205
    __nesc_atomic_end(__nesc_atomic); }
}

# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$stop(void ){
#line 73
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop();
#line 73
}
#line 73
# 71 "/root/local/tinyos-2.1.1/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop(void )
{
#line 72
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$stop();
}

# 78 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop();
#line 78
}
#line 78
# 100 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void )
{




  uint32_t now = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow();
  int32_t min_remaining = (1UL << 31) - 1;
  bool min_remaining_isset = FALSE;
  uint16_t num;

  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop();

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;
          int32_t remaining = timer->dt - elapsed;

          if (remaining < min_remaining) 
            {
              min_remaining = remaining;
              min_remaining_isset = TRUE;
            }
        }
    }

  if (min_remaining_isset) 
    {
      if (min_remaining <= 0) {
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(now);
        }
      else {
#line 135
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(now, min_remaining);
        }
    }
}

# 169 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void )
#line 169
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()], /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg, FAIL);
}

# 310 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static inline void PacketHandlerP$AMSend$sendDone(message_t *msg, error_t error)
{

  if (&PacketHandlerP$pkt[sim_node()] == msg) 
    {
      PacketHandlerP$busy[sim_node()] = FALSE;
      PacketHandlerP$PacketHandler$postSendTask();
    }
}

# 110 "/root/local/tinyos-2.1.1/tos/interfaces/AMSend.nc"
inline static void /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(message_t * msg, error_t error){
#line 110
  PacketHandlerP$AMSend$sendDone(msg, error);
#line 110
}
#line 110
# 65 "/root/local/tinyos-2.1.1/tos/system/AMQueueEntryP.nc"
static inline void /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err)
#line 65
{
  /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(m, err);
}

# 215 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err)
#line 215
{
}

# 100 "/root/local/tinyos-2.1.1/tos/interfaces/Send.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(uint8_t arg_0x40beda98, message_t * msg, error_t error){
#line 100
  switch (arg_0x40beda98) {
#line 100
    case 0U:
#line 100
      /*PacketHandlerC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(arg_0x40beda98, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 126 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void )
#line 126
{
  uint8_t i;
#line 127
  uint8_t j;
#line 127
  uint8_t mask;
#line 127
  uint8_t last;
  message_t *msg;

#line 129
  for (i = 0; i < 1 / 8 + 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][i]) {
          for (mask = 1, j = 0; j < 8; j++) {
              if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][i] & mask) {
                  last = i * 8 + j;
                  msg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][last].msg;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][last].msg = (void *)0;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][i] &= ~mask;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(last, msg, ECANCEL);
                }
              mask <<= 1;
            }
        }
    }
}

# 11 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
inline static error_t LinkStateRoutingP$PacketHandler$send(uint16_t dest, bool updateTTL){
#line 11
  unsigned char __nesc_result;
#line 11

#line 11
  __nesc_result = PacketHandlerP$PacketHandler$send(dest, updateTTL);
#line 11

#line 11
  return __nesc_result;
#line 11
}
#line 11
#line 9
inline static void LinkStateRoutingP$PacketHandler$makePack(uint16_t dest, uint8_t protocol, uint8_t *payload){
#line 9
  PacketHandlerP$PacketHandler$makePack(dest, protocol, payload);
#line 9
}
#line 9
# 254 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static inline void LinkStateRoutingP$SendNeighbors$runTask(void )
{

  LinkStateRoutingP$PacketHandler$makePack(UNSPECIFIED, PROTOCOL_LINKSTATE, LinkStateRoutingP$linkStatePacket[sim_node()]);
  LinkStateRoutingP$PacketHandler$send(AM_BROADCAST_ADDR, FALSE);


  memset(LinkStateRoutingP$linkStatePacket[sim_node()], 0, sizeof LinkStateRoutingP$linkStatePacket[sim_node()]);
}

# 221 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline void SimSchedulerBasicP$TaskBasic$default$runTask(uint8_t id)
{
}

# 75 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static void SimSchedulerBasicP$TaskBasic$runTask(uint8_t arg_0x4068f1b8){
#line 75
  switch (arg_0x4068f1b8) {
#line 75
    case Node$doFrequentEvents:
#line 75
      Node$doFrequentEvents$runTask();
#line 75
      break;
#line 75
    case Node$doModerateEvents:
#line 75
      Node$doModerateEvents$runTask();
#line 75
      break;
#line 75
    case Node$doSparseEvents:
#line 75
      Node$doSparseEvents$runTask();
#line 75
      break;
#line 75
    case Node$doRareEvents:
#line 75
      Node$doRareEvents$runTask();
#line 75
      break;
#line 75
    case TossimPacketModelC$startDoneTask:
#line 75
      TossimPacketModelC$startDoneTask$runTask();
#line 75
      break;
#line 75
    case TossimPacketModelC$stopDoneTask:
#line 75
      TossimPacketModelC$stopDoneTask$runTask();
#line 75
      break;
#line 75
    case TossimPacketModelC$sendDoneTask:
#line 75
      TossimPacketModelC$sendDoneTask$runTask();
#line 75
      break;
#line 75
    case PacketHandlerP$sendBufferTask:
#line 75
      PacketHandlerP$sendBufferTask$runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired:
#line 75
      /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer:
#line 75
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask();
#line 75
      break;
#line 75
    case LinkStateRoutingP$SendNeighbors:
#line 75
      LinkStateRoutingP$SendNeighbors$runTask();
#line 75
      break;
#line 75
    default:
#line 75
      SimSchedulerBasicP$TaskBasic$default$runTask(arg_0x4068f1b8);
#line 75
      break;
#line 75
    }
#line 75
}
#line 75
#line 67
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 177 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline uint8_t TossimActiveMessageC$Packet$payloadLength(message_t *msg)
#line 177
{
  return __nesc_ntoh_uint8(TossimActiveMessageC$getHeader(msg)->length.nxdata);
}

# 78 "/root/local/tinyos-2.1.1/tos/interfaces/Packet.nc"
inline static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$Packet$payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 65 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void )
#line 65
{
  uint8_t i;

#line 67
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] + 1) % 1;
  for (i = 0; i < 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg == (void *)0 || 
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] / 8] & (1 << /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] % 8)) 
        {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] + 1) % 1;
        }
      else {
          break;
        }
    }
  if (i >= 1) {
#line 78
    /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = 1;
    }
}

#line 174
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void )
#line 174
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket();
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] < 1) {
      error_t nextErr;
      message_t *nextMsg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg;
      am_id_t nextId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(nextMsg);
      am_addr_t nextDest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(nextMsg);
      uint8_t len = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(nextMsg);

#line 182
      nextErr = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(nextId, nextDest, nextMsg, len);
      if (nextErr != SUCCESS) {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask();
        }
    }
}

# 483 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
static inline void CpmModelC$free_receive_message(CpmModelC$receive_message_t *msg)
#line 483
{
  free(msg);
}

# 61 "/root/local/tinyos-2.1.1/tos/lib/tossim/GainRadioModel.nc"
inline static bool CpmModelC$Model$shouldAck(message_t *msg){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = TossimPacketModelC$GainRadioModel$shouldAck(msg);
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 85 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModel.nc"
inline static void TossimPacketModelC$Packet$receive(message_t *msg){
#line 85
  TossimActiveMessageC$Model$receive(msg);
#line 85
}
#line 85
# 288 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$GainRadioModel$receive(message_t *msg)
#line 288
{
  if (TossimPacketModelC$running[sim_node()] && !TossimPacketModelC$transmitting[sim_node()]) {
      TossimPacketModelC$Packet$receive(msg);
    }
}

# 60 "/root/local/tinyos-2.1.1/tos/lib/tossim/GainRadioModel.nc"
inline static void CpmModelC$Model$receive(message_t *msg){
#line 60
  TossimPacketModelC$GainRadioModel$receive(msg);
#line 60
}
#line 60
# 260 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
static inline bool CpmModelC$checkReceive(CpmModelC$receive_message_t *msg)
#line 260
{
  double noise = CpmModelC$noise_hash_generation();
  CpmModelC$receive_message_t *list = CpmModelC$outstandingReceptionHead[sim_node()];

#line 263
  noise = pow(10.0, noise / 10.0);
  while (list != (void *)0) {
      if (list != msg) {
          noise += pow(10.0, list->power / 10.0);
        }
      list = list->next;
    }
  noise = 10.0 * log(noise) / log(10.0);
  return CpmModelC$shouldReceive(msg->power - noise);
}

#line 296
static inline void CpmModelC$sim_gain_receive_handle(sim_event_t *evt)
#line 296
{
  CpmModelC$receive_message_t *mine = (CpmModelC$receive_message_t *)evt->data;
  CpmModelC$receive_message_t *predecessor = (void *)0;
  CpmModelC$receive_message_t *list = CpmModelC$outstandingReceptionHead[sim_node()];

  sim_log_debug(133U, "CpmModelC", "Handling reception event @ %s.\n", sim_time_string());
  while (list != (void *)0) {
      if (list->next == mine) {
          predecessor = list;
        }
      list = list->next;
    }
  if (predecessor) {
      predecessor->next = mine->next;
    }
  else {
#line 311
    if (mine == CpmModelC$outstandingReceptionHead[sim_node()]) {
        CpmModelC$outstandingReceptionHead[sim_node()] = mine->next;
      }
    else {
        sim_log_error(134U, "CpmModelC", "Incoming packet list structure is corrupted: entry is not the head and no entry points to it.\n");
      }
    }
#line 317
  sim_log_debug(135U, "CpmModelC,SNRLoss", "Packet from %i to %i\n", (int )mine->source, (int )sim_node());
  if (!CpmModelC$checkReceive(mine)) {
      sim_log_debug(136U, "CpmModelC,SNRLoss", " - lost packet from %i as SNR was too low.\n", (int )mine->source);
      mine->lost = 1;
    }
  if (! mine->lost) {



      tossim_metadata_t *meta = (tossim_metadata_t *)& mine->msg->metadata;

#line 327
      __nesc_hton_int8(meta->strength.nxdata, mine->strength);

      sim_log_debug_clear(137U, "CpmModelC,SNRLoss", "  -signaling reception\n");
      CpmModelC$Model$receive(mine->msg);
      if (mine->ack) {
          sim_log_debug_clear(138U, "CpmModelC", " acknowledgment requested, ");
        }
      else {
          sim_log_debug_clear(139U, "CpmModelC", " no acknowledgment requested.\n");
        }

      if (mine->ack && CpmModelC$Model$shouldAck(mine->msg)) {
          sim_log_debug_clear(140U, "CpmModelC", " scheduling ack.\n");
          CpmModelC$sim_gain_schedule_ack(mine->source, sim_time() + 1, mine);
        }
      else {
          CpmModelC$free_receive_message(mine);
        }

      CpmModelC$receiving[sim_node()] = 0;
    }
  else {
      if (RandomUniform() < 0.001) {
          sim_log_debug(141U, "CpmModelC,SNRLoss", "Packet was technically lost, but TOSSIM introduces an ack false positive rate.\n");
          if (mine->ack && CpmModelC$Model$shouldAck(mine->msg)) {
              sim_log_debug_clear(142U, "CpmModelC", " scheduling ack.\n");
              CpmModelC$sim_gain_schedule_ack(mine->source, sim_time() + 1, mine);
            }
          else {
              CpmModelC$free_receive_message(mine);
            }
        }
      else {
          CpmModelC$free_receive_message(mine);
        }
      CpmModelC$receiving[sim_node()] = 0;
      sim_log_debug_clear(143U, "CpmModelC,SNRLoss", "  -packet was lost.\n");
    }
}

#line 467
static inline sim_event_t *CpmModelC$allocate_receive_event(sim_time_t endTime, CpmModelC$receive_message_t *msg)
#line 467
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 469
  evt->mote = sim_node();
  evt->time = endTime;
  evt->handle = CpmModelC$sim_gain_receive_handle;
  evt->cleanup = sim_queue_cleanup_event;
  evt->cancelled = 0;
  evt->force = 1;
  evt->data = msg;
  return evt;
}

static inline CpmModelC$receive_message_t *CpmModelC$allocate_receive_message(void )
#line 479
{
  return (CpmModelC$receive_message_t *)malloc(sizeof(CpmModelC$receive_message_t ));
}

#line 369
static inline void CpmModelC$enqueue_receive_event(int source, sim_time_t endTime, message_t *msg, bool receive, double power, double reversePower)
#line 369
{
  sim_event_t *evt;
  CpmModelC$receive_message_t *list;
  CpmModelC$receive_message_t *rcv = CpmModelC$allocate_receive_message();
  double noiseStr = CpmModelC$packetNoise(rcv);

#line 374
  rcv->source = source;
  rcv->start = sim_time();
  rcv->end = endTime;
  rcv->power = power;
  rcv->reversePower = reversePower;




  rcv->strength = (int8_t )floor(10.0 * log(pow(10.0, power / 10.0) + pow(10.0, noiseStr / 10.0)) / log(10.0));
  rcv->msg = msg;
  rcv->lost = 0;
  rcv->ack = receive;





  if (!sim_mote_is_on(sim_node())) {
      sim_log_debug(144U, "CpmModelC", "Lost packet from %i due to %i being off\n", source, sim_node());
      rcv->lost = 1;
    }
  else {
#line 396
    if (!CpmModelC$shouldReceive(power - noiseStr)) {
        sim_log_debug(145U, "CpmModelC,SNRLoss", "Lost packet from %i to %i due to SNR being too low (%i)\n", source, sim_node(), (int )(power - noiseStr));
        rcv->lost = 1;
      }
    else {
#line 400
      if (CpmModelC$receiving[sim_node()]) {
          sim_log_debug(146U, "CpmModelC,SNRLoss", "Lost packet from %i due to %i being mid-reception\n", source, sim_node());
          rcv->lost = 1;
        }
      else {
#line 404
        if (CpmModelC$transmitting[sim_node()] && rcv->start < CpmModelC$transmissionEndTime[sim_node()] && CpmModelC$transmissionEndTime[sim_node()] <= rcv->end) {
            sim_log_debug(147U, "CpmModelC,SNRLoss", "Lost packet from %i due to %i being mid-transmission, transmissionEndTime %llu\n", source, sim_node(), CpmModelC$transmissionEndTime[sim_node()]);
            rcv->lost = 1;
          }
        else {
            CpmModelC$receiving[sim_node()] = 1;
          }
        }
      }
    }
#line 412
  list = CpmModelC$outstandingReceptionHead[sim_node()];
  while (list != (void *)0) {
      if (!CpmModelC$shouldReceive(list->power - rcv->power)) {
          sim_log_debug(148U, "Gain,SNRLoss", "Going to lose packet from %i with signal %lf as am receiving a packet from %i with signal %lf\n", list->source, list->power, source, rcv->power);
          list->lost = 1;
        }
      list = list->next;
    }

  rcv->next = CpmModelC$outstandingReceptionHead[sim_node()];
  CpmModelC$outstandingReceptionHead[sim_node()] = rcv;
  evt = CpmModelC$allocate_receive_event(endTime, rcv);
  sim_queue_insert(evt);
}


static inline void CpmModelC$sim_gain_put(int dest, message_t *msg, sim_time_t endTime, bool receive, double power, double reversePower)
#line 428
{
  int prevNode = sim_node();

#line 430
  sim_log_debug(149U, "CpmModelC", "Enqueing reception event for %i at %llu with power %lf.\n", dest, endTime, power);
  sim_set_node(dest);
  CpmModelC$enqueue_receive_event(prevNode, endTime, msg, receive, power, reversePower);
  sim_set_node(prevNode);
}

static inline void CpmModelC$Model$putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double power, double reversePower)
#line 436
{
  CpmModelC$receive_message_t *list;
  gain_entry_t *neighborEntry = sim_gain_first(sim_node());

#line 439
  CpmModelC$requestAck[sim_node()] = ack;
  CpmModelC$outgoing[sim_node()] = msg;
  CpmModelC$transmissionEndTime[sim_node()] = endTime;
  sim_log_debug(150U, "CpmModelC", "Node %i transmitting to %i, finishes at %llu.\n", sim_node(), dest, endTime);

  while (neighborEntry != (void *)0) {
      int other = neighborEntry->mote;

#line 446
      CpmModelC$sim_gain_put(other, msg, endTime, ack, power + sim_gain_value(sim_node(), other), reversePower + sim_gain_value(other, sim_node()));
      neighborEntry = sim_gain_next(neighborEntry);
    }

  list = CpmModelC$outstandingReceptionHead[sim_node()];
  while (list != (void *)0) {
      list->lost = 1;
      sim_log_debug(151U, "CpmModelC,SNRLoss", "Lost packet from %i because %i has outstanding reception, startTime %llu endTime %llu\n", list->source, sim_node(), list->start, list->end);
      list = list->next;
    }
}

# 48 "/root/local/tinyos-2.1.1/tos/lib/tossim/GainRadioModel.nc"
inline static void TossimPacketModelC$GainRadioModel$putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double gain, double reverseGain){
#line 48
  CpmModelC$Model$putOnAirTo(dest, msg, ack, endTime, gain, reverseGain);
#line 48
}
#line 48
# 280 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$send_transmit_done(sim_event_t *evt)
#line 280
{
  message_t *rval = TossimPacketModelC$sending[sim_node()];

#line 282
  TossimPacketModelC$sending[sim_node()] = (void *)0;
  TossimPacketModelC$transmitting[sim_node()] = FALSE;
  sim_log_debug(125U, "TossimPacketModelC", "PACKET: Signaling send done at %llu.\n", sim_time());
  TossimPacketModelC$Packet$sendDone(rval, TossimPacketModelC$running[sim_node()] ? SUCCESS : EOFF);
}

#line 253
static inline void TossimPacketModelC$send_transmit(sim_event_t *evt)
#line 253
{
  sim_time_t duration;
  tossim_metadata_t *metadata = TossimPacketModelC$getMetadata(TossimPacketModelC$sending[sim_node()]);

  duration = 8 * TossimPacketModelC$sendingLength[sim_node()];
  duration /= sim_csma_bits_per_symbol();
  duration += sim_csma_preamble_length();

  if (__nesc_ntoh_uint8(metadata->ack.nxdata)) {
      duration += sim_csma_ack_time();
    }
  duration *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();

  evt->time += duration;
  evt->handle = TossimPacketModelC$send_transmit_done;

  sim_log_debug(123U, "TossimPacketModelC", "PACKET: Broadcasting packet to everyone.\n");
  TossimPacketModelC$GainRadioModel$putOnAirTo(TossimPacketModelC$destNode[sim_node()], TossimPacketModelC$sending[sim_node()], __nesc_ntoh_uint8(metadata->ack.nxdata), evt->time, 0.0, 0.0);
  __nesc_hton_uint8(metadata->ack.nxdata, 0);

  evt->time += sim_csma_rxtx_delay() * (sim_ticks_per_sec() / sim_csma_symbols_per_sec());

  sim_log_debug(124U, "TossimPacketModelC", "PACKET: Send done at %llu.\n", evt->time);

  sim_queue_insert(evt);
}

# 459 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
static inline void CpmModelC$Model$setPendingTransmission(void )
#line 459
{
  CpmModelC$transmitting[sim_node()] = TRUE;
  sim_log_debug(152U, "CpmModelC", "setPendingTransmission: transmitting %i @ %s\n", CpmModelC$transmitting[sim_node()], sim_time_string());
}

# 57 "/root/local/tinyos-2.1.1/tos/lib/tossim/GainRadioModel.nc"
inline static void TossimPacketModelC$GainRadioModel$setPendingTransmission(void ){
#line 57
  CpmModelC$Model$setPendingTransmission();
#line 57
}
#line 57
# 211 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
static inline bool CpmModelC$Model$clearChannel(void )
#line 211
{
  sim_log_debug(131U, "CpmModelC", "Checking clear channel @ %s: %f <= %f \n", sim_time_string(), (double )CpmModelC$packetNoise((void *)0), CpmModelC$clearThreshold[sim_node()]);
  return CpmModelC$packetNoise((void *)0) < CpmModelC$clearThreshold[sim_node()];
}

# 56 "/root/local/tinyos-2.1.1/tos/lib/tossim/GainRadioModel.nc"
inline static bool TossimPacketModelC$GainRadioModel$clearChannel(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = CpmModelC$Model$clearChannel();
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 211 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$send_backoff(sim_event_t *evt)
#line 211
{
  TossimPacketModelC$backoffCount[sim_node()]++;
  if (TossimPacketModelC$GainRadioModel$clearChannel()) {
      TossimPacketModelC$neededFreeSamples[sim_node()]--;
    }
  else {
      TossimPacketModelC$neededFreeSamples[sim_node()] = sim_csma_min_free_samples();
    }
  if (TossimPacketModelC$neededFreeSamples[sim_node()] == 0) {
      sim_time_t delay;

#line 221
      delay = sim_csma_rxtx_delay();
      delay *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
      evt->time += delay;
      TossimPacketModelC$transmitting[sim_node()] = TRUE;
      TossimPacketModelC$GainRadioModel$setPendingTransmission();
      evt->handle = TossimPacketModelC$send_transmit;
      sim_queue_insert(evt);
    }
  else {
#line 229
    if (sim_csma_max_iterations() == 0 || 
    TossimPacketModelC$backoffCount[sim_node()] <= sim_csma_max_iterations()) {
        sim_time_t backoff = sim_random();
        sim_time_t modulo = sim_csma_high() - sim_csma_low();

#line 233
        modulo *= pow(sim_csma_exponent_base(), TossimPacketModelC$backoffCount[sim_node()]);
        backoff %= modulo;

        backoff += sim_csma_init_low();
        backoff *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
        evt->time += backoff;
        sim_queue_insert(evt);
      }
    else {
        message_t *rval = TossimPacketModelC$sending[sim_node()];

#line 243
        TossimPacketModelC$sending[sim_node()] = (void *)0;
        sim_log_debug(122U, "TossimPacketModelC", "PACKET: Failed to send packet due to busy channel.\n");
        TossimPacketModelC$Packet$sendDone(rval, EBUSY);
      }
    }
}

#line 187
static inline void TossimPacketModelC$start_csma(void )
#line 187
{
  sim_time_t first_sample;




  sim_time_t backoff = sim_random();

#line 194
  backoff %= sim_csma_init_high() - sim_csma_init_low();
  backoff += sim_csma_init_low();
  backoff *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
  sim_log_debug(121U, "TossimPacketModelC", "Starting CMSA with %lli.\n", backoff);
  first_sample = sim_time() + backoff;

  TossimPacketModelC$sendEvent[sim_node()].mote = sim_node();
  TossimPacketModelC$sendEvent[sim_node()].time = first_sample;
  TossimPacketModelC$sendEvent[sim_node()].force = 0;
  TossimPacketModelC$sendEvent[sim_node()].cancelled = 0;

  TossimPacketModelC$sendEvent[sim_node()].handle = TossimPacketModelC$send_backoff;
  TossimPacketModelC$sendEvent[sim_node()].cleanup = sim_queue_cleanup_none;
  sim_queue_insert(&TossimPacketModelC$sendEvent[sim_node()]);
}

#line 161
static inline error_t TossimPacketModelC$Packet$send(int dest, message_t *msg, uint8_t len)
#line 161
{
  if (!TossimPacketModelC$initialized[sim_node()]) {
      sim_log_error(119U, "TossimPacketModelC", "TossimPacketModelC: Send.send() called, but not initialized!\n");
      return EOFF;
    }
  if (!TossimPacketModelC$running[sim_node()]) {
      sim_log_error(120U, "TossimPacketModelC", "TossimPacketModelC: Send.send() called, but not running!\n");
      return EOFF;
    }

  if (TossimPacketModelC$sending[sim_node()] != (void *)0) {
      return EBUSY;
    }
  TossimPacketModelC$sendingLength[sim_node()] = len;
  TossimPacketModelC$sending[sim_node()] = msg;
  TossimPacketModelC$destNode[sim_node()] = dest;
  TossimPacketModelC$backoffCount[sim_node()] = 0;
  TossimPacketModelC$neededFreeSamples[sim_node()] = sim_csma_min_free_samples();
  TossimPacketModelC$start_csma();
  return SUCCESS;
}

# 57 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModel.nc"
inline static error_t TossimActiveMessageC$Model$send(int node, message_t *msg, uint8_t len){
#line 57
  unsigned char __nesc_result;
#line 57

#line 57
  __nesc_result = TossimPacketModelC$Packet$send(node, msg, len);
#line 57

#line 57
  return __nesc_result;
#line 57
}
#line 57
# 90 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
static inline double CpmModelC$timeInMs(void )
#line 90
{
  sim_time_t ftime = sim_time();
  int hours;
#line 92
  int minutes;
#line 92
  int seconds;
  sim_time_t secondBillionths;
  int temp_time;
  double ms_time;

  secondBillionths = ftime % sim_ticks_per_sec();
  if (sim_ticks_per_sec() > (sim_time_t )1000000000) {
      secondBillionths /= sim_ticks_per_sec() / (sim_time_t )1000000000;
    }
  else {
      secondBillionths *= (sim_time_t )1000000000 / sim_ticks_per_sec();
    }
  temp_time = (int )(secondBillionths / 10000);

  if (temp_time % 10 >= 5) {
      temp_time += 10 - temp_time % 10;
    }
  else {
      temp_time -= temp_time % 10;
    }
  ms_time = (float )(temp_time / 100.0);

  seconds = (int )(ftime / sim_ticks_per_sec());
  minutes = seconds / 60;
  hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;

  ms_time += (hours * 3600 + minutes * 60 + seconds) * 1000;

  return ms_time;
}

#line 230
static inline double CpmModelC$prr_estimate_from_snr(double SNR)
#line 230
{



  double beta1 = 0.9794;
  double beta2 = 2.3851;
  double X = SNR - beta2;
  double PSE = 0.5 * erfc(beta1 * X / sqrt(2));
  double prr_hat = pow(1 - PSE, 23 * 2);

#line 239
  sim_log_debug(132U, "CpmModelC,SNR", "SNR is %lf, PRR is %lf\n", SNR, prr_hat);
  if (prr_hat > 1) {
    prr_hat = 1.1;
    }
  else {
#line 242
    if (prr_hat < 0) {
      prr_hat = -0.1;
      }
    }
#line 245
  return prr_hat;
}

# 127 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static inline bool TossimActiveMessageC$Model$shouldAck(message_t *msg)
#line 127
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(msg);

#line 129
  if (__nesc_ntoh_uint16(header->dest.nxdata) == TossimActiveMessageC$amAddress()) {
      sim_log_debug(112U, "Acks", "Received packet addressed to me so ack it\n");
      return TRUE;
    }
  return FALSE;
}

# 87 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModel.nc"
inline static bool TossimPacketModelC$Packet$shouldAck(message_t *msg){
#line 87
  unsigned char __nesc_result;
#line 87

#line 87
  __nesc_result = TossimActiveMessageC$Model$shouldAck(msg);
#line 87

#line 87
  return __nesc_result;
#line 87
}
#line 87
# 296 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$GainRadioModel$acked(message_t *msg)
#line 296
{
  if (TossimPacketModelC$running[sim_node()]) {
      tossim_metadata_t *metadata = TossimPacketModelC$getMetadata(TossimPacketModelC$sending[sim_node()]);

#line 299
      __nesc_hton_uint8(metadata->ack.nxdata, 1);
      if (msg != TossimPacketModelC$sending[sim_node()]) {
          TossimPacketModelC$error[sim_node()] = 1;
          sim_log_debug(126U, "TossimPacketModelC", "Requested ack for 0x%x, but outgoing packet is 0x%x.\n", msg, TossimPacketModelC$sending[sim_node()]);
        }
    }
}

# 59 "/root/local/tinyos-2.1.1/tos/lib/tossim/GainRadioModel.nc"
inline static void CpmModelC$Model$acked(message_t *msg){
#line 59
  TossimPacketModelC$GainRadioModel$acked(msg);
#line 59
}
#line 59
# 151 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
static inline double CpmModelC$arr_estimate_from_snr(double SNR)
#line 151
{
  double beta1 = 0.9794;
  double beta2 = 2.3851;
  double X = SNR - beta2;
  double PSE = 0.5 * erfc(beta1 * X / sqrt(2));
  double prr_hat = pow(1 - PSE, 23 * 2);

#line 157
  sim_log_debug(129U, "CpmModelC,SNRLoss", "SNR is %lf, ARR is %lf\n", SNR, prr_hat);
  if (prr_hat > 1) {
    prr_hat = 1.1;
    }
  else {
#line 160
    if (prr_hat < 0) {
      prr_hat = -0.1;
      }
    }
#line 163
  return prr_hat;
}

static inline int CpmModelC$shouldAckReceive(double snr)
#line 166
{
  double prr = CpmModelC$arr_estimate_from_snr(snr);
  double coin = RandomUniform();

#line 169
  if (prr >= 0 && prr <= 1) {
      if (coin < prr) {
        prr = 1.0;
        }
      else {
#line 173
        prr = 0.0;
        }
    }
#line 175
  return (int )prr;
}

static inline void CpmModelC$sim_gain_ack_handle(sim_event_t *evt)
#line 178
{






  if (
#line 184
  CpmModelC$requestAck[sim_node()] && 
  CpmModelC$outgoing[sim_node()] != (void *)0 && 
  sim_mote_is_on(sim_node())) {
      CpmModelC$receive_message_t *rcv = (CpmModelC$receive_message_t *)evt->data;
      double power = rcv->reversePower;
      double noise = CpmModelC$packetNoise(rcv);
      double snr = power - noise;

#line 191
      if (CpmModelC$shouldAckReceive(snr)) {
          CpmModelC$Model$acked(CpmModelC$outgoing[sim_node()]);
        }
    }
  CpmModelC$free_receive_message((CpmModelC$receive_message_t *)evt->data);
}

# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t PacketHandlerP$sendBufferTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(PacketHandlerP$sendBufferTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 280 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static inline void PacketHandlerP$sendTimer$fired(void )
{
  PacketHandlerP$sendBufferTask$postTask();
}

# 236 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
static inline socket_t TransportP$Transport$accept(socket_t fd)
{
  return FAIL;
}

#line 152
static inline void TransportP$AttemptConnection$fired(void )
{
  socket_t newFd = TransportP$Transport$accept(0);

#line 155
  if (newFd != NULL_SOCKET) 
    {
    }
  else 

    {
    }
}

# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t Node$doFrequentEvents$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(Node$doFrequentEvents);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 138 "/root/workspace/Project1/src/Node.nc"
static inline void Node$FrequentUpdate$fired(void )
{
  Node$doFrequentEvents$postTask();
}

# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t Node$doModerateEvents$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(Node$doModerateEvents);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 145 "/root/workspace/Project1/src/Node.nc"
static inline void Node$ModerateUpdate$fired(void )
{
  Node$doModerateEvents$postTask();
}

# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t Node$doSparseEvents$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(Node$doSparseEvents);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 152 "/root/workspace/Project1/src/Node.nc"
static inline void Node$SparseUpdate$fired(void )
{
  Node$doSparseEvents$postTask();
}

# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t Node$doRareEvents$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(Node$doRareEvents);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 159 "/root/workspace/Project1/src/Node.nc"
static inline void Node$RareUpdate$fired(void )
{
  Node$doRareEvents$postTask();
}

# 204 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(uint8_t num)
{
}

# 83 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(uint8_t arg_0x40b7e3a8){
#line 83
  switch (arg_0x40b7e3a8) {
#line 83
    case 0U:
#line 83
      PacketHandlerP$sendTimer$fired();
#line 83
      break;
#line 83
    case 1U:
#line 83
      TransportP$AttemptConnection$fired();
#line 83
      break;
#line 83
    case 2U:
#line 83
      Node$FrequentUpdate$fired();
#line 83
      break;
#line 83
    case 3U:
#line 83
      Node$ModerateUpdate$fired();
#line 83
      break;
#line 83
    case 4U:
#line 83
      Node$SparseUpdate$fired();
#line 83
      break;
#line 83
    case 5U:
#line 83
      Node$RareUpdate$fired();
#line 83
      break;
#line 83
    default:
#line 83
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(arg_0x40b7e3a8);
#line 83
      break;
#line 83
    }
#line 83
}
#line 83
# 54 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type t){
#line 54
  HplAtm128Timer0AsyncP$Compare$set(t);
#line 54
}
#line 54
# 61 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Timer.nc"
inline static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$timer_size /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get(void ){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = HplAtm128Timer0AsyncP$Timer0$get();
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 569 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline int HplAtm128Timer0AsyncP$TimerAsync$compareBusy(void )
#line 569
{
  return (* (volatile uint8_t *)&atm128RegFile[sim_node()][0x30] & (1 << OCR0UB)) != 0;
}

# 44 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
inline static int /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$compareBusy(void ){
#line 44
  int __nesc_result;
#line 44

#line 44
  __nesc_result = HplAtm128Timer0AsyncP$TimerAsync$compareBusy();
#line 44

#line 44
  return __nesc_result;
#line 44
}
#line 44
# 74 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setOcr0(uint8_t n)
#line 74
{
  while (/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$compareBusy()) 
    ;
  if (n == /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get()) {
    n++;
    }


  if (/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] + n + 1 < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()]) {
    n = -/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] - 1;
    }
#line 84
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(n);
}

# 577 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$cancel_compare(void )
#line 577
{
  sim_log_debug(184U, "HplAtm128CompareC", "Cancelling compare at 0x%p\n", HplAtm128Timer0AsyncP$compare[sim_node()]);
  if (HplAtm128Timer0AsyncP$compare[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$compare[sim_node()]->cancelled = 1;
      HplAtm128Timer0AsyncP$compare[sim_node()]->cleanup = sim_queue_cleanup_total;
    }
}

#line 116
static inline void HplAtm128Timer0AsyncP$notify_changed(void )
#line 116
{
  uint8_t newScale = HplAtm128Timer0AsyncP$Timer0$getScale();

#line 118
  if (newScale != AVR_CLOCK_OFF && 
  HplAtm128Timer0AsyncP$oldScale[sim_node()] == AVR_CLOCK_OFF) {
      HplAtm128Timer0AsyncP$lastZero[sim_node()] = sim_time();
    }
  HplAtm128Timer0AsyncP$oldScale[sim_node()] = newScale;

  HplAtm128Timer0AsyncP$schedule_new_compare();
}

#line 545
static inline void HplAtm128Timer0AsyncP$cancel_overflow(void )
#line 545
{
  if (HplAtm128Timer0AsyncP$overflow[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$overflow[sim_node()]->cancelled = 1;
      sim_log_debug(183U, "HplAtm128Timer0AsyncP", "Cancelling overflow %p.\n", HplAtm128Timer0AsyncP$overflow[sim_node()]);
      HplAtm128Timer0AsyncP$overflow[sim_node()]->cleanup = sim_queue_cleanup_total;
    }
}

#line 481
static inline void HplAtm128Timer0AsyncP$timer0_overflow_handle(sim_event_t *evt)
#line 481
{
  if (evt->cancelled) {
      return;
    }
  else {
      if ((atm128RegFile[sim_node()][ATM128_TIMSK] & (1 << TOIE0)) != 0) {
          atm128RegFile[sim_node()][ATM128_TIFR] &= ~(1 << TOV0);
          sim_log_debug(180U, "HplAtm128Timer0AsyncP", "Overflow interrupt at %s\n", sim_time_string());
          INTERRUPT_16();
        }
      else {
          sim_log_debug(181U, "HplAtm128Timer0AsyncP", "Setting overflow bit at %s\n", sim_time_string());
          atm128RegFile[sim_node()][ATM128_TIFR] |= 1 << TOV0;
        }
      HplAtm128Timer0AsyncP$configure_overflow(evt);
      sim_queue_insert(evt);
    }
}

static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_overflow(void )
#line 500
{
  sim_event_t *newEvent = sim_queue_allocate_event();

  newEvent->handle = HplAtm128Timer0AsyncP$timer0_overflow_handle;
  newEvent->cleanup = sim_queue_cleanup_none;
  return newEvent;
}

#line 534
static inline void HplAtm128Timer0AsyncP$schedule_new_overflow(void )
#line 534
{
  sim_event_t *newEvent = HplAtm128Timer0AsyncP$allocate_overflow();

#line 536
  HplAtm128Timer0AsyncP$configure_overflow(newEvent);

  if (HplAtm128Timer0AsyncP$overflow[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$cancel_overflow();
    }
  HplAtm128Timer0AsyncP$overflow[sim_node()] = newEvent;
  sim_queue_insert(newEvent);
}

#line 148
static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t)
#line 148
{
  t *= sim_ticks_per_sec();
  t /= HplAtm128Timer0AsyncP$notify_clockTicksPerSec();
  return t;
}

#line 297
static inline void HplAtm128Timer0AsyncP$Timer0$set(uint8_t newVal)
#line 297
{
  uint8_t curVal = HplAtm128Timer0AsyncP$Timer0$get();

#line 299
  sim_log_debug(173U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Setting timer: %hhu\n", newVal);
  if (newVal == curVal) {
      return;
    }
  else {
      sim_time_t adjustment = curVal - newVal;

#line 305
      adjustment = adjustment << HplAtm128Timer0AsyncP$shiftFromScale();
      adjustment = HplAtm128Timer0AsyncP$clock_to_sim(adjustment);

      if (newVal < curVal) {
          HplAtm128Timer0AsyncP$lastZero[sim_node()] += adjustment;
        }
      else {
          HplAtm128Timer0AsyncP$lastZero[sim_node()] -= adjustment;
        }

      HplAtm128Timer0AsyncP$schedule_new_overflow();
      HplAtm128Timer0AsyncP$notify_changed();
    }
}

#line 187
static inline void HplAtm128Timer0AsyncP$timer0_compare_handle(sim_event_t *evt)
#line 187
{
  sim_log_debug(163U, "HplAtm128Timer0AsyncP", "Beginning compare 0x%p at %s\n", evt, sim_time_string());
  if (evt->cancelled) {
      return;
    }
  else {
      char timeStr[128];

#line 194
      sim_print_now(timeStr, 128);
      sim_log_debug(164U, "HplAtm128Timer0AsyncP", "Handling compare at 0x%p @ %s\n", evt, sim_time_string());

      if ((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM01)) != 0 && !((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM00)) != 0)) {
          sim_log_debug(165U, "HplAtm128Timer0AsyncP", "%s: CTC is set, clear timer.\n", __FUNCTION__);
          HplAtm128Timer0AsyncP$Timer0$set(0);
        }
      else {
          sim_log_debug(166U, "HplAtm128Timer0AsyncP", "%s: TCCR is 0x%hhx, %i, %i\n", __FUNCTION__, * (volatile uint8_t *)&atm128RegFile[sim_node()][0x33], (int )((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM01)) != 0), (int )((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM00)) != 0));
        }

      if ((atm128RegFile[sim_node()][ATM128_TIMSK] & (1 << OCIE0)) != 0) {
          sim_log_debug(167U, "HplAtm128Timer0AsyncP", "TIFR is %hhx\n", * (volatile uint8_t *)&atm128RegFile[sim_node()][0x36]);
          atm128RegFile[sim_node()][ATM128_TIFR] &= ~(1 << OCF0);
          sim_log_debug(168U, "HplAtm128Timer0AsyncP", "TIFR is %hhx\n", * (volatile uint8_t *)&atm128RegFile[sim_node()][0x36]);
          sim_log_debug(169U, "HplAtm128Timer0AsyncP", "Compare interrupt @ %s\n", timeStr);
          INTERRUPT_15();
        }
      else {
          atm128RegFile[sim_node()][ATM128_TIFR] |= 1 << OCF0;
        }

      if (! evt->cancelled) {
          HplAtm128Timer0AsyncP$configure_compare(evt);
          sim_queue_insert(evt);
        }
    }
}

static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_compare(void )
#line 223
{
  sim_event_t *newEvent = sim_queue_allocate_event();

#line 225
  sim_log_debug(170U, "HplAtm128Timer0AsyncP", "Allocated compare at 0x%p\n", newEvent);
  newEvent->handle = HplAtm128Timer0AsyncP$timer0_compare_handle;
  newEvent->cleanup = sim_queue_cleanup_none;
  return newEvent;
}

# 230 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow(void )
#line 230
{
}

# 70 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Timer.nc"
inline static void HplAtm128Timer0AsyncP$Timer0$overflow(void ){
#line 70
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow();
#line 70
}
#line 70
# 58 "/root/local/tinyos-2.1.1/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow(void )
{
}

# 82 "/root/local/tinyos-2.1.1/tos/lib/timer/Counter.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$overflow(void ){
#line 82
  /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow();
#line 82
}
#line 82
# 85 "/root/local/tinyos-2.1.1/tos/chips/atm128/sim/atm128hardware.h"
static __inline void __nesc_enable_interrupt()
#line 85
{
  atm128RegFile[sim_node()][* (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F]] |= 1 << 7;
}

# 48 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get(void ){
#line 48
  unsigned char __nesc_result;
#line 48

#line 48
  __nesc_result = HplAtm128Timer0AsyncP$Compare$get();
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 149 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired(void )
#line 149
{
  int overflowed;


  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] += /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get() + 1U;
  overflowed = !/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()];
  __nesc_enable_interrupt();
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt();
  if (overflowed) {
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$overflow();
    }
}

# 58 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void HplAtm128Timer0AsyncP$Compare$fired(void ){
#line 58
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired();
#line 58
}
#line 58
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 81 "/root/local/tinyos-2.1.1/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired(void )
{
#line 82
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$postTask();
}

# 78 "/root/local/tinyos-2.1.1/tos/lib/timer/Alarm.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$fired(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired();
#line 78
}
#line 78
# 67 "/root/local/tinyos-2.1.1/tos/interfaces/TaskBasic.nc"
inline static error_t TossimPacketModelC$startDoneTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(TossimPacketModelC$startDoneTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t LinkStateRoutingP$SendNeighbors$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(LinkStateRoutingP$SendNeighbors);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 61 "/root/local/tinyos-2.1.1/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP$SubInit$default$init(void )
#line 61
{
  return SUCCESS;
}

# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
inline static error_t MotePlatformP$SubInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MotePlatformP$SubInit$default$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 59 "/root/local/tinyos-2.1.1/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr(void )
#line 59
{
#line 59
  atm128RegFile[sim_node()][27U] &= ~(1 << 4);
}

# 41 "/root/local/tinyos-2.1.1/tos/interfaces/GeneralIO.nc"
inline static void MotePlatformP$SerialIdPin$clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr();
#line 41
}
#line 41
# 62 "/root/local/tinyos-2.1.1/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput(void )
#line 62
{
#line 62
  atm128RegFile[sim_node()][26U] &= ~(1 << 4);
}

# 44 "/root/local/tinyos-2.1.1/tos/interfaces/GeneralIO.nc"
inline static void MotePlatformP$SerialIdPin$makeInput(void ){
#line 44
  /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput();
#line 44
}
#line 44
# 49 "/root/local/tinyos-2.1.1/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP$PlatformInit$init(void )
#line 49
{

  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x15] = 0;
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x14] = 0xff;


  MotePlatformP$SerialIdPin$makeInput();
  MotePlatformP$SerialIdPin$clr();

  return MotePlatformP$SubInit$init();
}

# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
inline static error_t PlatformP$MoteInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MotePlatformP$PlatformInit$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 69 "/root/local/tinyos-2.1.1/tos/types/TinyError.h"
static inline  error_t ecombine(error_t r1, error_t r2)




{
  return r1 == r2 ? r1 : FAIL;
}

# 21 "/root/local/tinyos-2.1.1/tos/platforms/mica/sim/MeasureClockC.nc"
static inline error_t MeasureClockC$Init$init(void )
#line 21
{
  return SUCCESS;
}

# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
inline static error_t PlatformP$MeasureClock$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MeasureClockC$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 51 "/root/local/tinyos-2.1.1/tos/platforms/mica/PlatformP.nc"
static inline error_t PlatformP$Init$init(void )
{
  error_t ok;


  ok = PlatformP$MeasureClock$init();
  ok = ecombine(ok, PlatformP$MoteInit$init());

  return ok;
}

# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
inline static error_t SimMainP$PlatformInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformP$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 65 "/root/local/tinyos-2.1.1/tos/interfaces/Scheduler.nc"
inline static bool SimMainP$Scheduler$runNextTask(void ){
#line 65
  unsigned char __nesc_result;
#line 65

#line 65
  __nesc_result = SimSchedulerBasicP$Scheduler$runNextTask();
#line 65

#line 65
  return __nesc_result;
#line 65
}
#line 65
# 86 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static inline error_t TossimPacketModelC$Init$init(void )
#line 86
{
  sim_log_debug(114U, "TossimPacketModelC", "TossimPacketModelC: Init.init() called\n");
  TossimPacketModelC$initialized[sim_node()] = TRUE;



  TossimPacketModelC$sendEvent[sim_node()].cancelled = 1;
  return SUCCESS;
}

# 447 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$Compare$start(void )
#line 447
{
#line 447
  atm128RegFile[sim_node()][ATM128_TIMSK] |= 1 << OCIE0;
}

# 65 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$start(void ){
#line 65
  HplAtm128Timer0AsyncP$Compare$start();
#line 65
}
#line 65
# 364 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(Atm128TimerControl_t x)
#line 364
{
  sim_log_debug(175U, "HplAtm128Timer0AsyncP", "Setting control to be 0x%hhx\n", x.flat);
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x33] = x.flat;
}

# 46 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$setControl(Atm128TimerControl_t control){
#line 46
  HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(control);
#line 46
}
#line 46
# 561 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous(void )
#line 561
{
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x30] |= 1 << AS0;
}

# 32 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$setTimer0Asynchronous(void ){
#line 32
  HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous();
#line 32
}
#line 32
# 54 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline error_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init(void )
#line 54
{
  /* atomic removed: atomic calls only */
  {
    Atm128TimerControl_t x;

    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$setTimer0Asynchronous();
    x.flat = 0;
    x.bits.cs = 3;
    x.bits.wgm1 = 1;
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$setControl(x);
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT);
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$start();
  }
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt();
  return SUCCESS;
}

# 65 "/root/local/tinyos-2.1.1/tos/system/PoolP.nc"
static inline error_t /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Init$init(void )
#line 65
{
  int i;

#line 67
  for (i = 0; i < 20; i++) {
      /*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue[sim_node()][i] = &/*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool[sim_node()][i];
    }
  /*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[sim_node()] = 20;
  /*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[sim_node()] = 0;
  return SUCCESS;
}

# 55 "/root/local/tinyos-2.1.1/tos/system/RandomMlcgC.nc"
static inline error_t RandomMlcgC$Init$init(void )
#line 55
{
  /* atomic removed: atomic calls only */
#line 56
  RandomMlcgC$seed[sim_node()] = (uint32_t )(TOS_NODE_ID + 1);

  return SUCCESS;
}

# 62 "/root/local/tinyos-2.1.1/tos/interfaces/Init.nc"
inline static error_t SimMainP$SoftwareInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = RandomMlcgC$Init$init();
#line 62
  __nesc_result = ecombine(__nesc_result, /*PacketHandlerC.PoolC.PoolP*/PoolP$0$Init$init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init());
#line 62
  __nesc_result = ecombine(__nesc_result, TossimPacketModelC$Init$init());
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 46 "/root/local/tinyos-2.1.1/tos/interfaces/Random.nc"
inline static uint32_t Node$Random$rand32(void ){
#line 46
  unsigned int __nesc_result;
#line 46

#line 46
  __nesc_result = RandomMlcgC$Random$rand32();
#line 46

#line 46
  return __nesc_result;
#line 46
}
#line 46
inline static uint32_t TransportP$Random$rand32(void ){
#line 46
  unsigned int __nesc_result;
#line 46

#line 46
  __nesc_result = RandomMlcgC$Random$rand32();
#line 46

#line 46
  return __nesc_result;
#line 46
}
#line 46
# 23 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
static inline void TransportP$Transport$initialize(void )
{
  memset(TransportP$TCPTable[sim_node()], 0, sizeof TransportP$TCPTable[sim_node()]);
  TransportP$Attempt_Connection_Time[sim_node()] = TransportP$Random$rand32() % 200 + 3999;
}

# 20 "/root/workspace/Project1/src/lib/interfaces/Transport.nc"
inline static void Node$Transport$initialize(void ){
#line 20
  TransportP$Transport$initialize();
#line 20
}
#line 20
# 21 "/root/workspace/Project1/src/lib/modules/NeighborDiscoveryP.nc"
static inline void NeighborDiscoveryP$NeighborDiscovery$initialize(void )
{
  memset(NeighborDiscoveryP$pingPacket[sim_node()], 0, sizeof NeighborDiscoveryP$pingPacket[sim_node()]);
}

# 6 "/root/workspace/Project1/src/lib/interfaces/NeighborDiscovery.nc"
inline static void Node$NeighborDiscovery$initialize(void ){
#line 6
  NeighborDiscoveryP$NeighborDiscovery$initialize();
#line 6
}
#line 6
# 32 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static inline void PacketHandlerP$PacketHandler$initialize(void )
{
}

# 5 "/root/workspace/Project1/src/lib/interfaces/PacketHandler.nc"
inline static void Node$PacketHandler$initialize(void ){
#line 5
  PacketHandlerP$PacketHandler$initialize();
#line 5
}
#line 5
# 29 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static inline void LinkStateRoutingP$LinkStateRouting$initialize(void )
{

  memset(LinkStateRoutingP$linkStatePacket[sim_node()], 0, sizeof LinkStateRoutingP$linkStatePacket[sim_node()]);
  memset(LinkStateRoutingP$linkStates[sim_node()], 0, sizeof LinkStateRoutingP$linkStates[sim_node()]);
  memset(LinkStateRoutingP$compareBuffer[sim_node()], 0, sizeof LinkStateRoutingP$compareBuffer[sim_node()]);
  memset(LinkStateRoutingP$hopThrough[sim_node()], 0, sizeof LinkStateRoutingP$hopThrough[sim_node()]);
  memset(LinkStateRoutingP$existing[sim_node()], 0, sizeof LinkStateRoutingP$existing[sim_node()]);
  memset(LinkStateRoutingP$unconsidered[sim_node()], 0, sizeof LinkStateRoutingP$unconsidered[sim_node()]);
}

# 5 "/root/workspace/Project1/src/lib/interfaces/LinkStateRouting.nc"
inline static void Node$LinkStateRouting$initialize(void ){
#line 5
  LinkStateRoutingP$LinkStateRouting$initialize();
#line 5
}
#line 5
# 16 "/root/workspace/Project1/src/lib/modules/CommandHandlerP.nc"
static inline void CommandHandlerP$CommandHandler$initialize(void )
{
}

# 5 "/root/workspace/Project1/src/lib/interfaces/CommandHandler.nc"
inline static void Node$CommandHandler$initialize(void ){
#line 5
  CommandHandlerP$CommandHandler$initialize();
#line 5
}
#line 5
# 45 "/root/workspace/Project1/src/Node.nc"
static inline void Node$Boot$booted(void )
{
  Node$SplitControl$start();


  Node$CommandHandler$initialize();
  Node$LinkStateRouting$initialize();
  Node$PacketHandler$initialize();
  Node$NeighborDiscovery$initialize();
  Node$Transport$initialize();


  Node$PeriodFrequent[sim_node()] = Node$Random$rand32() % 200 + 3999;
  Node$PeriodModerate[sim_node()] = Node$Random$rand32() % 2000 + 19991;
  Node$PeriodSparse[sim_node()] = Node$Random$rand32() % 20000 + 189999;
  Node$PeriodRare[sim_node()] = Node$Random$rand32() % 40000 + 889999;

  Node$FrequentUpdate$startOneShot(Node$PeriodFrequent[sim_node()]);
  Node$ModerateUpdate$startOneShot(Node$PeriodModerate[sim_node()]);
  Node$SparseUpdate$startOneShot(Node$PeriodSparse[sim_node()]);
  Node$RareUpdate$startOneShot(Node$PeriodRare[sim_node()]);

  sim_log_debug(47U, "genDebug", "Booted\n");
}

# 60 "/root/local/tinyos-2.1.1/tos/interfaces/Boot.nc"
inline static void SimMainP$Boot$booted(void ){
#line 60
  Node$Boot$booted();
#line 60
}
#line 60
# 55 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMoteP.nc"
static inline long long int SimMoteP$SimMote$getEuid(void )
#line 55
{
  return SimMoteP$euid[sim_node()];
}

#line 58
static inline void SimMoteP$SimMote$setEuid(long long int e)
#line 58
{
  SimMoteP$euid[sim_node()] = e;
}







static inline int SimMoteP$SimMote$getVariableInfo(char *name, void **addr, size_t *size)
#line 68
{
  return __nesc_nido_resolve(sim_node(), name, (uintptr_t *)addr, (size_t *)size);
}

#line 85
static inline void SimMoteP$SimMote$turnOff(void )
#line 85
{
  SimMoteP$isOn[sim_node()] = FALSE;
}

#line 157
static inline void SimMoteP$sim_mote_boot_handle(sim_event_t *e)
#line 157
{
  char buf[128];

#line 159
  sim_print_now(buf, 128);

  SimMoteP$bootEvent[sim_node()] = (sim_event_t *)(void *)0;
  sim_log_debug(108U, "SimMoteP", "Turning on mote %i at time %s.\n", (int )sim_node(), buf);
  SimMoteP$SimMote$turnOn();
}

# 46 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_event_queue.c"
  void sim_queue_init()
#line 46
{
  init_heap(&eventHeap);
}

  void sim_queue_insert(sim_event_t *event)
#line 50
{
  sim_log_debug(0U, "Queue", "Inserting 0x%p\n", event);
  heap_insert(&eventHeap, event, event->time);
}

# 246 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_log.c"
static void sim_log_debug(uint16_t id, char *string, const char *format, ...)
#line 246
{
  va_list args;
  int i;

#line 249
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 254
      __builtin_va_start(args, format);
      fprintf(file, "DEBUG (%i): ", (int )sim_node());
      vfprintf(file, format, args);
      fflush(file);
    }
}

#line 84
static void fillInOutput(int id, char *name)
#line 84
{
  char *termination = name;
  char *namePos = name;
  int count = 0;
  char *newName = (char *)malloc(strlen(name) + 1);

#line 89
  memset(newName, 0, strlen(name) + 1);

  while (termination != (void *)0) {
      sim_log_channel_t *channel;

      termination = strrchr(namePos, ',');

      if (termination == (void *)0) {
          strcpy(newName, namePos);
        }
      else 
        {
          memcpy(newName, namePos, termination - namePos);
          newName[termination - namePos] = 0;
        }

      channel = hashtable_search(channelTable, newName);
      if (channel != (void *)0) {
          count += channel->numOutputs;
        }

      namePos = termination + 1;
    }

  termination = name;
  namePos = name;


  outputs[id].files = (FILE **)malloc(sizeof(FILE *) * count);
  outputs[id].num = 0;


  while (termination != (void *)0) {
      sim_log_channel_t *channel;

      termination = strrchr(namePos, ',');

      if (termination == (void *)0) {
          strcpy(newName, namePos);
        }
      else 
        {
          memcpy(newName, namePos, termination - namePos);
          newName[termination - namePos] = 0;
        }

      channel = hashtable_search(channelTable, newName);
      if (channel != (void *)0) {
          int i;
#line 137
          int j;

#line 138
          for (i = 0; i < channel->numOutputs; i++) {
              int duplicate = 0;
              int outputCount = outputs[id].num;


              for (j = 0; j < outputCount; j++) {
                  if (fileno(outputs[id].files[j]) == fileno(channel->outputs[i])) {
                      duplicate = 1;
                      j = outputCount;
                    }
                }
              if (!duplicate) {
                  outputs[id].files[outputCount] = channel->outputs[i];
                  outputs[id].num++;
                }
            }
        }
      namePos = termination + 1;
    }
}

# 121 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_tossim.c"
  unsigned long sim_node()
#line 121
{
  return current_node;
}

# 197 "/root/local/tinyos-2.1.1/tos/lib/tossim/heap.c"
static void up_heap(heap_t *heap, int findex)
#line 197
{
  int parent_index;

#line 199
  if (findex == 0) {
      return;
    }

  parent_index = (findex - 1) / 2;

  if (((node_t *)heap->data)[parent_index].key > ((node_t *)heap->data)[findex].key) {
      swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[parent_index]);
      up_heap(heap, parent_index);
    }
}

#line 158
static void swap(node_t *first, node_t *second)
#line 158
{
  long long int key;
  void *data;

  key = first->key;
  first->key = second->key;
  second->key = key;

  data = first->data;
  first->data = second->data;
  second->data = data;
}

# 55 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_event_queue.c"
  sim_event_t *sim_queue_pop()
#line 55
{
  long long int key;

#line 57
  return (sim_event_t *)heap_pop_min_data(&eventHeap, &key);
}

# 114 "/root/local/tinyos-2.1.1/tos/lib/tossim/heap.c"
static void *heap_pop_min_data(heap_t *heap, long long int *key)
#line 114
{
  int last_index = heap->size - 1;
  void *data = ((node_t *)heap->data)[0].data;

#line 117
  if (key != (void *)0) {
      *key = ((node_t *)heap->data)[0].key;
    }
  ((node_t *)heap->data)[0].data = ((node_t *)heap->data)[last_index].data;
  ((node_t *)heap->data)[0].key = ((node_t *)heap->data)[last_index].key;

  heap->size--;

  down_heap(heap, 0);

  return data;
}

#line 171
static void down_heap(heap_t *heap, int findex)
#line 171
{
  int right_index = (findex + 1) * 2;
  int left_index = findex * 2 + 1;

  if (right_index < heap->size) {
      long long int left_key = ((node_t *)heap->data)[left_index].key;
      long long int right_key = ((node_t *)heap->data)[right_index].key;
      int min_key_index = left_key < right_key ? left_index : right_index;

      if (((node_t *)heap->data)[min_key_index].key < ((node_t *)heap->data)[findex].key) {
          swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[min_key_index]);
          down_heap(heap, min_key_index);
        }
    }
  else {
#line 185
    if (left_index >= heap->size) {
        return;
      }
    else {
        long long int left_key = ((node_t *)heap->data)[left_index].key;

#line 190
        if (left_key < ((node_t *)heap->data)[findex].key) {
            swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[left_index]);
            return;
          }
      }
    }
}

# 60 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_event_queue.c"
  bool sim_queue_is_empty()
#line 60
{
  return heap_is_empty(&eventHeap);
}

  long long int sim_queue_peek_time()
#line 64
{
  if (heap_is_empty(&eventHeap)) {
      return -1;
    }
  else {
      return heap_get_min_key(&eventHeap);
    }
}


  void sim_queue_cleanup_none(sim_event_t *event)
#line 74
{
  sim_log_debug(1U, "Queue", "cleanup_none: 0x%p\n", event);
}


  void sim_queue_cleanup_event(sim_event_t *event)
#line 79
{
  sim_log_debug(2U, "Queue", "cleanup_event: 0x%p\n", event);
  free(event);
}

  void sim_queue_cleanup_data(sim_event_t *event)
#line 84
{
  sim_log_debug(3U, "Queue", "cleanup_data: 0x%p\n", event);
  free(event->data);
  event->data = (void *)0;
}

  void sim_queue_cleanup_total(sim_event_t *event)
#line 90
{
  sim_log_debug(4U, "Queue", "cleanup_total: 0x%p\n", event);
  free(event->data);
  event->data = (void *)0;
  free(event);
}

# 57 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_tossim.c"
  void sim_init()
#line 57
{
  sim_queue_init();
  sim_log_init();
  sim_log_commit_change();
  sim_noise_init();

  {
    struct timeval tv;

#line 65
    gettimeofday(&tv, (void *)0);





    if (tv.tv_usec != 0) {
        sim_random_seed(tv.tv_usec);
      }
    else {
        sim_random_seed(tv.tv_sec);
      }
  }
}

# 234 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_log.c"
static void sim_log_commit_change()
#line 234
{
  int i;

#line 236
  for (i = 0; i < SIM_LOG_OUTPUT_COUNT; i++) {
      if (outputs[i].files != (void *)0) {
          outputs[i].num = 0;
          free(outputs[i].files);
          outputs[i].files = (void *)0;
        }
    }
}

# 67 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_noise.c"
  void sim_noise_init()
{
  int j;



  for (j = 0; j < 1000; j++) {
      noiseData[j].noiseTable = create_hashtable(NOISE_HASHTABLE_SIZE, sim_noise_hash, sim_noise_eq);
      noiseData[j].noiseGenTime = 0;
      noiseData[j].noiseTrace = (char *)malloc(sizeof(char ) * NOISE_MIN_TRACE);
      noiseData[j].noiseTraceLen = NOISE_MIN_TRACE;
      noiseData[j].noiseTraceIndex = 0;
    }
}

# 102 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_tossim.c"
  void sim_random_seed(int seed)
#line 102
{

  if (seed == 0) {
      seed = 1;
    }
  sim_seed = seed;
}

#line 80
  void sim_end()
#line 80
{
  sim_queue_init();
}



  int sim_random()
#line 86
{
  uint32_t mlcg;
#line 87
  uint32_t p;
#line 87
  uint32_t q;
  uint64_t tmpseed;

#line 89
  tmpseed = (uint64_t )33614U * (uint64_t )sim_seed;
  q = tmpseed;
  q = q >> 1;
  p = tmpseed >> 32;
  mlcg = p + q;
  if (mlcg & 0x80000000) {
      mlcg = mlcg & 0x7FFFFFFF;
      mlcg++;
    }
  sim_seed = mlcg;
  return mlcg;
}









  sim_time_t sim_time()
#line 110
{
  return sim_ticks;
}

#line 113
  void sim_set_time(sim_time_t t)
#line 113
{
  sim_ticks = t;
}

  sim_time_t sim_ticks_per_sec()
#line 117
{
  return 10000000000ULL;
}




  void sim_set_node(unsigned long node)
#line 124
{
  current_node = node;
  TOS_NODE_ID = node;
}

  bool sim_run_next_event()
#line 129
{
  bool result = FALSE;

#line 131
  if (!sim_queue_is_empty()) {
      sim_event_t *event = sim_queue_pop();

#line 133
      sim_set_time(event->time);
      sim_set_node(event->mote);



      sim_log_debug(5U, "Tossim", "CORE: popping event 0x%p for %i at %llu with handler %p... ", event, sim_node(), sim_time(), event->handle);
      if ((sim_mote_is_on(event->mote) || event->force) && 
      event->handle != (void *)0) {
          result = TRUE;
          sim_log_debug_clear(6U, "Tossim", " mote is on (or forced event), run it.\n");
          event->handle(event);
        }
      else {
          sim_log_debug_clear(7U, "Tossim", "\n");
        }
      if (event->cleanup != (void *)0) {
          event->cleanup(event);
        }
    }

  return result;
}

# 134 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMoteP.nc"
  bool sim_mote_is_on(int mote)
#line 134
{
  bool result;
  int tmp = sim_node();

#line 137
  sim_set_node(mote);
  result = SimMoteP$SimMote$isOn();
  sim_set_node(tmp);
  return result;
}

# 276 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_log.c"
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...)
#line 276
{
  va_list args;
  int i;

#line 279
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 284
      __builtin_va_start(args, format);
      vfprintf(file, format, args);
      fflush(file);
    }
}

# 156 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_tossim.c"
  int sim_print_time(char *buf, int len, sim_time_t ftime)
#line 156
{
  int hours;
  int minutes;
  int seconds;
  sim_time_t secondBillionths;

  secondBillionths = ftime % sim_ticks_per_sec();
  if (sim_ticks_per_sec() > (sim_time_t )1000000000) {
      secondBillionths /= sim_ticks_per_sec() / (sim_time_t )1000000000;
    }
  else {
      secondBillionths *= (sim_time_t )1000000000 / sim_ticks_per_sec();
    }

  seconds = (int )(ftime / sim_ticks_per_sec());
  minutes = seconds / 60;
  hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;
  buf[len - 1] = 0;
  return snprintf(buf, len - 1, "%i:%i:%i.%09llu", hours, minutes, seconds, secondBillionths);
}

  int sim_print_now(char *buf, int len)
#line 179
{
  return sim_print_time(buf, len, sim_time());
}


  char *sim_time_string()
#line 184
{
  sim_print_now(simTimeBuf, 128);
  return simTimeBuf;
}

  void sim_add_channel(char *channel, FILE *file)
#line 189
{
  sim_log_add_channel(channel, file);
}

  bool sim_remove_channel(char *channel, FILE *file)
#line 193
{
  return sim_log_remove_channel(channel, file);
}

# 57 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_csma.c"
  int sim_csma_init_high()
#line 57
{
  return csmaInitHigh;
}

#line 60
  int sim_csma_init_low()
#line 60
{
  return csmaInitLow;
}

#line 63
  int sim_csma_high()
#line 63
{
  return csmaHigh;
}

#line 66
  int sim_csma_low()
#line 66
{
  return csmaLow;
}

#line 69
  int sim_csma_symbols_per_sec()
#line 69
{
  return csmaSymbolsPerSec;
}

#line 72
  int sim_csma_bits_per_symbol()
#line 72
{
  return csmaBitsPerSymbol;
}

#line 75
  int sim_csma_preamble_length()
#line 75
{
  return csmaPreambleLength;
}

#line 78
  int sim_csma_exponent_base()
#line 78
{
  return csmaExponentBase;
#line 79
  ;
}

#line 81
  int sim_csma_max_iterations()
#line 81
{
  return csmaMaxIterations;
}

#line 84
  int sim_csma_min_free_samples()
#line 84
{
  return csmaMinFreeSamples;
}

#line 87
  int sim_csma_rxtx_delay()
#line 87
{
  return csmaRxTxDelay;
}

#line 90
  int sim_csma_ack_time()
#line 90
{
  return csmaAckTime;
}



  void sim_csma_set_init_high(int val)
#line 96
{
  csmaInitHigh = val;
}

#line 99
  void sim_csma_set_init_low(int val)
#line 99
{
  csmaInitLow = val;
}

#line 102
  void sim_csma_set_high(int val)
#line 102
{
  csmaHigh = val;
}

#line 105
  void sim_csma_set_low(int val)
#line 105
{
  csmaLow = val;
}

#line 108
  void sim_csma_set_symbols_per_sec(int val)
#line 108
{
  csmaSymbolsPerSec = val;
}

#line 111
  void sim_csma_set_bits_per_symbol(int val)
#line 111
{
  csmaBitsPerSymbol = val;
}

#line 114
  void sim_csma_set_preamble_length(int val)
#line 114
{
  csmaPreambleLength = val;
}

#line 117
  void sim_csma_set_exponent_base(int val)
#line 117
{
  csmaExponentBase = val;
}

#line 120
  void sim_csma_set_max_iterations(int val)
#line 120
{
  csmaMaxIterations = val;
}

#line 123
  void sim_csma_set_min_free_samples(int val)
#line 123
{
  csmaMinFreeSamples = val;
}

#line 126
  void sim_csma_set_rxtx_delay(int val)
#line 126
{
  csmaRxTxDelay = val;
}

#line 129
  void sim_csma_set_ack_time(int val)
#line 129
{
  csmaAckTime = val;
}

# 16 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_gain.c"
  gain_entry_t *sim_gain_first(int src)
#line 16
{
  if (src > 1000) {
      return connectivity[1000];
    }
  return connectivity[src];
}

  gain_entry_t *sim_gain_next(gain_entry_t *currentLink)
#line 23
{
  return currentLink->next;
}

  void sim_gain_add(int src, int dest, double gain)
#line 27
{
  gain_entry_t *current;
  int temp = sim_node();

#line 30
  if (src > 1000) {
      src = 1000;
    }
  sim_set_node(src);

  current = sim_gain_first(src);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          break;
        }
      current = current->next;
    }

  if (current == (void *)0) {
      current = sim_gain_allocate_link(dest);
      current->next = connectivity[src];
      connectivity[src] = current;
    }
  current->mote = dest;
  current->gain = gain;
  sim_log_debug(8U, "Gain", "Adding link from %i to %i with gain %f\n", src, dest, gain);
  sim_set_node(temp);
}

  double sim_gain_value(int src, int dest)
#line 55
{
  gain_entry_t *current;
  int temp = sim_node();

#line 58
  sim_set_node(src);
  current = sim_gain_first(src);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          sim_log_debug(9U, "Gain", "Getting link from %i to %i with gain %f\n", src, dest, current->gain);
          return current->gain;
        }
      current = current->next;
    }
  sim_set_node(temp);
  sim_log_debug(10U, "Gain", "Getting default link from %i to %i with gain %f\n", src, dest, 1.0);
  return 1.0;
}

  bool sim_gain_connected(int src, int dest)
#line 73
{
  gain_entry_t *current;
  int temp = sim_node();

#line 76
  sim_set_node(src);
  current = sim_gain_first(src);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          return TRUE;
        }
      current = current->next;
    }
  sim_set_node(temp);
  return FALSE;
}

  void sim_gain_remove(int src, int dest)
#line 89
{
  gain_entry_t *current;
  gain_entry_t *prevLink;
  int temp = sim_node();

  if (src > 1000) {
      src = 1000;
    }

  sim_set_node(src);

  current = sim_gain_first(src);
  prevLink = (void *)0;

  while (current != (void *)0) {
      gain_entry_t *tmp;

#line 105
      if (current->mote == dest) {
          if (prevLink == (void *)0) {
              connectivity[src] = current->next;
            }
          else {
              prevLink->next = current->next;
            }
          tmp = current->next;
          sim_gain_deallocate_link(current);
          current = tmp;
        }
      else {
          prevLink = current;
          current = current->next;
        }
    }
  sim_set_node(temp);
}

#line 169
  void sim_gain_deallocate_link(gain_entry_t *linkToDelete)
#line 169
{
  free(linkToDelete);
}

#line 124
  void sim_gain_set_noise_floor(int node, double mean, double range)
#line 124
{
  if (node > 1000) {
      node = 1000;
    }
  localNoise[node].mean = mean;
  localNoise[node].range = range;
}

#line 148
  double sim_gain_sample_noise(int node)
#line 148
{
  double val;
#line 149
  double adjust;

#line 150
  if (node > 1000) {
      node = 1000;
    }
  val = localNoise[node].mean;
  adjust = sim_random() % 2000000;
  adjust /= 1000000.0;
  adjust -= 1.0;
  adjust *= localNoise[node].range;
  return val + adjust;
}

#line 173
  void sim_gain_set_sensitivity(double s)
#line 173
{
  sensitivity = s;
}

  double sim_gain_sensitivity()
#line 177
{
  return sensitivity;
}

# 84 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_noise.c"
  void sim_noise_create_model(uint16_t node_id)
#line 84
{
  makeNoiseModel(node_id);
  makePmfDistr(node_id);
}

#line 419
  void makeNoiseModel(uint16_t node_id)
#line 419
{
  int i;

#line 421
  for (i = 0; i < NOISE_HISTORY; i++) {
      noiseData[node_id].key[i] = search_bin_num(noiseData[node_id].noiseTrace[i]);
      sim_log_debug(44U, "Insert", "Setting history %i to be %i\n", (int )i, (int )noiseData[node_id].key[i]);
    }




  for (i = NOISE_HISTORY; i < noiseData[node_id].noiseTraceIndex; i++) {
      sim_noise_add(node_id, noiseData[node_id].noiseTrace[i]);
      arrangeKey(node_id);
      noiseData[node_id].key[NOISE_HISTORY - 1] = search_bin_num(noiseData[node_id].noiseTrace[i]);
    }
  noiseData[node_id].generated = 1;
}

#line 113
  uint8_t search_bin_num(char noise)
{
  uint8_t bin;

#line 116
  if (noise > NOISE_MAX || noise < NOISE_MIN) {
      noise = NOISE_MIN;
    }
  bin = (noise - NOISE_MIN) / NOISE_QUANTIZE_INTERVAL + 1;
  return bin;
}

#line 144
  void sim_noise_add(uint16_t node_id, char noise)
{
  int i;
  struct hashtable *pnoiseTable = noiseData[node_id].noiseTable;
  char *key = noiseData[node_id].key;
  sim_noise_hash_t *noise_hash;

#line 150
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, key);
  sim_log_debug(13U, "Insert", "Adding noise value %hhi\n", noise);
  if (noise_hash == (void *)0) {
      noise_hash = (sim_noise_hash_t *)malloc(sizeof(sim_noise_hash_t ));
      memcpy((void *)noise_hash->key, (void *)key, NOISE_HISTORY);

      noise_hash->numElements = 0;
      noise_hash->size = NOISE_DEFAULT_ELEMENT_SIZE;
      noise_hash->elements = (char *)malloc(sizeof(char ) * noise_hash->size);
      memset((void *)noise_hash->elements, 0, sizeof(char ) * noise_hash->size);

      noise_hash->flag = 0;
      for (i = 0; i < NOISE_NUM_VALUES; i++) {
          noise_hash->dist[i] = 0;
        }
      hashtable_insert(pnoiseTable, key, noise_hash);
      sim_log_debug(14U, "Insert", "Inserting %p into table %p with key ", noise_hash, pnoiseTable);
      {
        int ctr;

#line 169
        for (ctr = 0; ctr < NOISE_HISTORY; ctr++) 
          sim_log_debug_clear(15U, "Insert", "%0.3hhi ", key[ctr]);
      }
      sim_log_debug_clear(16U, "Insert", "\n");
    }

  if (noise_hash->numElements == noise_hash->size) 
    {
      char *newElements;
      int newSize = noise_hash->size * 2;

      newElements = (char *)malloc(sizeof(char ) * newSize);
      memcpy(newElements, noise_hash->elements, noise_hash->size);
      free(noise_hash->elements);
      noise_hash->elements = newElements;
      noise_hash->size = newSize;
    }

  noise_hash->elements[noise_hash->numElements] = noise;

  noise_hash->numElements++;
}

#line 245
  void arrangeKey(uint16_t node_id)
{
  char *pKey = noiseData[node_id].key;

#line 248
  memcpy(pKey, pKey + 1, NOISE_HISTORY - 1);
}





  void makePmfDistr(uint16_t node_id)
{
  int i;
  char *pKey = noiseData[node_id].key;
  char *fKey = noiseData[node_id].freqKey;

  FreqKeyNum = 0;
  for (i = 0; i < NOISE_HISTORY; i++) {
      pKey[i] = search_bin_num(noiseData[node_id].noiseTrace[i]);
    }

  for (i = NOISE_HISTORY; i < noiseData[node_id].noiseTraceIndex; i++) {
      if (i == NOISE_HISTORY) {
        }

      sim_noise_dist(node_id);
      arrangeKey(node_id);
      pKey[NOISE_HISTORY - 1] = search_bin_num(noiseData[node_id].noiseTrace[i]);
    }

  sim_log_debug_clear(21U, "HASH", "FreqKey = ");
  for (i = 0; i < NOISE_HISTORY; i++) 
    {
      sim_log_debug_clear(22U, "HASH", "%d,", fKey[i]);
    }
  sim_log_debug_clear(23U, "HASH", "\n");
}

#line 192
  void sim_noise_dist(uint16_t node_id)
{
  int i;
  uint8_t bin;
  float cmf = 0;
  struct hashtable *pnoiseTable = noiseData[node_id].noiseTable;
  char *key = noiseData[node_id].key;
  char *freqKey = noiseData[node_id].freqKey;
  sim_noise_hash_t *noise_hash;

#line 201
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, key);



  if (noise_hash->flag == 1) {
    return;
    }
  for (i = 0; i < NOISE_NUM_VALUES; i++) {
      noise_hash->dist[i] = 0.0;
    }

  for (i = 0; i < noise_hash->numElements; i++) 
    {
      float val;

#line 215
      sim_log_debug(17U, "Noise_output", "Noise is found to be %i\n", noise_hash->elements[i]);
      bin = noise_hash->elements[i] - NOISE_MIN_QUANTIZE;

      val = noise_hash->dist[bin];
      val += (float )1.0;
      noise_hash->dist[bin] = val;
    }

  for (i = 0; i < NOISE_NUM_VALUES; i++) 
    {
      noise_hash->dist[i] = noise_hash->dist[i] / noise_hash->numElements;
      cmf += noise_hash->dist[i];
      noise_hash->dist[i] = cmf;
    }
  noise_hash->flag = 1;


  if (noise_hash->numElements > FreqKeyNum) 
    {
      int j;

#line 235
      FreqKeyNum = noise_hash->numElements;
      memcpy((void *)freqKey, (void *)key, NOISE_HISTORY);
      sim_log_debug(18U, "HashZeroDebug", "Setting most frequent key (%i): ", (int )FreqKeyNum);
      for (j = 0; j < NOISE_HISTORY; j++) {
          sim_log_debug_clear(19U, "HashZeroDebug", "[%hhu] ", key[j]);
        }
      sim_log_debug_clear(20U, "HashZeroDebug", "\n");
    }
}

#line 97
  void sim_noise_trace_add(uint16_t node_id, char noiseVal)
#line 97
{

  if (noiseData[node_id].noiseTraceIndex == 
  noiseData[node_id].noiseTraceLen) {
      char *data = (char *)malloc(sizeof(char ) * noiseData[node_id].noiseTraceLen * 2);

#line 102
      memcpy(data, noiseData[node_id].noiseTrace, noiseData[node_id].noiseTraceLen);
      free(noiseData[node_id].noiseTrace);
      noiseData[node_id].noiseTraceLen *= 2;
      noiseData[node_id].noiseTrace = data;
    }
  noiseData[node_id].noiseTrace[noiseData[node_id].noiseTraceIndex] = noiseVal;
  noiseData[node_id].noiseTraceIndex++;
  sim_log_debug(12U, "Insert", "Adding noise value %i for %i of %i\n", (int )noiseData[node_id].noiseTraceIndex, (int )node_id, (int )noiseVal);
}

#line 123
  char search_noise_from_bin_num(int i)
{
  char noise;

#line 126
  noise = NOISE_MIN + (i - 1) * NOISE_QUANTIZE_INTERVAL;
  return noise;
}

#line 288
  char sim_noise_gen(uint16_t node_id)
{
  int i;
  int noiseIndex = 0;
  char noise;
  struct hashtable *pnoiseTable = noiseData[node_id].noiseTable;
  char *pKey = noiseData[node_id].key;
  char *fKey = noiseData[node_id].freqKey;
  double ranNum = RandomUniform();
  sim_noise_hash_t *noise_hash;

#line 298
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, pKey);

  if (noise_hash == (void *)0) {

      sim_log_debug(24U, "Noise_c", "Did not pattern match");

      sim_noise_alarm();
      noise = 0;
      sim_log_debug_clear(25U, "HASH", "(N)Noise\n");
      sim_log_debug(26U, "HashZeroDebug", "Defaulting to common hash.\n");
      memcpy((void *)pKey, (void *)fKey, NOISE_HISTORY);
      noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, pKey);
    }

  sim_log_debug_clear(27U, "HASH", "Key = ");
  for (i = 0; i < NOISE_HISTORY; i++) {
      sim_log_debug_clear(28U, "HASH", "%d,", pKey[i]);
    }
  sim_log_debug_clear(29U, "HASH", "\n");

  sim_log_debug(30U, "HASH", "Printing Key\n");
  sim_log_debug(31U, "HASH", "noise_hash->numElements=%d\n", noise_hash->numElements);


  numTotal++;


  if (noise_hash->numElements == 1) {
      noise = noise_hash->elements[0];
      sim_log_debug_clear(32U, "HASH", "(E)Noise = %d\n", noise);

      numCase1++;
      sim_log_debug(33U, "Noise_c", "In case 1: %i of %i\n", numCase1, numTotal);

      sim_log_debug(34U, "NoiseAudit", "Noise: %i\n", noise);
      return noise;
    }


  numCase2++;
  sim_log_debug(35U, "Noise_c", "In case 2: %i of %i\n", numCase2, numTotal);


  for (i = 0; i < NOISE_NUM_VALUES - 1; i++) {
      sim_log_debug(36U, "HASH", "IN:for i=%d\n", i);
      if (i == 0) {
          if (ranNum <= noise_hash->dist[i]) {
              noiseIndex = i;
              sim_log_debug_clear(37U, "HASH", "Selected Bin = %d -> ", i + 1);
              break;
            }
        }
      else {
#line 350
        if (noise_hash->dist[i - 1] < ranNum && 
        ranNum <= noise_hash->dist[i]) {
            noiseIndex = i;
            sim_log_debug_clear(38U, "HASH", "Selected Bin = %d -> ", i + 1);
            break;
          }
        }
    }
#line 357
  sim_log_debug(39U, "HASH", "OUT:for i=%d\n", i);

  noise = NOISE_MIN_QUANTIZE + i;
  sim_log_debug(40U, "NoiseAudit", "Noise: %i\n", noise);
  return noise;
}

# 103 "/root/local/tinyos-2.1.1/tos/lib/tossim/randomlib.c"
static double RandomUniform(void )
{
  double uni;
  int seed1;
#line 106
  int seed2;


  if (!test) 
    {



      seed1 = sim_random() % 31329;
      seed2 = sim_random() % 30082;
      RandomInitialise(seed1, seed2);
    }

  uni = randU[i97 - 1] - randU[j97 - 1];
  if (uni <= 0.0) {
    uni++;
    }
#line 122
  randU[i97 - 1] = uni;
  i97--;
  if (i97 == 0) {
    i97 = 97;
    }
#line 126
  j97--;
  if (j97 == 0) {
    j97 = 97;
    }
#line 129
  randC -= randCD;
  if (randC < 0.0) {
    randC += randCM;
    }
#line 132
  uni -= randC;
  if (uni < 0.0) {
    uni++;
    }
  return uni;
}

# 364 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_noise.c"
  char sim_noise_generate(uint16_t node_id, uint32_t cur_t)
#line 364
{
  uint32_t i;
  uint32_t prev_t;
  uint32_t delta_t;
  char *noiseG;
  char noise;

  prev_t = noiseData[node_id].noiseGenTime;

  if (noiseData[node_id].generated == 0) {
      sim_log_error(41U, "TOSSIM", "Tried to generate noise from an uninitialized radio model of node %hu.\n", node_id);
      return 127;
    }

  if (0 <= cur_t && cur_t < NOISE_HISTORY) {
      noiseData[node_id].noiseGenTime = cur_t;
      noiseData[node_id].key[cur_t] = search_bin_num(noiseData[node_id].noiseTrace[cur_t]);
      noiseData[node_id].lastNoiseVal = noiseData[node_id].noiseTrace[cur_t];
      return noiseData[node_id].noiseTrace[cur_t];
    }

  if (prev_t == 0) {
    delta_t = cur_t - (NOISE_HISTORY - 1);
    }
  else {
#line 388
    delta_t = cur_t - prev_t;
    }
  sim_log_debug_clear(42U, "HASH", "delta_t = %d\n", delta_t);

  if (delta_t == 0) {
    noise = noiseData[node_id].lastNoiseVal;
    }
  else 
#line 394
    {
      noiseG = (char *)malloc(sizeof(char ) * delta_t);

      for (i = 0; i < delta_t; i++) {
          noiseG[i] = sim_noise_gen(node_id);
          arrangeKey(node_id);
          noiseData[node_id].key[NOISE_HISTORY - 1] = search_bin_num(noiseG[i]);
        }
      noise = noiseG[delta_t - 1];
      noiseData[node_id].lastNoiseVal = noise;

      free(noiseG);
    }
  noiseData[node_id].noiseGenTime = cur_t;
  if (noise == 0) {
      sim_log_debug(43U, "HashZeroDebug", "Generated noise of zero.\n");
    }

  return noise;
}

# 261 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_log.c"
static void sim_log_error(uint16_t id, char *string, const char *format, ...)
#line 261
{
  va_list args;
  int i;

#line 264
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 269
      __builtin_va_start(args, format);
      fprintf(file, "ERROR (%i): ", (int )sim_node());
      vfprintf(file, format, args);
      fflush(file);
    }
}

# 54 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_packet.c"
  void sim_packet_set_source(sim_packet_t *msg, uint16_t src)
#line 54
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 56
  __nesc_hton_uint16(hdr->src.nxdata, src);
}

  uint16_t sim_packet_source(sim_packet_t *msg)
#line 59
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 61
  return __nesc_ntoh_uint16(hdr->src.nxdata);
}

  void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest)
#line 64
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 66
  __nesc_hton_uint16(hdr->dest.nxdata, dest);
}

  uint16_t sim_packet_destination(sim_packet_t *msg)
#line 69
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 71
  return __nesc_ntoh_uint16(hdr->dest.nxdata);
}

  void sim_packet_set_length(sim_packet_t *msg, uint8_t length)
#line 74
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 76
  __nesc_hton_uint8(hdr->length.nxdata, length);
}

#line 78
  uint16_t sim_packet_length(sim_packet_t *msg)
#line 78
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 80
  return __nesc_ntoh_uint8(hdr->length.nxdata);
}

  void sim_packet_set_type(sim_packet_t *msg, uint8_t type)
#line 83
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 85
  __nesc_hton_uint8(hdr->type.nxdata, type);
}

  uint8_t sim_packet_type(sim_packet_t *msg)
#line 88
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 90
  return __nesc_ntoh_uint8(hdr->type.nxdata);
}

  uint8_t *sim_packet_data(sim_packet_t *p)
#line 93
{
  message_t *msg = (message_t *)p;

#line 95
  return (uint8_t *)& msg->data;
}

#line 97
  void sim_packet_set_strength(sim_packet_t *p, uint16_t str)
#line 97
{
  message_t *msg = (message_t *)p;
  tossim_metadata_t *md = (tossim_metadata_t *)& msg->metadata;

#line 100
  __nesc_hton_int8(md->strength.nxdata, str);
}

#line 102
  void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t)
#line 102
{
  if (t < sim_time()) {
      t = sim_time();
    }
  sim_log_debug(45U, "Packet", "sim_packet.c: Delivering packet %p to %i at %llu\n", msg, node, t);
  active_message_deliver(node, (message_t *)msg, t);
}

# 254 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
  void active_message_deliver(int node, message_t *msg, sim_time_t t)
#line 254
{
  sim_event_t *evt = TossimActiveMessageC$allocate_deliver_event(node, msg, t);

#line 256
  sim_queue_insert(evt);
}

#line 109
static void TossimActiveMessageC$Model$receive(message_t *msg)
#line 109
{
  uint8_t len;
  void *payload;

  memcpy(TossimActiveMessageC$bufferPointer[sim_node()], msg, sizeof(message_t ));
  len = TossimActiveMessageC$Packet$payloadLength(TossimActiveMessageC$bufferPointer[sim_node()]);
  payload = TossimActiveMessageC$Packet$getPayload(TossimActiveMessageC$bufferPointer[sim_node()], TossimActiveMessageC$Packet$maxPayloadLength());

  if (TossimActiveMessageC$AMPacket$isForMe(msg)) {
      sim_log_debug(110U, "AM", "Received active message (%p) of type %hhu and length %hhu for me @ %s.\n", TossimActiveMessageC$bufferPointer[sim_node()], TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), len, sim_time_string());
      TossimActiveMessageC$bufferPointer[sim_node()] = TossimActiveMessageC$Receive$receive(TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), TossimActiveMessageC$bufferPointer[sim_node()], payload, len);
    }
  else {
      sim_log_debug(111U, "AM", "Snooped on active message of type %hhu and length %hhu for %hu @ %s.\n", TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), len, TossimActiveMessageC$AMPacket$destination(TossimActiveMessageC$bufferPointer[sim_node()]), sim_time_string());
      TossimActiveMessageC$bufferPointer[sim_node()] = TossimActiveMessageC$Snoop$receive(TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), TossimActiveMessageC$bufferPointer[sim_node()], payload, len);
    }
}

#line 140
static am_addr_t TossimActiveMessageC$AMPacket$destination(message_t *amsg)
#line 140
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 142
  return __nesc_ntoh_uint16(header->dest.nxdata);
}

# 76 "/root/local/tinyos-2.1.1/tos/lib/tossim/ActiveMessageAddressC.nc"
static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void )
#line 76
{
  if (!ActiveMessageAddressC$set[sim_node()]) {
      ActiveMessageAddressC$addr[sim_node()] = TOS_NODE_ID;
      ActiveMessageAddressC$set[sim_node()] = TRUE;
    }
  return ActiveMessageAddressC$addr[sim_node()];
}

# 165 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static am_id_t TossimActiveMessageC$AMPacket$type(message_t *amsg)
#line 165
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 167
  return __nesc_ntoh_uint8(header->type.nxdata);
}

# 168 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static void PacketHandlerP$PacketHandler$makePack(uint16_t dest, uint8_t protocol, uint8_t *payload)
{

  if (++PacketHandlerP$SEQUENCE_NUM[sim_node()] > 65000) {
    PacketHandlerP$SEQUENCE_NUM[sim_node()] = 0;
    }
  __nesc_hton_uint16(PacketHandlerP$sendPackage[sim_node()].src.nxdata, TOS_NODE_ID);
  __nesc_hton_uint16(PacketHandlerP$sendPackage[sim_node()].dest.nxdata, dest);
  __nesc_hton_uint8(PacketHandlerP$sendPackage[sim_node()].TTL.nxdata, MAX_TTL);
  __nesc_hton_uint16(PacketHandlerP$sendPackage[sim_node()].seq.nxdata, PacketHandlerP$SEQUENCE_NUM[sim_node()]);
  __nesc_hton_uint8(PacketHandlerP$sendPackage[sim_node()].protocol.nxdata, protocol);
  memcpy(PacketHandlerP$sendPackage[sim_node()].payload, payload, PACKET_MAX_PAYLOAD_SIZE8);
}

#line 213
static error_t PacketHandlerP$PacketHandler$send(uint16_t dest, bool updateTTL)
{
  unsigned char __nesc_temp43;
  unsigned char *__nesc_temp42;
#line 215
  sendInfo *input;

  if (PacketHandlerP$Pool$empty()) {
    return FAIL;
    }

  if (updateTTL) {
    (__nesc_temp42 = PacketHandlerP$sendPackage[sim_node()].TTL.nxdata, __nesc_hton_uint8(__nesc_temp42, (__nesc_temp43 = __nesc_ntoh_uint8(__nesc_temp42)) - 1), __nesc_temp43);
    }

  if (__nesc_ntoh_uint8(PacketHandlerP$sendPackage[sim_node()].TTL.nxdata) <= 0) {
    return FAIL;
    }

  if (__nesc_ntoh_uint16(PacketHandlerP$sendPackage[sim_node()].dest.nxdata) != UNSPECIFIED && dest == AM_BROADCAST_ADDR && __nesc_ntoh_uint8(PacketHandlerP$sendPackage[sim_node()].protocol.nxdata) == PROTOCOL_PING) 
    {
      if (PacketHandlerP$routingTable$contains(__nesc_ntoh_uint16(PacketHandlerP$sendPackage[sim_node()].dest.nxdata))) 
        {
          dest = (uint16_t )PacketHandlerP$routingTable$get(__nesc_ntoh_uint16(PacketHandlerP$sendPackage[sim_node()].dest.nxdata));
        }
      else 

        {
          sim_log_debug(154U, "Project2", "\tEntry for %d not found in routing table. Aborting.\n", __nesc_ntoh_uint16(PacketHandlerP$sendPackage[sim_node()].dest.nxdata));
          return FAIL;
        }
    }

  if (dest != AM_BROADCAST_ADDR && __nesc_ntoh_uint8(PacketHandlerP$sendPackage[sim_node()].protocol.nxdata) == PROTOCOL_PING) {
    sim_log_debug(155U, "Project2", "\tDelivering to hopping through %d to reach %d\n", dest, __nesc_ntoh_uint16(PacketHandlerP$sendPackage[sim_node()].dest.nxdata));
    }
  input = PacketHandlerP$Pool$get();
  input->packet = PacketHandlerP$sendPackage[sim_node()];
  input->dest = dest;

  PacketHandlerP$Queue$enqueue(input);
  PacketHandlerP$PacketHandler$postSendTask();

  return SUCCESS;
}

# 159 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static bool /*NodeC.routingTable*/HashmapC$2$Hashmap$contains(uint32_t k)
{
  uint32_t i = 0;
  uint32_t j = 0;

  do 
    {
      j = /*NodeC.routingTable*/HashmapC$2$hash(k, i);
      if (/*NodeC.routingTable*/HashmapC$2$map[sim_node()][j].key == k) {
        return TRUE;
        }
#line 169
      i++;
    }
  while (i < /*NodeC.routingTable*/HashmapC$2$HASH_MAX_SIZE[sim_node()]);

  return FALSE;
}

#line 121
static /*NodeC.routingTable*/HashmapC$2$t /*NodeC.routingTable*/HashmapC$2$Hashmap$get(uint32_t k)
{
  uint32_t i = 0;
  uint32_t j = 0;

  do 
    {
      j = /*NodeC.routingTable*/HashmapC$2$hash(k, i);

      if (/*NodeC.routingTable*/HashmapC$2$map[sim_node()][j].key == k) {
        return /*NodeC.routingTable*/HashmapC$2$map[sim_node()][j].value;
        }
      i++;
    }
  while (i < /*NodeC.routingTable*/HashmapC$2$HASH_MAX_SIZE[sim_node()]);

  return /*NodeC.routingTable*/HashmapC$2$map[sim_node()][0].value;
}

# 69 "/root/local/tinyos-2.1.1/tos/system/QueueC.nc"
static void /*PacketHandlerC.QueueC*/QueueC$0$printQueue(void )
#line 69
{

  int i;
#line 71
  int j;

#line 72
  sim_log_debug(185U, "QueueC", "head <-");
  for (i = /*PacketHandlerC.QueueC*/QueueC$0$head[sim_node()]; i < /*PacketHandlerC.QueueC*/QueueC$0$head[sim_node()] + /*PacketHandlerC.QueueC*/QueueC$0$size[sim_node()]; i++) {
      sim_log_debug_clear(186U, "QueueC", "[");
      for (j = 0; j < sizeof(/*PacketHandlerC.QueueC*/QueueC$0$queue_t ); j++) {
          uint8_t v = ((uint8_t *)&/*PacketHandlerC.QueueC*/QueueC$0$queue[sim_node()][i % 20])[j];

#line 77
          sim_log_debug_clear(187U, "QueueC", "%0.2hhx", v);
        }
      sim_log_debug_clear(188U, "QueueC", "] ");
    }
  sim_log_debug_clear(189U, "QueueC", "<- tail\n");
}

# 204 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static void PacketHandlerP$PacketHandler$postSendTask(void )
{
  if (!PacketHandlerP$sendTimer$isRunning()) 
    {
      PacketHandlerP$sendTimer$startOneShot(PacketHandlerP$Random$rand16() % 200 + 500);
    }
}

# 144 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num];

#line 147
  timer->t0 = t0;
  timer->dt = dt;
  timer->isoneshot = isoneshot;
  timer->isrunning = TRUE;
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask();
}

# 205 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimSchedulerBasicP.nc"
static error_t SimSchedulerBasicP$TaskBasic$postTask(uint8_t id)
{
  error_t result;

#line 208
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 208
    {
      result = SimSchedulerBasicP$pushTask(id) ? SUCCESS : EBUSY;
    }
#line 210
    __nesc_atomic_end(__nesc_atomic); }
  if (result == SUCCESS) {
      sim_log_debug(103U, "Scheduler", "Posting task %hhu.\n", id);
      SimSchedulerBasicP$sim_scheduler_submit_event();
    }
  else {
      sim_log_debug(104U, "Scheduler", "Posting task %hhu, but already posted.\n", id);
    }
  return result;
}

#line 77
static void SimSchedulerBasicP$sim_scheduler_submit_event(void )
#line 77
{
  if (SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] == FALSE) {
      SimSchedulerBasicP$sim_scheduler_event[sim_node()].time = sim_time() + SimSchedulerBasicP$sim_config_task_latency();
      sim_queue_insert(&SimSchedulerBasicP$sim_scheduler_event[sim_node()]);
      SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] = TRUE;
    }
}

# 161 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get(void )
#line 161
{
  uint32_t now;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {


      uint8_t now8 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get();

      if (/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag().bits.ocf0) {


        now = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get() + 1 + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get();
        }
      else {

        now = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] + now8;
        }
    }
#line 179
    __nesc_atomic_end(__nesc_atomic); }
#line 179
  return now;
}

# 282 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static uint8_t HplAtm128Timer0AsyncP$Timer0$get(void )
#line 282
{
  uint8_t rval;
  sim_time_t elapsed = sim_time() - HplAtm128Timer0AsyncP$last_zero();

#line 285
  elapsed = HplAtm128Timer0AsyncP$sim_to_clock(elapsed);
  elapsed = elapsed >> HplAtm128Timer0AsyncP$shiftFromScale();
  rval = (uint8_t )(elapsed & 0xff);
  sim_log_debug(172U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Getting timer: %hhu\n", rval);
  return rval;
}

#line 108
static sim_time_t HplAtm128Timer0AsyncP$last_zero(void )
#line 108
{
  if (HplAtm128Timer0AsyncP$lastZero[sim_node()] == 0) {
      HplAtm128Timer0AsyncP$lastZero[sim_node()] = sim_mote_start_time(sim_node());
    }
  return HplAtm128Timer0AsyncP$lastZero[sim_node()];
}

# 106 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMoteP.nc"
  long long int sim_mote_start_time(int mote)
#line 106
{
  long long int result;
  int tmp = sim_node();

#line 109
  sim_set_node(mote);
  result = SimMoteP$SimMote$getStartTime();
  sim_set_node(tmp);
  return result;
}

# 160 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void )
#line 160
{
  uint8_t scale = HplAtm128Timer0AsyncP$Timer0$getScale();

#line 162
  switch (scale) {
      case 0: 
        return 0;
      case 1: 
        return 0;
      case 2: 
        return 3;
      case 3: 
        return 5;
      case 4: 
        return 6;
      case 5: 
        return 7;
      case 6: 
        return 8;
      case 7: 
        return 10;
      default: 
        return 255;
    }
}

#line 321
static uint8_t HplAtm128Timer0AsyncP$Timer0$getScale(void )
#line 321
{
  return * (volatile uint8_t *)&atm128RegFile[sim_node()][0x33] & 0x7;
}

#line 383
static Atm128_TIFR_t HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag(void )
#line 383
{
  Atm128_TIFR_t at;

#line 385
  at.flat = * (volatile uint8_t *)&atm128RegFile[sim_node()][0x36];
  return at;
}

#line 457
static uint8_t HplAtm128Timer0AsyncP$Compare$get(void )
#line 457
{
  sim_log_debug(178U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Getting compare: %hhu\n", * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31]);
  return * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31];
}

# 69 "/root/local/tinyos-2.1.1/tos/system/RandomMlcgC.nc"
static uint32_t RandomMlcgC$Random$rand32(void )
#line 69
{
  uint32_t mlcg;
#line 70
  uint32_t p;
#line 70
  uint32_t q;
  uint64_t tmpseed;

#line 72
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      tmpseed = (uint64_t )33614U * (uint64_t )RandomMlcgC$seed[sim_node()];
      q = tmpseed;
      q = q >> 1;
      p = tmpseed >> 32;
      mlcg = p + q;
      if (mlcg & 0x80000000) {
          mlcg = mlcg & 0x7FFFFFFF;
          mlcg++;
        }
      RandomMlcgC$seed[sim_node()] = mlcg;
    }
#line 84
    __nesc_atomic_end(__nesc_atomic); }
  return mlcg;
}

# 121 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static /*NodeC.neighborTable*/HashmapC$0$t /*NodeC.neighborTable*/HashmapC$0$Hashmap$get(uint32_t k)
{
  uint32_t i = 0;
  uint32_t j = 0;

  do 
    {
      j = /*NodeC.neighborTable*/HashmapC$0$hash(k, i);

      if (/*NodeC.neighborTable*/HashmapC$0$map[sim_node()][j].key == k) {
        return /*NodeC.neighborTable*/HashmapC$0$map[sim_node()][j].value;
        }
      i++;
    }
  while (i < /*NodeC.neighborTable*/HashmapC$0$HASH_MAX_SIZE[sim_node()]);

  return /*NodeC.neighborTable*/HashmapC$0$map[sim_node()][0].value;
}

# 390 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static void LinkStateRoutingP$LinkStateRouting$printLinkState(void )
{
  uint32_t nodeIndex;
  uint32_t neighborIndex;

  sim_log_debug(220U, "Project2", "Link State:\n");
  for (nodeIndex = 0; nodeIndex < ROUTING_TABLE_SIZE; nodeIndex++) 
    {
      for (neighborIndex = 0; neighborIndex < ROUTING_TABLE_SIZE; neighborIndex++) 
        {
          if (LinkStateRoutingP$linkStates[sim_node()][nodeIndex][neighborIndex] == EMPTY) {
            continue;
            }
#line 402
          sim_log_debug(221U, "Project2", "\tLink State: %d <-> %d\n", nodeIndex, neighborIndex);
        }
    }
}

# 159 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static bool /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$contains(uint32_t k)
{
  uint32_t i = 0;
  uint32_t j = 0;

  do 
    {
      j = /*NodeC.TCPTablePTR*/HashmapC$3$hash(k, i);
      if (/*NodeC.TCPTablePTR*/HashmapC$3$map[sim_node()][j].key == k) {
        return TRUE;
        }
#line 169
      i++;
    }
  while (i < /*NodeC.TCPTablePTR*/HashmapC$3$HASH_MAX_SIZE[sim_node()]);

  return FALSE;
}

# 64 "/root/workspace/Project1/src/lib/modules/TransportP.nc"
static void TransportP$Transport$setConnectionPTR(uint32_t connectionKey, uint8_t initialState)
{
  uint32_t insertionIndex;


  TransportP$TCPTablePTR$insert(connectionKey, (void *)POINTER_NULL);
  insertionIndex = TransportP$TCPTablePTR$getIndex(connectionKey);


  TransportP$TCPTablePTR$insert(connectionKey, &TransportP$TCPTable[sim_node()][insertionIndex]);


  TransportP$Transport$setConnectionState(connectionKey, initialState);

  sim_log_debug(226U, "Project3", "\tTable entry made for %d with key %d\n", TOS_NODE_ID, connectionKey);
}

# 36 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static void /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$insert(uint32_t k, /*NodeC.TCPTablePTR*/HashmapC$3$t input)
{
  uint32_t i = 0;
  uint32_t j = 0;

  if (k == 0) {
    return;
    }


  do 
    {
      j = /*NodeC.TCPTablePTR*/HashmapC$3$hash(k, i);

      if (/*NodeC.TCPTablePTR*/HashmapC$3$map[sim_node()][j].key == 0 || /*NodeC.TCPTablePTR*/HashmapC$3$map[sim_node()][j].key == k) 
        {
          if (/*NodeC.TCPTablePTR*/HashmapC$3$map[sim_node()][j].key == 0) 
            {
              /*NodeC.TCPTablePTR*/HashmapC$3$keys[sim_node()][/*NodeC.TCPTablePTR*/HashmapC$3$numofVals[sim_node()]] = k;
              /*NodeC.TCPTablePTR*/HashmapC$3$numofVals[sim_node()]++;
            }

          /*NodeC.TCPTablePTR*/HashmapC$3$map[sim_node()][j].value = input;
          /*NodeC.TCPTablePTR*/HashmapC$3$map[sim_node()][j].key = k;

          return;
        }

      i++;
    }
  while (i < /*NodeC.TCPTablePTR*/HashmapC$3$HASH_MAX_SIZE[sim_node()]);
}

#line 140
static uint32_t /*NodeC.TCPTablePTR*/HashmapC$3$Hashmap$getIndex(uint32_t k)
{
  uint32_t i = 0;
  uint32_t j = 0;

  do 
    {
      j = /*NodeC.TCPTablePTR*/HashmapC$3$hash(k, i);

      if (/*NodeC.TCPTablePTR*/HashmapC$3$map[sim_node()][j].key == k) {
        return j;
        }
      i++;
    }
  while (i < /*NodeC.TCPTablePTR*/HashmapC$3$HASH_MAX_SIZE[sim_node()]);

  return -1;
}

#line 36
static void /*NodeC.neighborTable*/HashmapC$0$Hashmap$insert(uint32_t k, /*NodeC.neighborTable*/HashmapC$0$t input)
{
  uint32_t i = 0;
  uint32_t j = 0;

  if (k == 0) {
    return;
    }


  do 
    {
      j = /*NodeC.neighborTable*/HashmapC$0$hash(k, i);

      if (/*NodeC.neighborTable*/HashmapC$0$map[sim_node()][j].key == 0 || /*NodeC.neighborTable*/HashmapC$0$map[sim_node()][j].key == k) 
        {
          if (/*NodeC.neighborTable*/HashmapC$0$map[sim_node()][j].key == 0) 
            {
              /*NodeC.neighborTable*/HashmapC$0$keys[sim_node()][/*NodeC.neighborTable*/HashmapC$0$numofVals[sim_node()]] = k;
              /*NodeC.neighborTable*/HashmapC$0$numofVals[sim_node()]++;
            }

          /*NodeC.neighborTable*/HashmapC$0$map[sim_node()][j].value = input;
          /*NodeC.neighborTable*/HashmapC$0$map[sim_node()][j].key = k;

          return;
        }

      i++;
    }
  while (i < /*NodeC.neighborTable*/HashmapC$0$HASH_MAX_SIZE[sim_node()]);
}

# 77 "/root/workspace/Project1/src/lib/modules/PacketHandlerP.nc"
static void PacketHandlerP$PacketHandler$processSequence(pack *Package)
{
  PacketHandlerP$PacketHandler$ageSequenceTable();
  PacketHandlerP$PacketHandler$insertAge(__nesc_ntoh_uint16(Package->src.nxdata), __nesc_ntoh_uint16(Package->seq.nxdata), SEQUENCE_TABLE_MAX_AGE);
}



static void PacketHandlerP$PacketHandler$ageSequenceTable(void )
{
  uint32_t *keys;
  uint32_t keyInd;


  keys = PacketHandlerP$sequenceTable$getKeys();


  for (keyInd = 0; keyInd < SEQUENCE_TABLE_SIZE; keyInd++) 
    {
      if (keys[keyInd] == EMPTY) {
        continue;
        }
      PacketHandlerP$PacketHandler$decreaseAge(keys[keyInd]);
    }
}

# 36 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static void /*NodeC.sequenceTable*/HashmapC$1$Hashmap$insert(uint32_t k, /*NodeC.sequenceTable*/HashmapC$1$t input)
{
  uint32_t i = 0;
  uint32_t j = 0;

  if (k == 0) {
    return;
    }


  do 
    {
      j = /*NodeC.sequenceTable*/HashmapC$1$hash(k, i);

      if (/*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].key == 0 || /*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].key == k) 
        {
          if (/*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].key == 0) 
            {
              /*NodeC.sequenceTable*/HashmapC$1$keys[sim_node()][/*NodeC.sequenceTable*/HashmapC$1$numofVals[sim_node()]] = k;
              /*NodeC.sequenceTable*/HashmapC$1$numofVals[sim_node()]++;
            }

          /*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].value = input;
          /*NodeC.sequenceTable*/HashmapC$1$map[sim_node()][j].key = k;

          return;
        }

      i++;
    }
  while (i < /*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[sim_node()]);
}

# 110 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_packet.c"
  uint8_t sim_packet_max_length(sim_packet_t *msg)
#line 110
{
  return 28;
}

  sim_packet_t *sim_packet_allocate()
#line 114
{
  return (sim_packet_t *)malloc(sizeof(message_t ));
}

  void sim_packet_free(sim_packet_t *p)
#line 118
{
  printf("sim_packet.c: Freeing packet %p\n", p);
  free(p);
}

# 51 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMainP.nc"
  int sim_main_start_mote(void )
#line 51
{
  char timeBuf[128];

#line 53
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    {






      SimMainP$Scheduler$init();





      SimMainP$PlatformInit$init();
      while (SimMainP$Scheduler$runNextTask()) ;





      SimMainP$SoftwareInit$init();
      while (SimMainP$Scheduler$runNextTask()) ;
    }
#line 75
    __nesc_atomic_end(__nesc_atomic); }


  __nesc_enable_interrupt();

  sim_print_now(timeBuf, 128);
  sim_log_debug(99U, "SimMainP", "Mote %li signaling boot at time %s.\n", sim_node(), timeBuf);
  SimMainP$Boot$booted();





  return 0;
}

# 180 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimSchedulerBasicP.nc"
static bool SimSchedulerBasicP$Scheduler$runNextTask(void )
{
  uint8_t nextTask;

#line 183
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      nextTask = SimSchedulerBasicP$popTask();
      if (nextTask == SimSchedulerBasicP$NO_TASK) 
        {
          sim_log_debug(101U, "Scheduler", "Told to run next task, but no task to run.\n");
          {
            unsigned char __nesc_temp = 
#line 189
            FALSE;

            {
#line 189
              __nesc_atomic_end(__nesc_atomic); 
#line 189
              return __nesc_temp;
            }
          }
        }
    }
#line 193
    __nesc_atomic_end(__nesc_atomic); }
#line 192
  sim_log_debug(102U, "Scheduler", "Running task %hhu.\n", nextTask);
  SimSchedulerBasicP$TaskBasic$runTask(nextTask);
  return TRUE;
}

# 163 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(uint8_t last, message_t * msg, error_t err)
#line 163
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][last].msg = (void *)0;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend();
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(last, msg, err);
}

# 73 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimActiveMessageC.nc"
static error_t TossimActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len)
#line 75
{
  error_t err;
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 78
  sim_log_debug(109U, "AM", "AM: Sending packet (id=%hhu, len=%hhu) to %hu\n", id, len, addr);
  __nesc_hton_uint8(header->type.nxdata, id);
  __nesc_hton_uint16(header->dest.nxdata, addr);
  __nesc_hton_uint16(header->src.nxdata, TossimActiveMessageC$AMPacket$address());
  __nesc_hton_uint8(header->length.nxdata, len);
  err = TossimActiveMessageC$Model$send((int )addr, amsg, len + sizeof(tossim_header_t ) + sizeof(tossim_footer_t ));
  return err;
}

# 274 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
static double CpmModelC$packetNoise(CpmModelC$receive_message_t *msg)
#line 274
{
  double noise = CpmModelC$noise_hash_generation();
  CpmModelC$receive_message_t *list = CpmModelC$outstandingReceptionHead[sim_node()];

#line 277
  noise = pow(10.0, noise / 10.0);
  while (list != (void *)0) {
      if (list != msg) {
          noise += pow(10.0, list->power / 10.0);
        }
      list = list->next;
    }
  noise = 10.0 * log(noise) / log(10.0);
  return noise;
}

#line 126
static double CpmModelC$noise_hash_generation(void )
#line 126
{
  double CT = CpmModelC$timeInMs();
  uint32_t quotient = (sim_time_t )(CT * 10) / 10;
  uint8_t remain = (uint8_t )((sim_time_t )(CT * 10) % 10);
  double noise_val;
  uint16_t node_id = sim_node();

  sim_log_debug(127U, "CpmModelC", "IN: noise_hash_generation()\n");
  if (5 <= remain && remain < 10) {
      noise_val = (double )sim_noise_generate(node_id, quotient + 1);
    }
  else {
      noise_val = (double )sim_noise_generate(node_id, quotient);
    }
  sim_log_debug(128U, "CpmModelC,Tal", "%s: OUT: noise_hash_generation(): %lf\n", sim_time_string(), noise_val);

  return noise_val;
}

# 189 "/root/local/tinyos-2.1.1/tos/system/AMQueueImplP.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err)
#line 189
{





  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] >= 1) {
      return;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg == msg) {
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()], msg, err);
    }
  else {
      sim_log_debug(200U, "PointerBug", "%s received send done for %p, signaling for %p.\n", __FUNCTION__, msg, /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg);
    }
}

# 248 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
static bool CpmModelC$shouldReceive(double SNR)
#line 248
{
  double prr = CpmModelC$prr_estimate_from_snr(SNR);
  double coin = RandomUniform();

#line 251
  if (prr >= 0 && prr <= 1) {
      if (coin < prr) {
        prr = 1.0;
        }
      else {
#line 255
        prr = 0.0;
        }
    }
#line 257
  return prr;
}

# 307 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static bool TossimPacketModelC$GainRadioModel$shouldAck(message_t *msg)
#line 307
{
  if (TossimPacketModelC$running[sim_node()] && !TossimPacketModelC$transmitting[sim_node()]) {
      return TossimPacketModelC$Packet$shouldAck(msg);
    }
  else {
      return FALSE;
    }
}

# 216 "/root/local/tinyos-2.1.1/tos/lib/tossim/CpmModelC.nc"
static void CpmModelC$sim_gain_schedule_ack(int source, sim_time_t t, CpmModelC$receive_message_t *r)
#line 216
{
  sim_event_t *ackEvent = (sim_event_t *)malloc(sizeof(sim_event_t ));

  ackEvent->mote = source;
  ackEvent->force = 1;
  ackEvent->cancelled = 0;
  ackEvent->time = t;
  ackEvent->handle = CpmModelC$sim_gain_ack_handle;
  ackEvent->cleanup = sim_queue_cleanup_event;
  ackEvent->data = r;

  sim_queue_insert(ackEvent);
}

# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(uint32_t now)
{
  uint16_t num;

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;

          if (elapsed >= timer->dt) 
            {
              if (timer->isoneshot) {
                timer->isrunning = FALSE;
                }
              else {
#line 90
                timer->t0 += timer->dt;
                }
              /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(num);
              break;
            }
        }
    }
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask();
}

# 212 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(uint32_t nt0, uint32_t ndt)
#line 212
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()] = TRUE;
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()] = nt0;
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()] = ndt;
    }
#line 218
    __nesc_atomic_end(__nesc_atomic); }
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt();
}

#line 90
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt(void )
#line 90
{
  bool fired = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {



      uint8_t interrupt_in = 1 + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get() - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get();
      uint8_t newOcr0;
      uint8_t tifr = (uint8_t )/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag().flat;

#line 101
      sim_log_debug(158U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: TIFR is %hhx\n", tifr);
      if ((interrupt_in != 0 && interrupt_in < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT) || tifr & (1 << OCF0)) {
          if (interrupt_in < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT) {
              sim_log_debug(159U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: under min: %hhu.\n", interrupt_in);
            }
          else {
              sim_log_debug(160U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: OCF set.\n");
            }
          {
#line 109
            __nesc_atomic_end(__nesc_atomic); 
#line 109
            return;
          }
        }

      if (!/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()]) {
          newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT;
          sim_log_debug(161U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: no alarm set, set at max.\n");
        }
      else 
        {
          uint32_t now = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get();

#line 120
          sim_log_debug(162U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: now-t0 = %llu, dt = %llu\n", now - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()], /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()]);

          if ((uint32_t )(now - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()]) >= /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()]) 
            {
              /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()] = FALSE;
              fired = TRUE;
              newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT;
            }
          else 
            {


              uint32_t alarm_in = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()] + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()] - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()];

              if (alarm_in > /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT) {
                newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT;
                }
              else {
#line 136
                if ((uint8_t )alarm_in < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT) {
                  newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT;
                  }
                else {
#line 139
                  newOcr0 = alarm_in;
                  }
                }
            }
        }
#line 142
      newOcr0--;
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setOcr0(newOcr0);
    }
#line 144
    __nesc_atomic_end(__nesc_atomic); }
  if (fired) {
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$fired();
    }
}

# 463 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static void HplAtm128Timer0AsyncP$Compare$set(uint8_t t)
#line 463
{
  sim_log_debug(179U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Setting compare: %hhu\n", t);
  /* atomic removed: atomic calls only */
#line 465
  {




    if (t == 0 || t >= 0xfe) {
      t = 1;
      }
    if (t != * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31]) {
        * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31] = t;
        HplAtm128Timer0AsyncP$schedule_new_compare();
      }
  }
}

#line 267
static void HplAtm128Timer0AsyncP$schedule_new_compare(void )
#line 267
{
  if (HplAtm128Timer0AsyncP$compare[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$cancel_compare();
    }
  if (HplAtm128Timer0AsyncP$Timer0$getScale() != AVR_CLOCK_OFF) {
      sim_event_t *newEvent = HplAtm128Timer0AsyncP$allocate_compare();

#line 273
      HplAtm128Timer0AsyncP$configure_compare(newEvent);

      HplAtm128Timer0AsyncP$compare[sim_node()] = newEvent;
      sim_queue_insert(newEvent);
    }
}

# 97 "/root/local/tinyos-2.1.1/tos/lib/tossim/sim_event_queue.c"
static sim_event_t *sim_queue_allocate_event()
#line 97
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 99
  memset(evt, 0, sizeof(sim_event_t ));
  evt->mote = sim_node();
  return evt;
}

# 100 "/root/local/tinyos-2.1.1/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
  void INTERRUPT_16(void )
#line 100
{
  HplAtm128Timer0AsyncP$inOverflow[sim_node()] = TRUE;
  HplAtm128Timer0AsyncP$Timer0$overflow();
  HplAtm128Timer0AsyncP$inOverflow[sim_node()] = FALSE;
}

#line 508
static void HplAtm128Timer0AsyncP$configure_overflow(sim_event_t *evt)
#line 508
{
  sim_time_t overflowTime = 0;
  uint8_t timerVal = HplAtm128Timer0AsyncP$Timer0$get();
  uint8_t overflowVal = 0;




  overflowTime = (overflowVal - timerVal) & 0xff;
  if (overflowTime == 0) {
      overflowTime = 256;
    }




  overflowTime = overflowTime << HplAtm128Timer0AsyncP$shiftFromScale();
  overflowTime = HplAtm128Timer0AsyncP$clock_to_sim(overflowTime);
  overflowTime += sim_time();
  overflowTime -= (sim_time() - HplAtm128Timer0AsyncP$last_zero()) % (1 << HplAtm128Timer0AsyncP$shiftFromScale());

  sim_log_debug(182U, "HplAtm128Timer0AsyncP", "Scheduling new overflow for %i at time %llu\n", sim_node(), overflowTime);

  evt->time = overflowTime;
}

#line 94
  void INTERRUPT_15(void )
#line 94
{

  HplAtm128Timer0AsyncP$Compare$fired();
}

#line 231
static void HplAtm128Timer0AsyncP$configure_compare(sim_event_t *evt)
#line 231
{
  sim_time_t compareTime = 0;
  sim_time_t phaseOffset = 0;
  uint8_t timerVal = HplAtm128Timer0AsyncP$Timer0$get();
  uint8_t compareVal = HplAtm128Timer0AsyncP$Compare$get();




  compareTime = (compareVal - timerVal) & 0xff;
  if (compareTime == 0) {
      compareTime = 256;
    }






  compareTime = (compareTime + 1) << HplAtm128Timer0AsyncP$shiftFromScale();
  compareTime = HplAtm128Timer0AsyncP$clock_to_sim(compareTime);
  compareTime += sim_time();




  phaseOffset = sim_time();
  phaseOffset -= HplAtm128Timer0AsyncP$last_zero();
  phaseOffset %= HplAtm128Timer0AsyncP$clock_to_sim(1 << HplAtm128Timer0AsyncP$shiftFromScale());
  compareTime -= phaseOffset;

  sim_log_debug(171U, "HplAtm128Timer0AsyncP", "Configuring new compare of %i for %i at time %llu  (@ %llu)\n", (int )compareVal, sim_node(), compareTime, sim_time());

  evt->time = compareTime;
}

# 106 "/root/local/tinyos-2.1.1/tos/lib/tossim/TossimPacketModelC.nc"
static error_t TossimPacketModelC$Control$start(void )
#line 106
{
  if (!TossimPacketModelC$initialized[sim_node()]) {
      sim_log_error(115U, "TossimPacketModelC", "TossimPacketModelC: Control.start() called before initialization!\n");
      return FAIL;
    }
  sim_log_debug(116U, "TossimPacketModelC", "TossimPacketModelC: Control.start() called.\n");
  TossimPacketModelC$startDoneTask$postTask();
  return SUCCESS;
}

# 266 "/root/workspace/Project1/src/lib/modules/LinkStateRoutingP.nc"
static void LinkStateRoutingP$LinkStateRouting$shareLinkState(bool forcedShare)
{
  uint16_t *destinations;
  uint32_t *keys;
  uint32_t keyInd;
  uint32_t copyInd;
  uint16_t connectionState;
  bool unsentData = FALSE;

  if (!forcedShare) 
    {
      if (!LinkStateRoutingP$NeighborsChanged[sim_node()]) {
        return;
        }
      LinkStateRoutingP$NeighborsChanged[sim_node()] = !LinkStateRoutingP$NeighborsChanged[sim_node()];
    }


  memset(LinkStateRoutingP$linkStatePacket[sim_node()], 0, sizeof LinkStateRoutingP$linkStatePacket[sim_node()]);


  destinations = (uint16_t *)&LinkStateRoutingP$linkStatePacket[sim_node()][0];

  keys = LinkStateRoutingP$neighborTable$getKeys();


  for (keyInd = 0, copyInd = 0; keyInd < NEIGHBOR_TABLE_SIZE; keyInd++) 
    {

      if (keys[keyInd] == EMPTY) {
        continue;
        }

      connectionState = LinkStateRoutingP$neighborTable$get(keys[keyInd]);


      if (connectionState == CONNECTION_NONE) {
        continue;
        }

      if ((!(connectionState & CONNECTION_SEND) || !(connectionState & CONNECTION_RECEIVE)) || connectionState & CONNECTION_TIMED_OUT) {
        continue;
        }

      destinations[copyInd++ % PACKET_MAX_PAYLOAD_SIZE16] = keys[keyInd];


      unsentData = TRUE;


      if (copyInd % PACKET_MAX_PAYLOAD_SIZE16 == 0) 
        {

          LinkStateRoutingP$SendNeighbors$postTask();
          unsentData = FALSE;
        }
    }


  if (unsentData) 
    {

      LinkStateRoutingP$SendNeighbors$postTask();
    }
}

# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void Node$RareUpdate$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(5U, dt);
#line 73
}
#line 73
# 36 "/root/workspace/Project1/src/dataStructures/modules/HashmapC.nc"
static void /*NodeC.routingTable*/HashmapC$2$Hashmap$insert(uint32_t k, /*NodeC.routingTable*/HashmapC$2$t input)
{
  uint32_t i = 0;
  uint32_t j = 0;

  if (k == 0) {
    return;
    }


  do 
    {
      j = /*NodeC.routingTable*/HashmapC$2$hash(k, i);

      if (/*NodeC.routingTable*/HashmapC$2$map[sim_node()][j].key == 0 || /*NodeC.routingTable*/HashmapC$2$map[sim_node()][j].key == k) 
        {
          if (/*NodeC.routingTable*/HashmapC$2$map[sim_node()][j].key == 0) 
            {
              /*NodeC.routingTable*/HashmapC$2$keys[sim_node()][/*NodeC.routingTable*/HashmapC$2$numofVals[sim_node()]] = k;
              /*NodeC.routingTable*/HashmapC$2$numofVals[sim_node()]++;
            }

          /*NodeC.routingTable*/HashmapC$2$map[sim_node()][j].value = input;
          /*NodeC.routingTable*/HashmapC$2$map[sim_node()][j].key = k;

          return;
        }

      i++;
    }
  while (i < /*NodeC.routingTable*/HashmapC$2$HASH_MAX_SIZE[sim_node()]);
}

# 73 "/root/local/tinyos-2.1.1/tos/lib/timer/Timer.nc"
static void Node$SparseUpdate$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(4U, dt);
#line 73
}
#line 73
static void Node$ModerateUpdate$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(3U, dt);
#line 73
}
#line 73
static void Node$FrequentUpdate$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(2U, dt);
#line 73
}
#line 73
# 90 "/root/local/tinyos-2.1.1/tos/lib/tossim/SimMoteP.nc"
  long long int sim_mote_euid(int mote)
#line 90
{
  long long int result;
  int tmp = sim_node();

#line 93
  sim_set_node(mote);
  result = SimMoteP$SimMote$getEuid();
  sim_set_node(tmp);
  return result;
}

  void sim_mote_set_euid(int mote, long long int id)
#line 99
{
  int tmp = sim_node();

#line 101
  sim_set_node(mote);
  SimMoteP$SimMote$setEuid(id);
  sim_set_node(tmp);
}










  int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)
#line 115
{
  int result;
  int tmpID = sim_node();

#line 118
  sim_set_node(mote);
  result = SimMoteP$SimMote$getVariableInfo(name, ptr, len);
  sim_log_debug(106U, "SimMoteP", "Fetched %s of %i to be %p with len %i (result %i)\n", name, mote, *ptr, *len, result);
  sim_set_node(tmpID);
  return result;
}

  void sim_mote_set_start_time(int mote, long long int t)
#line 125
{
  int tmpID = sim_node();

#line 127
  sim_set_node(mote);
  SimMoteP$startTime[sim_node()] = t;
  sim_log_debug(107U, "SimMoteP", "Setting start time to %llu\n", SimMoteP$startTime[sim_node()]);
  sim_set_node(tmpID);
  return;
}










  void sim_mote_turn_on(int mote)
#line 143
{
  int tmp = sim_node();

#line 145
  sim_set_node(mote);
  SimMoteP$SimMote$turnOn();
  sim_set_node(tmp);
}

#line 72
static void SimMoteP$SimMote$turnOn(void )
#line 72
{
  if (!SimMoteP$isOn[sim_node()]) {
      if (SimMoteP$bootEvent[sim_node()] != (void *)0) {
          SimMoteP$bootEvent[sim_node()]->cancelled = TRUE;
        }
      __nesc_nido_initialise(sim_node());
      SimMoteP$startTime[sim_node()] = sim_time();
      sim_log_debug(105U, "SimMoteP", "Setting start time to %llu\n", SimMoteP$startTime[sim_node()]);
      SimMoteP$isOn[sim_node()] = TRUE;
      sim_main_start_mote();
    }
}

#line 150
  void sim_mote_turn_off(int mote)
#line 150
{
  int tmp = sim_node();

#line 152
  sim_set_node(mote);
  SimMoteP$SimMote$turnOff();
  sim_set_node(tmp);
}










  void sim_mote_enqueue_boot_event(int mote)
#line 166
{
  int tmp = sim_node();

#line 168
  sim_set_node(mote);

  if (SimMoteP$bootEvent[sim_node()] != (void *)0) {
      if (SimMoteP$bootEvent[sim_node()]->time == SimMoteP$startTime[sim_node()]) {

          SimMoteP$bootEvent[sim_node()]->cancelled = FALSE;
          return;
        }
      else {
          SimMoteP$bootEvent[sim_node()]->cancelled = TRUE;
        }
    }

  SimMoteP$bootEvent[sim_node()] = (sim_event_t *)malloc(sizeof(sim_event_t ));
  SimMoteP$bootEvent[sim_node()]->time = SimMoteP$startTime[sim_node()];
  SimMoteP$bootEvent[sim_node()]->mote = mote;
  SimMoteP$bootEvent[sim_node()]->force = TRUE;
  SimMoteP$bootEvent[sim_node()]->data = (void *)0;
  SimMoteP$bootEvent[sim_node()]->handle = SimMoteP$sim_mote_boot_handle;
  SimMoteP$bootEvent[sim_node()]->cleanup = sim_queue_cleanup_event;
  sim_queue_insert(SimMoteP$bootEvent[sim_node()]);

  sim_set_node(tmp);
}

/* Nido variable resolver function */

static int __nesc_nido_resolve(int __nesc_mote,
                               char* varname,
                               uintptr_t* addr, size_t* size)
{
  /* Module Node */
  if (!strcmp(varname, "Node$PeriodFrequent"))
  {
    *addr = (uintptr_t)&Node$PeriodFrequent[__nesc_mote];
    *size = sizeof(Node$PeriodFrequent[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "Node$PeriodModerate"))
  {
    *addr = (uintptr_t)&Node$PeriodModerate[__nesc_mote];
    *size = sizeof(Node$PeriodModerate[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "Node$PeriodSparse"))
  {
    *addr = (uintptr_t)&Node$PeriodSparse[__nesc_mote];
    *size = sizeof(Node$PeriodSparse[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "Node$PeriodRare"))
  {
    *addr = (uintptr_t)&Node$PeriodRare[__nesc_mote];
    *size = sizeof(Node$PeriodRare[__nesc_mote]);
    return 0;
  }

  /* Module PlatformP */

  /* Module MotePlatformP */

  /* Module HplAtm128GeneralIOPinP$0 */

  /* Module HplAtm128GeneralIOPinP$1 */

  /* Module HplAtm128GeneralIOPinP$2 */

  /* Module HplAtm128GeneralIOPinP$3 */

  /* Module HplAtm128GeneralIOPinP$4 */

  /* Module HplAtm128GeneralIOPinP$5 */

  /* Module HplAtm128GeneralIOPinP$6 */

  /* Module HplAtm128GeneralIOPinP$7 */

  /* Module HplAtm128GeneralIOPinP$8 */

  /* Module HplAtm128GeneralIOPinP$9 */

  /* Module HplAtm128GeneralIOPinP$10 */

  /* Module HplAtm128GeneralIOPinP$11 */

  /* Module HplAtm128GeneralIOPinP$12 */

  /* Module HplAtm128GeneralIOPinP$13 */

  /* Module HplAtm128GeneralIOPinP$14 */

  /* Module HplAtm128GeneralIOPinP$15 */

  /* Module HplAtm128GeneralIOPinP$16 */

  /* Module HplAtm128GeneralIOPinP$17 */

  /* Module HplAtm128GeneralIOPinP$18 */

  /* Module HplAtm128GeneralIOPinP$19 */

  /* Module HplAtm128GeneralIOPinP$20 */

  /* Module HplAtm128GeneralIOPinP$21 */

  /* Module HplAtm128GeneralIOPinP$22 */

  /* Module HplAtm128GeneralIOPinP$23 */

  /* Module HplAtm128GeneralIOPinP$24 */

  /* Module HplAtm128GeneralIOPinP$25 */

  /* Module HplAtm128GeneralIOPinP$26 */

  /* Module HplAtm128GeneralIOPinP$27 */

  /* Module HplAtm128GeneralIOPinP$28 */

  /* Module HplAtm128GeneralIOPinP$29 */

  /* Module HplAtm128GeneralIOPinP$30 */

  /* Module HplAtm128GeneralIOPinP$31 */

  /* Module HplAtm128GeneralIOPinP$32 */

  /* Module HplAtm128GeneralIOPinP$33 */

  /* Module HplAtm128GeneralIOPinP$34 */

  /* Module HplAtm128GeneralIOPinP$35 */

  /* Module HplAtm128GeneralIOPinP$36 */

  /* Module HplAtm128GeneralIOPinP$37 */

  /* Module HplAtm128GeneralIOPinP$38 */

  /* Module HplAtm128GeneralIOPinP$39 */

  /* Module HplAtm128GeneralIOPinP$40 */

  /* Module HplAtm128GeneralIOPinP$41 */

  /* Module HplAtm128GeneralIOPinP$42 */

  /* Module HplAtm128GeneralIOPinP$43 */

  /* Module HplAtm128GeneralIOPinP$44 */

  /* Module HplAtm128GeneralIOPinP$45 */

  /* Module HplAtm128GeneralIOPinP$46 */

  /* Module HplAtm128GeneralIOPinP$47 */

  /* Module HplAtm128GeneralIOSlowPinP$0 */

  /* Module HplAtm128GeneralIOSlowPinP$1 */

  /* Module HplAtm128GeneralIOSlowPinP$2 */

  /* Module HplAtm128GeneralIOSlowPinP$3 */

  /* Module HplAtm128GeneralIOSlowPinP$4 */

  /* Module HplAtm128GeneralIOSlowPinP$5 */

  /* Module HplAtm128GeneralIOSlowPinP$6 */

  /* Module HplAtm128GeneralIOSlowPinP$7 */

  /* Module HplAtm128GeneralIOSlowPinP$8 */

  /* Module HplAtm128GeneralIOSlowPinP$9 */

  /* Module HplAtm128GeneralIOSlowPinP$10 */

  /* Module HplAtm128GeneralIOSlowPinP$11 */

  /* Module HplAtm128GeneralIOSlowPinP$12 */

  /* Module MeasureClockC */

  /* Module SimMainP */

  /* Module SimSchedulerBasicP */
  if (!strcmp(varname, "SimSchedulerBasicP$m_head"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$m_head[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$m_head[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$m_tail"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$m_tail[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$m_tail[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$m_next"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$m_next[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$m_next[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$sim_scheduler_event_pending"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$sim_scheduler_event_pending[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$sim_scheduler_event_pending[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$sim_scheduler_event"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$sim_scheduler_event[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$sim_scheduler_event[__nesc_mote]);
    return 0;
  }

  /* Module SimMoteP */
  if (!strcmp(varname, "SimMoteP$euid"))
  {
    *addr = (uintptr_t)&SimMoteP$euid[__nesc_mote];
    *size = sizeof(SimMoteP$euid[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP$startTime"))
  {
    *addr = (uintptr_t)&SimMoteP$startTime[__nesc_mote];
    *size = sizeof(SimMoteP$startTime[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP$isOn"))
  {
    *addr = (uintptr_t)&SimMoteP$isOn[__nesc_mote];
    *size = sizeof(SimMoteP$isOn[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP$bootEvent"))
  {
    *addr = (uintptr_t)&SimMoteP$bootEvent[__nesc_mote];
    *size = sizeof(SimMoteP$bootEvent[__nesc_mote]);
    return 0;
  }

  /* Module TossimActiveMessageC */
  if (!strcmp(varname, "TossimActiveMessageC$buffer"))
  {
    *addr = (uintptr_t)&TossimActiveMessageC$buffer[__nesc_mote];
    *size = sizeof(TossimActiveMessageC$buffer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimActiveMessageC$bufferPointer"))
  {
    *addr = (uintptr_t)&TossimActiveMessageC$bufferPointer[__nesc_mote];
    *size = sizeof(TossimActiveMessageC$bufferPointer[__nesc_mote]);
    return 0;
  }

  /* Module TossimPacketModelC */
  if (!strcmp(varname, "TossimPacketModelC$initialized"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$initialized[__nesc_mote];
    *size = sizeof(TossimPacketModelC$initialized[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$running"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$running[__nesc_mote];
    *size = sizeof(TossimPacketModelC$running[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$backoffCount"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$backoffCount[__nesc_mote];
    *size = sizeof(TossimPacketModelC$backoffCount[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$neededFreeSamples"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$neededFreeSamples[__nesc_mote];
    *size = sizeof(TossimPacketModelC$neededFreeSamples[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$sending"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$sending[__nesc_mote];
    *size = sizeof(TossimPacketModelC$sending[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$transmitting"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$transmitting[__nesc_mote];
    *size = sizeof(TossimPacketModelC$transmitting[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$sendingLength"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$sendingLength[__nesc_mote];
    *size = sizeof(TossimPacketModelC$sendingLength[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$destNode"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$destNode[__nesc_mote];
    *size = sizeof(TossimPacketModelC$destNode[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$sendEvent"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$sendEvent[__nesc_mote];
    *size = sizeof(TossimPacketModelC$sendEvent[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$error"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$error[__nesc_mote];
    *size = sizeof(TossimPacketModelC$error[__nesc_mote]);
    return 0;
  }

  /* Module CpmModelC */
  if (!strcmp(varname, "CpmModelC$outgoing"))
  {
    *addr = (uintptr_t)&CpmModelC$outgoing[__nesc_mote];
    *size = sizeof(CpmModelC$outgoing[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$requestAck"))
  {
    *addr = (uintptr_t)&CpmModelC$requestAck[__nesc_mote];
    *size = sizeof(CpmModelC$requestAck[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$receiving"))
  {
    *addr = (uintptr_t)&CpmModelC$receiving[__nesc_mote];
    *size = sizeof(CpmModelC$receiving[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$transmitting"))
  {
    *addr = (uintptr_t)&CpmModelC$transmitting[__nesc_mote];
    *size = sizeof(CpmModelC$transmitting[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$transmissionEndTime"))
  {
    *addr = (uintptr_t)&CpmModelC$transmissionEndTime[__nesc_mote];
    *size = sizeof(CpmModelC$transmissionEndTime[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$outstandingReceptionHead"))
  {
    *addr = (uintptr_t)&CpmModelC$outstandingReceptionHead[__nesc_mote];
    *size = sizeof(CpmModelC$outstandingReceptionHead[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$clearThreshold"))
  {
    *addr = (uintptr_t)&CpmModelC$clearThreshold[__nesc_mote];
    *size = sizeof(CpmModelC$clearThreshold[__nesc_mote]);
    return 0;
  }

  /* Module ActiveMessageAddressC */
  if (!strcmp(varname, "ActiveMessageAddressC$set"))
  {
    *addr = (uintptr_t)&ActiveMessageAddressC$set[__nesc_mote];
    *size = sizeof(ActiveMessageAddressC$set[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "ActiveMessageAddressC$addr"))
  {
    *addr = (uintptr_t)&ActiveMessageAddressC$addr[__nesc_mote];
    *size = sizeof(ActiveMessageAddressC$addr[__nesc_mote]);
    return 0;
  }

  /* Module PacketHandlerP */
  if (!strcmp(varname, "PacketHandlerP$sendPackage"))
  {
    *addr = (uintptr_t)&PacketHandlerP$sendPackage[__nesc_mote];
    *size = sizeof(PacketHandlerP$sendPackage[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PacketHandlerP$pingPacket"))
  {
    *addr = (uintptr_t)&PacketHandlerP$pingPacket[__nesc_mote];
    *size = sizeof(PacketHandlerP$pingPacket[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PacketHandlerP$SEQUENCE_NUM"))
  {
    *addr = (uintptr_t)&PacketHandlerP$SEQUENCE_NUM[__nesc_mote];
    *size = sizeof(PacketHandlerP$SEQUENCE_NUM[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PacketHandlerP$busy"))
  {
    *addr = (uintptr_t)&PacketHandlerP$busy[__nesc_mote];
    *size = sizeof(PacketHandlerP$busy[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "PacketHandlerP$pkt"))
  {
    *addr = (uintptr_t)&PacketHandlerP$pkt[__nesc_mote];
    *size = sizeof(PacketHandlerP$pkt[__nesc_mote]);
    return 0;
  }

  /* Module Atm128AlarmAsyncP$0 */
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote]);
    return 0;
  }

  /* Module HplAtm128Timer0AsyncP */
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$inOverflow"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$inOverflow[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$inOverflow[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$lastZero"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$lastZero[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$lastZero[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$oldScale"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$oldScale[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$oldScale[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$compare"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$compare[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$compare[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$overflow"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$overflow[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$overflow[__nesc_mote]);
    return 0;
  }

  /* Module AlarmToTimerC$0 */
  if (!strcmp(varname, "/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt"))
  {
    *addr = (uintptr_t)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote];
    *size = sizeof(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot"))
  {
    *addr = (uintptr_t)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote];
    *size = sizeof(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote]);
    return 0;
  }

  /* Module VirtualizeTimerC$0 */
  if (!strcmp(varname, "/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers"))
  {
    *addr = (uintptr_t)&/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote];
    *size = sizeof(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote]);
    return 0;
  }

  /* Module CounterToLocalTimeC$0 */

  /* Module QueueC$0 */
  if (!strcmp(varname, "/*PacketHandlerC.QueueC*/QueueC$0$queue"))
  {
    *addr = (uintptr_t)&/*PacketHandlerC.QueueC*/QueueC$0$queue[__nesc_mote];
    *size = sizeof(/*PacketHandlerC.QueueC*/QueueC$0$queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*PacketHandlerC.QueueC*/QueueC$0$head"))
  {
    *addr = (uintptr_t)&/*PacketHandlerC.QueueC*/QueueC$0$head[__nesc_mote];
    *size = sizeof(/*PacketHandlerC.QueueC*/QueueC$0$head[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*PacketHandlerC.QueueC*/QueueC$0$tail"))
  {
    *addr = (uintptr_t)&/*PacketHandlerC.QueueC*/QueueC$0$tail[__nesc_mote];
    *size = sizeof(/*PacketHandlerC.QueueC*/QueueC$0$tail[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*PacketHandlerC.QueueC*/QueueC$0$size"))
  {
    *addr = (uintptr_t)&/*PacketHandlerC.QueueC*/QueueC$0$size[__nesc_mote];
    *size = sizeof(/*PacketHandlerC.QueueC*/QueueC$0$size[__nesc_mote]);
    return 0;
  }

  /* Module PoolP$0 */
  if (!strcmp(varname, "/*PacketHandlerC.PoolC.PoolP*/PoolP$0$free"))
  {
    *addr = (uintptr_t)&/*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[__nesc_mote];
    *size = sizeof(/*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*PacketHandlerC.PoolC.PoolP*/PoolP$0$index"))
  {
    *addr = (uintptr_t)&/*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[__nesc_mote];
    *size = sizeof(/*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue"))
  {
    *addr = (uintptr_t)&/*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue[__nesc_mote];
    *size = sizeof(/*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool"))
  {
    *addr = (uintptr_t)&/*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool[__nesc_mote];
    *size = sizeof(/*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool[__nesc_mote]);
    return 0;
  }

  /* Module AMQueueEntryP$0 */

  /* Module AMQueueImplP$0 */
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote]);
    return 0;
  }

  /* Module CommandHandlerP */

  /* Module NeighborDiscoveryP */
  if (!strcmp(varname, "NeighborDiscoveryP$pingPacket"))
  {
    *addr = (uintptr_t)&NeighborDiscoveryP$pingPacket[__nesc_mote];
    *size = sizeof(NeighborDiscoveryP$pingPacket[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "NeighborDiscoveryP$TimeOutState"))
  {
    *addr = (uintptr_t)&NeighborDiscoveryP$TimeOutState[__nesc_mote];
    *size = sizeof(NeighborDiscoveryP$TimeOutState[__nesc_mote]);
    return 0;
  }

  /* Module LinkStateRoutingP */
  if (!strcmp(varname, "LinkStateRoutingP$linkStatePacket"))
  {
    *addr = (uintptr_t)&LinkStateRoutingP$linkStatePacket[__nesc_mote];
    *size = sizeof(LinkStateRoutingP$linkStatePacket[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LinkStateRoutingP$linkStates"))
  {
    *addr = (uintptr_t)&LinkStateRoutingP$linkStates[__nesc_mote];
    *size = sizeof(LinkStateRoutingP$linkStates[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LinkStateRoutingP$compareBuffer"))
  {
    *addr = (uintptr_t)&LinkStateRoutingP$compareBuffer[__nesc_mote];
    *size = sizeof(LinkStateRoutingP$compareBuffer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LinkStateRoutingP$hopThrough"))
  {
    *addr = (uintptr_t)&LinkStateRoutingP$hopThrough[__nesc_mote];
    *size = sizeof(LinkStateRoutingP$hopThrough[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LinkStateRoutingP$unconsidered"))
  {
    *addr = (uintptr_t)&LinkStateRoutingP$unconsidered[__nesc_mote];
    *size = sizeof(LinkStateRoutingP$unconsidered[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LinkStateRoutingP$existing"))
  {
    *addr = (uintptr_t)&LinkStateRoutingP$existing[__nesc_mote];
    *size = sizeof(LinkStateRoutingP$existing[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LinkStateRoutingP$NeighborsChanged"))
  {
    *addr = (uintptr_t)&LinkStateRoutingP$NeighborsChanged[__nesc_mote];
    *size = sizeof(LinkStateRoutingP$NeighborsChanged[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LinkStateRoutingP$LSChanged"))
  {
    *addr = (uintptr_t)&LinkStateRoutingP$LSChanged[__nesc_mote];
    *size = sizeof(LinkStateRoutingP$LSChanged[__nesc_mote]);
    return 0;
  }

  /* Module TransportP */
  if (!strcmp(varname, "TransportP$TCPTable"))
  {
    *addr = (uintptr_t)&TransportP$TCPTable[__nesc_mote];
    *size = sizeof(TransportP$TCPTable[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TransportP$Attempt_Connection_Time"))
  {
    *addr = (uintptr_t)&TransportP$Attempt_Connection_Time[__nesc_mote];
    *size = sizeof(TransportP$Attempt_Connection_Time[__nesc_mote]);
    return 0;
  }

  /* Module HashmapC$0 */
  if (!strcmp(varname, "/*NodeC.neighborTable*/HashmapC$0$HASH_MAX_SIZE"))
  {
    *addr = (uintptr_t)&/*NodeC.neighborTable*/HashmapC$0$HASH_MAX_SIZE[__nesc_mote];
    *size = sizeof(/*NodeC.neighborTable*/HashmapC$0$HASH_MAX_SIZE[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.neighborTable*/HashmapC$0$map"))
  {
    *addr = (uintptr_t)&/*NodeC.neighborTable*/HashmapC$0$map[__nesc_mote];
    *size = sizeof(/*NodeC.neighborTable*/HashmapC$0$map[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.neighborTable*/HashmapC$0$keys"))
  {
    *addr = (uintptr_t)&/*NodeC.neighborTable*/HashmapC$0$keys[__nesc_mote];
    *size = sizeof(/*NodeC.neighborTable*/HashmapC$0$keys[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.neighborTable*/HashmapC$0$numofVals"))
  {
    *addr = (uintptr_t)&/*NodeC.neighborTable*/HashmapC$0$numofVals[__nesc_mote];
    *size = sizeof(/*NodeC.neighborTable*/HashmapC$0$numofVals[__nesc_mote]);
    return 0;
  }

  /* Module HashmapC$1 */
  if (!strcmp(varname, "/*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE"))
  {
    *addr = (uintptr_t)&/*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[__nesc_mote];
    *size = sizeof(/*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.sequenceTable*/HashmapC$1$map"))
  {
    *addr = (uintptr_t)&/*NodeC.sequenceTable*/HashmapC$1$map[__nesc_mote];
    *size = sizeof(/*NodeC.sequenceTable*/HashmapC$1$map[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.sequenceTable*/HashmapC$1$keys"))
  {
    *addr = (uintptr_t)&/*NodeC.sequenceTable*/HashmapC$1$keys[__nesc_mote];
    *size = sizeof(/*NodeC.sequenceTable*/HashmapC$1$keys[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.sequenceTable*/HashmapC$1$numofVals"))
  {
    *addr = (uintptr_t)&/*NodeC.sequenceTable*/HashmapC$1$numofVals[__nesc_mote];
    *size = sizeof(/*NodeC.sequenceTable*/HashmapC$1$numofVals[__nesc_mote]);
    return 0;
  }

  /* Module HashmapC$2 */
  if (!strcmp(varname, "/*NodeC.routingTable*/HashmapC$2$HASH_MAX_SIZE"))
  {
    *addr = (uintptr_t)&/*NodeC.routingTable*/HashmapC$2$HASH_MAX_SIZE[__nesc_mote];
    *size = sizeof(/*NodeC.routingTable*/HashmapC$2$HASH_MAX_SIZE[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.routingTable*/HashmapC$2$map"))
  {
    *addr = (uintptr_t)&/*NodeC.routingTable*/HashmapC$2$map[__nesc_mote];
    *size = sizeof(/*NodeC.routingTable*/HashmapC$2$map[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.routingTable*/HashmapC$2$keys"))
  {
    *addr = (uintptr_t)&/*NodeC.routingTable*/HashmapC$2$keys[__nesc_mote];
    *size = sizeof(/*NodeC.routingTable*/HashmapC$2$keys[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.routingTable*/HashmapC$2$numofVals"))
  {
    *addr = (uintptr_t)&/*NodeC.routingTable*/HashmapC$2$numofVals[__nesc_mote];
    *size = sizeof(/*NodeC.routingTable*/HashmapC$2$numofVals[__nesc_mote]);
    return 0;
  }

  /* Module HashmapC$3 */
  if (!strcmp(varname, "/*NodeC.TCPTablePTR*/HashmapC$3$HASH_MAX_SIZE"))
  {
    *addr = (uintptr_t)&/*NodeC.TCPTablePTR*/HashmapC$3$HASH_MAX_SIZE[__nesc_mote];
    *size = sizeof(/*NodeC.TCPTablePTR*/HashmapC$3$HASH_MAX_SIZE[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.TCPTablePTR*/HashmapC$3$map"))
  {
    *addr = (uintptr_t)&/*NodeC.TCPTablePTR*/HashmapC$3$map[__nesc_mote];
    *size = sizeof(/*NodeC.TCPTablePTR*/HashmapC$3$map[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.TCPTablePTR*/HashmapC$3$keys"))
  {
    *addr = (uintptr_t)&/*NodeC.TCPTablePTR*/HashmapC$3$keys[__nesc_mote];
    *size = sizeof(/*NodeC.TCPTablePTR*/HashmapC$3$keys[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*NodeC.TCPTablePTR*/HashmapC$3$numofVals"))
  {
    *addr = (uintptr_t)&/*NodeC.TCPTablePTR*/HashmapC$3$numofVals[__nesc_mote];
    *size = sizeof(/*NodeC.TCPTablePTR*/HashmapC$3$numofVals[__nesc_mote]);
    return 0;
  }

  /* Module RandomMlcgC */
  if (!strcmp(varname, "RandomMlcgC$seed"))
  {
    *addr = (uintptr_t)&RandomMlcgC$seed[__nesc_mote];
    *size = sizeof(RandomMlcgC$seed[__nesc_mote]);
    return 0;
  }

  return -1;
}
/* Invoke static initialisers for mote '__nesc_mote' */

static void __nesc_nido_initialise(int __nesc_mote)
{
  /* Module Node */
  memset((void *)&Node$PeriodFrequent[__nesc_mote], 0, sizeof Node$PeriodFrequent[__nesc_mote]);
  memset((void *)&Node$PeriodModerate[__nesc_mote], 0, sizeof Node$PeriodModerate[__nesc_mote]);
  memset((void *)&Node$PeriodSparse[__nesc_mote], 0, sizeof Node$PeriodSparse[__nesc_mote]);
  memset((void *)&Node$PeriodRare[__nesc_mote], 0, sizeof Node$PeriodRare[__nesc_mote]);

  /* Module PlatformP */

  /* Module MotePlatformP */

  /* Module HplAtm128GeneralIOPinP$0 */

  /* Module HplAtm128GeneralIOPinP$1 */

  /* Module HplAtm128GeneralIOPinP$2 */

  /* Module HplAtm128GeneralIOPinP$3 */

  /* Module HplAtm128GeneralIOPinP$4 */

  /* Module HplAtm128GeneralIOPinP$5 */

  /* Module HplAtm128GeneralIOPinP$6 */

  /* Module HplAtm128GeneralIOPinP$7 */

  /* Module HplAtm128GeneralIOPinP$8 */

  /* Module HplAtm128GeneralIOPinP$9 */

  /* Module HplAtm128GeneralIOPinP$10 */

  /* Module HplAtm128GeneralIOPinP$11 */

  /* Module HplAtm128GeneralIOPinP$12 */

  /* Module HplAtm128GeneralIOPinP$13 */

  /* Module HplAtm128GeneralIOPinP$14 */

  /* Module HplAtm128GeneralIOPinP$15 */

  /* Module HplAtm128GeneralIOPinP$16 */

  /* Module HplAtm128GeneralIOPinP$17 */

  /* Module HplAtm128GeneralIOPinP$18 */

  /* Module HplAtm128GeneralIOPinP$19 */

  /* Module HplAtm128GeneralIOPinP$20 */

  /* Module HplAtm128GeneralIOPinP$21 */

  /* Module HplAtm128GeneralIOPinP$22 */

  /* Module HplAtm128GeneralIOPinP$23 */

  /* Module HplAtm128GeneralIOPinP$24 */

  /* Module HplAtm128GeneralIOPinP$25 */

  /* Module HplAtm128GeneralIOPinP$26 */

  /* Module HplAtm128GeneralIOPinP$27 */

  /* Module HplAtm128GeneralIOPinP$28 */

  /* Module HplAtm128GeneralIOPinP$29 */

  /* Module HplAtm128GeneralIOPinP$30 */

  /* Module HplAtm128GeneralIOPinP$31 */

  /* Module HplAtm128GeneralIOPinP$32 */

  /* Module HplAtm128GeneralIOPinP$33 */

  /* Module HplAtm128GeneralIOPinP$34 */

  /* Module HplAtm128GeneralIOPinP$35 */

  /* Module HplAtm128GeneralIOPinP$36 */

  /* Module HplAtm128GeneralIOPinP$37 */

  /* Module HplAtm128GeneralIOPinP$38 */

  /* Module HplAtm128GeneralIOPinP$39 */

  /* Module HplAtm128GeneralIOPinP$40 */

  /* Module HplAtm128GeneralIOPinP$41 */

  /* Module HplAtm128GeneralIOPinP$42 */

  /* Module HplAtm128GeneralIOPinP$43 */

  /* Module HplAtm128GeneralIOPinP$44 */

  /* Module HplAtm128GeneralIOPinP$45 */

  /* Module HplAtm128GeneralIOPinP$46 */

  /* Module HplAtm128GeneralIOPinP$47 */

  /* Module HplAtm128GeneralIOSlowPinP$0 */

  /* Module HplAtm128GeneralIOSlowPinP$1 */

  /* Module HplAtm128GeneralIOSlowPinP$2 */

  /* Module HplAtm128GeneralIOSlowPinP$3 */

  /* Module HplAtm128GeneralIOSlowPinP$4 */

  /* Module HplAtm128GeneralIOSlowPinP$5 */

  /* Module HplAtm128GeneralIOSlowPinP$6 */

  /* Module HplAtm128GeneralIOSlowPinP$7 */

  /* Module HplAtm128GeneralIOSlowPinP$8 */

  /* Module HplAtm128GeneralIOSlowPinP$9 */

  /* Module HplAtm128GeneralIOSlowPinP$10 */

  /* Module HplAtm128GeneralIOSlowPinP$11 */

  /* Module HplAtm128GeneralIOSlowPinP$12 */

  /* Module MeasureClockC */

  /* Module SimMainP */

  /* Module SimSchedulerBasicP */
  memset((void *)&SimSchedulerBasicP$m_head[__nesc_mote], 0, sizeof SimSchedulerBasicP$m_head[__nesc_mote]);
  memset((void *)&SimSchedulerBasicP$m_tail[__nesc_mote], 0, sizeof SimSchedulerBasicP$m_tail[__nesc_mote]);
  memset((void *)&SimSchedulerBasicP$m_next[__nesc_mote], 0, sizeof SimSchedulerBasicP$m_next[__nesc_mote]);
  SimSchedulerBasicP$sim_scheduler_event_pending[__nesc_mote] = FALSE;
  memset((void *)&SimSchedulerBasicP$sim_scheduler_event[__nesc_mote], 0, sizeof SimSchedulerBasicP$sim_scheduler_event[__nesc_mote]);

  /* Module SimMoteP */
  memset((void *)&SimMoteP$euid[__nesc_mote], 0, sizeof SimMoteP$euid[__nesc_mote]);
  memset((void *)&SimMoteP$startTime[__nesc_mote], 0, sizeof SimMoteP$startTime[__nesc_mote]);
  memset((void *)&SimMoteP$isOn[__nesc_mote], 0, sizeof SimMoteP$isOn[__nesc_mote]);
  memset((void *)&SimMoteP$bootEvent[__nesc_mote], 0, sizeof SimMoteP$bootEvent[__nesc_mote]);

  /* Module TossimActiveMessageC */
  memset((void *)&TossimActiveMessageC$buffer[__nesc_mote], 0, sizeof TossimActiveMessageC$buffer[__nesc_mote]);
  TossimActiveMessageC$bufferPointer[__nesc_mote] = &TossimActiveMessageC$buffer[__nesc_mote];

  /* Module TossimPacketModelC */
  TossimPacketModelC$initialized[__nesc_mote] = FALSE;
  TossimPacketModelC$running[__nesc_mote] = FALSE;
  memset((void *)&TossimPacketModelC$backoffCount[__nesc_mote], 0, sizeof TossimPacketModelC$backoffCount[__nesc_mote]);
  memset((void *)&TossimPacketModelC$neededFreeSamples[__nesc_mote], 0, sizeof TossimPacketModelC$neededFreeSamples[__nesc_mote]);
  TossimPacketModelC$sending[__nesc_mote] = (void *)0;
  TossimPacketModelC$transmitting[__nesc_mote] = FALSE;
  TossimPacketModelC$sendingLength[__nesc_mote] = 0;
  memset((void *)&TossimPacketModelC$destNode[__nesc_mote], 0, sizeof TossimPacketModelC$destNode[__nesc_mote]);
  memset((void *)&TossimPacketModelC$sendEvent[__nesc_mote], 0, sizeof TossimPacketModelC$sendEvent[__nesc_mote]);
  TossimPacketModelC$error[__nesc_mote] = 0;

  /* Module CpmModelC */
  memset((void *)&CpmModelC$outgoing[__nesc_mote], 0, sizeof CpmModelC$outgoing[__nesc_mote]);
  memset((void *)&CpmModelC$requestAck[__nesc_mote], 0, sizeof CpmModelC$requestAck[__nesc_mote]);
  CpmModelC$receiving[__nesc_mote] = 0;
  CpmModelC$transmitting[__nesc_mote] = 0;
  memset((void *)&CpmModelC$transmissionEndTime[__nesc_mote], 0, sizeof CpmModelC$transmissionEndTime[__nesc_mote]);
  CpmModelC$outstandingReceptionHead[__nesc_mote] = (void *)0;
  CpmModelC$clearThreshold[__nesc_mote] = -72.0;

  /* Module ActiveMessageAddressC */
  ActiveMessageAddressC$set[__nesc_mote] = FALSE;
  memset((void *)&ActiveMessageAddressC$addr[__nesc_mote], 0, sizeof ActiveMessageAddressC$addr[__nesc_mote]);

  /* Module PacketHandlerP */
  memset((void *)&PacketHandlerP$sendPackage[__nesc_mote], 0, sizeof PacketHandlerP$sendPackage[__nesc_mote]);
  memset((void *)&PacketHandlerP$pingPacket[__nesc_mote], 0, sizeof PacketHandlerP$pingPacket[__nesc_mote]);
  PacketHandlerP$SEQUENCE_NUM[__nesc_mote] = 0;
  PacketHandlerP$busy[__nesc_mote] = FALSE;
  memset((void *)&PacketHandlerP$pkt[__nesc_mote], 0, sizeof PacketHandlerP$pkt[__nesc_mote]);

  /* Module Atm128AlarmAsyncP$0 */
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote]);
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote]);
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote]);
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote]);

  /* Module HplAtm128Timer0AsyncP */
  HplAtm128Timer0AsyncP$inOverflow[__nesc_mote] = 0;
  HplAtm128Timer0AsyncP$lastZero[__nesc_mote] = 0;
  HplAtm128Timer0AsyncP$oldScale[__nesc_mote] = AVR_CLOCK_OFF;
  memset((void *)&HplAtm128Timer0AsyncP$compare[__nesc_mote], 0, sizeof HplAtm128Timer0AsyncP$compare[__nesc_mote]);
  memset((void *)&HplAtm128Timer0AsyncP$overflow[__nesc_mote], 0, sizeof HplAtm128Timer0AsyncP$overflow[__nesc_mote]);

  /* Module AlarmToTimerC$0 */
  memset((void *)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote], 0, sizeof /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote]);
  memset((void *)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote], 0, sizeof /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote]);

  /* Module VirtualizeTimerC$0 */
  memset((void *)&/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote], 0, sizeof /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote]);

  /* Module CounterToLocalTimeC$0 */

  /* Module QueueC$0 */
  memset((void *)&/*PacketHandlerC.QueueC*/QueueC$0$queue[__nesc_mote], 0, sizeof /*PacketHandlerC.QueueC*/QueueC$0$queue[__nesc_mote]);
  /*PacketHandlerC.QueueC*/QueueC$0$head[__nesc_mote] = 0;
  /*PacketHandlerC.QueueC*/QueueC$0$tail[__nesc_mote] = 0;
  /*PacketHandlerC.QueueC*/QueueC$0$size[__nesc_mote] = 0;

  /* Module PoolP$0 */
  memset((void *)&/*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[__nesc_mote], 0, sizeof /*PacketHandlerC.PoolC.PoolP*/PoolP$0$free[__nesc_mote]);
  memset((void *)&/*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[__nesc_mote], 0, sizeof /*PacketHandlerC.PoolC.PoolP*/PoolP$0$index[__nesc_mote]);
  memset((void *)&/*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue[__nesc_mote], 0, sizeof /*PacketHandlerC.PoolC.PoolP*/PoolP$0$queue[__nesc_mote]);
  memset((void *)&/*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool[__nesc_mote], 0, sizeof /*PacketHandlerC.PoolC.PoolP*/PoolP$0$pool[__nesc_mote]);

  /* Module AMQueueEntryP$0 */

  /* Module AMQueueImplP$0 */
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[__nesc_mote] = 1;
  memset((void *)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote], 0, sizeof /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote]);
  memset((void *)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote], 0, sizeof /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote]);

  /* Module CommandHandlerP */

  /* Module NeighborDiscoveryP */
  memset((void *)&NeighborDiscoveryP$pingPacket[__nesc_mote], 0, sizeof NeighborDiscoveryP$pingPacket[__nesc_mote]);
  NeighborDiscoveryP$TimeOutState[__nesc_mote] = TRUE;

  /* Module LinkStateRoutingP */
  memset((void *)&LinkStateRoutingP$linkStatePacket[__nesc_mote], 0, sizeof LinkStateRoutingP$linkStatePacket[__nesc_mote]);
  memset((void *)&LinkStateRoutingP$linkStates[__nesc_mote], 0, sizeof LinkStateRoutingP$linkStates[__nesc_mote]);
  memset((void *)&LinkStateRoutingP$compareBuffer[__nesc_mote], 0, sizeof LinkStateRoutingP$compareBuffer[__nesc_mote]);
  memset((void *)&LinkStateRoutingP$hopThrough[__nesc_mote], 0, sizeof LinkStateRoutingP$hopThrough[__nesc_mote]);
  memset((void *)&LinkStateRoutingP$unconsidered[__nesc_mote], 0, sizeof LinkStateRoutingP$unconsidered[__nesc_mote]);
  memset((void *)&LinkStateRoutingP$existing[__nesc_mote], 0, sizeof LinkStateRoutingP$existing[__nesc_mote]);
  LinkStateRoutingP$NeighborsChanged[__nesc_mote] = FALSE;
  LinkStateRoutingP$LSChanged[__nesc_mote] = FALSE;

  /* Module TransportP */
  memset((void *)&TransportP$TCPTable[__nesc_mote], 0, sizeof TransportP$TCPTable[__nesc_mote]);
  memset((void *)&TransportP$Attempt_Connection_Time[__nesc_mote], 0, sizeof TransportP$Attempt_Connection_Time[__nesc_mote]);

  /* Module HashmapC$0 */
  /*NodeC.neighborTable*/HashmapC$0$HASH_MAX_SIZE[__nesc_mote] = 20;
  memset((void *)&/*NodeC.neighborTable*/HashmapC$0$map[__nesc_mote], 0, sizeof /*NodeC.neighborTable*/HashmapC$0$map[__nesc_mote]);
  memset((void *)&/*NodeC.neighborTable*/HashmapC$0$keys[__nesc_mote], 0, sizeof /*NodeC.neighborTable*/HashmapC$0$keys[__nesc_mote]);
  memset((void *)&/*NodeC.neighborTable*/HashmapC$0$numofVals[__nesc_mote], 0, sizeof /*NodeC.neighborTable*/HashmapC$0$numofVals[__nesc_mote]);

  /* Module HashmapC$1 */
  /*NodeC.sequenceTable*/HashmapC$1$HASH_MAX_SIZE[__nesc_mote] = 192;
  memset((void *)&/*NodeC.sequenceTable*/HashmapC$1$map[__nesc_mote], 0, sizeof /*NodeC.sequenceTable*/HashmapC$1$map[__nesc_mote]);
  memset((void *)&/*NodeC.sequenceTable*/HashmapC$1$keys[__nesc_mote], 0, sizeof /*NodeC.sequenceTable*/HashmapC$1$keys[__nesc_mote]);
  memset((void *)&/*NodeC.sequenceTable*/HashmapC$1$numofVals[__nesc_mote], 0, sizeof /*NodeC.sequenceTable*/HashmapC$1$numofVals[__nesc_mote]);

  /* Module HashmapC$2 */
  /*NodeC.routingTable*/HashmapC$2$HASH_MAX_SIZE[__nesc_mote] = 32;
  memset((void *)&/*NodeC.routingTable*/HashmapC$2$map[__nesc_mote], 0, sizeof /*NodeC.routingTable*/HashmapC$2$map[__nesc_mote]);
  memset((void *)&/*NodeC.routingTable*/HashmapC$2$keys[__nesc_mote], 0, sizeof /*NodeC.routingTable*/HashmapC$2$keys[__nesc_mote]);
  memset((void *)&/*NodeC.routingTable*/HashmapC$2$numofVals[__nesc_mote], 0, sizeof /*NodeC.routingTable*/HashmapC$2$numofVals[__nesc_mote]);

  /* Module HashmapC$3 */
  /*NodeC.TCPTablePTR*/HashmapC$3$HASH_MAX_SIZE[__nesc_mote] = 255;
  memset((void *)&/*NodeC.TCPTablePTR*/HashmapC$3$map[__nesc_mote], 0, sizeof /*NodeC.TCPTablePTR*/HashmapC$3$map[__nesc_mote]);
  memset((void *)&/*NodeC.TCPTablePTR*/HashmapC$3$keys[__nesc_mote], 0, sizeof /*NodeC.TCPTablePTR*/HashmapC$3$keys[__nesc_mote]);
  memset((void *)&/*NodeC.TCPTablePTR*/HashmapC$3$numofVals[__nesc_mote], 0, sizeof /*NodeC.TCPTablePTR*/HashmapC$3$numofVals[__nesc_mote]);

  /* Module RandomMlcgC */
  memset((void *)&RandomMlcgC$seed[__nesc_mote], 0, sizeof RandomMlcgC$seed[__nesc_mote]);

}
