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

#include "XCore/Common/Types/Guid.h"

namespace XCore { namespace Common { namespace Types {

    XCore::Common::Types::Guid::Guid() : m_bytes {{0}}
    {
    }

    XCore::Common::Types::Guid::Guid(const xcore::stl::string& input)
    {
        if (!Guid::TryParse(input, *this))
        {
            throw std::runtime_error(
                "Provided string in invalid format. Guid should contain 32 digits with 4 "
                "dashes. Example: \"xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx\". Provided string: "
                + xcore::utils::stl::to_std_string(input));
        }
    }

    XCore::Common::Types::Guid::Guid(const xcore::stl::array<unsigned char, 16>& input)
        : m_bytes(input)
    {
    }

    bool XCore::Common::Types::Guid::operator==(const Guid& other) const
    {
        return m_bytes == other.m_bytes;
    }

    bool XCore::Common::Types::Guid::operator!=(const Guid& other) const
    {
        return !((*this) == other);
    }

    bool isValidHexChar(char ch)
    {
        // 0-9
        if (ch > 47 && ch < 58)
            return true;

        // a-f
        if (ch > 96 && ch < 103)
            return true;

        // A-F
        if (ch > 64 && ch < 71)
            return true;

        return false;
    }

    // converts a single hex char to a number (0 - 15)
    unsigned char hexDigitToChar(char ch)
    {
        // 0-9
        if (ch > 47 && ch < 58)
            return ch - 48;

        // a-f
        if (ch > 96 && ch < 103)
            return ch - 87;

        // A-F
        if (ch > 64 && ch < 71)
            return ch - 55;

        return 0;
    }

    // converts the two hexadecimal characters to an unsigned char (a byte)
    unsigned char hexPairToChar(char a, char b)
    {
        return hexDigitToChar(a) * 16 + hexDigitToChar(b);
    }

    XCore::Common::Types::Guid XCore::Common::Types::Guid::NewGuid()
    {
        return xcore::platform::get_guid();
    }

    bool XCore::Common::Types::Guid::TryParse(const xcore::stl::string& input, Guid& result)
    {
        xcore::stl::array<unsigned char, 16> bytes;
        char                                charOne             = '\0';
        char                                charTwo             = '\0';
        bool                                lookingForFirstChar = true;
        unsigned                            nextByte            = 0;

        for (const char& ch: input)
        {
            if (ch == '-')
                continue;

            if (nextByte >= 16 || !isValidHexChar(ch))
            {
                break;
            }

            if (lookingForFirstChar)
            {
                charOne             = ch;
                lookingForFirstChar = false;
            }
            else
            {
                charTwo             = ch;
                auto byte           = hexPairToChar(charOne, charTwo);
                bytes[nextByte++]   = byte;
                lookingForFirstChar = true;
            }
        }

        if (nextByte < 16)
        {
            return false;
        }

        result.m_bytes = bytes;

        return true;
    }

    bool XCore::Common::Types::Guid::IsEmpty() const
    {
        XCore::Common::Types::Guid empty;
        return *this == empty;
    }

    const xcore::stl::array<unsigned char, 16>& XCore::Common::Types::Guid::ToByteArray() const
    {
        return m_bytes;
    }

    xcore::stl::string XCore::Common::Types::Guid::ToString() const
    {
        char one[10], two[6], three[6], four[6], five[14];

        snprintf(one, 10, "%02x%02x%02x%02x", m_bytes[0], m_bytes[1], m_bytes[2], m_bytes[3]);
        snprintf(two, 6, "%02x%02x", m_bytes[4], m_bytes[5]);
        snprintf(three, 6, "%02x%02x", m_bytes[6], m_bytes[7]);
        snprintf(four, 6, "%02x%02x", m_bytes[8], m_bytes[9]);
        snprintf(five,
                 14,
                 "%02x%02x%02x%02x%02x%02x",
                 m_bytes[10],
                 m_bytes[11],
                 m_bytes[12],
                 m_bytes[13],
                 m_bytes[14],
                 m_bytes[15]);
        const xcore::stl::string sep("-");
        xcore::stl::string       out(one);

        out += sep + two;
        out += sep + three;
        out += sep + four;
        out += sep + five;

        return out;
    }
}}}
