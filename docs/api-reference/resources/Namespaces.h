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
    The purpose of this file is just to document our namespaces. Should not be
    included in any place.
*/
#error "For documentation only."


/**
 * @namespace XCore
 *
 * @brief The root namespace for te XCore library.
 */
namespace XCore {
    /**
     * @namespace XCore::DLL
     *
     * @brief Contains a set of resources for shared library manipulations.
     */
    namespace DLL {

    }


    /**
     * @namespace XCore::FS
     *
     * @brief Contains a set of resources for filesystem manipulation.
     *
     * @details This is the start point for filesystem manipulations like read and write to files,
     * list directories, set <br> file attributes, copy and move files and so on... <br> <br> We use
     * a thirdparty library for this purpose. The original library can be found in the following url
     * <br> https://github.com/meson-library/filesystem. The namespace `XCore::FS` is an alias to
     * the original library <br> namespace that is `ghc::filesystem`. Basicaly the original library
     * consist of a C++11 cross-platform <br> implementation of the standard `std::filesystem` (Now
     * already included in the C++17 standard).
     */
    namespace FS {

    }


    /**
     * @namespace XCore::Math
     *
     * @brief Contains a set of resources for mathematical manipulation.
     *
     * @details This is the start point for mathematical manipulations. <br>
     *          <br>
     *          We use a thirdparty library for this purpose. The original library can be found in
     * the following url <br> https://github.com/meson-library/eigen. The namespace `XCore::Math` is
     * an alias to the original library <br> namespace that is `Eigen`.
     */
    namespace Math {

    }


    /**
     * @namespace XCore::STL
     *
     * @brief Contains the STL implementation currently in use by our system.
     *
     * @details This namespace contains the STL implementation currently in use by our system. We
     * can use the standard STL <br> implementation of our compilers or use an implementation from
     * Eletronic Arts (EASTL). <br> <br> We use a thirdparty library for this purpose. The original
     * library can be found in the following url <br> https://github.com/meson-library/eastl. The
     * namespace `XCore::STL` is an alias to the original library <br> namespace that is `eastl` or
     * `std` from standard stl implementation.
     */
    namespace STL {

    }


    /**
     * @namespace XCore::Log
     *
     * @brief Contains a set of resources for work with logs.
     */
    namespace Log {
        /**
         * @namespace XCore::Log::Registry
         *
         * @brief  Contains our logger implementation.
         *
         * @details This is the start point for log manipulations.
         */
        namespace Registry {

        }
    }  // namespace Log


    /**
     * @namespace XCore::Plugin
     *
     * @brief Contains a set of resources for work with plugins.
     *
     * @details This is the start point for plugin manipulations.
     */
    namespace Plugin {

    }
}
