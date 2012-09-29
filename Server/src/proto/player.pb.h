// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: player.proto

#ifndef PROTOBUF_player_2eproto__INCLUDED
#define PROTOBUF_player_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace proto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_player_2eproto();
void protobuf_AssignDesc_player_2eproto();
void protobuf_ShutdownFile_player_2eproto();

class Command;
class Command_Information;

enum Command_Type {
  Command_Type_SET_POSITION = 1,
  Command_Type_PREVIOUS_CHAPTER = 2,
  Command_Type_NEXT_CHAPTER = 3,
  Command_Type_REWIND = 4,
  Command_Type_FAST_FORWARD = 5,
  Command_Type_STOP = 6,
  Command_Type_PLAY = 7,
  Command_Type_PAUSE = 8,
  Command_Type_MUTE = 9,
  Command_Type_SET_VOLUME = 10,
  Command_Type_TOGGLE_FULL_SCREEN = 11,
  Command_Type_START_MOVIE = 12
};
bool Command_Type_IsValid(int value);
const Command_Type Command_Type_Type_MIN = Command_Type_SET_POSITION;
const Command_Type Command_Type_Type_MAX = Command_Type_START_MOVIE;
const int Command_Type_Type_ARRAYSIZE = Command_Type_Type_MAX + 1;

const ::google::protobuf::EnumDescriptor* Command_Type_descriptor();
inline const ::std::string& Command_Type_Name(Command_Type value) {
  return ::google::protobuf::internal::NameOfEnum(
    Command_Type_descriptor(), value);
}
inline bool Command_Type_Parse(
    const ::std::string& name, Command_Type* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Command_Type>(
    Command_Type_descriptor(), name, value);
}
// ===================================================================

class Command_Information : public ::google::protobuf::Message {
 public:
  Command_Information();
  virtual ~Command_Information();
  
  Command_Information(const Command_Information& from);
  
  inline Command_Information& operator=(const Command_Information& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Command_Information& default_instance();
  
  void Swap(Command_Information* other);
  
  // implements Message ----------------------------------------------
  
  Command_Information* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Command_Information& from);
  void MergeFrom(const Command_Information& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string value = 1;
  inline bool has_value() const;
  inline void clear_value();
  static const int kValueFieldNumber = 1;
  inline const ::std::string& value() const;
  inline void set_value(const ::std::string& value);
  inline void set_value(const char* value);
  inline void set_value(const char* value, size_t size);
  inline ::std::string* mutable_value();
  inline ::std::string* release_value();
  
  // @@protoc_insertion_point(class_scope:proto.Command.Information)
 private:
  inline void set_has_value();
  inline void clear_has_value();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* value_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_player_2eproto();
  friend void protobuf_AssignDesc_player_2eproto();
  friend void protobuf_ShutdownFile_player_2eproto();
  
  void InitAsDefaultInstance();
  static Command_Information* default_instance_;
};
// -------------------------------------------------------------------

class Command : public ::google::protobuf::Message {
 public:
  Command();
  virtual ~Command();
  
  Command(const Command& from);
  
  inline Command& operator=(const Command& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Command& default_instance();
  
  void Swap(Command* other);
  
  // implements Message ----------------------------------------------
  
  Command* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Command& from);
  void MergeFrom(const Command& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  typedef Command_Information Information;
  
  typedef Command_Type Type;
  static const Type SET_POSITION = Command_Type_SET_POSITION;
  static const Type PREVIOUS_CHAPTER = Command_Type_PREVIOUS_CHAPTER;
  static const Type NEXT_CHAPTER = Command_Type_NEXT_CHAPTER;
  static const Type REWIND = Command_Type_REWIND;
  static const Type FAST_FORWARD = Command_Type_FAST_FORWARD;
  static const Type STOP = Command_Type_STOP;
  static const Type PLAY = Command_Type_PLAY;
  static const Type PAUSE = Command_Type_PAUSE;
  static const Type MUTE = Command_Type_MUTE;
  static const Type SET_VOLUME = Command_Type_SET_VOLUME;
  static const Type TOGGLE_FULL_SCREEN = Command_Type_TOGGLE_FULL_SCREEN;
  static const Type START_MOVIE = Command_Type_START_MOVIE;
  static inline bool Type_IsValid(int value) {
    return Command_Type_IsValid(value);
  }
  static const Type Type_MIN =
    Command_Type_Type_MIN;
  static const Type Type_MAX =
    Command_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    Command_Type_Type_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Type_descriptor() {
    return Command_Type_descriptor();
  }
  static inline const ::std::string& Type_Name(Type value) {
    return Command_Type_Name(value);
  }
  static inline bool Type_Parse(const ::std::string& name,
      Type* value) {
    return Command_Type_Parse(name, value);
  }
  
  // accessors -------------------------------------------------------
  
  // required .proto.Command.Type type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::proto::Command_Type type() const;
  inline void set_type(::proto::Command_Type value);
  
  // optional .proto.Command.Information info = 2;
  inline bool has_info() const;
  inline void clear_info();
  static const int kInfoFieldNumber = 2;
  inline const ::proto::Command_Information& info() const;
  inline ::proto::Command_Information* mutable_info();
  inline ::proto::Command_Information* release_info();
  
  // @@protoc_insertion_point(class_scope:proto.Command)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_info();
  inline void clear_has_info();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::proto::Command_Information* info_;
  int type_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_player_2eproto();
  friend void protobuf_AssignDesc_player_2eproto();
  friend void protobuf_ShutdownFile_player_2eproto();
  
  void InitAsDefaultInstance();
  static Command* default_instance_;
};
// ===================================================================


// ===================================================================

// Command_Information

// required string value = 1;
inline bool Command_Information::has_value() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Command_Information::set_has_value() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Command_Information::clear_has_value() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Command_Information::clear_value() {
  if (value_ != &::google::protobuf::internal::kEmptyString) {
    value_->clear();
  }
  clear_has_value();
}
inline const ::std::string& Command_Information::value() const {
  return *value_;
}
inline void Command_Information::set_value(const ::std::string& value) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(value);
}
inline void Command_Information::set_value(const char* value) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(value);
}
inline void Command_Information::set_value(const char* value, size_t size) {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  value_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Command_Information::mutable_value() {
  set_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    value_ = new ::std::string;
  }
  return value_;
}
inline ::std::string* Command_Information::release_value() {
  clear_has_value();
  if (value_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = value_;
    value_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// -------------------------------------------------------------------

// Command

// required .proto.Command.Type type = 1;
inline bool Command::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Command::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Command::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Command::clear_type() {
  type_ = 1;
  clear_has_type();
}
inline ::proto::Command_Type Command::type() const {
  return static_cast< ::proto::Command_Type >(type_);
}
inline void Command::set_type(::proto::Command_Type value) {
  GOOGLE_DCHECK(::proto::Command_Type_IsValid(value));
  set_has_type();
  type_ = value;
}

// optional .proto.Command.Information info = 2;
inline bool Command::has_info() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Command::set_has_info() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Command::clear_has_info() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Command::clear_info() {
  if (info_ != NULL) info_->::proto::Command_Information::Clear();
  clear_has_info();
}
inline const ::proto::Command_Information& Command::info() const {
  return info_ != NULL ? *info_ : *default_instance_->info_;
}
inline ::proto::Command_Information* Command::mutable_info() {
  set_has_info();
  if (info_ == NULL) info_ = new ::proto::Command_Information;
  return info_;
}
inline ::proto::Command_Information* Command::release_info() {
  clear_has_info();
  ::proto::Command_Information* temp = info_;
  info_ = NULL;
  return temp;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto::Command_Type>() {
  return ::proto::Command_Type_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_player_2eproto__INCLUDED