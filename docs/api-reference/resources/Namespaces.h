// +---------------------------------------------------------------------------
// |
// |   XCore GPL Source Code
// |   Copyright (c) 2021 XNerv Ltda (http://xnerv.com). All rights reserved.
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

/**
 * @file
 *
 * @brief The purpose of this file is just to document our namespaces. Should not be included in any
 * place.
 */

#error "For namespaces documentation only. This file must not be included in any other file!"


/**
 * @namespace XCore
 *
 * @brief The root namespace for te XCore library.
 */
namespace XCore {
    /**
     * @namespace XCore::DLL
     *
     * @brief Contains a set of resources for work with shared library.
     */
    namespace DLL {

    }


    /**
     * @namespace XCore::Math
     *
     * @brief Contains a set of resources for work with math.
     *
     * @details This is the start point for mathematical manipulations. <br><br>We use a thirdparty
     * library for this purpose. The original library can be found in the following url <br>
     * https://github.com/meson-library/eigen. The namespace `XCore::Math` is an alias to the
     * original library <br> namespace that is `Eigen`.
     */
    namespace Math {

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
         * @brief Contains a global registry for loggers.
         */
        namespace Registry {

        }
    }


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

/**
 * @namespace xcore
 *
 * @brief This is the xcore, our complementary namespace to the 'std' namespace that is the standard
 * library.
 */
namespace xcore {
    /**
     * @namespace xcore::platform
     *
     * @brief Contains a set of specific platform implementation resources.
     */
    namespace platform {

    }

    /**
     * @namespace xcore::stl
     *
     * @brief Contains our stl implementation.
     *
     * @details This namespace contains our stl implementation. This stl implementation was made by
     * Electronic Arts (EASTL). The original thirdparty library can be found in the following url
     * https://github.com/meson-library/eastl. The namespace `xcore::stl` is an alias to the original
     * library namespace that is `eastl`.
     */
    namespace stl {

    }

    /**
     * @namespace xcore::filesystem
     *
     * @brief Contains a set of resources for work with filesystem.
     *
     * @details This is the start point for filesystem manipulations like read and write to files,
     * list directories, set <br> file attributes, copy and move files and so on... <br> <br> We use
     * a thirdparty library for this purpose. The original library can be found in the following url
     * <br> https://github.com/meson-library/filesystem. The namespace `xcore::filesystem` is an
     * alias to the original library <br> namespace that is `ghc::filesystem`. Basicaly the original
     * library consist of a C++11 cross-platform <br> implementation of the standard
     * `std::filesystem` (Now already included in the C++17 standard).
     */
    namespace filesystem {

    }
}
