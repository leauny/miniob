/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by WangYunlai on 2023/06/28.
//

#include <sstream>
#include <string>
#include <iomanip>
#include <regex>
#include <cmath>
#include "sql/parser/value.h"
#include "common/log/log.h"
#include "common/lang/comparator.h"
#include "common/lang/string.h"
#include "common/rc.h"
#include "storage/field/field_meta.h"

class FielsdMeta;
const char *ATTR_TYPE_NAME[] = {"undefined", "chars", "ints", "dates", "nulls", "texts", "floats", "booleans"};

const char *attr_type_to_string(AttrType type)
{
  if (type >= UNDEFINED && type <= FLOATS) {
    return ATTR_TYPE_NAME[type];
  }
  return "unknown";
}
AttrType attr_type_from_string(const char *s)
{
  for (unsigned int i = 0; i < sizeof(ATTR_TYPE_NAME) / sizeof(ATTR_TYPE_NAME[0]); i++) {
    if (0 == strcmp(ATTR_TYPE_NAME[i], s)) {
      return (AttrType)i;
    }
  }
  return UNDEFINED;
}

Value::Value(int val) { set_int(val); }

Value::Value(float val) { set_float(val); }

Value::Value(bool val) { set_boolean(val); }

Value::Value(const char *s, int len /*= 0*/) { set_string(s, len); }

Value::Value(date val) { set_date(val); }

Value::Value(date val, std::string date_format) { set_date(val, date_format); }

void Value::set_data(char *data, int length)
{
  switch (attr_type_) {
    case CHARS: {
      set_string(data, length);
    } break;
    case TEXTS: {
      set_string(data,length);
    } break;
    case INTS: {
      num_value_.int_value_ = *(int *)data;
      length_               = length;
    } break;
    case FLOATS: {
      num_value_.float_value_ = *(float *)data;
      length_                 = length;
    } break;
    case BOOLEANS: {
      num_value_.bool_value_ = *(int *)data != 0;
      length_                = length;
    } break;
    case DATES: {
      date_value_ = string_to_date(data, length);
      length_     = length;
    } break;
    case NULLS: {
      length_ = length;
    } break;
    default: {
      LOG_WARN("unknown data type: %d", attr_type_);
    } break;
  }
}
void Value::set_int(int val)
{
  attr_type_            = INTS;
  num_value_.int_value_ = val;
  length_               = sizeof(val);
}

void Value::set_float(float val)
{
  attr_type_              = FLOATS;
  num_value_.float_value_ = val;
  length_                 = sizeof(val);
}

void Value::set_float(float val, int round)
{
  attr_type_              = FLOATS;
  num_value_.float_value_ = std::round(val * pow(10, round_)) / pow(10, round_);
  round_                  = round;
  length_                 = sizeof(val);
}

void Value::set_boolean(bool val)
{
  attr_type_             = BOOLEANS;
  num_value_.bool_value_ = val;
  length_                = sizeof(val);
}
void Value::set_string(const char *s, int len /*= 0*/)
{
  attr_type_ = CHARS;
  if (len > 0) {
    len = strnlen(s, len);
    str_value_.assign(s, len);
  } else {
    str_value_.assign(s);
  }
  length_ = str_value_.length() + 1;
}
void Value::set_date(std::chrono::year_month_day val)
{
  attr_type_  = DATES;
  date_value_ = val;
  length_     = strlen(date_to_string(date_value_));
}

void Value::set_null()
{
  attr_type_ = NULLS;
  length_    = 4;
}

void Value::set_date(date val, std::string date_format)
{
  attr_type_   = DATES;
  date_value_  = val;
  date_format_ = date_format;
  length_      = strlen(date_to_string(date_value_));
}

void Value::set_value(const Value &value)
{
  switch (value.attr_type_) {
    case INTS: {
      set_int(value.get_int());
    } break;
    case FLOATS: {
      set_float(value.get_float());
    } break;
    case CHARS: {
      set_string(value.get_string().c_str());
    } break;
    case BOOLEANS: {
      set_boolean(value.get_boolean());
    } break;
    case DATES: {
      set_date(value.get_date());
    } break;
    case NULLS: {
      set_null();
    } break;
    case UNDEFINED: {
      ASSERT(false, "got an invalid value type");
    } break;
  }
}

const char *Value::data() const
{
  switch (attr_type_) {
    case CHARS: {
      return str_value_.c_str();
    } break;
    case DATES: {
      return date_to_string(date_value_);
    } break;
    case NULLS: {
      return "\7\7\7";
    } break;
    default: {
      return (const char *)&num_value_;
    } break;
  }
}

std::string Value::to_string() const
{
  std::stringstream os;
  switch (attr_type_) {
    case INTS: {
      os << num_value_.int_value_;
    } break;
    case FLOATS: {
      if (round_ < 0) {
        os << common::double_to_str(num_value_.float_value_);
      } else {
        os << common::double_to_str(std::round(num_value_.float_value_ * std::pow(10, round_)) / std::pow(10, round_));
      }
    } break;
    case BOOLEANS: {
      os << num_value_.bool_value_;
    } break;
    case DATES: {
      os << date_to_string(date_value_);
    } break;
    case CHARS: {
      os << str_value_;
    } break;
    case TEXTS: {
      os << str_value_;
    } break;
    case NULLS: {
      os << "null";
    } break;
    default: {
      LOG_WARN("unsupported attr type: %d", attr_type_);
    } break;
  }
  return os.str();
}

bool Value::is_like(const Value &other) const
{
  // 只判断CHARS
  if (!(this->attr_type_ == other.attr_type_ && this->attr_type_ == CHARS)) {
    return false;
  }
  std::string str         = this->str_value_.c_str();
  std::string old_pattern = other.str_value_.c_str();
  std::string new_pattern;
  bool        is_escape = false;
  // 将sql的通配符转换为正则表达式的通配符
  for (char i : old_pattern) {
    switch (i) {
      case '\\': {
        is_escape = true;
      } break;
      case '.': {
        new_pattern += "\\.";
      } break;
      case '*': {
        new_pattern += "\\*";
      } break;
      case '_': {
        if (is_escape) {
          new_pattern += '_';
          is_escape = false;
        } else {
          new_pattern += '.';
        }
      } break;
      case '%': {
        if (is_escape) {
          new_pattern += '%';
          is_escape = false;
        } else {
          new_pattern += ".*";
        }
      } break;
      default: {
        new_pattern += i;
        is_escape = false;
      }
    }
  }
  std::regex pattern(new_pattern);
  return std::regex_match(str, pattern);
}

int Value::compare(const Value &other) const
{
  if (this->attr_type_ == other.attr_type_) {
    switch (this->attr_type_) {
      case INTS: {
        return common::compare_int((void *)&this->num_value_.int_value_, (void *)&other.num_value_.int_value_);
      } break;
      case FLOATS: {
        return common::compare_float((void *)&this->num_value_.float_value_, (void *)&other.num_value_.float_value_);
      } break;
      case CHARS: {
        return common::compare_string((void *)this->str_value_.c_str(),
            this->str_value_.length(),
            (void *)other.str_value_.c_str(),
            other.str_value_.length());
      } break;
      case DATES: {
        return common::compare_date((void *)&this->date_value_, (void *)&other.date_value_);
      } break;
      case BOOLEANS: {
        return common::compare_int((void *)&this->num_value_.bool_value_, (void *)&other.num_value_.bool_value_);
      } break;
      case NULLS: {
        return 0;
      } break;
      default: {
        LOG_WARN("unsupported type: %d", this->attr_type_);
      }
    }
  } else if (this->attr_type_ == INTS && other.attr_type_ == FLOATS) {
    float this_data = this->num_value_.int_value_;
    return common::compare_float((void *)&this_data, (void *)&other.num_value_.float_value_);
  } else if (this->attr_type_ == FLOATS && other.attr_type_ == INTS) {
    float other_data = other.num_value_.int_value_;
    return common::compare_float((void *)&this->num_value_.float_value_, (void *)&other_data);
  } else if (this->attr_type_ == CHARS && other.attr_type_ == FLOATS) {
    float       this_data;
    std::string v = this->str_value_;
    if (!(('0' <= v[0] && v[0] <= '9') || (v[0] == '.'))) {
      this_data = 0;
    } else {
      this_data = std::stof(v);
    }
    return common::compare_float((void *)&this_data, (void *)&other.num_value_.float_value_);
  } else if (this->attr_type_ == FLOATS && other.attr_type_ == CHARS) {
    float       other_data;
    std::string v = other.str_value_;
    if (!(('0' <= v[0] && v[0] <= '9') || (v[0] == '.'))) {
      other_data = 0;
    } else {
      other_data = std::stof(v);
    }
    return common::compare_float((void *)&this->num_value_.float_value_, (void *)&other_data);
  } else if (this->attr_type_ == CHARS && other.attr_type_ == INTS) {
    float       this_data;
    std::string v = this->str_value_;
    if (!('0' <= v[0] && v[0] <= '9')) {
      this_data = 0;
    } else {
      this_data = std::stof(v);
    }
    float other_data = other.num_value_.int_value_;
    return common::compare_float((void *)&this_data, (void *)&other_data);
  } else if (this->attr_type_ == INTS && other.attr_type_ == CHARS) {
    float       this_data = this->num_value_.int_value_;
    float       other_data;
    std::string v = other.str_value_;
    if (!('0' <= v[0] && v[0] <= '9')) {
      other_data = 0;
    } else {
      other_data = std::stof(v);
    }
    return common::compare_float((void *)&this_data, (void *)&other_data);
  } else if (this->attr_type_ == NULLS && other.attr_type_ != NULLS) {
    return -1;
  } else if (other.attr_type_ == NULLS && this->attr_type_ != NULLS) {
    return 1;
  }
  LOG_WARN("not supported");
  return -1;  // TODO return rc?
}

int Value::get_int() const
{
  switch (attr_type_) {
    case CHARS: {
      try {
        return (int)(std::stol(str_value_));
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to number. s=%s, ex=%s", str_value_.c_str(), ex.what());
        return 0;
      }
    }
    case INTS: {
      return num_value_.int_value_;
    }
    case FLOATS: {
      return (int)(num_value_.float_value_);
    }
    case BOOLEANS: {
      return (int)(num_value_.bool_value_);
    }
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}

float Value::get_float() const
{
  switch (attr_type_) {
    case CHARS: {
      try {
        return std::stof(str_value_);
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to float. s=%s, ex=%s", str_value_.c_str(), ex.what());
        return 0.0;
      }
    } break;
    case INTS: {
      return float(num_value_.int_value_);
    } break;
    case FLOATS: {
      return num_value_.float_value_;
    } break;
    case BOOLEANS: {
      return float(num_value_.bool_value_);
    } break;
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}

std::string Value::get_string() const { return this->to_string(); }

bool Value::get_boolean() const
{
  switch (attr_type_) {
    case CHARS: {
      try {
        float val = std::stof(str_value_);
        if (val >= EPSILON || val <= -EPSILON) {
          return true;
        }
        int int_val = std::stoi(str_value_);
        if (int_val != 0) {
          return true;
        }
        return false;
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to float or integer. s=%s, ex=%s", str_value_.c_str(), ex.what());
        return false;
      }
    } break;
    case INTS: {
      return num_value_.int_value_ != 0;
    } break;
    case FLOATS: {
      float val = num_value_.float_value_;
      return val >= EPSILON || val <= -EPSILON;
    } break;
    case BOOLEANS: {
      return num_value_.bool_value_;
    } break;
    case DATES: return date_value_ != date(std::chrono::year(0), std::chrono::month(0), std::chrono::day(0));
    case NULLS: return false;
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return false;
    }
  }
  return false;
}
date Value::get_date() const { return this->date_value_; }

const char *Value::date_to_string(date val) const
{
  std::tm time{};
  time.tm_year = static_cast<int>(val.year()) - 1900;
  time.tm_mon  = static_cast<unsigned>(val.month()) - 1;
  time.tm_mday = static_cast<unsigned>(val.day());

  bool        is_format = false;
  std::string format;
  for (char c : date_format_) {
    switch (c) {
      case '%': {
        format += c;
        is_format = !is_format;
      } break;
      case 'n':
      case 'z': {
        if (!is_format) {
          format += c;
          break;
        }
        // n和z不识别
        format    = format.substr(0, format.size() - 1) + c;
        is_format = false;
      } break;
      case 'M': {
        if (!is_format) {
          format += c;
          break;
        }
        format += 'B';
        is_format = false;
      } break;
      case 'D': {
        if (!is_format) {
          format += c;
          break;
        }
        // c++会自动加空格，因此去除前面的%后直接写入结果
        format = format.substr(0, format.size() - 1) + std::to_string(time.tm_mday);
        if (time.tm_mday % 10 == 1 && time.tm_mday != 11) {
          format += "st";
        } else if (time.tm_mday % 10 == 2 && time.tm_mday != 12) {
          format += "nd";
        } else if (time.tm_mday % 10 == 3 && time.tm_mday != 13) {
          format += "rd";
        } else {
          format += "th";
        }
        is_format = false;
      } break;
      default: format += c; is_format = false;
    }
  }

  std::stringstream ss;
  ss << std::put_time(&time, format.c_str());
  std::string date_string = ss.str();

  // 分配动态内存来存储字符串，并复制字符串内容
  char *result = new char[date_string.length() + 1];
  strcpy(result, date_string.c_str());

  return result;
}

date Value::string_to_date(const char *data, int length)
{
  char              *tmp = common::substr(data, 0, length - 1);
  std::istringstream iss(tmp);
  char               delimiter = std::string(tmp).find('-') == std::string::npos ? '/' : '-';
  std::string        token;

  std::getline(iss, token, delimiter);
  int year = std::stoi(token);
  if (year / 100 == 0) {
    year += 2000;
  }

  std::getline(iss, token, delimiter);
  int month = std::stoi(token);

  std::getline(iss, token);
  int                         day = std::stoi(token);
  std::chrono::year_month_day ymd{std::chrono::year(year), std::chrono::month(month), std::chrono::day(day)};
  return ymd;
}
std::string Value::get_date_format() const { return date_format_; }

RC value_cast(const FieldMeta *field_meta, Value &value)
{
  AttrType field_type = field_meta->type();
  AttrType value_type = value.attr_type();
  if (field_type != value_type) {
    if (field_meta->nullable() && value_type == NULLS) {
      // do nothing, skip the type check and convert
    } else if (!field_meta->nullable() && value_type == NULLS) {
      LOG_WARN("field type mismatch. field=%s, field type=%d, value_type=%d",
          field_meta->name(), field_type, value_type);
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    } else if (field_type == CHARS || field_type == TEXTS) {
      const char *data = value.get_string().c_str();
      value.set_string(data, strlen(data));
    } else if (field_type == INTS) {
      int data;
      switch (value_type) {
        case CHARS: {
          std::string v = (char *)value.data();
          if (!('0' <= v[0] && v[0] <= '9')) {
            data = 0;
          } else {
            data = std::stoi(v);
          }
        } break;
        case FLOATS: {
          float v = *(float *)value.data();
          data    = (int)std::round(v);
        } break;
      }
      value.set_int(data);
    } else if (field_type == FLOATS) {
      float data;
      switch (value_type) {
        case CHARS: {
          std::string v = (char *)value.data();
          if (!(('0' <= v[0] && v[0] <= '9') || (v[0] == '.'))) {
            data = 0;
          } else {
            data = std::stof(v);
          }
        } break;
        case INTS: {
          int v = *(int *)value.data();
          data  = (float)v;
        } break;
      }
      value.set_float(data);
    } else {
      LOG_WARN("field type mismatch. field=%s, field type=%d, value_type=%d",
          field_meta->name(), field_type, value_type);
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  }
  return RC::SUCCESS;
}
