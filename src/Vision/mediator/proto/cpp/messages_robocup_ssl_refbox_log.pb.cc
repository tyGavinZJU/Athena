// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: messages_robocup_ssl_refbox_log.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "messages_robocup_ssl_refbox_log.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* Log_Frame_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Log_Frame_reflection_ = NULL;
const ::google::protobuf::Descriptor* Refbox_Log_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Refbox_Log_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto() {
  protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "messages_robocup_ssl_refbox_log.proto");
  GOOGLE_CHECK(file != NULL);
  Log_Frame_descriptor_ = file->message_type(0);
  static const int Log_Frame_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Log_Frame, frame_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Log_Frame, refbox_cmd_),
  };
  Log_Frame_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Log_Frame_descriptor_,
      Log_Frame::default_instance_,
      Log_Frame_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Log_Frame, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Log_Frame, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Log_Frame));
  Refbox_Log_descriptor_ = file->message_type(1);
  static const int Refbox_Log_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Refbox_Log, log_),
  };
  Refbox_Log_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Refbox_Log_descriptor_,
      Refbox_Log::default_instance_,
      Refbox_Log_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Refbox_Log, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Refbox_Log, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Refbox_Log));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Log_Frame_descriptor_, &Log_Frame::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Refbox_Log_descriptor_, &Refbox_Log::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_messages_5frobocup_5fssl_5frefbox_5flog_2eproto() {
  delete Log_Frame::default_instance_;
  delete Log_Frame_reflection_;
  delete Refbox_Log::default_instance_;
  delete Refbox_Log_reflection_;
}

void protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_messages_5frobocup_5fssl_5fdetection_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n%messages_robocup_ssl_refbox_log.proto\032"
    "$messages_robocup_ssl_detection.proto\"C\n"
    "\tLog_Frame\022\"\n\005frame\030\001 \002(\0132\023.SSL_Detectio"
    "nFrame\022\022\n\nrefbox_cmd\030\002 \002(\t\"%\n\nRefbox_Log"
    "\022\027\n\003log\030\001 \003(\0132\n.Log_Frame", 185);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "messages_robocup_ssl_refbox_log.proto", &protobuf_RegisterTypes);
  Log_Frame::default_instance_ = new Log_Frame();
  Refbox_Log::default_instance_ = new Refbox_Log();
  Log_Frame::default_instance_->InitAsDefaultInstance();
  Refbox_Log::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_messages_5frobocup_5fssl_5frefbox_5flog_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_messages_5frobocup_5fssl_5frefbox_5flog_2eproto {
  StaticDescriptorInitializer_messages_5frobocup_5fssl_5frefbox_5flog_2eproto() {
    protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  }
} static_descriptor_initializer_messages_5frobocup_5fssl_5frefbox_5flog_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Log_Frame::kFrameFieldNumber;
const int Log_Frame::kRefboxCmdFieldNumber;
#endif  // !_MSC_VER

Log_Frame::Log_Frame()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Log_Frame)
}

void Log_Frame::InitAsDefaultInstance() {
  frame_ = const_cast< ::SSL_DetectionFrame*>(&::SSL_DetectionFrame::default_instance());
}

Log_Frame::Log_Frame(const Log_Frame& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Log_Frame)
}

void Log_Frame::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  frame_ = NULL;
  refbox_cmd_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Log_Frame::~Log_Frame() {
  // @@protoc_insertion_point(destructor:Log_Frame)
  SharedDtor();
}

void Log_Frame::SharedDtor() {
  if (refbox_cmd_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete refbox_cmd_;
  }
  if (this != default_instance_) {
    delete frame_;
  }
}

void Log_Frame::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Log_Frame::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Log_Frame_descriptor_;
}

const Log_Frame& Log_Frame::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  return *default_instance_;
}

Log_Frame* Log_Frame::default_instance_ = NULL;

Log_Frame* Log_Frame::New() const {
  return new Log_Frame;
}

void Log_Frame::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_frame()) {
      if (frame_ != NULL) frame_->::SSL_DetectionFrame::Clear();
    }
    if (has_refbox_cmd()) {
      if (refbox_cmd_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        refbox_cmd_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Log_Frame::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Log_Frame)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .SSL_DetectionFrame frame = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_frame()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_refbox_cmd;
        break;
      }

      // required string refbox_cmd = 2;
      case 2: {
        if (tag == 18) {
         parse_refbox_cmd:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_refbox_cmd()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->refbox_cmd().data(), this->refbox_cmd().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "refbox_cmd");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Log_Frame)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Log_Frame)
  return false;
#undef DO_
}

void Log_Frame::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Log_Frame)
  // required .SSL_DetectionFrame frame = 1;
  if (has_frame()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->frame(), output);
  }

  // required string refbox_cmd = 2;
  if (has_refbox_cmd()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->refbox_cmd().data(), this->refbox_cmd().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "refbox_cmd");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->refbox_cmd(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Log_Frame)
}

::google::protobuf::uint8* Log_Frame::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Log_Frame)
  // required .SSL_DetectionFrame frame = 1;
  if (has_frame()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->frame(), target);
  }

  // required string refbox_cmd = 2;
  if (has_refbox_cmd()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->refbox_cmd().data(), this->refbox_cmd().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "refbox_cmd");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->refbox_cmd(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Log_Frame)
  return target;
}

int Log_Frame::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .SSL_DetectionFrame frame = 1;
    if (has_frame()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->frame());
    }

    // required string refbox_cmd = 2;
    if (has_refbox_cmd()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->refbox_cmd());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Log_Frame::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Log_Frame* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Log_Frame*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Log_Frame::MergeFrom(const Log_Frame& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_frame()) {
      mutable_frame()->::SSL_DetectionFrame::MergeFrom(from.frame());
    }
    if (from.has_refbox_cmd()) {
      set_refbox_cmd(from.refbox_cmd());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Log_Frame::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Log_Frame::CopyFrom(const Log_Frame& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Log_Frame::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_frame()) {
    if (!this->frame().IsInitialized()) return false;
  }
  return true;
}

void Log_Frame::Swap(Log_Frame* other) {
  if (other != this) {
    std::swap(frame_, other->frame_);
    std::swap(refbox_cmd_, other->refbox_cmd_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Log_Frame::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Log_Frame_descriptor_;
  metadata.reflection = Log_Frame_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Refbox_Log::kLogFieldNumber;
#endif  // !_MSC_VER

Refbox_Log::Refbox_Log()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Refbox_Log)
}

void Refbox_Log::InitAsDefaultInstance() {
}

Refbox_Log::Refbox_Log(const Refbox_Log& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Refbox_Log)
}

void Refbox_Log::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Refbox_Log::~Refbox_Log() {
  // @@protoc_insertion_point(destructor:Refbox_Log)
  SharedDtor();
}

void Refbox_Log::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Refbox_Log::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Refbox_Log::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Refbox_Log_descriptor_;
}

const Refbox_Log& Refbox_Log::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_messages_5frobocup_5fssl_5frefbox_5flog_2eproto();
  return *default_instance_;
}

Refbox_Log* Refbox_Log::default_instance_ = NULL;

Refbox_Log* Refbox_Log::New() const {
  return new Refbox_Log;
}

void Refbox_Log::Clear() {
  log_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Refbox_Log::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Refbox_Log)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Log_Frame log = 1;
      case 1: {
        if (tag == 10) {
         parse_log:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_log()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_log;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Refbox_Log)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Refbox_Log)
  return false;
#undef DO_
}

void Refbox_Log::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Refbox_Log)
  // repeated .Log_Frame log = 1;
  for (int i = 0; i < this->log_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->log(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Refbox_Log)
}

::google::protobuf::uint8* Refbox_Log::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Refbox_Log)
  // repeated .Log_Frame log = 1;
  for (int i = 0; i < this->log_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->log(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Refbox_Log)
  return target;
}

int Refbox_Log::ByteSize() const {
  int total_size = 0;

  // repeated .Log_Frame log = 1;
  total_size += 1 * this->log_size();
  for (int i = 0; i < this->log_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->log(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Refbox_Log::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Refbox_Log* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Refbox_Log*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Refbox_Log::MergeFrom(const Refbox_Log& from) {
  GOOGLE_CHECK_NE(&from, this);
  log_.MergeFrom(from.log_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Refbox_Log::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Refbox_Log::CopyFrom(const Refbox_Log& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Refbox_Log::IsInitialized() const {

  if (!::google::protobuf::internal::AllAreInitialized(this->log())) return false;
  return true;
}

void Refbox_Log::Swap(Refbox_Log* other) {
  if (other != this) {
    log_.Swap(&other->log_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Refbox_Log::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Refbox_Log_descriptor_;
  metadata.reflection = Refbox_Log_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
