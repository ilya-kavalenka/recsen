#pragma once

#include "common.h"
#include "message_info.h"

#include <sstream>
#include <string>
#include <optional>

namespace recsen::core
{
    class message_data_t
    {
    public:

        message_data_t();
        message_data_t(size_t size);
        message_data_t(const message_data_t& message_data);

        ~message_data_t();

        void set_bool(size_t offset, bool value);

        bool get_bool(size_t offset) const;

        void set_bool_optional(size_t offset, std::optional<bool> value);

        std::optional<bool> get_bool_optional(size_t offset) const;

        void set_char(size_t offset, char value);

        char get_char(size_t offset) const;

        void set_char_optional(size_t offset, std::optional<char> value);

        std::optional<char> get_char_optional(size_t offset) const;

        void set_uchar(size_t offset, wchar_t value);

        wchar_t get_uchar(size_t offset) const;

        void set_uchar_optional(size_t offset, std::optional<wchar_t> value);

        std::optional<wchar_t> get_uchar_optional(size_t offset) const;

        void set_int8(size_t offset, int8_t value);

        int8_t get_int8(size_t offset) const;

        void set_int8_optional(size_t offset, std::optional<int8_t> value);

        std::optional<int8_t> get_int8_optional(size_t offset) const;

        void set_uint8(size_t offset, uint8_t value);

        uint8_t get_uint8(size_t offset) const;

        void set_uint8_optional(size_t offset, std::optional<uint8_t> value);

        std::optional<uint8_t> get_uint8_optional(size_t offset) const;

        void set_int16(size_t offset, int16_t value);

        int16_t get_int16(size_t offset) const;

        void set_int16_optional(size_t offset, std::optional<int16_t> value);

        std::optional<int16_t> get_int16_optional(size_t offset) const;

        void set_uint16(size_t offset, uint16_t value);

        uint16_t get_uint16(size_t offset) const;

        void set_uint16_optional(size_t offset, std::optional<uint16_t> value);

        std::optional<uint16_t> get_uint16_optional(size_t offset) const;

        void set_int32(size_t offset, int32_t value);

        int32_t get_int32(size_t offset) const;

        void set_int32_optional(size_t offset, std::optional<int32_t> value);

        std::optional<int32_t> get_int32_optional(size_t offset) const;

        void set_uint32(size_t offset, uint32_t value);

        uint32_t get_uint32(size_t offset) const;

        void set_uint32_optional(size_t offset, std::optional<uint32_t> value);

        std::optional<uint32_t> get_uint32_optional(size_t offset) const;

        void set_int64(size_t offset, int64_t value);

        int64_t get_int64(size_t offset) const;

        void set_int64_optional(size_t offset, std::optional<int64_t> value);

        std::optional<int64_t> get_int64_optional(size_t offset) const;

        void set_uint64(size_t offset, uint64_t value);

        uint64_t get_uint64(size_t offset) const;

        void set_uint64_optional(size_t offset, std::optional<uint64_t> value);

        std::optional<uint64_t> get_uint64_optional(size_t offset) const;

        void set_double(size_t offset, double value);

        double get_double(size_t offset) const;

        void set_double_optional(size_t offset, std::optional<double> value);

        std::optional<double> get_double_optional(size_t offset) const;

        void set_timestamp(size_t offset, timestamp_t value);

        timestamp_t get_timestamp(size_t offset) const;

        void set_timestamp_optional(size_t offset, std::optional<timestamp_t> value);

        std::optional<timestamp_t> get_timestamp_optional(size_t offset) const;

    private:

        static size_t get_cappacity(size_t size);

        size_t capacity_;
        uint8_t* data_;
    };
}