#pragma once

#include <locale>
#include <codecvt>
#include <string>

// Given a UTF-8 encoded string return a new UCS-2 string.
inline std::u16string
utf8_to_ucs2(std::string const& input)
{
        std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> convert;
        {
            return convert.from_bytes(input);
        }
}

// Given a UCS-2 string return a new UTF-8 encoded string.
inline std::string
ucs2_to_utf8(std::u16string const& input)
{
        std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> convert;
        return convert.to_bytes(input);
}