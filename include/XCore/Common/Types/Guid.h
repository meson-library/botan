/*
The MIT License (MIT)

Copyright (c) 2014 Graeme Hill (http://graemehill.ca)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once

#include "../Core.h"

namespace XCore { namespace Common { namespace Types {

    class Guid
    {
    public:
        Guid();
        Guid(const core::stl::string& input);
        Guid(const core::stl::array<unsigned char, 16>& input);

        Guid(const Guid& other) = default;
        Guid& operator=(const Guid& other) = default;
        Guid(Guid&& other)                 = default;
        Guid& operator=(Guid&& other) = default;

        bool operator==(const Guid& other) const;
        bool operator!=(const Guid& other) const;

        static Guid NewGuid();

        static bool TryParse(const core::stl::string& input, Guid& result);
        bool        IsEmpty() const;
        const core::stl::array<unsigned char, 16>& ToByteArray() const;
        core::stl::string                          ToString() const;

    private:
        core::stl::array<unsigned char, 16> m_bytes;
    };
}}}
