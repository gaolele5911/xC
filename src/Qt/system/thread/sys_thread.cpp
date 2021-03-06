//
//  sys_bitmap.mm
// System_api
//
//  Created by zjy on 12-6-27.
//  Copyright 2011 __MyCompanyName__. All rights reserved.

#include "../../include/sys_thread.h"
#include "../include/sys_threaddef.h"



SYS_Thread* sys_ThreadCreate(SYS_ThreadProcFunc proc, void* pvuser)
{
    SYS_Thread * pThread = new SYS_Thread;
    if (pThread)
    {
        pThread->_pThreadEngine = new CThreadEngine;
        pThread->_pThreadProcFunc = proc;
        pThread->_pvUser = pvuser;
        pThread->_pThreadEngine->SetNotify(pThread);
    }
    return pThread;
}

unsigned char sys_ThreadStart(SYS_Thread* pthread)
{
    if (pthread)
    {
        pthread->_pThreadEngine->Start();
        return 1;
    }
    return 0;
}

unsigned char sys_ThreadCancel(SYS_Thread* pthread)
{
    if (pthread)
    {
        pthread->_pThreadEngine->Cancel();
        return 1;
    }
    return 0;
}

unsigned char sys_ThreadIsExecuting(SYS_Thread* pthread)
{
    if (pthread)
    {
        return pthread->_pThreadEngine->IsExecuting();
    }
    return 0;
}

void sys_ThreadDestory(SYS_Thread* pthread)
{
    if (pthread)
    {
        delete pthread->_pThreadEngine;
        delete pthread;
        pthread = NULL;
    }
}

/************************************************************************************/
/*                                                                                  */
/*      线程间互斥相关api接口声明                                                       */
/*                                                                                  */
/************************************************************************************/

SYS_Mutex* sys_MutexCreate()
{
    SYS_Mutex* pmutex= new SYS_Mutex;
    pmutex->_pMutexEngine = new CMutexEngine;
    return  pmutex;
}

void sys_MutexLock(SYS_Mutex* pmutex)
{
    if (pmutex) {
        pmutex->_pMutexEngine->lock();
    }
}

void sys_MutexUnlock(SYS_Mutex* pmutex)
{
    if (pmutex) {
        pmutex->_pMutexEngine->unlock();
    }
}

void sys_MutexDestory(SYS_Mutex* pmutex)
{
    if (pmutex) {
        delete pmutex->_pMutexEngine;
        delete pmutex;
        pmutex= NULL;
    }
}




