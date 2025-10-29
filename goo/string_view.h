//========================================================================
//
// string_view.h
//
// This file is licensed under the GPLv2 or later.
//
// Copyright 2025 Jonathan Hähne
//
//========================================================================

#ifndef STRING_VIEW_H
#define STRING_VIEW_H

#include <string_view>
#include <string>

// Adaptor to allow lookups into a std::unordered_map<std::string, ...> by const char * or string_view.
struct string_hash
{
    using is_transparent = void;
    [[nodiscard]] size_t operator()(const char *txt) const { return std::hash<std::string_view> {}(txt); }
    [[nodiscard]] size_t operator()(std::string_view txt) const { return std::hash<std::string_view> {}(txt); }
    [[nodiscard]] size_t operator()(const std::string &txt) const { return std::hash<std::string> {}(txt); }
};

#endif
