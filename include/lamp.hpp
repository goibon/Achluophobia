#ifndef LAMP
#define LAMP
class Lamp {
private:
  static const int MAX_CHARGE = 500;
  static const int PUMP_AMOUNT = 5;
  int mCharge;
  int mDrainRate;
  bool mIsDrained;

public:
  Lamp();
  int getCharge();
  bool isDrained();
  void pump();
  void drain();
  void increaseDrainRate(int increment);
};
#endif
