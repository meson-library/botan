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

/**
 * @namespace xcore
 * 
 * @brief The root namespace for te xcore library.
 * 
 */
namespace xcore
{
    /**
     * @namespace xcore::dll
     * 
     * @brief Contains a set of resources for shared library manipulations.
     * 
     */
    namespace dll
    {

    }



    /**
     * @namespace xcore::fs
     * 
     * @brief Contains a set of resources for filesystem manipulation.
     * 
     * @details This is the start point for filesystem manipulations like read and write to files, list directories, set <br> 
     *          file attributes, copy and move files and so on... <br>
     *          <br>
     *          We use a thirdparty library for this purpose. The original library can be found in the following url <br> 
     *          https://github.com/meson-library/filesystem. The namespace `xcore::fs` is an alias to the original library <br>
     *          namespace that is `ghc::filesystem`. Basicaly the original library consist of a C++11 cross-platform <br>
     *          implementation of the standard `std::filesystem` (Now already included in the C++17 standard).
     * 
     */
    namespace fs
    {

    }



    /**
     * @namespace xcore::math
     * 
     * @brief Contains a set of resources for mathematical manipulation.
     * 
     * @details This is the start point for mathematical manipulations. <br>
     *          <br>
     *          We use a thirdparty library for this purpose. The original library can be found in the following url <br> 
     *          https://github.com/meson-library/eigen. The namespace `xcore::math` is an alias to the original library <br>
     *          namespace that is `Eigen`.
     * 
     */
    namespace math
    {

    }



    /**
     * @namespace xcore::stl
     * 
     * @brief Contains the STL implementation currently in use by our system.
     * 
     * @details This namespace contains the STL implementation currently in use by our system. We can use the standard STL <br>
     *          implementation of our compilers or use an implementation from Eletronic Arts (EASTL). <br>
     *          <br>
     *          We use a thirdparty library for this purpose. The original library can be found in the following url <br> 
     *          https://github.com/meson-library/eastl. The namespace `xcore::math` is an alias to the original library <br>
     *          namespace that is `eastl`.
     * 
     */
    namespace stl
    {

    }



    /**
    * @namespace xcore::log
    * 
    * @brief Contains a set of resources for work with logs.
    * 
    * @details This is the start point for log manipulations. <br>
    *          <br>
    *          We use a thirdparty library for this purpose. The original library can be found in the following url <br> 
    *          https://github.com/meson-library/spdlog. The namespace `xcore::log` is an alias to the original library <br>
    *          namespace that is `spdlog`.
    * 
    */
    namespace log
    {

    }



    /**
    * @namespace xcore::plugin
    * 
    * @brief Contains a set of resources for work with plugins.
    * 
    * @details This is the start point for plugin manipulations.
    * 
    */
    namespace plugin
    {

    }
}