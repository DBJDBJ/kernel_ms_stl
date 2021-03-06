/*
(c) 2020 by dbj@dbj.org -- LICENSE_DBJ -- https://dbj.org/license_dbj/

Kernel switch, what is that?

*/

#include "fwk/nanoclib.h"
#include "use_cases/canary.h"

#if _HAS_EXCEPTIONS
#include "use_cases/standard_try_throw_catch.h"
#endif // _HAS_EXCEPTIONS

#if ! _HAS_EXCEPTIONS
#include "use_cases/seh_ms_stl.h"
#endif // ! _HAS_EXCEPTIONS

#ifdef SAMPLE_COMDEF_KERNEL_COMBO
#include "use_cases/comdef_kernel_combo.h"
#endif // SAMPLE_COMDEF_KERNEL_COMBO

// #define DBJ_WIN_ERR_SAMPLE
#ifdef DBJ_WIN_ERR_SAMPLE
#include "infrastructure/winerr_dbj.h"
#endif // DBJ_WIN_ERR_SAMPLE

#define DBJ_TUF_SAMPLING
#ifdef DBJ_TUF_SAMPLING
#include "TUF\tuf.h"
#endif // DBJ_TUF_SAMPLING

#define DBJ_NBT_SAMPLING
#ifdef DBJ_NBT_SAMPLING
#include "infrastructure/dbj_nothing_but.h"
#endif // DBJ_NBT_SAMPLING


// user code start here
// this is called from framework
// framework is where SE handling is implemented
extern "C" int program (int argc , char ** argv ) 
{

#ifdef DBJ_NBT_SAMPLING
sample_nothing_but(argc,argv);
#endif

#ifdef DBJ_TUF_SAMPLING
return test_tuf(argc,argv);
#endif // DBJ_TUF_SAMPLING

#if ! _HAS_EXCEPTIONS
// seh_ms_stl();
#endif // ! _HAS_EXCEPTIONS

#ifdef DBJ_WIN_ERR_SAMPLE
//dbj::_win_raise_error(CO_E_SERVER_START_TIMEOUT);
dbj::is_win10() ;
#endif // DBJ_WIN_ERR_SAMPLE

#ifdef SAMPLE_COMDEF_KERNEL_COMBO
comdef_kernel_combo();
#endif // SAMPLE_COMDEF_KERNEL_COMBO

#if _HAS_EXCEPTIONS
standard_try_throw_catch();
#endif // _HAS_EXCEPTIONS
  return 0;
}
//--------------------------------------------------------------------------------------
// this instance dtor is always visited
static canary in_the_bottomles_pit(__FILE__, __LINE__ ) ;


