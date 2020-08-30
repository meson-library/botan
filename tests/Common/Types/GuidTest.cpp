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

#include <XCore/XCore.h>
#include <gtest/gtest.h>

TEST(CommonTypesMainTests, NewGuidShouldNotBeEmpty)
{
    auto guid01 = XCore::Common::Types::Guid::NewGuid();
    EXPECT_FALSE(guid01.IsEmpty());
}

TEST(CommonTypesMainTests, GuidShouldBeEmpty)
{
    XCore::Common::Types::Guid guid;
    EXPECT_TRUE(guid.IsEmpty());
    EXPECT_STRCASEEQ(guid.ToString().c_str(), "00000000-0000-0000-0000-000000000000");
}

TEST(CommonTypesMainTests, GuidShouldNotBeEmpty)
{
    XCore::Common::Types::Guid guid("591b22fd-3812-4195-a95e-a8597e80fda3");
    EXPECT_FALSE(guid.IsEmpty());
    ASSERT_STRCASENE(guid.ToString().c_str(), "00000000-0000-0000-0000-000000000000");
}

TEST(CommonTypesMainTests, GuidShouldBe_FFA8F07B32194945B6A3FFF9CEE5D469)
{
    XCore::Common::Types::Guid guid("ffa8f07b-3219-4945-b6a3-fff9cee5d469");
    EXPECT_STRCASEEQ(guid.ToString().c_str(), "ffa8f07b-3219-4945-b6a3-fff9cee5d469");
}

TEST(CommonTypesMainTests, GuidShouldThrowWhenConstructorWithEmptyArg)
{
    EXPECT_THROW(XCore::Common::Types::Guid guid(""), std::runtime_error);
}

TEST(CommonTypesMainTests, GuidShouldThrowWhenConstructorWithMalformedArg)
{
    EXPECT_THROW(XCore::Common::Types::Guid guid("-3219-4945-b6a3-fff9cee5d469"), std::runtime_error);
}

TEST(CommonTypesMainTests, GuidTryParseShouldReturnTrueWhenParseValidArg)
{
    XCore::Common::Types::Guid guid;
    EXPECT_TRUE(XCore::Common::Types::Guid::TryParse("0ef3013f-c739-4d6c-9190-1a0bfc647762", guid));
}

TEST(CommonTypesMainTests, GuidTryParseShouldReturnValidGuidWhenParseValidArg)
{
    XCore::Common::Types::Guid guid;
    XCore::Common::Types::Guid::TryParse("2a7179d5-bf22-43ff-9783-08d695043671", guid);

    EXPECT_EQ(guid, XCore::Common::Types::Guid::Guid("2a7179d5-bf22-43ff-9783-08d695043671"));
}

TEST(CommonTypesMainTests, GuidCopyTest)
{
    auto guid01 = XCore::Common::Types::Guid::Guid("a76c8778-e88c-41d8-ba1f-0e03e01fb7d6");

    auto guid02(guid01);

    EXPECT_EQ(guid02, guid01);
}

TEST(CommonTypesMainTests, GuidMoveTest)
{
    auto guid01 = XCore::Common::Types::Guid::Guid("f5c68663-7a6a-48d8-a94a-2b7167499bcc");
    auto guid02(std::move(guid01));

    EXPECT_EQ(guid02, guid01);
}

TEST(CommonTypesMainTests, GuidEqualityTest)
{
    auto guid01 = XCore::Common::Types::Guid::Guid("c5edddf9-7ce0-470a-a457-488676bfaef4");
    auto guid02 = XCore::Common::Types::Guid::Guid("c5edddf9-7ce0-470a-a457-488676bfaef4");
    auto guid03 = XCore::Common::Types::Guid::Guid("31fa551f-4002-4ffb-bf36-4f089c73cc91");

    EXPECT_TRUE(guid01 == guid02);
    EXPECT_FALSE(guid01 == guid03);
    EXPECT_FALSE(guid01 != guid02);
    EXPECT_TRUE(guid01 != guid03);
}

TEST(CommonTypesMainTests, GuidToStringShouldReturnValidValue)
{
    XCore::Common::Types::Guid guid01;
    auto guid02 = XCore::Common::Types::Guid::Guid("a76c8778-e88c-41d8-ba1f-0e03e01fb7d6");
    auto guid03 = XCore::Common::Types::Guid::Guid("d58adcc9-5035-46e7-916a-e6905ec08c3f");

    EXPECT_EQ(guid01.ToString(), "00000000-0000-0000-0000-000000000000");
    EXPECT_EQ(guid02.ToString(), "a76c8778-e88c-41d8-ba1f-0e03e01fb7d6");
    EXPECT_EQ(guid03.ToString(), "d58adcc9-5035-46e7-916a-e6905ec08c3f");
}
