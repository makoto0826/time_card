import 'package:flutter/material.dart';
import 'package:time_card_flutter/screens/scan_screen.dart';

void main() {
  runApp(const TimeCardApp());
}

class TimeCardApp extends StatelessWidget {
  const TimeCardApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const ScanScreen(),
    );
  }
}
