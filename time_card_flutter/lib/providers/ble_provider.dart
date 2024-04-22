import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:flutter_blue_plus/flutter_blue_plus.dart';

final scanProvider = Provider.autoDispose<Stream<List<ScanResult>>>((ref) {
  FlutterBluePlus.startScan();
  return FlutterBluePlus.onScanResults;
});

final deviceListProvider =
    StreamProvider.autoDispose<List<BluetoothDevice>>((ref) {
  final scan = ref.watch(scanProvider);
  return scan
      .map((scanResult) => scanResult.map((result) => result.device).toList());
});
