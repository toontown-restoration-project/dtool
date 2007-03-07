// Filename: mutexImpl.h
// Created by:  drose (08Aug02)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001 - 2004, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://etc.cmu.edu/panda3d/docs/license/ .
//
// To contact the maintainers of this program write to
// panda3d-general@lists.sourceforge.net .
//
////////////////////////////////////////////////////////////////////

#ifndef MUTEXIMPL_H
#define MUTEXIMPL_H

#include "dtoolbase.h"
#include "selectThreadImpl.h"

#if defined(THREAD_DUMMY_IMPL)

#include "mutexDummyImpl.h"
typedef MutexDummyImpl MutexImpl;
typedef MutexDummyImpl ReMutexImpl;
#define HAVE_REMUTEXIMPL 1

#elif defined(MUTEX_SPINLOCK)

#include "mutexSpinlockImpl.h"
typedef MutexSpinlockImpl MutexImpl;
#undef HAVE_REMUTEXIMPL

#elif defined(THREAD_WIN32_IMPL)

#include "mutexWin32Impl.h"
typedef MutexWin32Impl MutexImpl;
typedef MutexWin32Impl ReMutexImpl;  // Win32 Mutexes are always reentrant.
#define HAVE_REMUTEXIMPL 1

#elif defined(THREAD_LINUX_IMPL)

#include "mutexLinuxImpl.h"
typedef MutexLinuxImpl MutexImpl;
#undef HAVE_REMUTEXIMPL  // The futex implementation is non-reentrant.

#elif defined(THREAD_POSIX_IMPL)

#include "mutexPosixImpl.h"
typedef MutexPosixImpl MutexImpl;
typedef ReMutexPosixImpl ReMutexImpl;
#define HAVE_REMUTEXIMPL 1

#endif

#endif



