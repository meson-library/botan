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

/**
 * @file
 *
 * @brief Contains our stl implementation.
 */

#pragma once

#include "common.h"

/**
 * @cond
 */
#include <EASTL/algorithm.h>
#include <EASTL/allocator.h>
#include <EASTL/allocator_malloc.h>
#include <EASTL/any.h>
#include <EASTL/array.h>
#include <EASTL/bitset.h>
#include <EASTL/bitvector.h>
#include <EASTL/bonus/adaptors.h>
#include <EASTL/bonus/call_traits.h>
#include <EASTL/bonus/compressed_pair.h>
#include <EASTL/bonus/fixed_ring_buffer.h>
#include <EASTL/bonus/fixed_tuple_vector.h>
#include <EASTL/bonus/intrusive_sdlist.h>
#include <EASTL/bonus/intrusive_slist.h>
#include <EASTL/bonus/list_map.h>
#include <EASTL/bonus/lru_cache.h>
#include <EASTL/bonus/ring_buffer.h>
#include <EASTL/bonus/sort_extra.h>
#include <EASTL/bonus/sparse_matrix.h>
#include <EASTL/bonus/tuple_vector.h>
#include <EASTL/chrono.h>
#include <EASTL/core_allocator.h>
#include <EASTL/core_allocator_adapter.h>
#include <EASTL/deque.h>
#include <EASTL/finally.h>
#include <EASTL/fixed_allocator.h>
#include <EASTL/fixed_function.h>
#include <EASTL/fixed_hash_map.h>
#include <EASTL/fixed_hash_set.h>
#include <EASTL/fixed_list.h>
#include <EASTL/fixed_map.h>
#include <EASTL/fixed_set.h>
#include <EASTL/fixed_slist.h>
#include <EASTL/fixed_string.h>
#include <EASTL/fixed_substring.h>
#include <EASTL/fixed_vector.h>
#include <EASTL/functional.h>
#include <EASTL/hash_map.h>
#include <EASTL/hash_set.h>
#include <EASTL/heap.h>
#include <EASTL/initializer_list.h>
#include <EASTL/intrusive_hash_map.h>
#include <EASTL/intrusive_hash_set.h>
#include <EASTL/intrusive_list.h>
#include <EASTL/intrusive_ptr.h>
#include <EASTL/iterator.h>
#include <EASTL/linked_array.h>
#include <EASTL/linked_ptr.h>
#include <EASTL/list.h>
#include <EASTL/map.h>
#include <EASTL/memory.h>
#include <EASTL/meta.h>
#include <EASTL/numeric.h>
#include <EASTL/numeric_limits.h>
#include <EASTL/optional.h>
#include <EASTL/priority_queue.h>
#include <EASTL/queue.h>
#include <EASTL/random.h>
#include <EASTL/ratio.h>
#include <EASTL/safe_ptr.h>
#include <EASTL/scoped_array.h>
#include <EASTL/scoped_ptr.h>
#include <EASTL/segmented_vector.h>
#include <EASTL/set.h>
#include <EASTL/shared_array.h>
#include <EASTL/shared_ptr.h>
#include <EASTL/slist.h>
#include <EASTL/sort.h>
#include <EASTL/span.h>
#include <EASTL/stack.h>
#include <EASTL/string.h>
#include <EASTL/string_hash_map.h>
#include <EASTL/string_map.h>
#include <EASTL/string_view.h>
#include <EASTL/tuple.h>
#include <EASTL/type_traits.h>
#include <EASTL/unique_ptr.h>
#include <EASTL/unordered_map.h>
#include <EASTL/unordered_set.h>
#include <EASTL/utility.h>
#include <EASTL/variant.h>
#include <EASTL/vector.h>
#include <EASTL/vector_map.h>
#include <EASTL/vector_multimap.h>
#include <EASTL/vector_multiset.h>
#include <EASTL/vector_set.h>
#include <EASTL/version.h>
#include <EASTL/weak_ptr.h>
/**
 * @endcond
 */

#include <memory>

namespace xcore { namespace stl {
    using namespace eastl;

    /**
     * @brief Convert a std::shared_ptr<T> to a xcore::stl::shared_ptr<T>.
     *
     * @tparam T Type.
     *
     * @param[in] input The shared pointer to convert.
     *
     * @return A std::shared_ptr<T> as xcore::stl::shared_ptr<T>.
     */
    template<typename T>
    xcore::stl::shared_ptr<T> to_xcore_ptr(std::shared_ptr<T>& input)
    {
        return xcore::stl::shared_ptr<T>(input.get(), [input](T*) mutable {
            input.reset();
        });
    }

    /**
     * @brief Convert a xcore::stl::shared_ptr<T> to a std::shared_ptr<T>.
     *
     * @tparam T Type.
     *
     * @param[in] input The shared pointer to convert.
     *
     * @return A xcore::stl::shared_ptr<T> as std::shared_ptr<T>.
     */
    template<typename T>
    std::shared_ptr<T> to_std_ptr(xcore::stl::shared_ptr<T>& input)
    {
        return std::shared_ptr<T>(input.get(), [input](T*) mutable {
            input.reset();
        });
    }

    /**
     * @brief
     *
     * @tparam N
     * @tparam T
     * @param input
     * @return xcore::stl::array<T, N>
     */
    template<std::size_t N, typename T>
    xcore::stl::array<T, N> to_xcore_array(std::array<T, N>& input)
    {
        xcore::stl::array<T, N> converted;
        std::copy(input.begin(), input.end(), converted.begin());
        return converted;
    }

    /**
     * @brief Convert a std::string to a xcore::stl::string.
     *
     * @param[in] input The string to convert.
     *
     * @return A std::string as xcore::stl::string.
     */
    XCORE_API xcore::stl::string to_xcore_string(const std::string& input);

    /**
     * @brief Convert a xcore::stl::string to a std::string.
     *
     * @param[in] input The string to convert.
     *
     * @return A xcore::stl::string as std::string.
     */
    XCORE_API std::string to_std_string(const xcore::stl::string& input);
}}
