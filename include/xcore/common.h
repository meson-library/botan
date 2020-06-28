// +---------------------------------------------------------------------------
// |
// |   XCore GPL Source Code
// |   Copyright (c) 2020 XNerv Ltda (http://xnerv.com). All rights reserved.
// |
// |   This file is part of the XCore GPL Source Code.
// |
// |   XCore Source Code is free software: you can redistribute it and/or
// |   modify it under the terms of the GNU General Public License
// |   as published by the Free Software Foundation, either version 3
// |   of the License, or (at your option) any later version.
// |
// |   XCore Source Code is distributed in the hope that it will be useful,
// |   but WITHOUT ANY WARRANTY; without even the implied warranty of
// |   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// |   GNU General Public License for more details.
// |
// |   You should have received a copy of the GNU General Public License
// |   along with XCore Source Code. If not, see <http://www.gnu.org/licenses/>.
// |
// +---------------------------------------------------------------------------

#pragma once

/*
 * Macro for operational system identification.
 *
 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(DOXYGEN)
    /**
     * 	@ingroup    xcore
     *
     * 	@def        XCORE_OS_FAMILY_WINDOWS
     *
     *  @brief      The target operational system is Windows.
     */
#    define XCORE_OS_FAMILY_WINDOWS
#endif

#if defined(linux) || defined(__linux) || defined(__linux__) || defined(DOXYGEN)
    /**
     * 	@ingroup    xcore
     *
     * 	@def        XCORE_OS_FAMILY_LINUX
     *
     *  @brief      The target operational system is Linux.
     */
#    define XCORE_OS_FAMILY_LINUX
#endif

#if defined(__APPLE__) && defined(__MACH__) || defined(DOXYGEN)
    /**
     * 	@ingroup    xcore
     *
     * 	@def        XCORE_OS_FAMILY_OSX
     *
     *  @brief      The target operational system is OSX.
     */
#    define XCORE_OS_FAMILY_OSX
#endif

#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))  || defined(DOXYGEN)
    /**
     * 	@ingroup    xcore
     *
     * 	@def        XCORE_OS_FAMILY_UNIX
     *
     *  @brief      The target operational system is UNIX.
     */
#    define XCORE_OS_FAMILY_UNIX
#endif




/*
 * Macro for compiler identification.
 *
 */
#if defined(DOXYGEN)
    /**
     * 	@ingroup    xcore
     *
     * 	@def        XCORE_COMPILER_MSVC
     *
     *  @brief      The target compiler is MSVC.
     */
#    define XCORE_COMPILER_MSVC

    /**
     * 	@ingroup    xcore
     *
     * 	@def        XCORE_COMPILER_GCC
     *
     *  @brief      The target compiler is GCC.
     */
#    define XCORE_COMPILER_GCC

#elif defined(_MSC_VER)
#    if _MSC_VER >= 1500
#        define XCORE_COMPILER_MSVC
#    else
#        error MSVC++ compiler 9.0 or higher is required.
#    endif

#elif defined(__GNUC__)
#    if __GNUC__ >= 4
#        define XCORE_COMPILER_GCC
#    else
#        error GCC compiler greater than 4 is required.
#    endif

#else
#    error The compiler is not supported.
#endif




/*
 * Other macro definitions.
 *
 */
#if defined(DOXYGEN)
    /**
     *  @ingroup    xcore
     *
     *  @def        XCORE_CURRENT_FUNCTION
     *
     *  @brief      Valid only within a function and returns the signature of the enclosing function (as a string).
     */
#   define XCORE_CURRENT_FUNCTION

#elif defined(XCORE_COMPILER_MSVC)
#    define XCORE_SYMBOL_IMPORT __declspec(dllimport)
#    define XCORE_SYMBOL_EXPORT __declspec(dllexport)
#    define XCORE_SYMBOL_LOCAL
#
#    define XCORE_CURRENT_FUNCTION __FUNCSIG__

#elif defined(XCORE_COMPILER_GCC)
#    define XCORE_SYMBOL_IMPORT __attribute__ ((visibility ("default")))
#    define XCORE_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
#    define XCORE_SYMBOL_LOCAL  __attribute__ ((visibility ("hidden")))

#    define XCORE_CURRENT_FUNCTION __PRETTY_FUNCTION__
#endif




#if defined(DOXYGEN)
    /**
     *  @ingroup   xcore
     *
     *  @def       XCORE_API
     *
     *  @brief     Macro to import/export symbols from the public API.
     */
#    define XCORE_API

#elif defined(XCORE_BUILDING_STATIC_LIBRARY)
#    define XCORE_API

#elif defined(XCORE_BUILDING_SHARED_LIBRARY)
#    define XCORE_API XCORE_SYMBOL_EXPORT

#else
#    define XCORE_API XCORE_SYMBOL_IMPORT
#endif




#define XCORE_TEXTIFY2(A) #A
#define XCORE_TEXTIFY(A) XCORE_TEXTIFY2(A)




#if defined(XCORE_COMPILER_MSVC)
#include <windows.h>
typedef HMODULE XCORE_DLL_HANDLER;
typedef FARPROC XCORE_DLL_SYMBOL_POINTER;
#else
typedef void* XCORE_DLL_HANDLER;
typedef void* XCORE_DLL_SYMBOL_POINTER;
#endif