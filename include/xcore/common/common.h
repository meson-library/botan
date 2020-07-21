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

/**
 * @file
 * 
 * @brief Contains a common set of shared codes.
 *
 * @details This file contains a common set of shared codes, typedef(s)  
 *          and macro definitions, shared among all other source files.   
 *          Common codes you will find here are macros for data alignment,  
 *          architecture and operational system identification and so on...
 */

#pragma once

/*
 * Macros for operational system identification.
 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(DOXYGEN)
    /**
     * @brief Identify that the target operational system is Windows.
     */
    #define XCORE_OS_FAMILY_WINDOWS
#endif

#if defined(linux) || defined(__linux) || defined(__linux__) || defined(DOXYGEN)
    /**
     * @brief Identify that the target operational system is Linux.
     */
    #define XCORE_OS_FAMILY_LINUX
#endif

#if defined(__APPLE__) && defined(__MACH__) || defined(DOXYGEN)
    /**
     * @brief Identify that the target operational system is OSX.
     */
    #define XCORE_OS_FAMILY_OSX
#endif

#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))  || defined(DOXYGEN)
    /**
     * @brief Identify that the target operational system is UNIX.
     */
    #define XCORE_OS_FAMILY_UNIX
#endif



/*
 * Macro for compiler identification.
 */
#if defined(DOXYGEN)
    /**
     * @brief Identify that the target compiler is MSVC.
     */
    #define XCORE_COMPILER_MSVC

    /**
     * @brief Identify that the target compiler is GCC.
     */
    #define XCORE_COMPILER_GCC
#elif defined(_MSC_VER)
    #if _MSC_VER >= 1500
        #define XCORE_COMPILER_MSVC
    #else
        #error MSVC++ compiler 9.0 or higher is required.
    #endif
#elif defined(__GNUC__)
    #if __GNUC__ >= 4
        #define XCORE_COMPILER_GCC
    #else
        #error GCC compiler greater than 4 is required.
    #endif
#else
    #error The compiler is not supported.
#endif



/*
 * Other macro definitions.
 */
#if defined(DOXYGEN)
    /**
     * @brief Define what attribute must be used to import symbols from a shared
     *        library.
     *
     * @details Define what attribute must be used to instruct the linker to import
     *          a symbol from a shared library. On MSVC is `__declspec(dllimport)`
     *          on GCC is `__attribute__ ((visibility ("default")))`.
     */
    #define XCORE_SYMBOL_IMPORT

    /**
     * @brief Define what attribute must be used to export symbols from a shared
     *        library.
     *
     * @details Define what attribute must be used to instruct the linker to export
     *          a symbol to a shared library. On MSVC is `__declspec(dllexport)`
     *          on GCC is `__attribute__ ((visibility ("default")))`.
     */
    #define XCORE_SYMBOL_EXPORT

    /**
     * @brief Define what attribute must be used to not export symbols from a shared
     *        library.
     *
     * @details Define what attribute must be used to instruct the linker to not export
     *          any symbol from a shared library. In MSVC, all symbols are not exported
     *          by default, so we don't need any attributes to prevent symbol export.
     *          In GCC, all synbols are exported by default, so we use the following
     *          attribute to prevent symbol export `__attribute__ ((visibility ("hidden")))`.
     */
    #define XCORE_SYMBOL_LOCAL

    /**
     * @brief Valid only within a function and returns the signature of the enclosing
     *        function (as a string).
     */
    #define XCORE_CURRENT_FUNCTION
#elif defined(XCORE_COMPILER_MSVC)
    #define XCORE_SYMBOL_IMPORT __declspec(dllimport)
    #define XCORE_SYMBOL_EXPORT __declspec(dllexport)
    #define XCORE_SYMBOL_LOCAL

    #define XCORE_CURRENT_FUNCTION __FUNCSIG__
#elif defined(XCORE_COMPILER_GCC)
    #define XCORE_SYMBOL_IMPORT __attribute__ ((visibility ("default")))
    #define XCORE_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
    #define XCORE_SYMBOL_LOCAL  __attribute__ ((visibility ("hidden")))

    #define XCORE_CURRENT_FUNCTION __PRETTY_FUNCTION__
#endif



#if defined(DOXYGEN)
    /**
     * @brief Macro to import/export symbols from the public API.
     *        The value is determined by the macros #XCORE_SYMBOL_IMPORT
     *        and #XCORE_SYMBOL_EXPORT.
     */
    #define XCORE_API
#elif defined(XCORE_BUILD_STATIC_LIBRARY)
    #define XCORE_API
#elif defined(XCORE_BUILD_SHARED_LIBRARY)
    #define XCORE_API XCORE_SYMBOL_EXPORT
#else
    #define XCORE_API XCORE_SYMBOL_IMPORT
#endif



/**
 * @brief Stringify the identifier passed as argument.
 *
 * @details Turns an unquoted identifier into a "quoted" string.
 *
 * @code{.c}
 *     #define PI 3.14
 *     XCORE_STRINGIFY_IDENTIFIER(PI) // After macro expansion, we will get this: "PI".
 *                                    // The only thing made was the quotation of the
 *                                    // identifier passed as argument.
 * @endcode
 */
#define XCORE_STRINGIFY_IDENTIFIER(ARG) #ARG

/**
 * @brief Stringify the value of the macro passed as argument.
 *
 * @details Turns the value of the macro passed as argument into a "quoted" string.
 *
 * @code{.c}
 *     #define PI 3.14
 *     XCORE_STRINGIFY_MACRO(PI) // After macro expansion, we will get this: "3.14".
 *                               // The only thing made was the quotation of the value
 *                               // of the macro passed as argument.
 * @endcode
 */
#define XCORE_STRINGIFY_MACRO(ARG) XCORE_STRINGIFY_IDENTIFIER(ARG)



#if defined(XCORE_COMPILER_MSVC) || defined(DOXYGEN)
    #include <windows.h>

    /**
     * @brief A handle to manage a dynamic shared library.
     *
     * @details On MSVC this macro expands to #HMODULE and
     *          on GCC expands to `void*`.
     */
    typedef HMODULE XCORE_DLL_HANDLER;

    /**
     * @brief A pointer to a symbol inside a shared library.
     *
     * @details On MSVC this macro expands to #FARPROC and
     *          on GCC expands to `void*`.
     */
    typedef FARPROC XCORE_DLL_SYMBOL_POINTER;
#else
    typedef void* XCORE_DLL_HANDLER;
    typedef void* XCORE_DLL_SYMBOL_POINTER;
#endif



/**
 * @brief Represent the default STL implementation.
 */
#define XCORE_STL   1

/**
 * @brief Represent the EASTL implementation.
 */
#define XCORE_EASTL 2



#if defined(DOXYGEN)
    /**
     * @brief Calling convention.
     *
     * @details On MSVC `__stdcall` and on GCC `__attribute__((stdcall))`
     */
    #define XCORE_STDCALL

    /**
     * @brief Calling convention.
     *
     * @details On MSVC `__cdecl` and on GCC expand to nothing.
     */
    #define XCORE_CDECL

    /**
     * @brief Calling convention.
     *
     * @details On MSVC `__fastcall` and on GCC `__attribute__((fastcall))`
     */
    #define XCORE_FASTCALL
#elif defined(XCORE_COMPILER_MSVC)
    #define XCORE_STDCALL __stdcall
    #define XCORE_CDECL __cdecl
    #define XCORE_FASTCALL __fastcall
#elif defined(XCORE_COMPILER_GCC)
    #define XCORE_STDCALL  __attribute__((stdcall))
    #define XCORE_CDECL
    #define XCORE_FASTCALL __attribute__((fastcall))
#endif



#if defined(__cplusplus)
    /**
     * @brief This macro should be used to indicate that the functions
     *        declared after this macro should be treated with C linkage.
     *        Therefore, C++ will not mangle the function names.
     */
    #define XCORE_EXTERN_C_BEGIN extern "C" {

    /**
     * @brief This macro should be used in conjunction with #XCORE_EXTERN_C_BEGIN.
     */
    #define XCORE_EXTERN_C_END }
#else
    #define XCORE_EXTERN_C_BEGIN
    #define XCORE_EXTERN_C_END
#endif



#if defined(DOXYGEN)
    /**
     * @brief Force a function to be inlined.
     *
     * @details As the name say, force a function to be inlined even if the compiler disagree
     *          with you. On MSVC this macro expand to `__forceinline`. On GCC this macro expand
     *          to `__attribute__((always_inline)) inline`.
     */
    #define XCORE_FORCE_INLINE
#elif defined(XCORE_COMPILER_MSVC)
    #define XCORE_FORCE_INLINE __forceinline
#elif defined(XCORE_COMPILER_GCC)
    #define XCORE_FORCE_INLINE __attribute__((always_inline)) inline
#endif



#if defined(DOXYGEN)
    /**
     * @brief Specifies the alignment requirement of a type or an object.
     */
    #define XCORE_ALIGN(x)

    /**
     * @brief Returns the alignment, in bytes, of the specified type.
     */
    #define XCORE_ALIGNOF(x)
#elif defined(XCORE_COMPILER_MSVC)
    #define XCORE_ALIGN(x)   __declspec(align(x))
    #define XCORE_ALIGNOF(x) __alignof(x)
#elif defined(XCORE_COMPILER_GCC)
    #define XCORE_ALIGN(x)   __attribute__((aligned(x)))
    #define XCORE_ALIGNOF(x) __alignof__(x)
#endif



#if defined(DOXYGEN)
    /**
     * @brief Identify that the target system is 32 bits.
     */
    #define XCORE_SYSTEM_32BIT

    /**
     * @brief Identify that the target system is 64 bits.
     */
    #define XCORE_SYSTEM_64BIT
#elif defined(XCORE_COMPILER_MSVC)
    #if _WIN64
        #define XCORE_SYSTEM_64BIT
    #else
        #define XCORE_SYSTEM_32BIT
    #endif
#elif defined(XCORE_COMPILER_GCC)
    #if __x86_64__ || __ppc64__
        #define XCORE_SYSTEM_64BIT
    #else
        #define XCORE_SYSTEM_32BIT
    #endif
#endif



/**
 * @brief Disable move and copy constructors and operator= overloadings.
 *
 * @details With this method we can disable the copy/move constructors
 *          and operator= overloading. Thus, transforming our type into 
 *          a non-copyable and non-movable type.
 *
 * @attention Only the copy constructor and the operator= overload are disabled (deleted)
 *            by this macro. However, according to the C++11 standard, when a copy constructor
 *            is provided (Even if is a deleted copy constructor), the move constructor and the 
 *            move operator= is not generated by the compiler. Thus, transforming our type 
 *            into a non-copyable and non-movable type. For more info about move constructors, 
 *            go to the <a href="https://en.cppreference.com/w/cpp/language/move_constructor" 
 *            target="_blank">C++ reference website</a>.
 *
 * @param TypeName Name of the non copyable type (struct or class).
 */
#define XCORE_DISABLE_COPY_AND_MOVE(TypeName) \
    explicit TypeName(const TypeName& typeName) = delete; \
    TypeName & operator=(const TypeName & typeName) = delete
