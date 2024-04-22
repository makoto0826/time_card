// coverage:ignore-file
// GENERATED CODE - DO NOT MODIFY BY HAND
// ignore_for_file: type=lint
// ignore_for_file: unused_element, deprecated_member_use, deprecated_member_use_from_same_package, use_function_type_syntax_for_parameters, unnecessary_const, avoid_init_to_null, invalid_override_different_default_values_named, prefer_expression_function_bodies, annotate_overrides, invalid_annotation_target, unnecessary_question_mark

part of 'setting_request.dart';

// **************************************************************************
// FreezedGenerator
// **************************************************************************

T _$identity<T>(T value) => value;

final _privateConstructorUsedError = UnsupportedError(
    'It seems like you constructed your class using `MyClass._()`. This constructor is only meant to be used by freezed and you are not supposed to need it nor use it.\nPlease check the documentation here for more information: https://github.com/rrousselGit/freezed#adding-getters-and-methods-to-our-models');

/// @nodoc
mixin _$SettingRequest {
  String get ip => throw _privateConstructorUsedError;
  String get subnet => throw _privateConstructorUsedError;
  String get gw => throw _privateConstructorUsedError;
  String get dns1 => throw _privateConstructorUsedError;
  String get dns2 => throw _privateConstructorUsedError;
  String get apiKey => throw _privateConstructorUsedError;
  String get endPoint => throw _privateConstructorUsedError;

  @JsonKey(ignore: true)
  $SettingRequestCopyWith<SettingRequest> get copyWith =>
      throw _privateConstructorUsedError;
}

/// @nodoc
abstract class $SettingRequestCopyWith<$Res> {
  factory $SettingRequestCopyWith(
          SettingRequest value, $Res Function(SettingRequest) then) =
      _$SettingRequestCopyWithImpl<$Res, SettingRequest>;
  @useResult
  $Res call(
      {String ip,
      String subnet,
      String gw,
      String dns1,
      String dns2,
      String apiKey,
      String endPoint});
}

/// @nodoc
class _$SettingRequestCopyWithImpl<$Res, $Val extends SettingRequest>
    implements $SettingRequestCopyWith<$Res> {
  _$SettingRequestCopyWithImpl(this._value, this._then);

  // ignore: unused_field
  final $Val _value;
  // ignore: unused_field
  final $Res Function($Val) _then;

  @pragma('vm:prefer-inline')
  @override
  $Res call({
    Object? ip = null,
    Object? subnet = null,
    Object? gw = null,
    Object? dns1 = null,
    Object? dns2 = null,
    Object? apiKey = null,
    Object? endPoint = null,
  }) {
    return _then(_value.copyWith(
      ip: null == ip
          ? _value.ip
          : ip // ignore: cast_nullable_to_non_nullable
              as String,
      subnet: null == subnet
          ? _value.subnet
          : subnet // ignore: cast_nullable_to_non_nullable
              as String,
      gw: null == gw
          ? _value.gw
          : gw // ignore: cast_nullable_to_non_nullable
              as String,
      dns1: null == dns1
          ? _value.dns1
          : dns1 // ignore: cast_nullable_to_non_nullable
              as String,
      dns2: null == dns2
          ? _value.dns2
          : dns2 // ignore: cast_nullable_to_non_nullable
              as String,
      apiKey: null == apiKey
          ? _value.apiKey
          : apiKey // ignore: cast_nullable_to_non_nullable
              as String,
      endPoint: null == endPoint
          ? _value.endPoint
          : endPoint // ignore: cast_nullable_to_non_nullable
              as String,
    ) as $Val);
  }
}

/// @nodoc
abstract class _$$SettingRequestImplCopyWith<$Res>
    implements $SettingRequestCopyWith<$Res> {
  factory _$$SettingRequestImplCopyWith(_$SettingRequestImpl value,
          $Res Function(_$SettingRequestImpl) then) =
      __$$SettingRequestImplCopyWithImpl<$Res>;
  @override
  @useResult
  $Res call(
      {String ip,
      String subnet,
      String gw,
      String dns1,
      String dns2,
      String apiKey,
      String endPoint});
}

/// @nodoc
class __$$SettingRequestImplCopyWithImpl<$Res>
    extends _$SettingRequestCopyWithImpl<$Res, _$SettingRequestImpl>
    implements _$$SettingRequestImplCopyWith<$Res> {
  __$$SettingRequestImplCopyWithImpl(
      _$SettingRequestImpl _value, $Res Function(_$SettingRequestImpl) _then)
      : super(_value, _then);

  @pragma('vm:prefer-inline')
  @override
  $Res call({
    Object? ip = null,
    Object? subnet = null,
    Object? gw = null,
    Object? dns1 = null,
    Object? dns2 = null,
    Object? apiKey = null,
    Object? endPoint = null,
  }) {
    return _then(_$SettingRequestImpl(
      ip: null == ip
          ? _value.ip
          : ip // ignore: cast_nullable_to_non_nullable
              as String,
      subnet: null == subnet
          ? _value.subnet
          : subnet // ignore: cast_nullable_to_non_nullable
              as String,
      gw: null == gw
          ? _value.gw
          : gw // ignore: cast_nullable_to_non_nullable
              as String,
      dns1: null == dns1
          ? _value.dns1
          : dns1 // ignore: cast_nullable_to_non_nullable
              as String,
      dns2: null == dns2
          ? _value.dns2
          : dns2 // ignore: cast_nullable_to_non_nullable
              as String,
      apiKey: null == apiKey
          ? _value.apiKey
          : apiKey // ignore: cast_nullable_to_non_nullable
              as String,
      endPoint: null == endPoint
          ? _value.endPoint
          : endPoint // ignore: cast_nullable_to_non_nullable
              as String,
    ));
  }
}

/// @nodoc

class _$SettingRequestImpl
    with DiagnosticableTreeMixin
    implements _SettingRequest {
  const _$SettingRequestImpl(
      {required this.ip,
      required this.subnet,
      required this.gw,
      required this.dns1,
      required this.dns2,
      required this.apiKey,
      required this.endPoint});

  @override
  final String ip;
  @override
  final String subnet;
  @override
  final String gw;
  @override
  final String dns1;
  @override
  final String dns2;
  @override
  final String apiKey;
  @override
  final String endPoint;

  @override
  String toString({DiagnosticLevel minLevel = DiagnosticLevel.info}) {
    return 'SettingRequest(ip: $ip, subnet: $subnet, gw: $gw, dns1: $dns1, dns2: $dns2, apiKey: $apiKey, endPoint: $endPoint)';
  }

  @override
  void debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties
      ..add(DiagnosticsProperty('type', 'SettingRequest'))
      ..add(DiagnosticsProperty('ip', ip))
      ..add(DiagnosticsProperty('subnet', subnet))
      ..add(DiagnosticsProperty('gw', gw))
      ..add(DiagnosticsProperty('dns1', dns1))
      ..add(DiagnosticsProperty('dns2', dns2))
      ..add(DiagnosticsProperty('apiKey', apiKey))
      ..add(DiagnosticsProperty('endPoint', endPoint));
  }

  @override
  bool operator ==(Object other) {
    return identical(this, other) ||
        (other.runtimeType == runtimeType &&
            other is _$SettingRequestImpl &&
            (identical(other.ip, ip) || other.ip == ip) &&
            (identical(other.subnet, subnet) || other.subnet == subnet) &&
            (identical(other.gw, gw) || other.gw == gw) &&
            (identical(other.dns1, dns1) || other.dns1 == dns1) &&
            (identical(other.dns2, dns2) || other.dns2 == dns2) &&
            (identical(other.apiKey, apiKey) || other.apiKey == apiKey) &&
            (identical(other.endPoint, endPoint) ||
                other.endPoint == endPoint));
  }

  @override
  int get hashCode =>
      Object.hash(runtimeType, ip, subnet, gw, dns1, dns2, apiKey, endPoint);

  @JsonKey(ignore: true)
  @override
  @pragma('vm:prefer-inline')
  _$$SettingRequestImplCopyWith<_$SettingRequestImpl> get copyWith =>
      __$$SettingRequestImplCopyWithImpl<_$SettingRequestImpl>(
          this, _$identity);
}

abstract class _SettingRequest implements SettingRequest {
  const factory _SettingRequest(
      {required final String ip,
      required final String subnet,
      required final String gw,
      required final String dns1,
      required final String dns2,
      required final String apiKey,
      required final String endPoint}) = _$SettingRequestImpl;

  @override
  String get ip;
  @override
  String get subnet;
  @override
  String get gw;
  @override
  String get dns1;
  @override
  String get dns2;
  @override
  String get apiKey;
  @override
  String get endPoint;
  @override
  @JsonKey(ignore: true)
  _$$SettingRequestImplCopyWith<_$SettingRequestImpl> get copyWith =>
      throw _privateConstructorUsedError;
}
