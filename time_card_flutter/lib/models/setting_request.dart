import 'package:freezed_annotation/freezed_annotation.dart';
import 'package:flutter/foundation.dart';
part 'setting_request.freezed.dart';

@freezed
class SettingRequest with _$SettingRequest {
  const factory SettingRequest(
      {required String ip,
      required String subnet,
      required String gw,
      required String dns1,
      required String dns2,
      required String apiKey,
      required String endPoint}) = _SettingRequest;
}
