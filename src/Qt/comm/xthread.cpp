#include "../../xthread.h"
#include "../include/sys_thread.h"

xthread_t * xthread_create(xfn_thread_proc_t proc, void* pvuser)
{
    return (xthread_t *)sys_ThreadCreate((SYS_ThreadProcFunc)proc, pvuser);
}

xbool_t xthread_start(xthread_t * pthread)
{
    return sys_ThreadStart((SYS_Thread*) pthread);
}

xbool_t xthread_isExecuting(xthread_t * pthread)
{
    return sys_ThreadIsExecuting((SYS_Thread*) pthread);
}

void tr_ThreadDestory(xthread_t * pthread)
{
    sys_ThreadDestory((SYS_Thread*) pthread);
}


/************************************************************************************/
/*                                                                                  */
/*      线程间互斥相关api接口声明                                                       */
/*                                                                                  */
/************************************************************************************/

xmutex_t * xmutex_create()
{
    return (xmutex_t *)sys_MutexCreate();
}

void tr_MutexLock(xmutex_t * pmutex)
{
    sys_MutexLock((SYS_Mutex*) pmutex);
}

void tr_MutexUnlock(xmutex_t * pmutex)
{
    sys_MutexUnlock((SYS_Mutex*) pmutex);
}

void tr_MutexDestory(xmutex_t * pmutex)
{
    sys_MutexDestory((SYS_Mutex*) pmutex);
}









